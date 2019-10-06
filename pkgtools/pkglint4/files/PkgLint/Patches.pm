# $NetBSD: Patches.pm,v 1.2 2019/10/06 10:33:34 rillig Exp $
#
# Everything concerning checks for patch files.
#

use strict;
use warnings;

sub checkline_cpp_macro_names($$) {
	my ($line, $text) = @_;
	my ($rest);

	use constant good_macros => PkgLint::Util::array_to_hash(qw(
		__STDC__

		__GNUC__ __GNUC_MINOR__
		__SUNPRO_C

		__i386
		__mips
		__sparc

		__APPLE__
		__bsdi__
		__CYGWIN__
		__DragonFly__
		__FreeBSD__ __FreeBSD_version
		__INTERIX
		__linux__
		__MINGW32__
		__NetBSD__ __NetBSD_Version__
		__OpenBSD__
		__SVR4
		__sgi
		__sun

		__GLIBC__
	));
	use constant bad_macros  => {
		"__sgi__" => "__sgi",
		"__sparc__" => "__sparc",
		"__sparc_v9__" => "__sparcv9",
		"__sun__" => "__sun",
		"__svr4__" => "__SVR4",
	};

	$rest = $text;
	while ($rest =~ s/defined\((__[\w_]+)\)// || $rest =~ s/\b(_\w+)\(//) {
		my ($macro) = ($1);

		if (exists(good_macros->{$macro})) {
			$opt_debug_misc and $line->log_debug("Found good macro \"${macro}\".");
		} elsif (exists(bad_macros->{$macro})) {
			$line->log_warning("The macro \"${macro}\" is not portable enough. Please use \"".bad_macros->{$macro}."\" instead.");
			$line->explain_warning("See the pkgsrc guide, section \"CPP defines\" for details.");

		} elsif ($macro eq "__NetBSD_Prereq__") {
			$line->log_warning("Please use __NetBSD_Version__ instead of __NetBSD_Prereq__.");
			$line->explain_warning(
"The __NetBSD_Prereq__ macro is pretty new. It was born in NetBSD",
"4.99.3, and maybe it won't survive for long. A better (and compatible)",
"way is to compare __NetBSD_Version__ directly to the required version",
"number.");

		} elsif ($macro =~ m"^_+NetBSD_+Version_+$"i && $macro ne "__NetBSD_Version__") {
			$line->log_warning("Misspelled variant \"${macro}\" of \"__NetBSD_Version__\".");

		} else {
			$opt_debug_unchecked and $line->log_debug("Unchecked macro \"${macro}\".");
		}
	}
}

sub checkfile_patch($) {
	my ($fname) = @_;
	my ($lines);
	my ($state, $redostate, $nextstate, $dellines, $addlines, $hunks);
	my ($seen_comment, $current_fname, $patched_files);
	my ($leading_context_lines, $trailing_context_lines, $context_scanning_leading);

	# Abbreviations used:
	# style: [c] = context diff, [u] = unified diff
	# scope: [f] = file, [h] = hunk, [l] = line
	# action: [d] = delete, [m] = modify, [a] = add, [c] = context
	use constant re_patch_rcsid	=> qr"^\$.*\$$";
	use constant re_patch_text	=> qr"^(.+)$";
	use constant re_patch_empty	=> qr"^$";
	use constant re_patch_cfd	=> qr"^\*\*\*\s(\S+)(.*)$";
	use constant re_patch_cfa	=> qr"^---\s(\S+)(.*)$";
	use constant re_patch_ch	=> qr"^\*{15}(.*)$";
	use constant re_patch_chd	=> qr"^\*{3}\s(\d+)(?:,(\d+))?\s\*{4}$";
	use constant re_patch_cha	=> qr"^-{3}\s(\d+)(?:,(\d+))?\s-{4}$";
	use constant re_patch_cld	=> qr"^(?:-\s(.*))?$";
	use constant re_patch_clm	=> qr"^(?:!\s(.*))?$";
	use constant re_patch_cla	=> qr"^(?:\+\s(.*))?$";
	use constant re_patch_clc	=> qr"^(?:\s\s(.*))?$";
	use constant re_patch_ufd	=> qr"^---\s(\S+)(?:\s+(.*))?$";
	use constant re_patch_ufa	=> qr"^\+{3}\s(\S+)(?:\s+(.*))?$";
	use constant re_patch_uh	=> qr"^\@\@\s-(?:(\d+),)?(\d+)\s\+(?:(\d+),)?(\d+)\s\@\@(.*)$";
	use constant re_patch_uld	=> qr"^-(.*)$";
	use constant re_patch_ula	=> qr"^\+(.*)$";
	use constant re_patch_ulc	=> qr"^\s(.*)$";
	use constant re_patch_ulnonl	=> qr"^\\ No newline at end of file$";

	use enum qw(:PST_
		START CENTER TEXT
		CFA CH CHD CLD0 CLD CLA0 CLA
		UFA UH UL
	);

	my @comment_explanation = (
"Each patch must document why it is necessary. If it has been applied",
"because of a security issue, a reference to the CVE should be mentioned",
"as well.",
"",
"Since it is our goal to have as few patches as possible, all patches",
"should be sent to the upstream maintainers of the package. After you",
"have done so, you should add a reference to the bug report containing",
"the patch.");

	my ($line, $m);

	my $check_text = sub($) {
		my ($text) = @_;

		if ($text =~ m"(\$(Author|Date|Header|Id|Locker|Log|Name|RCSfile|Revision|Source|State|$opt_rcsidstring)(?::[^\$]*)?\$)") {
			my ($tag) = ($2);

			if ($text =~ re_patch_uh) {
				$line->log_warning("Found RCS tag \"\$${tag}\$\". Please remove it.");
				$line->set_text($1);
			} else {
				$line->log_warning("Found RCS tag \"\$${tag}\$\". Please remove it by reducing the number of context lines using pkgdiff or \"diff -U[210]\".");
			}
		}
	};

	my $check_contents = sub() {

		if ($m->has(1)) {
			$check_text->($m->text(1));
		}
	};

	my $check_added_contents = sub() {
		my $text;

		return unless $m->has(1);
		$text = $m->text(1);
		checkline_cpp_macro_names($line, $text);
	};

	my $check_hunk_end = sub($$$) {
		my ($deldelta, $adddelta, $newstate) = @_;

		if ($deldelta > 0 && $dellines == 0) {
			$redostate = $newstate;
			if (defined($addlines) && $addlines > 0) {
				$line->log_error("Expected ${addlines} more lines to be added.");
			}
		} elsif ($adddelta > 0 && $addlines == 0) {
			$redostate = $newstate;
			if (defined($dellines) && $dellines > 0) {
				$line->log_error("Expected ${dellines} more lines to be deleted.");
			}
		} else {
			if (defined($context_scanning_leading)) {
				if ($deldelta != 0 && $adddelta != 0) {
					if ($context_scanning_leading) {
						$leading_context_lines++;
					} else {
						$trailing_context_lines++;
					}
				} else {
					if ($context_scanning_leading) {
						$context_scanning_leading = false;
					} else {
						$trailing_context_lines = 0;
					}
				}
			}

			if ($deldelta != 0) {
				$dellines -= $deldelta;
			}
			if ($adddelta != 0) {
				$addlines -= $adddelta;
			}
			if (!((defined($dellines) && $dellines > 0) ||
			      (defined($addlines) && $addlines > 0))) {
				if (defined($context_scanning_leading)) {
					if ($leading_context_lines != $trailing_context_lines) {
						$opt_debug_patches and $line->log_warning("The hunk that ends here does not have as many leading (${leading_context_lines}) as trailing (${trailing_context_lines}) lines of context.");
					}
				}
				$nextstate = $newstate;
			}
		}
	};

	# @param deldelta
	#	The number of lines that are deleted from the patched file.
	# @param adddelta
	#	The number of lines that are added to the patched file.
	# @param newstate
	#	The follow-up state when this line is the last line to be
	#	added in this hunk of the patch.
	#
	my $check_hunk_line = sub($$$) {
		my ($deldelta, $adddelta, $newstate) = @_;

		$check_contents->();
		$check_hunk_end->($deldelta, $adddelta, $newstate);

		# If -Wextra is given, the context lines are checked for
		# absolute paths and similar things. If it is not given,
		# only those lines that really add something to the patched
		# file are checked.
		if ($adddelta != 0 && ($deldelta == 0 || $opt_warn_extra)) {
			$check_added_contents->();
		}
	};

	# [ regex, to state, action ]
	my $transitions = {
		PST_START() =>
		[   [re_patch_rcsid, PST_CENTER, sub() {
			checkline_rcsid($line, "");
		}], [undef, PST_CENTER, sub() {
			checkline_rcsid($line, "");
		}]],
		PST_CENTER() =>
		[   [re_patch_empty, PST_TEXT, sub() {
			#
		}], [re_patch_cfd, PST_CFA, sub() {
			if ($seen_comment) {
				$opt_warn_space and $line->log_note("Empty line expected.");
			} else {
				$line->log_error("Comment expected.");
				$line->explain_error(@comment_explanation);
			}
			$line->log_warning("Please use unified diffs (diff -u) for patches.");
		}], [re_patch_ufd, PST_UFA, sub() {
			if ($seen_comment) {
				$opt_warn_space and $line->log_note("Empty line expected.");
			} else {
				$line->log_error("Comment expected.");
				$line->explain_error(@comment_explanation);
			}
		}], [undef, PST_TEXT, sub() {
			$opt_warn_space and $line->log_note("Empty line expected.");
		}]],
		PST_TEXT() =>
		[   [re_patch_cfd, PST_CFA, sub() {
			if (!$seen_comment) {
				$line->log_error("Comment expected.");
				$line->explain_error(@comment_explanation);
			}
			$line->log_warning("Please use unified diffs (diff -u) for patches.");
		}], [re_patch_ufd, PST_UFA, sub() {
			if (!$seen_comment) {
				$line->log_error("Comment expected.");
				$line->explain_error(@comment_explanation);
			}
		}], [re_patch_text, PST_TEXT, sub() {
			$seen_comment = true;
		}], [re_patch_empty, PST_TEXT, sub() {
			#
		}], [undef, PST_TEXT, sub() {
			#
		}]],
		PST_CFA() =>
		[   [re_patch_cfa, PST_CH, sub() {
			$current_fname = $m->text(1);
			$patched_files++;
			$hunks = 0;
		}]],
		PST_CH() =>
		[   [re_patch_ch, PST_CHD, sub() {
			$hunks++;
		}]],
		PST_CHD() =>
		[   [re_patch_chd, PST_CLD0, sub() {
			$dellines = ($m->has(2))
			    ? (1 + $m->text(2) - $m->text(1))
			    : ($m->text(1));
		}]],
		PST_CLD0() =>
		[   [re_patch_clc, PST_CLD, sub() {
			$check_hunk_line->(1, 0, PST_CLD0);
		}], [re_patch_cld, PST_CLD, sub() {
			$check_hunk_line->(1, 0, PST_CLD0);
		}], [re_patch_clm, PST_CLD, sub() {
			$check_hunk_line->(1, 0, PST_CLD0);
		}], [re_patch_cha, PST_CLA0, sub() {
			$dellines = undef;
			$addlines = ($m->has(2))
			    ? (1 + $m->text(2) - $m->text(1))
			    : ($m->text(1));
		}]],
		PST_CLD() =>
		[   [re_patch_clc, PST_CLD, sub() {
			$check_hunk_line->(1, 0, PST_CLD0);
		}], [re_patch_cld, PST_CLD, sub() {
			$check_hunk_line->(1, 0, PST_CLD0);
		}], [re_patch_clm, PST_CLD, sub() {
			$check_hunk_line->(1, 0, PST_CLD0);
		}], [undef, PST_CLD0, sub() {
			if ($dellines != 0) {
				$line->log_warning("Invalid number of deleted lines (${dellines} missing).");
			}
		}]],
		PST_CLA0() =>
		[   [re_patch_clc, PST_CLA, sub() {
			$check_hunk_line->(0, 1, PST_CH);
		}], [re_patch_clm, PST_CLA, sub() {
			$check_hunk_line->(0, 1, PST_CH);
		}], [re_patch_cla, PST_CLA, sub() {
			$check_hunk_line->(0, 1, PST_CH);
		}], [undef, PST_CH, sub() {
			#
		}]],
		PST_CLA() =>
		[   [re_patch_clc, PST_CLA, sub() {
			$check_hunk_line->(0, 1, PST_CH);
		}], [re_patch_clm, PST_CLA, sub() {
			$check_hunk_line->(0, 1, PST_CH);
		}], [re_patch_cla, PST_CLA, sub() {
			$check_hunk_line->(0, 1, PST_CH);
		}], [undef, PST_CLA0, sub() {
			if ($addlines != 0) {
				$line->log_warning("Invalid number of added lines (${addlines} missing).");
			}
		}]],
		PST_CH() =>
		[   [undef, PST_TEXT, sub() {
			#
		}]],
		PST_UFA() =>
		[   [re_patch_ufa, PST_UH, sub() {
			$current_fname = $m->text(1);
			$patched_files++;
			$hunks = 0;
		}]],
		PST_UH() =>
		[   [re_patch_uh, PST_UL, sub() {
			$dellines = ($m->has(1) ? $m->text(2) : 1);
			$addlines = ($m->has(3) ? $m->text(4) : 1);
			$check_text->($line->text);
			if ($line->text =~ m"\r$") {
				$line->log_error("The hunk header must not end with a CR character.");
				$line->explain_error(
"The MacOS X patch utility cannot handle these.");
			}
			$hunks++;
			$context_scanning_leading = (($m->has(1) && $m->text(1) ne "1") ? true : undef);
			$leading_context_lines = 0;
			$trailing_context_lines = 0;
		}], [undef, PST_TEXT, sub() {
			($hunks != 0) || $line->log_warning("No hunks for file ${current_fname}.");
		}]],
		PST_UL() =>
		[   [re_patch_uld, PST_UL, sub() {
			$check_hunk_line->(1, 0, PST_UH);
		}], [re_patch_ula, PST_UL, sub() {
			$check_hunk_line->(0, 1, PST_UH);
		}], [re_patch_ulc, PST_UL, sub() {
			$check_hunk_line->(1, 1, PST_UH);
		}], [re_patch_ulnonl, PST_UL, sub() {
			#
		}], [re_patch_empty, PST_UL, sub() {
			$opt_warn_space and $line->log_note("Leading white-space missing in hunk.");
			$check_hunk_line->(1, 1, PST_UH);
		}], [undef, PST_UH, sub() {
			if ($dellines != 0 || $addlines != 0) {
				$line->log_warning("Unexpected end of hunk (-${dellines},+${addlines} expected).");
			}
		}]]};

	$opt_debug_trace and log_debug($fname, NO_LINES, "checkfile_patch()");

	checkperms($fname);
	if (!($lines = load_lines($fname, false))) {
		log_error($fname, NO_LINE_NUMBER, "Could not be read.");
		return;
	}
	if (@{$lines} == 0) {
		log_error($fname, NO_LINE_NUMBER, "Must not be empty.");
		return;
	}

	$state = PST_START;
	$dellines = undef;
	$addlines = undef;
	$patched_files = 0;
	$seen_comment = false;
	$current_fname = undef;
	$hunks = undef;

	for (my $lineno = 0; $lineno <= $#{$lines}; ) {
		$line = $lines->[$lineno];
		my $text = $line->text;

		$opt_debug_patches and $line->log_debug("[${state} ${patched_files}/".($hunks||0)."/-".($dellines||0)."+".($addlines||0)."] $text");

		my $found = false;
		foreach my $t (@{$transitions->{$state}}) {
				if (!defined($t->[0])) {
					$m = undef;
				} elsif ($text =~ $t->[0]) {
					$opt_debug_patches and $line->log_debug($t->[0]);
					$m = PkgLint::SimpleMatch->new($text, \@-, \@+);
				} else {
					next;
				}
				$redostate = undef;
				$nextstate = $t->[1];
				$t->[2]->();
				if (defined($redostate)) {
					$state = $redostate;
				} else {
					$state = $nextstate;
					if (defined($t->[0])) {
						$lineno++;
					}
				}
				$found = true;
				last;
		}

		if (!$found) {
			$line->log_error("Parse error: state=${state}");
			$state = PST_TEXT;
			$lineno++;
		}
	}

	while ($state != PST_TEXT) {
		$opt_debug_patches and log_debug($fname, "EOF", "[${state} ${patched_files}/".($hunks||0)."/-".($dellines||0)."+".($addlines||0)."]");

		my $found = false;
		foreach my $t (@{$transitions->{$state}}) {
			if (!defined($t->[0])) {
				my $newstate;

				$m = undef;
				$redostate = undef;
				$nextstate = $t->[1];
				$t->[2]->();
				$newstate = (defined($redostate)) ? $redostate : $nextstate;
				if ($newstate == $state) {
					log_fatal($fname, "EOF", "Internal error in the patch transition table.");
				}
				$state = $newstate;
				$found = true;
				last;
			}
		}

		if (!$found) {
			log_error($fname, "EOF", "Parse error: state=${state}");
			$state = PST_TEXT;
		}
	}

	if ($patched_files > 1) {
		log_warning($fname, NO_LINE_NUMBER, "Contains patches for $patched_files files, should be only one.");

	} elsif ($patched_files == 0) {
		log_error($fname, NO_LINE_NUMBER, "Contains no patch.");
	}

	checklines_trailing_empty_lines($lines);
}

