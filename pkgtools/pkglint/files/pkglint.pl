#! @PERL@ -w
#
# pkglint - lint for package directory
#
# implemented by:
#	Jun-ichiro itojun Hagino <itojun@itojun.org>
#	Yoshishige Arai <ryo2@on.rim.or.jp>
#
# Copyright(c) 1997 by Jun-ichiro Hagino <itojun@itojun.org>.
# All rights reserved.
# Freely redistributable.  Absolutely no warranty.
#
# From Id: portlint.pl,v 1.64 1998/02/28 02:34:05 itojun Exp
# $NetBSD: pkglint.pl,v 1.295 2005/10/07 17:34:11 rillig Exp $
#
# This version contains lots of changes necessary for NetBSD packages
# done by:
#	Hubert Feyrer <hubertf@netbsd.org>,
#	Thorsten Frueauf <frueauf@netbsd.org>,
#	Thomas Klausner <wiz@netbsd.org>,
#	Roland Illig <rillig@NetBSD.org>
#	and others.
#

#==========================================================================
# Some comments on the overall structure: The @EXPORT clauses in the pack-
# ages must be in a BEGIN block, because otherwise the names starting with
# an uppercase letter are not recognized as subroutines but as file handles.
#==========================================================================

package PkgLint::Util;
#==========================================================================
# This package is a catch-all for everything that does not fit in any other
# package. Currently it contains the boolean constants C<false> and C<true>.
#==========================================================================
BEGIN {
	use Exporter;
	use vars qw(@ISA @EXPORT_OK);
	@ISA = qw(Exporter);
	@EXPORT_OK = qw(false print_table true);
}

use constant false	=> 0;
use constant true	=> 1;

sub print_table($$) {
	my ($out, $table) = @_;
	my (@width) = ();
	foreach my $row (@{$table}) {
		foreach my $i (0..$#{$row}) {
			if (!defined($width[$i]) || length($row->[$i]) > $width[$i]) {
				$width[$i] = length($row->[$i]);
			}
		}
	}
	foreach my $row (@{$table}) {
		my ($max) = ($#{$row});
		foreach my $i (0..$max) {
			if ($i != 0) {
				print $out ("  ");
			}
			print $out ($row->[$i]);
			if ($i != $max) {
				print $out (" " x ($width[$i] - length($row->[$i])));
			}
		}
		print $out ("\n");
	}
}

#== End of PkgLint::Util ==================================================

package PkgLint::Logging;
#==========================================================================
# This package provides the subroutines log_error, log_warning and log_info
# for printing messages to the user in a common format. The three subrou-
# tines have the parameters $file, $lineno and $message. In case there's no
# file appropriate for the message, NO_FILE may be passed, likewise for
# $lineno and NO_LINE_NUMBER. At the end of the program, the subroutine
# print_summary_and_exit should be called.
#
# Examples:
#   log_error(NO_FILE, NO_LINE_NUMBER, "Invalid command line.");
#   log_warning($file, NO_LINE_NUMBER, "Not found.");
#   log_info($file, $lineno, sprintf("invalid character (0x%02x).", $c));
#==========================================================================

use strict;
use warnings;
BEGIN {
	use Exporter;
	use vars qw(@ISA @EXPORT_OK);
	@ISA = qw(Exporter);
	@EXPORT_OK = qw(
		NO_FILE NO_LINE_NUMBER
		log_error log_warning log_info log_subinfo
		print_summary_and_exit set_verbose is_verbose
		set_gcc_output_format
	);
	import PkgLint::Util qw(
		false true
	);
}

use constant NO_FILE		=> undef;
use constant NO_LINE_NUMBER	=> undef;

my $errors		= 0;
my $warnings		= 0;
my $verbose_flag	= false;
my $gcc_output_format	= false;

sub log_message($$$$$) {
	my ($file, $subr, $lineno, $type, $message) = @_;
	my ($text, $sep);

	if (defined($file)) {
		# strip "." path components
		$file =~ s,^(?:\./)+,,;
		$file =~ s,/(?:\./)+,/,g;
		$file =~ s,/+,/,g;

		# strip intermediate "../.." path components
		while ($file =~ s,/[^.][^/]*/[^.][^/]*/\.\./\.\./,/,) {
		}
	}

	$text = "";
	$sep = "";
	if (!$gcc_output_format && defined($type)) {
		$text .= "${sep}${type}:";
		$sep = " ";
	}
	if (defined($file)) {
		$text .= defined($lineno)
		    ? "${sep}${file}:${lineno}"
		    : "${sep}${file}";
		$sep = ": ";
	}
	if ($gcc_output_format && defined($type)) {
		$text .= "${sep}${type}:";
		$sep = " ";
	}
	if (defined($subr)) {
		$text .= "${sep}[${subr}]";
		$sep = " ";
	}
	if (defined($message)) {
		$text .= "${sep}${message}";
		$sep = "";
	}

	print("${text}\n");
}

sub log_error($$$) {
	my ($file, $lineno, $msg) = @_;
	log_message($file, undef, $lineno, $gcc_output_format ? "error" : "ERROR", $msg);
	$errors++;
}
sub log_warning($$$) {
	my ($file, $lineno, $msg) = @_;
	log_message($file, undef, $lineno, $gcc_output_format ? "warning" : "WARN", $msg);
	$warnings++;
}
sub log_info($$$) {
	my ($file, $lineno, $msg) = @_;
	if ($verbose_flag) {
		log_message($file, undef, $lineno, $gcc_output_format ? "info" : "OK", $msg);
	}
}
sub log_subinfo($$$$) {
	my ($subr, $file, $lineno, $msg) = @_;
	if ($verbose_flag) {
		log_message($file, $subr, $lineno, $gcc_output_format ? "info" : "OK", $msg);
	}
}

sub print_summary_and_exit($) {
	my ($quiet) = @_;

	if (!$quiet) {
		if ($errors != 0 || $warnings != 0) {
			print("$errors errors and $warnings warnings found.\n");
		} else {
			print "looks fine.\n";
		}
	}
	exit($errors != 0);
}

sub set_verbose($) {
	my ($verbose) = @_;
	$verbose_flag = $verbose;
}

sub set_gcc_output_format() {
	$gcc_output_format = true;
}

#== End of PkgLint::Logging ===============================================

package PkgLint::FileUtil::Line;
#==========================================================================
# A Line is a class that contains the read-only fields C<file>, C<lineno>
# and C<text>, as well as some methods for printing diagnostics easily.
#==========================================================================
sub new($$$$) {
	my ($class, $file, $lineno, $text) = @_;
	my ($self) = ([$file, $lineno, $text]);
	bless($self, $class);
	return $self;
}
sub file($) {
	return shift(@_)->[0];
}
sub lineno($) {
	return shift(@_)->[1];
}
sub text($) {
	return shift(@_)->[2];
}

sub log_error($$) {
	my ($self, $text) = @_;
	PkgLint::Logging::log_error($self->file, $self->lineno, $text);
}
sub log_warning($$) {
	my ($self, $text) = @_;
	PkgLint::Logging::log_warning($self->file, $self->lineno, $text);
}
sub log_info($$) {
	my ($self, $text) = @_;
	PkgLint::Logging::log_info($self->file, $self->lineno, $text);
}
sub to_string($) {
	my ($self) = @_;
	return sprintf("%s:%s: %s", $self->file, $self->lineno, $self->text);
}
#== End of PkgLint::FileUtil::Line ========================================

package PkgLint::FileUtil;
#==========================================================================
# This package provides the subroutine load_file, which reads a file
# completely into memory as an array of lines.
#==========================================================================
use strict;
use warnings;

BEGIN {
	use Exporter;
	use vars qw(@ISA @EXPORT_OK);
	@ISA = qw(Exporter);
	@EXPORT_OK = qw(load_file);

	import PkgLint::Util qw(
		false true
	);
}

sub load_file($) {
	my ($fname) = @_;
	my ($result, $line, $lineno, $seen_newline);

	$result = [];
	open(F, "< $fname") or return undef;
	$lineno = 0;
	$seen_newline = true;
	while (defined($line = <F>)) {
		$lineno++;
		$seen_newline = ($line =~ s/\n$//);
		push(@{$result}, PkgLint::FileUtil::Line->new($fname, $lineno, $line));
	}
	if (!$seen_newline) {
		$result->[-1]->log_error("File must end with a newline.");
	}
	close(F) or return undef;
	return $result;
}

#== End of PkgLint::FileUtil ==============================================

package main;
use strict;
use warnings;

use Getopt::Long qw(:config no_ignore_case bundling require_order);
use File::Basename;
use Cwd;

BEGIN {
	import PkgLint::Util qw(
		false true
	);
	import PkgLint::Logging qw(
		NO_FILE NO_LINE_NUMBER
		log_error log_warning log_info log_subinfo
		print_summary_and_exit
	);
	import PkgLint::FileUtil qw(
		load_file
	);
}

# Buildtime configuration
my $conf_rcsidstring	= 'NetBSD';
my $conf_pkgsrcdir	= '@PKGSRCDIR@';
my $conf_localbase	= '@PREFIX@';
my $conf_distver	= '@DISTVER@';
my $conf_make		= '@MAKE@';
my $conf_datadir	= '@DATADIR@';

# Command Line Options

my $opt_check_DESCR	= true;
my $opt_check_distinfo	= true;
my $opt_check_extra	= true;
my $opt_check_bl3	= true;
my $opt_check_Makefile	= true;
my $opt_check_MESSAGE	= true;
my $opt_check_patches	= true;
my $opt_check_PLIST	= true;
my (%checks) = (
	"DESCR"		=> [\$opt_check_DESCR, "check DESCR file"],
	"distinfo"	=> [\$opt_check_distinfo, "check distinfo file"],
	"bl3"		=> [\$opt_check_bl3, "check buildlink3 files"],
	"extra"		=> [\$opt_check_extra, "check various additional files"],
	"Makefile"	=> [\$opt_check_Makefile, "check Makefiles"],
	"MESSAGE"	=> [\$opt_check_MESSAGE, "check MESSAGE files"],
	"patches"	=> [\$opt_check_patches, "check patches"],
	"PLIST"		=> [\$opt_check_PLIST, "check PLIST files"],
);

my $opt_warn_absname	= true;
my $opt_warn_directcmd	= true;
my $opt_warn_exec	= true;
my $opt_warn_order	= true;
my $opt_warn_paren	= true;
my $opt_warn_plist_sort	= false;
my $opt_warn_types	= true;
my $opt_warn_vague	= false;
my $opt_warn_workdir	= true;
my (%warnings) = (
	"absname"	=> [\$opt_warn_absname, "warn about use of absolute file names"],
	"directcmd"	=> [\$opt_warn_directcmd, "warn about use of direct command names instead of Make variables"],
	"exec"		=> [\$opt_warn_exec, "warn if source files are executable"],
	"order"		=> [\$opt_warn_order, "warn if Makefile entries are unordered"],
	"paren"		=> [\$opt_warn_paren, "warn about use of \$(VAR) instead of \${VAR} in Makefiles"],
	"plist-sort"	=> [\$opt_warn_plist_sort, "warn about unsorted entries in PLISTs"],
	"types"		=> [\$opt_warn_types, "do some simple type checking in Makefiles"],
	"vague"		=> [\$opt_warn_vague, "show old (unreliable, vague) warnings"],
	"workdir"	=> [\$opt_warn_workdir, "warn that work* should not be committed into CVS"],
);

my $opt_autofix		= false;
my $opt_dumpmakefile	= false;
my $opt_quiet		= false;
my $opt_recursive	= false;
my $opt_rcsidstring	= $conf_rcsidstring;
my (@options) = (
	# [ usage-opt, usage-message, getopt-opt, getopt-action ]
	[ "-C{check,...}", "Enable or disable specific checks",
	  "check|C=s",
	  sub {
		my ($opt, $val) = @_;
		parse_multioption($val, \%checks);
	  } ],
	[ "-F|--autofix", "Try to automatically fix some errors (experimental)",
	  "autofix|F", \$opt_autofix ],
	[ "-I|--dumpmakefile", "Dump the Makefile after parsing",
	  "dumpmakefile|I", \$opt_dumpmakefile ],
	[ "-R|--rcsidstring", "Set the allowed RCS Id strings",
	  "rcsidstring|R=s", \$opt_rcsidstring ],
	[ "-V|--version", "print the version number of pkglint",
	  "version|V",
	  sub {
		print("$conf_distver\n");
		exit(0);
	  } ],
	[ "-W{warn,...}", "enable or disable specific warnings",
	  "warning|W=s",
	  sub {
		my ($opt, $val) = @_;
		parse_multioption($val, \%warnings);
	  } ],
	[ "-g", "Mimic the gcc output format",
	  "gcc-output-format|g",
	  sub {
		PkgLint::Logging::set_gcc_output_format();
	  } ],
	[ "-h|--help", "print a detailed help message",
	  "help|h",
	  sub {
		help(*STDOUT, 0, 1);
	  } ],
	[ "-q", "don't print a summary line when finishing",
	  "quiet|q", \$opt_quiet ],
	[ "-r", "Recursive---check subdirectories, too",
	  "recursive|r", \$opt_recursive ],
	[ "-v|--verbose", "print progress messages",
	  "verbose|v",
	  sub {
		PkgLint::Logging::set_verbose(true);
	  } ]
);

# Constants
my $regex_mail_address	= qr"^[-\w\d_.]+\@[-\w\d.]+$";
my $regex_pkgname	= qr"^((?:[\w.+]|-[^\d])+)-(\d(?:\w|\.\d)*)$";
my $regex_unresolved	= qr"\$\{";
my $regex_url		= qr"^(?:http://|ftp://|#)"; # allow empty URLs
my $regex_url_directory	= qr"(?:http://|ftp://)\S+/";
my $regex_validchars	= qr"[\011\040-\176]";
my $regex_varassign	= qr"^([-A-Z_a-z0-9.\${}]+)\s*(=|\?=|\+=|:=|!=)\s*(.*?)$";
my $regex_yes		= qr"^(?:YES|yes)$";
my $regex_yesno		= qr"^(?:YES|yes|NO|no)$";

# Global variables
my $pkgdir;
my $filesdir;
my $patchdir;
my $distinfo_file;
my $scriptdir;
my $seen_USE_PKGLOCALEDIR;
my $seen_Makefile_common;
my $pkgname;
my @todo_dirs;

sub readmakefile($$$$);
sub checkextra($$);
sub checkorder($$@);
sub checkearlier($@);
sub check_predefined_sites($$);

sub help($$$) {
	my ($out, $exitval, $show_all) = @_;
	my ($prog) = (basename($0));
	print $out ("usage: $prog [options] [package_directory]\n\n");

	my (@option_table) = ();
	foreach my $opt (@options) {
		push(@option_table, ["  ", $opt->[0], $opt->[1]]);
	}
	print $out ("options:\n");
	PkgLint::Util::print_table($out, \@option_table);
	print $out ("\n");

	if (!$show_all) {
		exit($exitval);
	}

	my (@checks_table) = (
		["  ", "all", "", "enable all checks"],
		["  ", "none", "", "disable all checks"],
	);
	foreach my $check (sort keys %checks) {
		push(@checks_table, [ "  ", $check,
			(${$checks{$check}->[0]} ? "(enabled)" : "(disabled)"),
			$checks{$check}->[1]]);
	}
	print $out ("checks: (use \"check\" to enable, \"no-check\" to disable)\n");
	PkgLint::Util::print_table($out, \@checks_table);
	print $out ("\n");

	my (@warnings_table) = (
		["  ", "all", "", "enable all warnings"],
		["  ", "none", "", "disable all warnings"],
	);
	foreach my $warning (sort keys %warnings) {
		push(@warnings_table, [ "  ", $warning,
			(${$warnings{$warning}->[0]} ? "(enabled)" : "(disabled)"),
			$warnings{$warning}->[1]]);
	}
	print $out ("warnings: (use \"warn\" to enable, \"no-warn\" to disable)\n");
	PkgLint::Util::print_table($out, \@warnings_table);
	print $out ("\n");

	exit($exitval);
}

sub parse_multioption($$) {
	my ($value, $optdefs) = @_;
	foreach my $opt (split(qr",", $value)) {
		if ($opt eq "none") {
			foreach my $key (keys %{$optdefs}) {
				${$optdefs->{$key}->[0]} = false;
			}

		} elsif ($opt eq "all") {
			foreach my $key (keys %{$optdefs}) {
				${$optdefs->{$key}->[0]} = true;
			}

		} else {
			my ($value) = (($opt =~ s/^no-//) ? false : true);
			if (exists($optdefs->{$opt})) {
				${$optdefs->{$opt}->[0]} = $value;
			} else {
				help(*STDERR, 1, 0);
			}
		}
	}
}

sub parse_command_line() {
	my (%options);

	foreach my $opt (@options) {
		$options{$opt->[2]} = $opt->[3];
	}
	{
		local $SIG{__WARN__} = sub {};
		if (!GetOptions(%options)) {
			help(*STDERR, 1, false);
		}
	}
}

sub get_logical_line($$) {
	my ($lines, $ref_lineno) = @_;
	my ($value, $lineno, $first, $file, $firstlineno, $lastlineno);

	$value = "";
	$first = true;
	$lineno = ${$ref_lineno};
	$file = $lines->[$lineno]->file;
	$firstlineno = $lines->[$lineno]->lineno;

	for (; $lineno <= $#{$lines}; $lineno++) {
		if ($lines->[$lineno]->text =~ qr"^(\s*)(.*?)\s*(\\?)$") {
			my ($indent, $text, $cont) = ($1, $2, $3);

			if ($first) {
				$value .= $indent;
				$first = false;
			}

			$value .= $text;

			if ($cont eq "\\") {
				$value .= " ";
			} else {
				last;
			}
		}
	}

	$lastlineno = $lines->[$lineno]->lineno;
	${$ref_lineno} = $lineno + 1;

	return PkgLint::FileUtil::Line->new($file,
	    $firstlineno == $lastlineno
		? $firstlineno
		: "$firstlineno--$lastlineno",
	    $value);
}

sub to_logical_lines($) {
	my ($lines) = @_;

	my @loglines = ();
	for (my $lineno = 0; $lineno <= $#{$lines}; ) {
		push(@loglines, get_logical_line($lines, \$lineno));
	}
	return \@loglines;
}

sub load_make_vars_typemap() {
	my ($lines, $vartypes);

	if (!($lines = (load_file("${conf_datadir}/makevars.map")))) {
		return false;
	}
	$vartypes = {};

	foreach my $line (@{$lines}) {
		if ($line->text =~ qr"^(?:#.*|\s*)$") {
			# ignore empty and comment lines

		} elsif ($line->text =~ qr"^([\w\d_.]+)\s+([\w_]+)$") {
			$vartypes->{$1} = $2;

		} else {
			$line->log_error("[internal] Unknown line format.");
		}
	}
	return $vartypes;
}

sub load_predefined_sites($) {
	my ($pkgsrc_rootdir) = @_;
	my ($fname) = ("$pkgsrc_rootdir/mk/bsd.sites.mk");
	my ($lines) = load_file($fname);
	my ($varname) = undef;
	my ($ignoring) = false;
	my ($predefined_sites) = {};

	if (!$lines) {
		log_error($fname, NO_LINE_NUMBER, "Could not be read.");
		return false;
	}
	foreach my $line (@{$lines}) {
		my $text = $line->text;

		if ($text =~ qr"^(MASTER_SITE_\w+)\+=\s*\\$"o) {
			$varname = $1;
			$ignoring = false;

		} elsif ($text eq "MASTER_SITE_BACKUP?=\t\\") {
			$ignoring = true;

		} elsif ($text =~ qr"^\t($regex_url_directory)(?:|\s*\\)$"o) {
			if (!$ignoring) {
				if (defined($varname)) {
					$predefined_sites->{$1} = $varname;
				} else {
					$line->log_error("Lonely URL found.");
				}
			}

		} elsif ($text =~ qr"^(?:#.*|\s*)$") {
			# ignore empty and comment lines

		} elsif ($text =~ qr"BSD_SITES_MK") {
			# ignore multiple inclusion guards

		} else {
			$line->log_error("Unknown line type.");
		}
	}
	log_info($fname, NO_LINE_NUMBER, sprintf("Loaded %d MASTER_SITE_* definitions.", scalar(keys(%{$predefined_sites}))));
	return $predefined_sites;
}

sub is_committed($) {
	my ($fname) = @_;
	my ($basename, $entries);

	$basename = basename($fname);
	$entries = load_file(dirname($fname) . "/CVS/Entries");
	if (!$entries) {
		return false;
	}
	foreach my $entry (@{$entries}) {
		if ($entry->text =~ qr"^/\Q${basename}\E/") {
			return true;
		}
	}
	return false;
}

# - A directory that has no entries except ".", ".." and "CVS" is empty.
# - A directory whose entries besides ".", ".." and "CVS" are all empty is empty.
# - No other directories are empty.
sub is_emptydir($);
sub is_emptydir($) {
	my ($dir) = @_;
	my ($rv);

	if (!opendir(DIR, $dir)) {
		return true;
	}

	$rv = true;
	foreach my $subdir (readdir(DIR)) {
		next if $subdir eq "." || $subdir eq ".." || $subdir eq "CVS";
		next if -d "${dir}/${subdir}" && is_emptydir("${dir}/${subdir}");

		$rv = false;
		last;
	}

	closedir(DIR);
	return $rv;
}

sub get_subdirs($) {
	my ($dir) = @_;
	my (@result) = ();

	if (opendir(DIR, $dir)) {
		foreach my $subdir (readdir(DIR)) {
			if ($subdir ne "." && $subdir ne ".." && $subdir ne "CVS" && -d "${dir}/${subdir}" && !is_emptydir("${dir}/${subdir}")) {
				push(@result, $subdir);
			}
		}
		closedir(DIR);
	}
	return @result;
}

sub checkperms($) {
	my ($fname) = @_;

	if ($opt_warn_exec && -f $fname && -x $fname && !is_committed($fname)) {
		log_warning($fname, NO_LINE_NUMBER, "Should not be executable.");
	}
}

#
# Subroutines to check a single line.
#

sub checkline_length($$) {
	my ($line, $maxlength) = @_;

	if (length($line->text) > $maxlength) {
		$line->log_warning("Line too long (should be no more than $maxlength characters).");
	}
}

sub checkline_valid_characters($$) {
	my ($line, $re_validchars) = @_;
	my ($rest);

	($rest = $line->text) =~ s/$re_validchars//g;
	if ($rest ne "") {
		my @chars = map { $_ = sprintf("0x%02x", ord($_)); } split(//, $rest);
		$line->log_warning(sprintf("Line contains invalid characters (%s).", join(", ", @chars)));
	}
}

sub checkline_valid_characters_in_variable($$) {
	my ($line, $re_validchars) = @_;
	my ($varname, $rest);

	$rest = $line->text;
	if ($rest =~ $regex_varassign) {
		($varname, undef, $rest) = ($1, $2, $3);
	} else {
		return;
	}

	$rest =~ s/$re_validchars//g;
	if ($rest ne "") {
		my @chars = map { $_ = sprintf("0x%02x", ord($_)); } split(//, $rest);
		$line->log_warning(sprintf("${varname} contains invalid characters (%s).", join(", ", @chars)));
	}
}

sub checkline_trailing_whitespace($) {
	my ($line) = @_;
	if ($line->text =~ /\s+$/) {
		$line->log_warning("Trailing white-space.");
	}
}

sub checkline_rcsid_regex($$$) {
	my ($line, $prefix_regex, $prefix) = @_;
	if ($line->text !~ qr"^${prefix_regex}\$($opt_rcsidstring)(?::[^\$]*|)\$$") {
		$line->log_error("\"${prefix}\$${opt_rcsidstring}\$\" expected.");
		return false;
	}
	return true;
}

sub checkline_rcsid($$) {
	my ($line, $prefix) = @_;
	checkline_rcsid_regex($line, quotemeta($prefix), $prefix);
}

#
# Subroutines to check an array of lines.
#

sub checklines_trailing_empty_lines($) {
	my ($lines) = @_;
	my ($last, $max);

	$max = $#{$lines} + 1;
	for ($last = $max; $last > 1 && $lines->[$last - 1]->text eq ""; ) {
		$last--;
	}
	if ($last != $max) {
		$lines->[$last]->log_warning("Trailing empty lines.");
	}
}

#
# Subroutines to check a file.
#

sub checkfile_DESCR($$) {
	my ($dir, $fname) = @_;
	my ($maxchars, $maxlines) = (80, 24);
	my ($descr);

	log_subinfo("checkfile_DESCR", $fname, NO_LINE_NUMBER, undef);

	checkperms($fname);
	if (!($descr = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}
	if (@{$descr} == 0) {
		log_error($fname, NO_LINE_NUMBER, "Must not be empty.");
		return;
	}

	foreach my $line (@{$descr}) {
		checkline_length($line, $maxchars);
		checkline_trailing_whitespace($line);
		checkline_valid_characters($line, $regex_validchars);
	}
	checklines_trailing_empty_lines($descr);

	if (@{$descr} > $maxlines) {
		log_warning($fname, NO_LINE_NUMBER, "File too long (should be no more than $maxlines lines).");
	}
}

sub checkfile_distinfo($$) {
	my ($dir, $fname) = @_;
	my ($lines, %in_distinfo, %sums);

	log_subinfo("checkfile_distinfo", $fname, NO_LINE_NUMBER, undef);

	checkperms($fname);
	if (!($lines = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}

	if (@{$lines} == 0) {
		log_error($fname, NO_LINE_NUMBER, "Must not be empty.");
		return;
	}

	checkline_rcsid($lines->[0], "");
	if (1 <= $#{$lines} && $lines->[1]->text ne "") {
		$lines->[1]->log_warning("Empty line expected.");
	}

	foreach my $line (@{$lines}[2..$#{$lines}]) {
		if ($line->text !~ /^(MD5|SHA1|RMD160|Size) \(([^)]+)\) = (.*)(?: bytes)?$/) {
			$line->log_error("Unknown line type.");
			next;
		}

		my ($alg, $file, $sum) = ($1, $2, $3);

		if ($file =~ /^patch-[A-Za-z0-9]+$/) {
			if (-f "${dir}/${patchdir}/${file}") {
				my $chksum = `sed -e '/\$NetBSD.*/d' $dir/$patchdir/$file | digest $alg`;
				$chksum =~ s/\r*\n*\z//;
				if ($sum ne $chksum) {
					$line->log_error("Checksum of $file differs. Rerun '$conf_make makepatchsum'.");
				}
			} else {
				$line->log_warning("$file does not exist.");
			}
		} else {
			$sums{$alg}->{$file} = $line;
		}
		$in_distinfo{$file} = true;
	}
	checklines_trailing_empty_lines($lines);

	# Check for distfiles that have SHA1, but not RMD160 checksums
	foreach my $sha1_file (sort(keys(%{$sums{"SHA1"}}))) {
		if (!exists($sums{"RMD160"}->{$sha1_file})) {
			$sums{"SHA1"}->{$sha1_file}->log_error("RMD160 checksum missing for \"${sha1_file}\".");
		}
	}

	foreach my $patch (<${dir}/$patchdir/patch-*>) {
		$patch = basename($patch);
		if (!exists($in_distinfo{$patch})) {
			log_error($fname, NO_LINE_NUMBER, "$patch is not recorded. Rerun '$conf_make makepatchsum'.");
		}
	}
}

sub checkfile_MESSAGE($$) {
	my ($dir, $fname) = @_;
	my ($message);

	log_subinfo("checkfile_MESSAGE", $fname, NO_LINE_NUMBER, undef);

	checkperms($fname);
	if (!defined($message = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}

	if (@{$message} < 3) {
		log_warning($fname, NO_LINE_NUMBER, "File too short.");
		return;
	}
	if ($message->[0]->text ne "=" x 75) {
		$message->[0]->log_warning("Expected a line of exactly 75 \"=\" characters.");
	}
	checkline_rcsid($message->[1], "");
	foreach my $line (@{$message}) {
		checkline_length($line, 80);
		checkline_trailing_whitespace($line);
		checkline_valid_characters($line, $regex_validchars);
	}
	if ($message->[-1]->text ne "=" x 75) {
		$message->[-1]->log_warning("Expected a line of exactly 75 \"=\" characters.");
	}
	checklines_trailing_empty_lines($message);
}

sub checkfile_PLIST($$) {
	my ($dir, $fname) = @_;
	my ($plist, $last_file_seen);

	log_subinfo("checkfile_PLIST", $fname, NO_LINE_NUMBER, undef);

	checkperms($fname);
	if (!($plist = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}
	if (@{$plist} == 0) {
		log_error($fname, NO_LINE_NUMBER, "Must not be empty.");
		return;
	}
	checkline_rcsid($plist->[0], "\@comment ");

	line:
	foreach my $line (@{$plist}) {
		my $text = $line->text;

		checkline_trailing_whitespace($line);

		if ($text =~ /<\$ARCH>/) {
			$line->log_warning("use of <\$ARCH> is deprecated, use \${MACHINE_ARCH} instead.");
		}
		if ($text =~ /^\@([a-z]+)\s+(.*)/) {
			my ($cmd, $arg) = ($1, $2);
			if ($cmd eq "cwd" || $cmd eq "cd") {
				$line->log_error("\@cwd and \@cd must not be used anymore.");

			} elsif ($cmd eq "unexec" && $arg =~ /^rmdir/) {
				$line->log_warning("Use \"\@dirrm\" instead of \"\@unexec rmdir\".");

			} elsif (($cmd eq "exec" || $cmd eq "unexec")) {
				if ($arg =~ /(?:install-info|\$\{INSTALL_INFO\})/) {
					$line->log_warning("\@exec/unexec install-info is deprecated.");

				} elsif ($arg =~ /ldconfig/ && $arg !~ qr"/usr/bin/true") {
					$line->log_error("ldconfig must be used with \"||/usr/bin/true\".");
				}

			} elsif ($cmd eq "comment") {
				# nothing to do

			} elsif ($cmd eq "dirrm" || $cmd eq "option") {
				# no check made

			} elsif ($cmd eq "mode" || $cmd eq "owner" || $cmd eq "group") {
				$line->log_warning("\"\@mode/owner/group\" are deprecated, please use chmod/".
					"chown/chgrp in the pkg Makefile and let tar do the rest.");

			} else {
				$line->log_warning("Unknown PLIST directive \"\@$cmd\"");
			}
			next line;
		}

		if ($text =~ /^\//) {
			$line->log_error("Use of full pathname disallowed.");
		}

		if ($opt_warn_plist_sort && $text =~ qr"^\w" && $text !~ $regex_unresolved) {
			if (defined($last_file_seen)) {
				if ($last_file_seen gt $text) {
					$line->log_warning("${text} should be sorted before ${last_file_seen}.");
				}
			}
			$last_file_seen = $text;
		}

		if ($text =~ qr"^doc/") {
			$line->log_error("Documentation must be installed under share/doc, not doc.");

		} elsif ($text =~ qr"^etc/rc\.d/") {
			$line->log_error("RCD_SCRIPTS must not be registered in the PLIST. Please use the RCD_SCRIPTS framework.");

		} elsif ($text =~ qr"^etc/") {
			$line->log_error("Configuration files must not be registered in the PLIST. Please use the PKG_SYSCONFDIR framework.");

		} elsif ($text eq "info/dir") {
			$line->log_error("\"info/dir\" must not be listed. Use install-info to add/remove an entry.");

		} elsif ($text =~ qr"^lib/locale/") {
			$line->log_error("\"lib/locale\" must not be listed. Use \${PKGLOCALEDIR}/locale and set USE_PKGLOCALEDIR instead.");

		} elsif ($text =~ qr"^share/locale/") {
			$line->log_warning("Use of \"share/locale\" is deprecated.  Use \${PKGLOCALEDIR}/locale and set USE_PKGLOCALEDIR instead.");

		} elsif ($text =~ qr"^share/man/") {
			$line->log_warning("Man pages should be installed into man/, not share/man/.");
		}

		if ($text =~ /\${PKGLOCALEDIR}/ && !$seen_USE_PKGLOCALEDIR) {
			$line->log_warning("PLIST contains \${PKGLOCALEDIR}, but USE_PKGLOCALEDIR was not found.");
		}
	}
	checklines_trailing_empty_lines($plist);
}

sub checkfile_buildlink3_mk($$) {
	my ($dir, $fname) = @_;
	my ($lines);

	log_subinfo("checkfile_buildlink3_mk", $fname, NO_LINE_NUMBER, undef);

	if (!($lines = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}
	checklines_deprecated_variables($lines);
	checklines_trailing_empty_lines($lines);
	checklines_direct_tools($lines);
}

sub checkfile_extra($$) {
	my ($dir, $fname) = @_;
	my ($lines);

	log_subinfo("checkfile_extra", $fname, NO_LINE_NUMBER, undef);

	$lines = load_file($fname);
	if (!$lines) {
		log_error($fname, NO_LINE_NUMBER, "Could not be read.");
		return;
	}
	checklines_trailing_empty_lines($lines);
	checkperms($fname);
}

sub checklines_multiple_patches($) {
	my ($lines) = @_;
	my ($files_in_patch, $patch_state, $line_type, $dellines);

	$files_in_patch = 0;
	$patch_state = "";
	$dellines = 0;
	foreach my $line (@{$lines}) {
		my $text = $line->text;

		if ($text =~ qr"^@@ -\d+,(\d+) \+\d+,\d+ @@") {
			$line_type = "";
			$dellines = $1;

		} elsif ($dellines == 0 && index($text, "--- ") == 0 && $text !~ qr"^--- \d+(?:,\d+|) ----$") {
			$line_type = "-";

		} elsif (index($text, "*** ") == 0 && $text !~ qr"^\*\*\* \d+(?:,\d+|) \*\*\*\*$") {
			$line->log_warning("Please use unified diffs (diff -u) for patches.");
			$line_type = "*";

		} elsif (index($text, "+++ ") == 0) {
			$line_type = "+";

		} elsif ($dellines > 0 && $text =~ qr"^(?:-|\s)") {
			$line_type = "";
			$dellines--;

		} else {
			$line_type = "";
		}

		if ($patch_state eq "*") {
			if ($line_type eq "-") {
				$files_in_patch++;
				$patch_state = "";
			} else {
				$line->log_error("[internal] Unknown patch format.");
			}

		} elsif ($patch_state eq "-") {
			if ($line_type eq "+") {
				$files_in_patch++;
				$patch_state = "";
			} else {
				$line->log_error("[internal] Unknown patch format.");
			}

		} elsif ($patch_state eq "") {
			$patch_state = $line_type;
		}
	}

	if ($files_in_patch > 1) {
		log_warning($lines->[0]->file, NO_LINE_NUMBER, "Contains patches for $files_in_patch files, should be only one.");

	} elsif ($files_in_patch == 0) {
		log_error($lines->[0]->file, NO_LINE_NUMBER, "Contains no patch.");
	}
}

sub checkfile_patches_patch($$) {
	my ($dir, $fname) = @_;
	my ($lines);

	log_subinfo("checkfile_patches_patch", $fname, NO_LINE_NUMBER, undef);

	checkperms($fname);
	if (!($lines = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Could not be read.");
		return;
	}
	if (@{$lines} == 0) {
		log_error($fname, NO_LINE_NUMBER, "Must not be empty.");
		return;
	}
	checkline_rcsid($lines->[0], "");

	foreach my $line (@{$lines}[1..$#{$lines}]) {
		if ($line->text =~ qr"\$(Author|Date|Header|Id|Locker|Log|Name|RCSfile|Revision|Source|State|$opt_rcsidstring)(?::[^\$]*?|)\$") {
			my ($tag) = ($1);
			$line->log_warning("Possible RCS tag \"\$${tag}\$\". Please remove it by reducing the number of context lines using pkgdiff or \"diff -U[210]\".");
		}
	}
	checklines_trailing_empty_lines($lines);

	checklines_multiple_patches($lines);
}

sub readmakefile($$$$) {
	my ($dir, $file, $all_lines, $seen_Makefile_include) = @_;
	my $contents = "";
	my ($includefile, $dirname, $savedln, $level, $lines);

	$lines = load_file($file);
	if (!defined ($lines)) {
		return false;
	}
	foreach my $line (@{$lines}) {
		my $text = $line->text;

		push(@{$all_lines}, $line);
		# try to get any included file
		if ($text =~ qr"^\.\s*include\s+\"([^\$]+)\"$") {
			$includefile = $1;
			if (exists($seen_Makefile_include->{$includefile})) {
				$contents .= "### pkglint ### skipped $includefile\n";
				next;
			}
			if (!$opt_check_bl3 && $includefile =~ qr"/buildlink3.mk$") {
				$contents .= "### pkglint ### skipped $includefile\n";
				next;
			}

			$seen_Makefile_include->{$includefile} = true;
			if ($includefile =~ qr"^\.\./[^./][^/]*/[^/]+") {
				$line->log_warning("Relative directories should look like \"../../cat/pkg\", not \"../pkg\".");
			}
			if ($includefile =~ qr"^(?:\.\./(?:\.\./[^/]+/)?[^/]+/)?([^/]+)$") {
				my ($basename) = ($1);
				if ($basename ne "buildlink3.mk") {
					$seen_Makefile_common = true;
				}
			}
			if ($includefile =~ /\/mk\/texinfo\.mk/) {
				$line->log_error("Do not include $includefile.");
			}
			if ($includefile =~ /\/mk\/(?:bsd|java)/) {
				# skip these files
				$contents .= $text . "\n";
			} else {
				$dirname = dirname($file);
				# Only look in the directory relative to the
				# current file and in the current working directory.
				# We don't have an include dir list, like make(1) does.
				if (!-f "$dirname/$includefile") {
					$dirname = $dir;
				}
				if (!-f "$dirname/$includefile") {
					$line->log_error("Cannot read $dirname/$includefile.");
				} else {
					$line->log_info("Including $dirname/$includefile");
					$contents .= readmakefile($dir, "$dirname/$includefile", $all_lines, $seen_Makefile_include);
				}
			}

		} elsif ($text =~ qr"^\.\s*include\s+(.*)") {
			$line->log_info("Skipping include file $1");

		} else {
			$contents .= $text . "\n";
		}
	}
	return $contents;
}

# The pkglint author thinks that variables containing lists of things
# should have a name indicating some plural form. Sadly, there are other
# reasons like backwards compatibility and other developer's
# expectations that make changes to most of the following variables
# highly unlikely.
my $get_regex_plurals_value = undef;
sub get_regex_plurals() {

	if (defined($get_regex_plurals_value)) {
		return $get_regex_plurals_value;
	}

	my @plurals_ok = qw(
		.*S
		.*_ENV
		.*_REQD
		BUILDLINK_LDADD
		BUILDLINK_RECOMMENDED
		COMMENT
		EXTRACT_ONLY
		SUBST_SED
		_.*
	);
	my @plurals_missing_an_s = qw(
		.*_OVERRIDE
		.*_PREREQ
		.*_SRC
		.*_SUBST
		.*_TARGET
		.*_TMPL
		BUILDLINK_DEPMETHOD
		BUILDLINK_TRANSFORM
		CONFLICT
		EVAL_PREFIX
		INTERACTIVE_STAGE
		LICENSE
		MASTER_SITE_.*
		NOT_FOR_COMPILER
		NOT_FOR_PLATFORM
		ONLY_FOR_COMPILER
		ONLY_FOR_PLATFORM
		PERL5_PACKLIST
		PKG_FAIL_REASON
		PKG_SKIP_REASON
	);
	my @plurals_reluctantly_accepted = qw(
		CRYPTO
		FIX_RPATH
		PRINT_PLIST_AWK
		PYTHON_VERSIONS_INCOMPATIBLE
		REPLACE_INTERPRETER
		REPLACE_PERL
		REPLACE_RUBY
		RESTRICTED
		SITES_.*
	);
	my $plurals = join("|",
		@plurals_ok,
		@plurals_missing_an_s,
		@plurals_reluctantly_accepted
	);

	$get_regex_plurals_value = qr"^(?:${plurals})$";
	return $get_regex_plurals_value;
}

sub checkline_Makefile_vartype($$) {
	my ($line, $vartypes) = @_;
	if ($line->text =~ $regex_varassign) {
		my ($varname, $op, $value) = ($1, $2, $3);
		if ($value =~ qr"\$") {
			# ignore values that contain other variables

		} elsif (exists($vartypes->{$varname})) {
			my ($type) = ($vartypes->{$varname});
			if ($type eq "Boolean") {
				if ($value !~ $regex_yesno) {
					$line->log_warning("$varname should be set to YES, yes, NO, or no.");
				}

			} elsif ($type eq "Yes_Or_Undefined") {
				if ($value !~ $regex_yes) {
					$line->log_warning("$varname should be set to YES or yes.");
				}

			} elsif ($type eq "Mail_Address") {
				if ($value !~ $regex_mail_address) {
					$line->log_warning("\"$value\" is not a valid mail address.");
				}

			} elsif ($type eq "URL") {
				if ($value !~ $regex_url) {
					$line->log_warning("\"$value\" is not a valid URL.");
				}

			} elsif ($type eq "Integer") {
				if ($value !~ qr"^\d+$") {
					$line->log_warning("\"$value\" is not a valid Integer.");
				}

			} else {
				$line->log_error("[internal] Type $type unknown.");
			}

		} elsif ($op eq "+=") {
			my $varbase = ($varname =~ qr"(.+?)\..*") ? $1 : $varname;
			my $regex_plurals = get_regex_plurals();

			if ($varbase !~ $regex_plurals) {
				$line->log_warning("As ${varname} is modified using \"+=\", its name should indicate plural.");
			}
		}
	}
}

my $checklines_Makefile_varuse_map = undef;
sub checklines_Makefile_varuse($) {
	my ($lines) = @_;

	# Check variable name quoting
	foreach my $line (@{$lines}) {
		if ($line->text =~ qr"^[^#]*[^\$]\$(\w+)") {
			my ($varname) = ($1);
			$line->log_warning("please write either \${$varname} or \$\$$varname instead of \$$varname.");
		}
	}

	return if (!$opt_warn_types);

	# Load variable type definitions
	if (!defined($checklines_Makefile_varuse_map)) {
		$checklines_Makefile_varuse_map = load_make_vars_typemap();
	}
	return if (!$checklines_Makefile_varuse_map);

	# Check variable types
	foreach my $line (@{$lines}) {
		checkline_Makefile_vartype($line, $checklines_Makefile_varuse_map);
	}
}

sub checklines_deprecated_variables($) {
	my ($lines) = @_;
	my ($fname) = ("${conf_datadir}/deprecated.map");
	my ($deprecated) = load_file($fname);
	my %vars = ();

	if (!$deprecated) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}

	foreach my $line (@{$deprecated}) {
		if ($line->text =~ qr"^#" || $line->text =~ qr"^\s*$") {
			next;

		} elsif ($line->text =~ qr"^(\S+)\s+(.*)$") {
			$vars{$1} = $2;

		} else {
			$line->log_error("[internal] Unknown line format.");
		}
	}

	foreach my $line (@{$lines}) {
		if ($line->text =~ $regex_varassign) {
			my ($varname, undef, undef) = ($1, $2, $3);
			if (exists($vars{$varname})) {
				$line->log_warning("${varname} is deprecated. $vars{$varname}");
			}
		}
	}
}

sub checklines_direct_tools($) {
	my ($subr) = "checklines_direct_tools";
	my ($lines) = @_;

	return if (!$opt_warn_directcmd);

	log_info(NO_FILE, NO_LINE_NUMBER, "Checking direct use of tool names.");

	my @tools = qw(
		awk basename cat chmod chown chgrp cmp cp cut digest
		dirname echo egrep false file find gmake grep gtar gzcat
		id ident install ldconfig ln md5 mkdir mtree mv patch
		pax pkg_add pkg_create pkg_delete pkg_info rm rmdir sed
		setenv sh sort su tail test touch tr true type wc
		xmkmf);
	my @cmd_tools = qw(
		file gunzip gzip);
	my $tools = join("|", @tools, @cmd_tools);
	my $regex_tools = qr"${tools}";
	my $regex_tools_with_context = qr"(?:^|\s|/)($regex_tools)(?:\s|$)";

	my @ok_vars = qw(
		BUILDLINK_TRANSFORM BUILD_DEPENDS
		COMMENT CONFLICTS
		DEPENDS DISTNAME
		EXTRACT_SUFX EXTRACT_USING
		INTERACTIVE_STAGE
		MANSOURCEPATH MASTER_SITES
		PKGNAME PKGSRC_USE_TOOLS PKG_FAIL_REASON
		SUBST_MESSAGE\\..*
		.*_TARGET
		USE_TOOLS);
	my @valid_shellcmds = (
		qr"for file in",
		qr"(?:\./Build|\$\{JAM_COMMAND\})\s+(?:install|test)",
		qr"\"[^\"]*${regex_tools}[^\"]*\"",
		qr"\'[^\']*${regex_tools}[^\']*\'",
		qr"#.*",
	);

	my %toolvar = ();
	foreach my $tool (@tools) {
		$toolvar{$tool} = uc($tool);
	}
	foreach my $tool (@cmd_tools) {
		$toolvar{$tool} = uc($tool)."_CMD";
	}

	my $ok_vars = join("|", @ok_vars);
	my $regex_ok_vars = qr"^(?:${ok_vars})$";
	my $valid_shellcmds = join("|", @valid_shellcmds);
	my $regex_valid_shellcmds = qr"(?:${valid_shellcmds})";

	log_subinfo($subr, NO_FILE, NO_LINE_NUMBER, "regex_tools=${regex_tools}");
	log_subinfo($subr, NO_FILE, NO_LINE_NUMBER, "regex_ok_vars=${regex_ok_vars}");
	log_subinfo($subr, NO_FILE, NO_LINE_NUMBER, "regex_valid_shellcmds=${regex_valid_shellcmds}");

	foreach my $line (@{$lines}) {
		my $text = $line->text;

		next unless ($text =~ $regex_tools_with_context);
		my ($tool) = ($1);

		# skip comments
		if ($text =~ qr"^#") {

		# process variable assignments
		} elsif ($text =~ $regex_varassign) {
			my ($varname, undef, $varvalue) = ($1, $2, $3);

			if ($varname =~ $regex_ok_vars) {
				$line->log_info("Legitimate direct use of \"${tool}\" in variable ${varname}.");
			} else {
				$line->log_warning("Possible direct use of \"${tool}\" in variable ${varname}. Please use \$\{$toolvar{$tool}\} instead.");
			}

		# process shell commands
		} elsif ($text =~ qr"^\t(.*)$") {
			my ($short_shellcmd, $remaining_shellcmd) = ($1, $1);

			# Remove known legitimate uses from the string
			$remaining_shellcmd =~ s,$regex_valid_shellcmds,,g;

			# As shell commands tend to become long, extract
			# the relevant part only.
			if ($short_shellcmd =~ qr"(.{0,15})\Q${tool}\E(.{0,15})") {
				my ($before, $after) = ($1, $2);

				if (length($before) == 15) {
					$before = "...${before}";
				}
				if (length($after) == 15) {
					$after = "${after}...";
				}
				$short_shellcmd = "${before}${tool}${after}";
			}

			if ($remaining_shellcmd =~ $regex_tools_with_context) {
				$line->log_warning("Possible direct use of \"${tool}\" in shell command \"${short_shellcmd}\". Please use \$\{$toolvar{$tool}\} instead.");
			} else {
				$line->log_info("Legitimate direct use of \"${tool}\" in shell command \"${short_shellcmd}\".");
			}

		# skip processing directives
		} elsif ($text =~ qr"^\.") {

		# skip dependency specifications
		} elsif ($text =~ qr"^([-\w.]+):") {

		} else {
			$line->log_error("[internal:checklines_direct_tools] unknown line format");
		}
	}
}

# This subroutine contains "local" checks that can be made looking only
# at a single line at a time. The other checks are in
# checkfile_package_Makefile.
sub checklines_package_Makefile($) {
	my ($lines) = @_;

	foreach my $line (@{$lines}) {
		my $text = $line->text;

		if ($line->lineno == 1) {
			checkline_rcsid_regex($line, qr"#\s+", "# ");
		}

		checkline_trailing_whitespace($line);

		if ($text =~ /^\040{8}/) {
			$line->log_warning("Use tab (not spaces) to make indentation.");
		}

		if ($text =~ $regex_varassign) {
			my ($varname, $op, $value) = ($1, $2, $3);

			if ($varname eq "COMMENT") {
				if ($value =~ qr"^(a|an)\s+"i) {
					$line->log_warning("COMMENT should not begin with '$1'.");
				}
				if ($value =~ qr"^[a-z]") {
					$line->log_warning("COMMENT should start with a capital letter.");
				}
				if ($value =~ qr"\.$") {
					$line->log_warning("COMMENT should not end with a period.");
				}
				if (length($value) > 70) {
					$line->log_warning("COMMENT should not be longer than 70 characters.");
				}
			}

			if ($varname eq "PKG_SUPPORTED_OPTIONS" || $varname eq "PKG_SUGGESTED_OPTIONS") {
				if ($value =~ qr"_") {
					$line->log_warning("Options should not contain underscores.");
				}
			}

			if ($varname eq "SVR4_PKGNAME") {
				if ($value =~ $regex_unresolved) {
					$line->log_error("SVR4_PKGNAME must not contain references to other variables.");
				} elsif (length($value) > 5) {
					$line->log_error("SVR4_PKGNAME must not be longer than 5 characters.");
				}
			}

			if ($value eq "# defined" && $varname !~ qr".*(?:_MK|_COMMON)$") {
				$line->log_warning("Please use \"# empty\", \"# none\" or \"yes\" instead of \"# defined\".");
			}

			if ($varname =~ qr"^NO_(.*)_ON_(.*)$") {
				my ($what, $where) = ($1, $2);
				if (($what ne "SRC" && $what ne "BIN") || ($where ne "FTP" && $where ne "CDROM")) {
					$line->log_error("Misspelled variable: Valid names are USE_{BIN,SRC}_ON_{FTP,CDROM}.");
				}
			}
		}
	}

	checklines_trailing_empty_lines($lines);
}

sub expand_variable($$) {
	my ($whole, $varname) = @_;
	my ($value, $re);

	$re = qr"\n${varname}([+:?]?)=[ \t]*([^\n#]*)";
	$value = undef;
	while ($whole =~ m/$re/g) {
		my ($op, $val) = ($1, $2);
		if ($op ne "?" || !defined($value)) {
			$value = $val;
		}
	}
	if (!defined($value)) {
		return undef;
	}

	$value =~ s,\$\{\.CURDIR\},.,g;
	$value =~ s,\$\{PKGSRCDIR\},../..,g;
	$value =~ s,\$\{PHPPKGSRCDIR\},../../lang/php5,g;
	if (defined($pkgdir)) {
		$value =~ s,\$\{PKGDIR\},$pkgdir,g;
	}
	if ($value =~ $regex_unresolved) {
		log_subinfo("expand_variable", NO_FILE, NO_LINE_NUMBER, "The variable ${varname} could not be resolved completely. Its value is \"${value}\".");
	}
	return $value;
}

sub set_default_value($$) {
	my ($varref, $value) = @_;

	if (!defined(${$varref}) || ${$varref} =~ $regex_unresolved) {
		${$varref} = $value;
	}
}

sub load_package_Makefile($$$$$) {
	my ($subr) = "load_package_Makefile";
	my ($dir, $fname, $ref_whole, $ref_lines, $ref_loglines) = @_;
	my ($whole, $lines, $loglines);

	log_info($fname, NO_LINE_NUMBER, "Checking package Makefile.");

	$whole = readmakefile($dir, $fname, $lines = [], {});
	if (!$whole) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return false;
	}
	$loglines = to_logical_lines($lines);

	if ($opt_dumpmakefile) {
		print("OK: whole Makefile (with all included files) follows:\n");
		foreach my $line (@{$loglines}) {
			printf("%s\n", $line->to_string());
		}
	}

	# HACK
	if ($whole !~ qr"\nUSE_PHP_EXT_PATCHES") {
		log_info($fname, NO_LINE_NUMBER, "[hack] USE_PHP_EXT_PATCHES");
		$whole =~ s,\nPATCHDIR=.*PHPPKGSRCDIR.*,,;
	}
	# HACK
	if ($whole =~ qr"\nPECL_VERSION") {
		log_info($fname, NO_LINE_NUMBER, "[hack] PECL_VERSION");
		$whole =~ s,\nDISTINFO_FILE=.*PHPPKGSRCDIR.*,,;
	}

	$pkgdir = expand_variable($whole, "PKGDIR");
	set_default_value(\$pkgdir, ".");
	$distinfo_file = expand_variable($whole, "DISTINFO_FILE");
	set_default_value(\$distinfo_file, "distinfo");
	$filesdir = expand_variable($whole, "FILESDIR");
	set_default_value(\$filesdir, "files");
	$patchdir = expand_variable($whole, "PATCHDIR");
	set_default_value(\$patchdir, "patches");
	$scriptdir = expand_variable($whole, "SCRIPTDIR");
	set_default_value(\$scriptdir, "scripts");

	log_subinfo($subr, NO_FILE, NO_LINE_NUMBER, "DISTINFO_FILE=$distinfo_file");
	log_subinfo($subr, NO_FILE, NO_LINE_NUMBER, "FILESDIR=$filesdir");
	log_subinfo($subr, NO_FILE, NO_LINE_NUMBER, "PATCHDIR=$patchdir");
	log_subinfo($subr, NO_FILE, NO_LINE_NUMBER, "PKGDIR=$pkgdir");
	log_subinfo($subr, NO_FILE, NO_LINE_NUMBER, "SCRIPTDIR=$scriptdir");

	${$ref_whole} = $whole;
	${$ref_lines} = $lines;
	${$ref_loglines} = $loglines;
	return true;
}

sub checkfile_package_Makefile($$$$$) {
	my ($dir, $fname, $rawwhole, $lines, $loglines) = @_;
	my ($distname, $category, $distfiles,
	    $extract_sufx, $wrksrc);
	my ($abspkgdir, $whole, $tmp, $idx, @sections, @varnames);
	
	log_subinfo("checkfile_package_Makefile", $fname, NO_LINE_NUMBER, undef);

	checkperms($fname);
	checklines_package_Makefile($lines);

	$abspkgdir = Cwd::abs_path($dir);
	$category = basename(dirname($abspkgdir));
	$whole = "\n${rawwhole}";

	#
	# whole file: $(VARIABLE)
	#
	if ($opt_warn_paren) {
		if ($whole =~ /[^\$]\$\([\w\d]+\)/) {
			$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "Use \${VARIABLE} instead of \$(VARIABLE).");
		}
	}

	checklines_deprecated_variables($lines);

	#
	# whole file: INTERACTIVE_STAGE
	#
	$whole =~ s/\n#[^\n]*/\n/g;
	$whole =~ s/\n\n+/\n/g;
	if ($whole =~ /\nINTERACTIVE_STAGE/) {
		if ($whole !~ /defined\((BATCH|FOR_CDROM)\)/) {
			$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "Use of INTERACTIVE_STAGE discouraged. ".
				"Provide batch mode by using BATCH and/or FOR_CDROM.");
		}
	}

	if (   $whole !~ qr"\nPLIST_SRC"
	    && $whole !~ qr"\nNO_PKG_REGISTER"
	    && !-f "$dir/$pkgdir/PLIST"
	    && !-f "$dir/$pkgdir/PLIST.common") {
		$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "No PLIST or PLIST.common, and PLIST_SRC and NO_PKG_REGISTER unset. Are you sure PLIST handling is ok?");
	}

	if ($whole =~ qr"\nNO_CHECKSUM") {
		if (-f "${dir}/${distinfo_file}") {
			log_warning("${dir}/${distinfo_file}", NO_LINE_NUMBER, "This file should not exist if NO_CHECKSUM is set.");
		}
	} else {
		if (!-f "${dir}/${distinfo_file}") {
			log_warning("${dir}/${distinfo_file}", NO_LINE_NUMBER, "File not found. Please run '${conf_make} makesum'.");
		}
	}

	if ($whole =~ /\nUSE_PERL[^5]/) {
		$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "USE_PERL found -- you probably mean USE_PERL5.");
	}
	if ($whole =~ /\nUSE_PKGLOCALEDIR/) {
		$seen_USE_PKGLOCALEDIR = true;
	}
	if ($whole =~ m|\${MKDIR}.*(\${PREFIX}[/0-9a-zA-Z\${}]*)|) {
		$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "\${MKDIR} $1: consider using INSTALL_*_DIR");
	}
	if ($whole =~ m|\${INSTALL}(.*)\n|) {
		my $args = $1;
		if ($args =~ /-d/) {
			if ($args !~ /-[ogm]/) {
				$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "\${INSTALL}$args: " .
					"consider using INSTALL_*_DIR");
			}
		}
	}
	if ($whole =~ /\n\t-(.*(MKDIR|INSTALL.*-d|INSTALL_.*_DIR).*)/g) {
		$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "$1: no need to use '-' before command.");
	}

	checklines_direct_tools($loglines);

	#
	# whole file: continuation line in DEPENDS
	#
	if ($whole =~ /\n(BUILD_|)DEPENDS[^\n]*\\\n/) {
		$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "Please don't use continuation lines in (BUILD_)DEPENDS, use (BUILD_)DEPENDS+= instead.");
	}

	# whole file: check for pkgsrc-wip remnants
	#
	if ($whole =~ /\/wip\//
	 && $category ne "wip") {
		$opt_warn_vague && log_error(NO_FILE, NO_LINE_NUMBER, "Possible pkgsrc-wip pathname detected.");
	}

	if ($whole =~ /etc\/rc\.d/) {
		$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "Use RCD_SCRIPTS mechanism to install rc.d ".
			"scripts automatically to \${RCD_SCRIPTS_EXAMPLEDIR}.");
	}

	#
	# break the makefile into sections.
	#
	@sections = split(/\n\n+/, $rawwhole);
	foreach my $i (0..$#sections) {
		if ($sections[$i] !~ /\n$/) {
			$sections[$i] .= "\n";
		}
	}
	$idx = 0;

	# section 1 (comment lines): No checks needed
	$idx++;

	#
	# for the rest of the checks, comment lines are not important.
	#
	foreach my $i (0..$#sections) {
		$sections[$i] =~ s/^#[^\n]*//g;
		$sections[$i] =~ s/\n#[^\n]*//g;
		$sections[$i] =~ s/\n\n+/\n/g;
		$sections[$i] =~ s/^\n+//g;
		$sections[$i] =~ s/\\\n/ /g;
	}

	#
	#
	# section 2: DISTNAME/PKGNAME/...
	#
	log_info($fname, NO_LINE_NUMBER, "Checking DISTNAME section.");
	$tmp = $sections[$idx++];

	# check the order of items.
	&checkorder('DISTNAME', $tmp, qw(
		DISTNAME PKGNAME PKGREVISION SVR4_PKGNAME CATEGORIES
		MASTER_SITES DYNAMIC_MASTER_SITES MASTER_SITE_SUBDIR
		EXTRACT_SUFX DISTFILES ONLY_FOR_ARCHS NO_SRC_ON_FTP
		NO_BIN_ON_FTP));

	# check the items that have to be there.
	$tmp = "\n" . $tmp;
	foreach my $i ('DISTNAME', 'CATEGORIES') {
		if (!$seen_Makefile_common && $tmp !~ /\n$i=/) {
			$opt_warn_vague && log_error(NO_FILE, NO_LINE_NUMBER, "$i has to be there.");
		}
		if ($tmp =~ /\n$i(\?=)/) {
			$opt_warn_vague && log_error(NO_FILE, NO_LINE_NUMBER, "$i has to be set by \"=\", not by \"$1\".");
		}
	}

	# check for pkgsrc-wip remnants in CATEGORIES
	if ($tmp =~ /\nCATEGORIES=[ \t]*.*wip.*\n/
	 && $category ne "wip") {
		$opt_warn_vague && log_error(NO_FILE, NO_LINE_NUMBER, "Don't forget to remove \"wip\" from CATEGORIES.");
	}

	# check the URL
	if ($tmp =~ /\nMASTER_SITES[+?]?=[ \t]*([^\n]*)\n/
	 && $1 !~ /^[ \t]*$/) {
		log_info(NO_FILE, NO_LINE_NUMBER, "Seen MASTER_SITES, sanity checking URLs.");
		my @sites = split(/\s+/, $1);
		foreach my $i (@sites) {
			if ($i =~ m#^\w+://#) {
				if ($i !~ m#/$#) {
					$opt_warn_vague && log_error(NO_FILE, NO_LINE_NUMBER, "URL \"$i\" should ".
						"end with \"/\".");
				}
				if ($i =~ m#://[^/]*:/#) {
					$opt_warn_vague && log_error(NO_FILE, NO_LINE_NUMBER, "URL \"$i\" contains ".
						"extra \":\".");
				}
				check_predefined_sites("$dir/../..", $i);
			} else {
				log_info(NO_FILE, NO_LINE_NUMBER, "non-URL \"$i\" ok.");
			}
		if ($tmp =~ /\nDYNAMIC_MASTER_SITES[+?]?=/) {
			$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "MASTER_SITES and DYNAMIC_MASTER_SITES ".
				"found. Is this ok?");
			}
		}

	} elsif ($tmp !~ /\nDYNAMIC_MASTER_SITES[+?]?=/) {
		$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "no MASTER_SITES or DYNAMIC_MASTER_SITES found. ".
			"Is this ok?");
	}

	# check DISTFILES and related items.
	$distname     = expand_variable($tmp, "DISTNAME");
	$pkgname      = expand_variable($tmp, "PKGNAME");
	$extract_sufx = expand_variable($tmp, "EXTRACT_SUFX");
	$distfiles    = expand_variable($tmp, "DISTFILES");

	if (defined($extract_sufx)) {
		log_info(NO_FILE, NO_LINE_NUMBER, "Seen EXTRACT_SUFX, checking value.");
		if (defined($distfiles)) {
			$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "no need to define EXTRACT_SUFX if ".
				"DISTFILES is defined.");
		}
		if ($extract_sufx eq '.tar.gz') {
			$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "EXTRACT_SUFX is \".tar.gz.\" ".
				"by default. You don't need to specify it.");
		}
	} else {
		log_info(NO_FILE, NO_LINE_NUMBER, "No EXTRACT_SUFX seen, using default value.");
		$extract_sufx = '.tar.gz';
	}

	if ($opt_warn_vague && defined($pkgname) && defined($distname) && ($pkgname eq $distname || $pkgname eq "\${DISTNAME}")) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "PKGNAME is \${DISTNAME} by default. You don't need to define PKGNAME.");
	}
	if ($opt_warn_vague && defined($pkgname) && $pkgname !~ $regex_unresolved && $pkgname !~ $regex_pkgname) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "PKGNAME should have the form packagename-version, where version consists only of digits, letters and dots.");
	}

	if ($opt_warn_vague && !defined($pkgname) && defined($distname) && $distname !~ $regex_unresolved && $distname !~ $regex_pkgname) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "As DISTNAME ist not a valid package name, please define the PKGNAME explicitly.");
	}

	if (defined($distname) && $distname =~ qr"(nb\d+)") {
			$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "Is '$1' really ok on DISTNAME, ".
				"or is it intended for PKGNAME?");
	}

	if (!defined($pkgname)) {
		$pkgname = $distname;
	}

	# if DISTFILES have only single item, it is better to avoid DISTFILES
	# and to use combination of DISTNAME and EXTRACT_SUFX.
	# example:
	#	DISTFILES=package-1.0.tgz
	# should be
	#	DISTNAME=     package-1.0
	#	EXTRACT_SUFX= .tgz
	if ($opt_warn_vague && defined($distfiles) && $distfiles !~ $regex_unresolved && $distfiles =~ /^\S+$/) {
		log_info(NO_FILE, NO_LINE_NUMBER, "Seen DISTFILES with single item, checking value.");
		log_warning(NO_FILE, NO_LINE_NUMBER, "Use of DISTFILES with single file ".
			"is discouraged. Distribution filename should be set by ".
			"DISTNAME and EXTRACT_SUFX.");
		if (defined($distname) && defined($extract_sufx) && $distfiles eq "${distname}${extract_sufx}") {
			log_warning(NO_FILE, NO_LINE_NUMBER, "Definition of DISTFILES not necessary. ".
				"DISTFILES is \${DISTNAME}\${EXTRACT_SUFX} by default.");
		}

		# make an advice only in certain cases.
		if (defined($pkgname) && $distfiles =~ /^$pkgname([-\.].+)$/) {
			log_warning(NO_FILE, NO_LINE_NUMBER, "How about \"DISTNAME=$pkgname\"".
				(($1 eq '.tar.gz')
					? ""
					: " and \"EXTRACT_SUFX=$1\"").
				", instead of DISTFILES?");
		}
	}

	push(@varnames, qw(
		DISTNAME PKGNAME SVR4_PKGNAME CATEGORIES MASTER_SITES
		MASTER_SITE_SUBDIR EXTRACT_SUFX DISTFILES));

	#
	# section 3: PATCH_SITES/PATCHFILES(optional)
	#
	log_info($fname, NO_LINE_NUMBER, "Checking optional PATCH section.");
	$tmp = $sections[$idx];

	if ($tmp =~ /(PATCH_SITES|PATCH_SITE_SUBDIR|PATCHFILES|PATCH_DIST_STRIP|PATCH_DIST_CAT)/) {
		&checkearlier($tmp, @varnames);

		$tmp = "\n$tmp";

		if ($tmp =~ /\n(PATCH_SITES)=/) {
			log_info(NO_FILE, NO_LINE_NUMBER, "Seen PATCH_SITES.");
			$tmp =~ s/$1[^\n]+\n//;
		}
		if ($tmp =~ /\n(PATCH_SITE_SUBDIR)=/) {
			log_info(NO_FILE, NO_LINE_NUMBER, "Seen PATCH_SITE_SUBDIR.");
			$tmp =~ s/$1[^\n]+\n//;
		}
		if ($tmp =~ /\n(PATCHFILES)=/) {
			log_info(NO_FILE, NO_LINE_NUMBER, "Seen PATCHFILES.");
			$tmp =~ s/$1[^\n]+\n//;
		}
		if ($tmp =~ /\n(PATCH_DIST_ARGS)=/) {
			log_info(NO_FILE, NO_LINE_NUMBER, "Seen PATCH_DIST_ARGS.");
			$tmp =~ s/$1[^\n]+\n//;
		}
		if ($tmp =~ /\n(PATCH_DIST_STRIP)=/) {
			log_info(NO_FILE, NO_LINE_NUMBER, "Seen PATCH_DIST_STRIP.");
			$tmp =~ s/$1[^\n]+\n//;
		}

		&checkextra($tmp, 'PATCH_SITES');

		$idx++;
	}

	push(@varnames, qw(PATCH_SITES PATCHFILES PATCH_DIST_STRIP));

	#
	# section 4: MAINTAINER
	#
	log_info($fname, NO_LINE_NUMBER, "Checking MAINTAINER section.");
	$tmp = $sections[$idx++];

	# check the order of items.
	&checkorder('MAINTAINER', $tmp, qw(MAINTAINER HOMEPAGE COMMENT));

	# warnings for missing or incorrect HOMEPAGE
	$tmp = "\n" . $tmp;
	if ($tmp !~ /\nHOMEPAGE[+?]?=[ \t]*([^\n]*)\n/ || $1 =~ /^[ \t]*$/) {
		$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "Please add HOMEPAGE if the package has one.");
	} else {
		my $i = $1;
		if ($i =~ m#^\w+://#) {
			if ($i !~ m#^\w+://[^\n/]+/#) {
				$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "URL \"$i\" does not ".
						"end with \"/\".");
			}
		}
	}

	# warnings for missing COMMENT
	if ($tmp !~ /\nCOMMENT=\s*(.*)$/) {
		$opt_warn_vague && log_error(NO_FILE, NO_LINE_NUMBER, "Please add a short COMMENT describing the package.");
	}

	checkearlier($tmp, @varnames);
	$tmp = "\n" . $tmp;
	if ($tmp =~ /\nMAINTAINER=[^@]+\@netbsd.org/) {
		$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "\@netbsd.org should be \@NetBSD.org in MAINTAINER.");

	} elsif ($tmp =~ /\nMAINTAINER=[^\n]+/) {
		$tmp =~ s/\nMAINTAINER=[^\n]+//;

	} else {
		$opt_warn_vague && log_error($fname, NO_LINE_NUMBER, "No MAINTAINER found.");
	}
	$tmp =~ s/\n\n+/\n/g;

	push(@varnames, qw(MAINTAINER HOMEPAGE COMMENT));

	#
	# section 5: *_DEPENDS (may not be there)
	#
	log_info($fname, NO_LINE_NUMBER, "Checking optional DEPENDS section.");
	$tmp = $sections[$idx];

	my @linestocheck = qw(BUILD_USES_MSGFMT BUILD_DEPENDS DEPENDS);
	if ($tmp =~ /(DEPENDS_TARGET|FETCH_DEPENDS|LIB_DEPENDS|RUN_DEPENDS).*=/) {
		$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "$1 is deprecated, please use DEPENDS.");
	}
	if ($tmp =~ /(LIB_|BUILD_|RUN_|FETCH_)?DEPENDS/ or
	    $tmp =~ /BUILD_USES_MSGFMT/) {
		&checkearlier($tmp, @varnames);

		foreach my $i (grep(/^[A-Z_]*DEPENDS[?+]?=/, split(/\n/, $tmp))) {
			$i =~ s/^([A-Z_]*DEPENDS)[?+]?=[ \t]*//;
			my $j = $1;
			log_info(NO_FILE, NO_LINE_NUMBER, "Checking packages listed in $j.");
			foreach my $k (split(/\s+/, $i)) {
				my $l = (split(':', $k))[0];

				# check BUILD_USES_MSGFMT
				if ($l =~ /^(msgfmt|gettext)$/) {
					$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "Dependency to $1 ".
						"listed in $j. Consider using".
						" BUILD_USES_MSGFMT.");
				}
				# check USE_PERL5
				if ($l =~ /^perl(\.\d+)?$/) {
					$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "Dependency to perl ".
						"listed in $j. Consider using".
						" USE_PERL5.");
				}

				# check USE_GMAKE
				if ($l =~ /^(gmake|\${GMAKE})$/) {
					$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "Dependency to $1 ".
						"listed in $j. Consider using".
						" USE_TOOLS+=gmake.");
				}

				# check direct dependencies on -dirs packages
				if ($l =~ /^([-a-zA-Z0-9]+)-dirs[-><=]+(.*)/) {
					$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "Dependency to $1-dirs ".
						"listed in $j. Consider using".
						" USE_DIRS+=$1-$2.");
				}

				# check pkg dir existence
				my @m = split(/:/, $k);
				if ($#m >= 1) {
					$m[1] =~ s/\${PKGSRCDIR}/$ENV{'PKGSRCDIR'}/;
					if ($m[1] =~ /\/$/) {
						$opt_warn_vague && log_error(NO_FILE, NO_LINE_NUMBER, "Trailing '/' (slash) for directory $m[1] listed in $j.");
					}
					if (! -d "$dir/$m[1]") {
						$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "No package directory $m[1] found, even though it is listed in $j.");
					} else {
						log_info(NO_FILE, NO_LINE_NUMBER, "Package directory $m[1] found.");
					}
				} else {
					$opt_warn_vague && log_error(NO_FILE, NO_LINE_NUMBER, "Invalid package dependency specification \"$k\".");
				}
			}
		}
		foreach my $i (@linestocheck) {
			$tmp =~ s/$i[?+]?=[^\n]+\n//g;
		}

		&checkextra($tmp, '*_DEPENDS');

		$idx++;
	}

	push(@varnames, @linestocheck);
	&checkearlier($tmp, @varnames);

	#
	# Makefile 6: check the rest of file
	#
	log_info($fname, NO_LINE_NUMBER, "Checking the rest of the file.");
	$tmp = join("\n\n", @sections[$idx .. $#{sections}]);

	$tmp = "\n" . $tmp;	# to make the begin-of-line check easier

	&checkearlier($tmp, @varnames);

	# check WRKSRC
	#
	# do not use DISTFILES/DISTNAME to control over WRKSRC.
	# DISTNAME is for controlling distribution filename.
	# example:
	#	DISTNAME= package
	#	PKGNAME=  package-1.0
	#	DISTFILES=package-1.0.tgz
	# should be
	#	DISTNAME=    package-1.0
	#	EXTRACT_SUFX=.tgz
	#	WRKSRC=      ${WRKDIR}/package
	#
	$wrksrc = '';
	$wrksrc = $1 if ($tmp =~ /\nWRKSRC[+?]?=[ \t]*([^\n]*)\n/);

	if (defined($distfiles) && $distfiles =~ qr"^\S+$" && defined($distname)) {
		if (defined($wrksrc) && $wrksrc ne "\${WRKDIR\}") {
		    $opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "Do not use DISTFILES and DISTNAME ".
			"to control WRKSRC. how about ".
			"\"WRKSRC=\${WRKDIR}/$distname\"?");
		} else {
		    $opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "DISTFILES/DISTNAME affects WRKSRC. ".
			"Use caution when changing them.");
		}
	}

	foreach my $i (grep(/^(\W+_ENV)[?+]?=/, split(/\n/, $tmp))) {
		$i =~ s/^(\W+_ENV)[?+]?=[ \t]*//;
		my $j = $1;
		foreach my $k (split(/\s+/, $i)) {
			if ($k !~/^".*"$/ && $k =~ /\${/ && $k !~/:Q}/) {
				# FIXME: don't "quote", always use :Q
				$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "Definition of $k in $j. ".
				"should use :Q or be quoted.");
			}
		}
	}

	# check USE_X11 and USE_IMAKE
	if ($tmp =~ /\nUSE_IMAKE[?+]?=/ && $tmp =~ /\nUSE_X11[?+]?=/) {
		$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "Since you already have USE_IMAKE, ".
			"you don't need USE_X11.");
	}

	# check direct use of important make targets.
	if ($tmp =~ /\n(fetch|extract|patch|configure|build|install):/) {
		$opt_warn_vague && log_error(NO_FILE, NO_LINE_NUMBER, "Direct redefinition of make target \"$1\" ".
			"discouraged. Redefine \"do-$1\" instead.");
	}

	checklines_Makefile_varuse($lines);
}

sub checkextra($$) {
	my ($str, $section) = @_;

	$str = "\n" . $str if ($str !~ /^\n/);
	$str =~ s/\n#[^\n]*/\n/g;
	$str =~ s/\n\n+/\n/g;
	$str =~ s/^\s+//;
	$str =~ s/\s+$//;
	return if ($str eq '');

	if ($str =~ /^([\w\d]+)/) {
		$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "Extra item placed in the ".
			"$section section, ".
			"for example, \"$1\".");
	} else {
		$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "Extra item placed in the ".
			"$section section.");
	}
}

sub checkorder($$@) {
	my ($section, $str, @order) = @_;

	if ($seen_Makefile_common || !$opt_warn_order) {
		log_info(NO_FILE, NO_LINE_NUMBER, "Skipping the Makefile order checks.");
		return;
	}

	log_info(NO_FILE, NO_LINE_NUMBER, "Checking the order of $section section.");

	my @items = ();
	foreach my $i (split("\n", $str)) {
		$i =~ s/[+?]?=.*$//;
		push(@items, $i);
	}

	@items = reverse(@items);
	my $j = -1;
	my $invalidorder = 0;
	while (@items) {
		my $i = pop(@items);
		my $k = 0;
		while ($k < @order && $order[$k] ne $i) {
			$k++;
		}
		if ($k <= $#order) {
			if ($k < $j) {
				$opt_warn_vague && log_error(NO_FILE, NO_LINE_NUMBER, "$i appears out-of-order.");
				$invalidorder++;
			} else {
				log_info(NO_FILE, NO_LINE_NUMBER, "Seen $i, in order.");
			}
			$j = $k;
		} else {
			$opt_warn_vague && log_error(NO_FILE, NO_LINE_NUMBER, "Extra item \"$i\" placed in".
				" the $section section.");
		}
	}
	if ($invalidorder) {
		$opt_warn_vague && log_error(NO_FILE, NO_LINE_NUMBER, "Order must be " . join('/', @order) . '.');
	} else {
		log_info(NO_FILE, NO_LINE_NUMBER, "$section section is ordered properly.");
	}
}

sub checkearlier($@) {
	my ($str, @varnames) = @_;

	if ($seen_Makefile_common || !$opt_warn_order) {
		log_info(NO_FILE, NO_LINE_NUMBER, "Skipping the Makefile earlier checks.");
		return;
	}

	log_info(NO_FILE, NO_LINE_NUMBER, "Checking items that have to appear earlier.");
	foreach my $i (@varnames) {
		if ($str =~ /\n$i[?+]?=/) {
			$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "\"$i\" has to appear earlier.");
		}
	}
}

my $predefined_sites_rootdir = undef;
my $predefined_sites = undef;
sub check_predefined_sites($$) {
	my ($pkgsrc_rootdir, $url) = @_;

	if (!defined($predefined_sites) || $predefined_sites_rootdir ne $pkgsrc_rootdir) {
		my $sites = load_predefined_sites($pkgsrc_rootdir);
		if ($sites != false) {
			$predefined_sites = $sites;
			$predefined_sites_rootdir = $pkgsrc_rootdir;
		}
	}
	if (!defined($predefined_sites)) {
		return false;
	}

	foreach my $site (keys(%{$predefined_sites})) {
		next unless (index($url, $site) == 0);
		my $subdir = substr($url, length($site));
		$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "Please use \${$predefined_sites->{$site}:=$subdir} instead of \"$url\".");
		return;
	}
	log_info(NO_FILE, NO_LINE_NUMBER, "URL does not match any of the predefined URLS. Good.");
}

sub checkdir_root($) {
	my ($dir) = @_;
	my ($fname) = "${dir}/Makefile";
	my ($lines, $prev_subdir, @subdirs);

	log_subinfo("checkdir_root", $fname, NO_LINE_NUMBER, "Checking pkgsrc root directory.");

	if (!($lines = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}

	if (0 <= $#{$lines}) {
		checkline_rcsid_regex($lines->[0], qr"#\s+", "# ");
	}

	foreach my $line (@{$lines}) {
		if ($line->text =~ qr"^(#?)SUBDIR\s*\+=(\s*)(\S+)\s*(?:#\s*(.*?)\s*|)$") {
			my ($comment_flag, $indentation, $subdir, $comment) = ($1, $2, $3, $4);

			if ($comment_flag eq "#" && (!defined($comment) || $comment eq "")) {
				$line->log_warning("${subdir} commented out without giving a reason.");
			}

			if ($indentation ne "\t") {
				$line->log_warning("Indentation should be a single tab character.");
			}

			if ($subdir =~ qr"\$" || !-f "${dir}/${subdir}/Makefile") {
				next;
			}

			if (defined($prev_subdir) && $subdir eq $prev_subdir) {
				$line->log_error("${subdir} must only appear once.");
			} elsif (defined($prev_subdir) && $subdir lt $prev_subdir) {
				$line->log_warning("${subdir} should come before ${prev_subdir}.");
			} else {
				# correctly ordered
			}

			$prev_subdir = $subdir;

			if ($comment_flag eq "") {
				push(@subdirs, "${dir}/${subdir}");
			}
		}
	}

	if ($opt_recursive) {
		push(@todo_dirs, @subdirs);
	}
}

sub checkdir_category($) {
	my ($dir) = @_;
	my $fname = "${dir}/Makefile";
	my ($lines, $lineno, $is_wip, @normalized_lines, $can_fix);

	if (!($lines = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}

	$is_wip = (basename(Cwd::abs_path($dir)) eq "wip");
	$can_fix = true;
	$lineno = 0;

	# The first line must contain the RCS Id
	if ($lineno <= $#{$lines} && checkline_rcsid_regex($lines->[$lineno], qr"#\s+", "# ")) {
		push(@normalized_lines, $lines->[$lineno++]->text);
	} else {
		# The error message has already been printed by checkline_rcsid_regex().
		push(@normalized_lines, "# \$NetBSD\$");
	}

	# Then, arbitrary comments may follow
	while ($lineno <= $#{$lines} && $lines->[$lineno]->text =~ qr"^#") {
		push(@normalized_lines, $lines->[$lineno++]->text);
	}

	# Then we need an empty line
	if ($lineno <= $#{$lines} && $lines->[$lineno]->text eq "") {
		push(@normalized_lines, $lines->[$lineno++]->text);
	} else {
		$lines->[$lineno]->log_error("Empty line expected.");
		push(@normalized_lines, "");
	}

	# Then comes the COMMENT line
	if ($lineno <= $#{$lines} && $lines->[$lineno]->text =~ qr"^COMMENT=\t*(.*)") {
		my ($comment) = ($1);

		checkline_valid_characters_in_variable($lines->[$lineno], qr"[-\040'(),/0-9A-Za-z]");
		push(@normalized_lines, $lines->[$lineno++]->text);
	} else {
		$lines->[$lineno]->log_error("COMMENT= line expected.");
		$can_fix = false;
	}

	# Then we need an empty line
	if ($lineno <= $#{$lines} && $lines->[$lineno]->text eq "") {
		push(@normalized_lines, $lines->[$lineno++]->text);
	} else {
		$lines->[$lineno]->log_error("Empty line expected.");
		push(@normalized_lines, "");
	}

	# And now to the most complicated part of the category Makefiles,
	# the (hopefully) sorted list of SUBDIRs. The first step is to
	# collect the SUBDIRs in the Makefile and in the file system.

	my (@f_subdirs, @m_subdirs);

	@f_subdirs = sort(get_subdirs($dir));

	my $prev_subdir = undef;
	while ($lineno <= $#{$lines}) {
		my $line = $lines->[$lineno];

		if ($line->text =~ qr"^(#?)SUBDIR\+=(\s*)(\S+)\s*(?:#\s*(.*?)\s*|)$") {
			my ($comment_flag, $indentation, $subdir, $comment) = ($1, $2, $3, $4);

			if ($comment_flag eq "#" && (!defined($comment) || $comment eq "")) {
				$line->log_warning("${subdir} commented out without giving a reason.");
			}

			if ($indentation ne "\t") {
				$line->log_warning("Indentation should be a single tab character.");
			}

			if (defined($prev_subdir) && $subdir eq $prev_subdir) {
				$line->log_error("${subdir} must only appear once.");
			} elsif (defined($prev_subdir) && $subdir lt $prev_subdir) {
				$line->log_warning("${subdir} should come before ${prev_subdir}.");
			} else {
				# correctly ordered
			}

			push(@m_subdirs, [$subdir, $line, $comment_flag ? false : true]);
			$prev_subdir = $subdir;
			$lineno++;

		} else {
			if ($line->text ne "") {
				$line->log_error("SUBDIR+= line or empty line expected.");
			}
			last;
		}
	}

	# To prevent unnecessary warnings about subdirectories that are
	# in one list, but not in the other, we generate the sets of
	# subdirs of each list.
	my (%f_check, %m_check);
	foreach my $f (@f_subdirs) { $f_check{$f} = true; }
	foreach my $m (@m_subdirs) { $m_check{$m->[0]} = true; }

	my ($f_index, $f_atend, $f_neednext, $f_current) = (0, false, true, undef, undef);
	my ($m_index, $m_atend, $m_neednext, $m_current) = (0, false, true, undef, undef);
	my ($line, $m_recurse);
	my (@subdirs);

	while (!($m_atend && $f_atend)) {

		if (!$m_atend && $m_neednext) {
			$m_neednext = false;
			if ($m_index > $#m_subdirs) {
				$m_atend = true;
				$line = $lines->[$lineno];
				next;
			} else {
				$m_current = $m_subdirs[$m_index]->[0];
				$line = $m_subdirs[$m_index]->[1];
				$m_recurse = $m_subdirs[$m_index]->[2];
				$m_index++;
			}
		}

		if (!$f_atend && $f_neednext) {
			$f_neednext = false;
			if ($f_index > $#f_subdirs) {
				$f_atend = true;
				next;
			} else {
				$f_current = $f_subdirs[$f_index++];
			}
		}

		if (!$f_atend && ($m_atend || $f_current lt $m_current)) {
			if (!exists($m_check{$f_current})) {
				$line->log_error("${f_current} exists in the file system, but not in the Makefile.");
			}
			$f_neednext = true;
			push(@normalized_lines, "SUBDIR+=\t${f_current}");

		} elsif (!$m_atend && ($f_atend || $m_current lt $f_current)) {
			if (!exists($f_check{$m_current})) {
				$line->log_error("${m_current} exists in the Makefile, but not in the file system.");
			}
			$m_neednext = true;

		} else { # $f_current eq $m_current
			$f_neednext = true;
			$m_neednext = true;
			push(@normalized_lines, $line->text);
			if ($m_recurse) {
				push(@subdirs, "${dir}/${m_current}");
			}
		}
	}

	# the wip category Makefile may have its own targets for generating
	# indexes and READMEs. Just skip them.
	if ($is_wip) {
		while ($lineno <= $#{$lines} - 2) {
			push(@normalized_lines, $lines->[$lineno++]->text);
		}
	}

	# Then we need an empty line
	if ($lineno <= $#{$lines} && $lines->[$lineno]->text eq "") {
		push(@normalized_lines, $lines->[$lineno++]->text);
	} else {
		$lines->[$lineno]->log_error("Empty line expected.");
		push(@normalized_lines, "");
	}

	# And, last but not least, the .include line
	my $final_line = ".include \"../mk/bsd.pkg.subdir.mk\"";
	if ($lineno <= $#{$lines} && $lines->[$lineno]->text eq $final_line) {
		push(@normalized_lines, $lines->[$lineno++]->text);
	} else {
		$lines->[$lineno]->log_error("Expected this: ${final_line}.");
		push(@normalized_lines, $final_line);
	}

	if ($lineno <= $#{$lines}) {
		$lines->[$lineno]->log_error("The file should end here.");
	}

	# If the user has requested automatic fixing and we can do it, we do it.
	if ($opt_autofix) {
		my $changed = false;
		if (scalar(@normalized_lines) != scalar(@{$lines})) {
			$changed = true;
		} else {
			for my $i (0..$#{$lines}) {
				if ($normalized_lines[$i] ne $lines->[$i]->text) {
					$changed = true;
				}
			}
		}

		if ($changed && $can_fix) {
			rename($fname, "${fname}.pkglint-backup") or die;
			open(F, "> ${fname}") or die;
			foreach my $line (@normalized_lines) {
				printf F ("%s\n", $line);
			}
			close(F) or die;
		}
	}

	if ($opt_recursive) {
		unshift(@todo_dirs, @subdirs);
	}
}

sub checkdir_package($) {
	my ($dir) = @_;

	my ($whole, $lines, $loglines, $have_distinfo, $have_patches);

	$pkgdir			= ".";
	$filesdir		= "files";
	$patchdir		= "patches";
	$distinfo_file		= "distinfo";
	$scriptdir		= "scripts";
	$seen_USE_PKGLOCALEDIR	= false;
	$seen_Makefile_common	= false;
	$pkgname		= undef;

	# we need to handle the Makefile first to get some variables
	if (!load_package_Makefile($dir, "${dir}/Makefile", \$whole, \$lines, \$loglines)) {
		log_error("${dir}/Makefile", NO_LINE_NUMBER, "Cannot be read.");
		return;
	}

	my @files = <${dir}/*>;
	if ($pkgdir ne ".") {
		push(@files, <${dir}/${pkgdir}/*>);
	}
	push(@files, <${dir}/${filesdir}/*>);
	push(@files, <${dir}/${patchdir}/*>);
	if ($distinfo_file !~ qr"^(?:\./)?distinfo$") {
		push(@files, "${dir}/${distinfo_file}");
	}
	$have_distinfo = false;
	$have_patches = false;
	foreach my $f (@files) {
		if      ($f =~ qr"(?:work[^/]*|~|\.orig|\.rej)$") {
			if ($opt_warn_workdir) {
				log_warning($f, NO_LINE_NUMBER, "Should be cleaned up before committing the package.");
			}

		} elsif (!-f $f) {
			# We don't have a check for non-regular files yet.

		} elsif ($f eq "${dir}/Makefile") {
			$opt_check_Makefile and checkfile_package_Makefile($dir, $f, $whole, $lines, $loglines);

		} elsif ($f =~ qr"/buildlink3.mk$") {
			$opt_check_bl3 and checkfile_buildlink3_mk($dir, $f);

		} elsif ($f =~ qr"/DESCR[^/]*$") {
			$opt_check_DESCR and checkfile_DESCR($dir, $f);

		} elsif ($f =~ qr"/distinfo$") {
			$have_distinfo = true;
			$opt_check_distinfo and checkfile_distinfo($dir, $f);

		} elsif ($f =~ qr"/MESSAGE[^/]*$") {
			$opt_check_MESSAGE and checkfile_MESSAGE($dir, $f);

		} elsif ($f =~ qr"/PLIST[^/]*$") {
			$opt_check_PLIST and checkfile_PLIST($dir, $f);

		} elsif ($f =~ qr"/patches/patch-[A-Za-z0-9]*$") {
			$have_patches = true;
			$opt_check_patches and checkfile_patches_patch($dir, $f);

		} elsif ($f =~ qr"/patches/[^/]*$") {
			log_warning($f, NO_LINE_NUMBER, "Patch files should be named \"patch-\", followed by letters and digits only.");

		} elsif (-T $f) {
			$opt_check_extra and checkfile_extra($dir, $f);

		} else {
			log_warning($f, NO_LINE_NUMBER, "Unexpectedly found a binary file.");
		}
	}

	if ($opt_check_distinfo && $opt_check_patches) {
		if ($have_patches && ! $have_distinfo) {
			log_warning("$dir/$distinfo_file", NO_LINE_NUMBER, "File not found. Please run '$conf_make makepatchsum'.");
		}
	}

	if (grep { $_ !~ qr"/CVS$" } <$dir/scripts/*>) {
		log_warning("$dir/scripts", NO_LINE_NUMBER, "This directory and its contents are deprecated! Please call the script(s) explicitly from the corresponding target(s) in the pkg's Makefile.");
	}
}

sub checkdir($) {
	my ($dir) = @_;

	if (-f "${dir}/../../mk/bsd.pkg.mk") {
		load_predefined_sites("${dir}/../..");
		checkdir_package($dir);

	} elsif (-f "${dir}/../mk/bsd.pkg.mk") {
		log_info(NO_FILE, NO_LINE_NUMBER, "Checking category Makefile.");
		checkdir_category($dir);

	} elsif (-f "${dir}/mk/bsd.pkg.mk") {
		checkdir_root($dir);

	} else {
		log_error($dir, NO_LINE_NUMBER, "Not a pkgsrc directory.");
	}
}

#
# The main program
#

sub main() {
	my ($startsec, $startusec, $endsec, $endusec);

	parse_command_line();

	@todo_dirs = (@ARGV != 0) ? @ARGV : (".");
	while (@todo_dirs != 0) {
		checkdir(shift(@todo_dirs));
	}

	print_summary_and_exit($opt_quiet);
}

main();
