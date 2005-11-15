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
# $NetBSD: pkglint.pl,v 1.360 2005/11/15 13:37:55 rillig Exp $
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
		log_fatal log_error log_warning log_note log_info log_subinfo
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

sub log_message($$$$$$) {
	my ($out, $file, $subr, $lineno, $type, $message) = @_;
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

	print $out ("${text}\n");
}

sub log_fatal($$$) {
	my ($file, $lineno, $msg) = @_;
	log_message(*STDERR, $file, undef, $lineno, $gcc_output_format ? "fatal" : "FATAL", $msg);
	exit(1);
}

sub log_error($$$) {
	my ($file, $lineno, $msg) = @_;
	log_message(*STDOUT, $file, undef, $lineno, $gcc_output_format ? "error" : "ERROR", $msg);
	$errors++;
}
sub log_warning($$$) {
	my ($file, $lineno, $msg) = @_;
	log_message(*STDOUT, $file, undef, $lineno, $gcc_output_format ? "warning" : "WARN", $msg);
	$warnings++;
}
sub log_note($$$) {
	my ($file, $lineno, $msg) = @_;
	log_message(*STDOUT, $file, undef, $lineno, $gcc_output_format ? "note" : "NOTE", $msg);
}
sub log_info($$$) {
	my ($file, $lineno, $msg) = @_;
	if ($verbose_flag) {
		log_message(*STDOUT, $file, undef, $lineno, $gcc_output_format ? "info" : "OK", $msg);
	}
}
sub log_subinfo($$$$) {
	my ($subr, $file, $lineno, $msg) = @_;
	if ($verbose_flag) {
		log_message(*STDOUT, $file, $subr, $lineno, $gcc_output_format ? "info" : "OK", $msg);
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
BEGIN {
	import PkgLint::Util qw(
		false true
	);
}

use constant FILE	=> 0;
use constant LINES	=> 1;
use constant TEXT	=> 2;
use constant PHYSLINES	=> 3;
use constant CHANGED	=> 4;
use constant BEFORE	=> 5;
use constant AFTER	=> 6;
	
sub new($$$$) {
	my ($class, $file, $lines, $text, $physlines) = @_;
	my ($self) = ([$file, $lines, $text, $physlines, false, [], []]);
	bless($self, $class);
	return $self;
}
sub file($) {
	return shift(@_)->[FILE];
}
sub lineno($) {
	return shift(@_)->[LINES];
}
sub text($) {
	return shift(@_)->[TEXT];
}
sub physlines($) {
	my ($self) = @_;
	return [@{$self->[BEFORE]}, @{$self->[PHYSLINES]}, @{$self->[AFTER]}];
}
sub is_changed($) {
	return shift(@_)->[CHANGED];
}

sub log_fatal($$) {
	my ($self, $text) = @_;
	PkgLint::Logging::log_fatal($self->[FILE], $self->[LINES], $text);
}
sub log_error($$) {
	my ($self, $text) = @_;
	PkgLint::Logging::log_error($self->[FILE], $self->[LINES], $text);
}
sub log_warning($$) {
	my ($self, $text) = @_;
	PkgLint::Logging::log_warning($self->[FILE], $self->[LINES], $text);
}
sub log_note($$) {
	my ($self, $text) = @_;
	PkgLint::Logging::log_note($self->[FILE], $self->[LINES], $text);
}
sub log_info($$) {
	my ($self, $text) = @_;
	PkgLint::Logging::log_info($self->[FILE], $self->[LINES], $text);
}
sub to_string($) {
	my ($self) = @_;
	return sprintf("%s:%s: %s", $self->[FILE], $self->[LINES], $self->[TEXT]);
}

sub prepend_before($$) {
	my ($self, $text) = @_;
	unshift(@{$self->[BEFORE]}, [0, "$text\n"]);
	$self->[CHANGED] = true;
}
sub append_before($$) {
	my ($self, $text) = @_;
	push(@{$self->[BEFORE]}, [0, "$text\n"]);
	$self->[CHANGED] = true;
}
sub prepend_after($$) {
	my ($self, $text) = @_;
	unshift(@{$self->[AFTER]}, [0, "$text\n"]);
	$self->[CHANGED] = true;
}
sub append_after($$) {
	my ($self, $text) = @_;
	push(@{$self->[AFTER]}, [0, "$text\n"]);
	$self->[CHANGED] = true;
}
sub delete($) {
	my ($self) = @_;
	$self->[PHYSLINES] = [];
	$self->[CHANGED] = true;
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
	@EXPORT_OK = qw(
		load_file load_lines
		save_autofix_changes
	);

	import PkgLint::Util qw(
		false true
	);
	import PkgLint::Logging qw(
		NO_LINE_NUMBER
		log_error log_note
	);
}

sub load_physical_lines($) {
	my ($fname) = @_;
	my ($physlines, $line, $lineno);

	$physlines = [];
	open(F, "< $fname") or return undef;
	$lineno = 0;
	while (defined($line = <F>)) {
		$lineno++;
		push(@{$physlines}, [$lineno, $line]);
	}
	close(F) or return undef;
	return $physlines;
}

sub get_logical_line($$$) {
	my ($fname, $lines, $ref_lineno) = @_;
	my ($value, $lineno, $first, $firstlineno, $lastlineno);

	$value = "";
	$first = true;
	$lineno = ${$ref_lineno};
	$firstlineno = $lines->[$lineno]->[0];

	for (; $lineno <= $#{$lines}; $lineno++) {
		if ($lines->[$lineno]->[1] =~ qr"^([ \t]*)(.*?)([ \t]*)(\\?)\n?$") {
			my ($indent, $text, $outdent, $cont) = ($1, $2, $3, $4);

			if ($first) {
				$value .= $indent;
				$first = false;
			}

			$value .= $text;

			if ($cont eq "\\") {
				$value .= " ";
			} else {
				$value .= $outdent;
				last;
			}
		}
	}

	if ($lineno > $#{@{$lines}}) {
		# The last line in the file is a continuation line
		$lineno--;
	}
	$lastlineno = $lines->[$lineno]->[0];
	${$ref_lineno} = $lineno + 1;

	return PkgLint::FileUtil::Line->new($fname,
	    $firstlineno == $lastlineno
		? $firstlineno
		: "$firstlineno--$lastlineno",
	    $value);
}

sub load_lines($$) {
	my ($fname, $fold_backslash_lines) = @_;
	my ($physlines, $seen_newline, $loglines) = @_;

	$physlines = load_physical_lines($fname);
	if (!$physlines) {
		return false;
	}

	$seen_newline = true;
	$loglines = [];
	if ($fold_backslash_lines) {
		for (my $lineno = 0; $lineno <= $#{$physlines}; ) {
			push(@{$loglines}, get_logical_line($fname, $physlines, \$lineno));
		}
	} else {
		foreach my $physline (@{$physlines}) {
			my $text = $physline->[1];

			$text =~ s/\n$//;
			push(@{$loglines}, PkgLint::FileUtil::Line->new($fname, $physline->[0], $text, [$physline]));
		}
	}

	if (0 <= $#{$physlines} && $physlines->[-1]->[1] !~ qr"\n$") {
		log_error($fname, $physlines->[-1]->[0], "File must end with a newline.");
	}

	return $loglines;
}

sub load_file($) {
	my ($fname) = @_;

	return load_lines($fname, false);
}

sub save_autofix_changes($) {
	my ($lines) = @_;

	my (%changed, %physlines);

	foreach my $line (@{$lines}) {
		if ($line->is_changed) {
			$changed{$line->file}++;
		}
		push(@{$physlines{$line->file}}, @{$line->physlines});
	}

	foreach my $fname (sort(keys(%changed))) {
		my $old = "${fname}.pkglint.old";
		my $new = "${fname}.pkglint.new";

		if (!open(F, ">", $new)) {
			log_error($new, NO_LINE_NUMBER, "$!");
			next;
		}
		foreach my $physline (@{$physlines{$fname}}) {
			print F ($physline->[1]);
		}
		if (!close(F)) {
			log_error($new, NO_LINE_NUMBER, "$!");
			next;
		}

		unlink($old); # without error checking
		if (!link($fname, $old)) {
			log_error($fname, NO_LINE_NUMBER, "$!");
			next;
		}
		if (!rename($new, $fname)) {
			log_error($fname, NO_LINE_NUMBER, "$!");
			next;
		}
		log_note($fname, NO_LINE_NUMBER, "Has been autofixed.");
	}
}

#== End of PkgLint::FileUtil ==============================================

package main;
use strict;
use warnings;

use Getopt::Long qw(:config no_ignore_case bundling require_order);
use Fcntl qw(:mode);
use File::Basename;
use File::stat;
use Cwd;

BEGIN {
	import PkgLint::Util qw(
		false true
	);
	import PkgLint::Logging qw(
		NO_FILE NO_LINE_NUMBER
		log_fatal log_error log_warning log_info log_subinfo
		print_summary_and_exit
	);
	import PkgLint::FileUtil qw(
		load_file load_lines
		save_autofix_changes
	);
}

# Buildtime configuration
use constant conf_rcsidstring	=> 'NetBSD';
use constant conf_distver	=> '@DISTVER@';
use constant conf_make		=> '@MAKE@';
use constant conf_datadir	=> '@DATADIR@';

# Command Line Options

my $opt_check_ALTERNATIVES = true;
my $opt_check_bl3	= true;
my $opt_check_DESCR	= true;
my $opt_check_distinfo	= true;
my $opt_check_extra	= false;
my $opt_check_INSTALL	= true;
my $opt_check_Makefile	= true;
my $opt_check_MESSAGE	= true;
my $opt_check_mk	= true;
my $opt_check_patches	= true;
my $opt_check_PLIST	= true;
my (%checks) = (
	"ALTERNATIVES"	=> [\$opt_check_ALTERNATIVES, "check ALTERNATIVES files"],
	"bl3"		=> [\$opt_check_bl3, "check buildlink3 files"],
	"DESCR"		=> [\$opt_check_DESCR, "check DESCR file"],
	"distinfo"	=> [\$opt_check_distinfo, "check distinfo file"],
	"extra"		=> [\$opt_check_extra, "check various additional files"],
	"INSTALL"	=> [\$opt_check_INSTALL, "check INSTALL and DEINSTALL scripts"],
	"Makefile"	=> [\$opt_check_Makefile, "check Makefiles"],
	"MESSAGE"	=> [\$opt_check_MESSAGE, "check MESSAGE files"],
	"mk"		=> [\$opt_check_mk, "check other .mk files"],
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
my (%warnings) = (
	"absname"	=> [\$opt_warn_absname, "warn about use of absolute file names"],
	"directcmd"	=> [\$opt_warn_directcmd, "warn about use of direct command names instead of Make variables"],
	"exec"		=> [\$opt_warn_exec, "warn if source files are executable"],
	"order"		=> [\$opt_warn_order, "warn if Makefile entries are unordered"],
	"paren"		=> [\$opt_warn_paren, "warn about use of \$(VAR) instead of \${VAR} in Makefiles"],
	"plist-sort"	=> [\$opt_warn_plist_sort, "warn about unsorted entries in PLISTs"],
	"types"		=> [\$opt_warn_types, "do some simple type checking in Makefiles"],
	"vague"		=> [\$opt_warn_vague, "show old (unreliable, vague) warnings"],
);

my $opt_autofix		= false;
my $opt_dumpmakefile	= false;
my $opt_import		= false;
my $opt_quiet		= false;
my $opt_recursive	= false;
my $opt_rcsidstring	= conf_rcsidstring;
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
		printf("%s\n", conf_distver);
		exit(0);
	  } ],
	[ "-W{warn,...}", "enable or disable specific warnings",
	  "warning|W=s",
	  sub {
		my ($opt, $val) = @_;
		parse_multioption($val, \%warnings);
	  } ],
	[ "-g|--gcc-output-format", "Mimic the gcc output format",
	  "gcc-output-format|g",
	  sub {
		PkgLint::Logging::set_gcc_output_format();
	  } ],
	[ "-h|--help", "print a detailed help message",
	  "help|h",
	  sub {
		help(*STDOUT, 0, 1);
	  } ],
	[ "-i|--import", "Prepare the import of a wip package",
	  "import|i", \$opt_import ],
	[ "-q|--quiet", "Don't print a summary line when finishing",
	  "quiet|q", \$opt_quiet ],
	[ "-r|--recursive", "Recursive---check subdirectories, too",
	  "recursive|r", \$opt_recursive ],
	[ "-v|--verbose", "print progress messages",
	  "verbose|v",
	  sub {
		PkgLint::Logging::set_verbose(true);
	  } ]
);

use constant regex_pkgname	=> qr"^((?:[\w.+]|-[^\d])+)-(\d(?:\w|\.\d)*)$";
use constant regex_shellcmd	=> qr"^\t(.*)$";
use constant regex_unresolved	=> qr"\$\{";
use constant regex_validchars	=> qr"[\011\040-\176]";
use constant regex_varassign	=> qr"^([-A-Z_a-z0-9.\${}\[]+)\s*(=|\?=|\+=|:=|!=)\s*((?:\\#|[^#])*?)(?:\s*(#.*))?$";

# Global variables

my $current_dir;		# The currently checked directory.
my $is_wip;			# Is the current directory from pkgsrc-wip?

my $pkgsrcdir;			# The pkgsrc root directory
my $pkgdir;			# PKGDIR from the package Makefile
my $filesdir;			# FILESDIR from the package Makefile
my $patchdir;			# PATCHDIR from the package Makefile
my $distinfo_file;		# DISTINFO_FILE from the package Makefile
my $pkgname;			# PKGNAME from the package Makefile
my $hack_php_patches;		# Ignore non-existing patches in distinfo

my $seen_USE_PKGLOCALEDIR;	# Does the package use PKGLOCALEDIR?
my $seen_Makefile_common;	# Does the package have any .includes?

my @todo_items;			# The list of directory entries that still need
				# to be checked. Mostly relevant with
				# --recursive.

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
				printf STDERR ("Invalid option: ${opt}\n");
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

sub load_make_vars_typemap() {
	my ($vartypes);
	my ($fname);

	$vartypes = {};

	$fname = conf_datadir."/makevars.map";
	if ((my $lines = load_file($fname))) {
		foreach my $line (@{$lines}) {
			if ($line->text =~ qr"^(?:#.*|\s*)$") {
				# ignore empty and comment lines

			} elsif ($line->text =~ qr"^([\w\d_.]+)\s+([-.+\w\d_* \{\}]+)$") {
				$vartypes->{$1} = $2;

			} else {
				$line->log_fatal("Unknown line format.");
			}
		}
	} else {
		log_fatal($fname, NO_LINE_NUMBER, "Cannot be read.");
	}

# TODO: Enable when the time is ripe.
if (false) {
	# Additionally, scan mk/defaults/mk.conf for variable
	# definitions. All these variables are reserved for the user and
	# must not be set within packages.
	$fname = "${pkgsrcdir}/mk/defaults/mk.conf";
	if ((my $lines = load_file($fname))) {
		foreach my $line (@{$lines}) {
			if ($line->text =~ qr"^#?([\w_]+)\?=") {
				my ($varname) = ($1);
				$line->log_info("Found user-definable variable ${varname}.");
				$vartypes->{$varname} = "Userdefined";
			}
		}
	} else {
		log_fatal($fname, NO_LINE_NUMBER, "Cannot be read.");
	}
}

	return $vartypes;
}

my $load_dist_sites_url2name = undef;
my $load_dist_sites_names = undef;
sub load_dist_sites() {
	my ($fname) = ("${pkgsrcdir}/mk/bsd.sites.mk");
	my ($lines) = load_file($fname);
	my ($varname) = undef;
	my ($ignoring) = false;
	my ($url2name) = {};
	my ($names) = {};

	if (!$lines) {
		log_error($fname, NO_LINE_NUMBER, "Could not be read.");
		$load_dist_sites_url2name = $url2name;
		$load_dist_sites_names = $names;
		return;
	}
	foreach my $line (@{$lines}) {
		my $text = $line->text;

		if ($text =~ qr"^(MASTER_SITE_\w+)\+=\s*\\$"o) {
			$varname = $1;
			$names->{$varname} = true;
			$ignoring = false;

		} elsif ($text eq "MASTER_SITE_BACKUP?=\t\\") {
			$ignoring = true;

		} elsif ($text =~ qr"^\t((?:http://|ftp://)\S+/)(?:|\s*\\)$"o) {
			if (!$ignoring) {
				if (defined($varname)) {
					$url2name->{$1} = $varname;
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

	# Explicitly allowed, although not defined in mk/bsd.sites.mk.
	$names->{"MASTER_SITE_SUSE_UPD"} = true;
	$names->{"MASTER_SITE_LOCAL"} = true;

	log_info($fname, NO_LINE_NUMBER, sprintf("Loaded %d MASTER_SITE_* definitions.", scalar(keys(%{$url2name}))));
	$load_dist_sites_url2name = $url2name;
	$load_dist_sites_names = $names;
}

sub get_dist_sites() {
	if (!defined($load_dist_sites_url2name)) {
		load_dist_sites();
	}
	return $load_dist_sites_url2name;
}

sub get_dist_sites_names() {
	if (!defined($load_dist_sites_names)) {
		load_dist_sites();
	}
	return $load_dist_sites_names;
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
	if ($rest =~ regex_varassign) {
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
	my ($id) = ($opt_rcsidstring . ($is_wip ? "|Id" : ""));

	if ($line->text !~ qr"^${prefix_regex}\$(${id})(?::[^\$]*|)\$$") {
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

sub checkfile_DESCR($) {
	my ($fname) = @_;
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
		checkline_valid_characters($line, regex_validchars);
	}
	checklines_trailing_empty_lines($descr);

	if (@{$descr} > $maxlines) {
		log_warning($fname, NO_LINE_NUMBER, "File too long (should be no more than $maxlines lines).");
	}
}

sub checkfile_distinfo($) {
	my ($fname) = @_;
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
			if (-f "${current_dir}/${patchdir}/${file}") {
				open(DIG, "sed '/\\\$NetBSD.*/d' ${current_dir}/${patchdir}/${file} | digest ${alg} |") or die;
				my $chksum = <DIG>;
				close(DIG);
				chomp($chksum);
				if ($sum ne $chksum) {
					$line->log_error("${alg} checksum of $file differs (expected ${sum}, got ${chksum}). Rerun '".conf_make." makepatchsum'.");
				}
			} elsif (!$hack_php_patches) {
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

	foreach my $patch (<${current_dir}/$patchdir/patch-*>) {
		$patch = basename($patch);
		if (!exists($in_distinfo{$patch})) {
			log_error($fname, NO_LINE_NUMBER, "$patch is not recorded. Rerun '".conf_make." makepatchsum'.");
		}
	}
}

sub checkfile_MESSAGE($) {
	my ($fname) = @_;
	my ($message);

	log_subinfo("checkfile_MESSAGE", $fname, NO_LINE_NUMBER, undef);

	checkperms($fname);
	if (!($message = load_file($fname))) {
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
		checkline_valid_characters($line, regex_validchars);
	}
	if ($message->[-1]->text ne "=" x 75) {
		$message->[-1]->log_warning("Expected a line of exactly 75 \"=\" characters.");
	}
	checklines_trailing_empty_lines($message);
}

sub checkfile_PLIST($) {
	my ($fname) = @_;
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

			if ($cmd eq "unexec" && $arg =~ /^rmdir/) {
				$line->log_warning("Use \"\@dirrm\" instead of \"\@unexec rmdir\".");

			} elsif (($cmd eq "exec" || $cmd eq "unexec")) {
				if ($arg =~ /(?:install-info|\$\{INSTALL_INFO\})/) {
					$line->log_warning("\@exec/unexec install-info is deprecated.");

				} elsif ($arg =~ /ldconfig/ && $arg !~ qr"/usr/bin/true") {
					$line->log_error("ldconfig must be used with \"||/usr/bin/true\".");
				}

			} elsif ($cmd eq "comment" || $cmd eq "dirrm") {
				# nothing to do

			} else {
				$line->log_warning("Unknown PLIST directive \"\@$cmd\".");
			}

		} elsif ($text =~ qr"^[A-Za-z0-9\$]") {
			if ($opt_warn_plist_sort && $text =~ qr"^\w" && $text !~ regex_unresolved) {
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
				$line->log_error("Configuration files must not be registered in the PLIST. Please use the CONF_FILES framework, which is described in mk/install/bsd.pkginstall.mk.");

			} elsif ($text eq "info/dir") {
				$line->log_error("\"info/dir\" must not be listed. Use install-info to add/remove an entry.");

			} elsif ($text =~ qr"^lib/locale/") {
				$line->log_error("\"lib/locale\" must not be listed. Use \${PKGLOCALEDIR}/locale and set USE_PKGLOCALEDIR instead.");

			} elsif ($text =~ qr"^share/locale/") {
				$line->log_warning("Use of \"share/locale\" is deprecated.  Use \${PKGLOCALEDIR}/locale and set USE_PKGLOCALEDIR instead.");

			} elsif ($text =~ qr"^share/man/") {
				$line->log_warning("Man pages should be installed into man/, not share/man/.");
			}

			if ($text =~ /\${PKGLOCALEDIR}/ && defined($seen_USE_PKGLOCALEDIR) && !$seen_USE_PKGLOCALEDIR) {
				$line->log_warning("PLIST contains \${PKGLOCALEDIR}, but USE_PKGLOCALEDIR was not found.");
			}

			if ($text =~ qr"/CVS/") {
				$line->log_warning("CVS files should not be in the PLIST.");
			}

		} else {
			$line->log_error("Unknown line type.");
		}
	}
	checklines_trailing_empty_lines($plist);
}

sub checkfile_extra($) {
	my ($fname) = @_;
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

sub checkfile_patches_patch($) {
	my ($fname) = @_;
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

sub readmakefile($$$$);
sub readmakefile($$$$) {
	my ($file, $main_lines, $all_lines, $seen_Makefile_include) = @_;
	my $contents = "";
	my ($includefile, $dirname, $lines, $is_main_Makefile);

	$lines = load_lines($file, true);
	if (!$lines) {
		return false;
	}

	$is_main_Makefile = (@{$main_lines} == 0);

	foreach my $line (@{$lines}) {
		my $text = $line->text;

		if ($is_main_Makefile) {
			push(@{$main_lines}, $line);
		}
		push(@{$all_lines}, $line);

		# try to get any included file
		my $is_include_line = false;
		if ($text =~ qr"^\.\s*include\s+\"(.*)\"$") {
			$includefile = $1;
			$includefile =~ s/\$\{.CURDIR\}/./;
			if ($includefile =~ regex_unresolved) {
				$includefile =~ s,\$\{PHPPKGSRCDIR\},../../lang/php5,g;
				$includefile =~ s,\$\{SUSE_DIR_PREFIX\},suse91,g;
				$includefile =~ s,\$\{PYPKGSRCDIR\},../../lang/python23,g;
				if ($file !~ qr"/mk/" && $includefile =~ regex_unresolved) {
					$line->log_warning("Skipping include file \"${includefile}\". This may result in false warnings.");
				}

			} elsif (exists($seen_Makefile_include->{$includefile})) {
				# Don't include any file twice

			} else {
				$is_include_line = true;
				$seen_Makefile_include->{$includefile} = true;
			}
		}

		if ($is_include_line) {
			if ($includefile =~ qr"^\.\./[^./][^/]*/[^/]+") {
				$line->log_warning("Relative directories should look like \"../../category/package\", not \"../package\".");
			}
			if ($includefile =~ qr"(?:^|/)Makefile.common$"
			    || ($includefile =~ qr"^(?:\.\./(?:\.\./[^/]+/)?[^/]+/)?([^/]+)$" && $1 ne "buildlink3.mk")) {
				$seen_Makefile_common = true;
			}
			if ($includefile =~ qr"/mk/") {
				# skip these files
				$contents .= $text . "\n";
			} else {
				$dirname = dirname($file);
				# Only look in the directory relative to the
				# current file and in the current working directory.
				# We don't have an include dir list, like make(1) does.
				if (!-f "$dirname/$includefile") {
					$dirname = $current_dir;
				}
				if (!-f "$dirname/$includefile") {
					$line->log_error("Cannot read $dirname/$includefile.");
				} else {
					$line->log_info("Including \"$dirname/$includefile\".");
					$contents .= readmakefile("$dirname/$includefile", $main_lines, $all_lines, $seen_Makefile_include);
				}
			}
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
		.*LIST
		.*_AWK
		.*_ENV
		.*_REQD
		.*_SED
		.*_SKIP
		BUILDLINK_LDADD
		BUILDLINK_RECOMMENDED
		COMMENT
		EXTRACT_ONLY
		GENERATE_PLIST
		PLIST_CAT
		PLIST_PRE
		PREPEND_PATH
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
		EVAL_PREFIX
		INTERACTIVE_STAGE
		LICENSE
		MASTER_SITE_.*
		MASTER_SORT_REGEX
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
		PYTHON_VERSIONS_INCOMPATIBLE
		REPLACE_INTERPRETER
		REPLACE_PERL
		REPLACE_RUBY
		RESTRICTED
		SITES_.*
		TOOLS_ALIASES\.*
		TOOLS_BROKEN
		TOOLS_CREATE
		TOOLS_GNU_MISSING
		TOOLS_NOOP
	);
	my $plurals = join("|",
		@plurals_ok,
		@plurals_missing_an_s,
		@plurals_reluctantly_accepted
	);

	$get_regex_plurals_value = qr"^(?:${plurals})$";
	return $get_regex_plurals_value;
}

my $get_tool_names_value = undef;
sub get_tool_names() {
	
	if (defined($get_tool_names_value)) {
		return $get_tool_names_value;
	}

	my $tools = {};
	foreach my $file (qw(autoconf automake defaults ldconfig make replace rpcgen texinfo)) {
		my $fname = "${pkgsrcdir}/mk/tools/${file}.mk";
		my $lines = load_lines($fname, true);

		if (!$lines) {
			log_fatal($fname, NO_LINE_NUMBER, "Cannot be read.");
			next;
		}

		foreach my $line (@{$lines}) {
			if ($line->text =~ regex_varassign) {
				my ($varname, undef, $value, undef) = ($1, $2, $3, $4);
				if ($varname eq "TOOLS_CREATE" && $value =~ qr"^([-\w.]+)$") {
					$tools->{$value} = true;

				} elsif ($varname =~ qr"^(?:TOOLS_PATH|_TOOLS_DEPMETHOD|_TOOLS_VARNAME)\.([-\w.]+|\[)$") {
					$tools->{$1} = true;

				} elsif ($varname eq "_TOOLS.x11-clients") {
					foreach my $tool (split(qr"\s+", $value)) {
						$tools->{$tool} = true;
					}
				}
			}
		}
	}
	log_info(NO_FILE, NO_LINE_NUMBER, "Known tools: ".join(" ", sort(keys(%{$tools}))));

	$get_tool_names_value = $tools;
	return $get_tool_names_value;
}

sub checktext_basic_vartype($$$$$) {
	my ($line, $varname, $type, $value, $comment) = @_;
	my ($value_novar);

	$value_novar = $value;
	while ($value_novar =~ s/\$\{[^{}]*\}//g) {
	}
	
	if ($type eq "Category") {
		my $allowed_categories = join("|", qw(
			archivers audio
			benchmarks biology
			cad chat chinese comms converters cross crosspkgtools
			databases devel
			editors emulators
			finance fonts
			games geography gnome gnustep graphics
			ham
			inputmethod
			japanese java
			kde korean
			lang linux
			mail math mbone meta-pkgs misc multimedia
			net news
			packages parallel perl5 pkgtools plan9 print python
			ruby
			security shells sysutils
			tcl textproc time tk
			windowmaker wm www
			x11 xmms
		));
		if ($value !~ qr"^(?:${allowed_categories})$") {
			$line->log_error("Invalid category \"${value}\".");
		}

	} elsif ($type eq "Comment") {
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

	} elsif ($type eq "Dependency") {
		if ($value =~ regex_unresolved) {
			# don't even try to check anything
		} elsif ($value =~ qr":\.\./\.\./([^/]+)/([^/]+)$") {
			my ($cat, $pkg) = ($1, $2);
			
			if (!$is_wip && $cat eq "wip") {
				$line->log_error("A pkgsrc package must not depend on any outside package.");
			}

			if (!-d "${pkgsrcdir}/${cat}/${pkg}") {
				$line->log_error("The package ${cat}/${pkg} does not exist.");
			}

			if ($pkg eq "msgfmt" || $pkg eq "gettext") {
				$line->log_warning("Please use BUILD_USES_MSGFMT=yes instead of this dependency.");

			} elsif ($pkg =~ qr"^perl\d+") {
				$line->log_warning("Please use USE_TOOLS+=perl:run instead of this dependency.");

			} elsif ($pkg eq "gmake") {
				$line->log_warning("Please use USE_TOOLS+=gmake instead of this dependency.");

			} elsif ($pkg =~ qr"^([-a-zA-Z0-9]+)-dirs[-><=]+(.*)$") {
				my ($dirs, $version) = ($1, $2);

				$line->log_warning("Please use USE_DIRS+=${dirs}-${version} instead of this dependency.");
			}

		} elsif ($value =~ qr":\.\./[^/]+$") {
			$line->log_warning("Dependencies should have the form \"../../category/package\".");

		} else {
			$line->log_warning("Unknown dependency format.");
		}

	} elsif ($type eq "DistSuffix") {
		if ($value eq ".tar.gz") {
			$line->log_note("\"${varname} is \".tar.gz\" by default, so this definition may be redundant.");
		}

	} elsif ($type eq "Filename") {
		if ($value_novar !~ qr"^[-0-9A-Za-z._~+%]*$") {
			$line->log_warning("\"${value}\" is not a valid filename.");
		}

	} elsif ($type eq "Filemask") {
		if ($value_novar !~ qr"^[-0-9A-Za-z._~+%*?]*$") {
			$line->log_warning("\"${value}\" is not a valid filename mask.");
		}

	} elsif ($type eq "Mail_Address") {
		if ($value =~ qr"^([-\w\d_.]+)\@([-\w\d.]+)$") {
			my (undef, $domain) = ($1, $2);
			if ($domain =~ qr"^NetBSD.org"i && $domain ne "NetBSD.org") {
				$line->log_warning("Please write NetBSD.org instead of ${domain}.");
			}

		} else {
			$line->log_warning("\"${value}\" is not a valid mail address.");
		}

	} elsif ($type eq "Option") {
		if ($value_novar !~ qr"^-?[a-z][-0-9a-z]*$") {
			$line->log_warning("\"${value}\" is not a valid option name.");
		}

	} elsif ($type eq "Pathname") {
		if ($value_novar !~ qr"^[-0-9A-Za-z._~+%/]*$") {
			$line->log_warning("\"${value}\" is not a valid pathname.");
		}

	} elsif ($type eq "Pathmask") {
		if ($value_novar !~ qr"^[-0-9A-Za-z._~+%*?/]*$") {
			$line->log_warning("\"${value}\" is not a valid pathname mask.");
		}

	} elsif ($type eq "PkgName") {
		if ($value eq $value_novar && $value !~ regex_pkgname) {
			$line->log_warning("\"${value}\" is not a valid package name.");
		}

	} elsif ($type eq "PkgRevision") {
		if ($value !~ qr"^\d+$") {
			$line->log_warning("\"${value}\" is not a valid Integer.");
		}
		if ($line->file !~ qr"(?:^|/)Makefile$") {
			$line->log_error("${varname} must not be set outside the package Makefile.");
		}

	} elsif ($type eq "Readonly") {
		$line->log_error("\"${varname}\" is a read-only variable and therefore must not be modified.");

	} elsif ($type eq "Stage") {
		if ($value !~ qr"^(?:pre|do|post)-(?:extract|patch|configure|build|install)$") {
			$line->log_warning("Invalid stage name. Use one of {pre,do,post}-{extract,patch,configure,build,install}.");
		}

	} elsif ($type eq "Tool") {
		if ($value =~ qr"^([-\w]+|\[)(?::(\w+))?$") {
			my ($toolname, $tooldep) = ($1, $2);
			if (!exists(get_tool_names()->{$toolname})) {
				$line->log_error("Unknown tool \"${toolname}\".");
			}
			if (defined($tooldep) && $tooldep !~ qr"^(?:build|pkgsrc|run)$") {
				$line->log_error("Unknown tool dependency \"${tooldep}\".");
			}
		} else {
			$line->log_error("Invalid tool syntax: \"${value}\".");
		}

	} elsif ($type eq "URL") {
		if ($value =~ qr"\$\{(MASTER_SITE_.*):=(.*)\}$") {
			my ($name, $subdir) = ($1, $2);

			if (!exists(get_dist_sites_names()->{$name})) {
				$line->log_error("${name} does not exist.");
			}
			if ($subdir !~ qr"/$") {
				$line->log_error("The subdirectory in ${name} must end with a slash.");
			}

		} elsif ($value =~ regex_unresolved) {
			# No further checks
			
		} elsif ($value =~ qr"^(?:http://|ftp://)[-0-9A-Za-z.]+(?::\d+)?/~?([-%&+,./0-9:=?\@A-Z_a-z]|\\#)*?$") {
			my $sites = get_dist_sites();

			foreach my $site (keys(%{$sites})) {
				if (index($value, $site) == 0) {
					my $subdir = substr($value, length($site));
					$line->log_warning(sprintf("Please use \${%s:=%s} instead of \"%s\".", $sites->{$site}, $subdir, $value));
					last;
				}
			}

		} elsif ($value eq "" && defined($comment) && $comment =~ qr"^#") {
			# Ok

		} else {
			$line->log_warning("\"${value}\" is not a valid URL.");
		}

	} elsif ($type eq "Userdefined") {
		$line->log_error("\"${varname}\" may only be set by the user, not the package.");

	} elsif ($type eq "Varname") {
		if ($value ne "" && $value_novar eq "") {
			# The value of another variable

		} elsif ($value_novar !~ qr"^[A-Z_][0-9A-Z_]*(?:[.].*)?$") {
			$line->log_warning("\"${value}\" is not a valid variable name.");
		}

	} elsif ($type eq "WrkdirSubdirectory") {
		# TODO: check for ${WRKDIR}/${DISTNAME}/foo

	} elsif ($type eq "WrksrcSubdirectory") {
		if ($value =~ qr"^(\$\{WRKSRC\}(?:/|$))") {
			my ($prefix) = ($1);
			# TODO: uncomment after 2005Q4
			#$line->log_note("The \"${prefix}\" prefix is not needed here.");

		} elsif ($value ne "" && $value_novar eq "") {
			# The value of another variable

		} elsif ($value_novar !~ qr"^(?:\.|[0-9A-Za-z][-0-9A-Za-z._/+]*)$") {
			$line->log_warning("\"${value}\" is not a valid subdirectory of \${WRKSRC}.");
		}

	} elsif ($type eq "Yes") {
		if ($value !~ qr"^(?:YES|yes)(?:\s+#.*)?$") {
			$line->log_warning("${varname} should be set to YES or yes.");
		}

	} elsif ($type eq "YesNo") {
		if ($value !~ qr"^(?:YES|yes|NO|no)(?:\s+#.*)?$") {
			$line->log_warning("${varname} should be set to YES, yes, NO, or no.");
		}

	} elsif ($type =~ qr"^\{\s*(.*?)\s*\}$") {
		my ($values) = ($1);
		my @enum = split(qr"\s+", $values);
		my $found = false;

		foreach my $v (@enum) {
			if ($v eq $value) {
				$found = true;
			}
		}
		if (!$found) {
			$line->log_warning("\"${value}\" is not valid for ${varname}. Use one of ${type} instead.");
		}

	} else {
		$line->log_fatal("Type ${type} unknown.");
	}
}

sub checkline_Makefile_vartype($$) {
	my ($line, $vartypes) = @_;
	if ($line->text =~ regex_varassign) {
		my ($varname, $op, $value, $comment) = ($1, $2, $3, $4);
		my $varbase = ($varname =~ qr"(.+?)\..*") ? $1 : $varname;
		my $type = exists($vartypes->{$varname}) ? $vartypes->{$varname}
			: exists($vartypes->{$varbase}) ? $vartypes->{$varbase}
			: undef;

		if ($op eq "+=") {
			my $regex_plurals = get_regex_plurals();

			if ($varbase !~ $regex_plurals) {
				$line->log_warning("As ${varname} is modified using \"+=\", its name should indicate plural.");
			}
		}

		if (!defined($type)) {
			$line->log_info("[checkline_Makefile_vartype] Unchecked variable ${varname}.");

		} elsif ($type =~ qr"^List(\*?)(?: of (.*))?$") {
			my ($append_only, $element_type) = ($1 eq "", $2);
			my (@values) = split(qr"\s+", $value); # XXX: This may be too simple

			if ($append_only && $op ne "+=" && !($value eq "" && defined($comment) && $comment =~ qr"^#")) {
				$line->log_warning("${varname} should be modified using \"+=\".");
			}

			if (defined($element_type)) {
				foreach my $v (@values) {
					checktext_basic_vartype($line, $varname, $element_type, $v, $comment);
				}
			}

		} else {
			checktext_basic_vartype($line, $varname, $type, $value, $comment);
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
			$line->log_warning("\$$varname is ambiguous. Use \${$varname} if you mean a Makefile variable or \$\$$varname if you mean a shell variable.");
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
	my ($fname) = (conf_datadir."/deprecated.map");
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
			$line->log_fatal("Unknown line format.");
		}
	}

	foreach my $line (@{$lines}) {
		if ($line->text =~ regex_varassign) {
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
		awk
		basename
		cat chgrp chmod chown cmp cp cut
		digest dirname
		echo egrep
		false file find
		gmake grep gtar gzcat
		id ident install
		ldconfig ln
		md5 mkdir mtree mv
		patch pax pkg_add pkg_create pkg_delete pkg_info
		rm rmdir sed setenv sh sort su
		tail test touch tr true type
		wc
		xmkmf
	);
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
		qr"\./${regex_tools}\b",
		qr"(?:\./Build|\$\{(?:BJAM_CMD|JAM_COMMAND)\})\s+(?:install|test)",
		qr"\$\{(?:GMAKE|MAKE_PROGRAM)\}\s+(?:install)",
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
		} elsif ($text =~ regex_varassign) {
			my ($varname, undef, $varvalue) = ($1, $2, $3);

			if ($varname =~ $regex_ok_vars) {
				$line->log_info("Legitimate direct use of tool \"${tool}\" in variable ${varname}.");
			} elsif ($varvalue =~ $regex_tools_with_context) {
				$line->log_warning("Possible direct use of tool \"${tool}\" in variable ${varname}. Please use \$\{$toolvar{$tool}\} instead.");
			} else {
				# the tool name has appeared in the comment
			}

		# process shell commands
		} elsif ($text =~ regex_shellcmd) {
			my ($shellcmd) = ($1);
			my ($short_shellcmd, $remaining_shellcmd) = ($shellcmd, $shellcmd);

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
				$line->log_warning("Possible direct use of tool \"${tool}\" in shell command \"${short_shellcmd}\". Please use \$\{$toolvar{$tool}\} instead.");
			} else {
				$line->log_info("Legitimate direct use of tool \"${tool}\" in shell command \"${short_shellcmd}\".");
			}

		# skip processing directives
		} elsif ($text =~ qr"^\.") {

		# skip dependency specifications
		} elsif ($text =~ qr"^([-\w.]+):") {

		} else {
			$line->log_error("[internal:checklines_direct_tools] unknown line format.");
		}
	}
}

sub checklines_package_Makefile_varorder($) {
	my ($lines) = @_;

# TODO: Add support for optional sections with non-optional variables.

	use constant once	=> 0;
	use constant optional	=> 1;
	use constant many	=> 2;
	my (@sections) = (
		[ "initial comments", once,
			[
			]
		],
		[ "DISTNAME", once,
			[
				[ "DISTNAME", once ],
				[ "PKGNAME",  optional ],
				[ "PKGREVISION", optional ],
				[ "SVR4_PKGNAME", optional ],
				[ "CATEGORIES", once ],
				[ "MASTER_SITES", once ],
				[ "DYNAMIC_MASTER_SITES", optional ],
				[ "MASTER_SITE_SUBDIR", optional ],
				[ "EXTRACT_SUFX", optional ],
				[ "DISTFILES", optional ],
# The following are questionable.
#				[ "NOT_FOR_PLATFORM", optional ],
#				[ "ONLY_FOR_PLATFORM", optional ],
#				[ "NO_BIN_ON_FTP", optional ],
#				[ "NO_SRC_ON_FTP", optional ],
#				[ "NO_BIN_ON_CDROM", optional ],
#				[ "NO_SRC_ON_CDROM", optional ],
			]
		],
		[ "PATCH_SITES", optional,
			[
				[ "PATCH_SITES", optional ], # or once?
				[ "PATCH_SITE_SUBDIR", optional ],
				[ "PATCHFILES", optional ], # or once?
				[ "PATCH_DIST_ARGS", optional ],
				[ "PATCH_DIST_STRIP", optional ],
				[ "PATCH_DIST_CAT", optional ],
			]
		],
		[ "MAINTAINER", once,
			[
				[ "MAINTAINER", once ],
				[ "HOMEPAGE", optional ],
				[ "COMMENT", once ],
			]
		],
		[ "DEPENDS", optional,
			[
				[ "BUILD_DEPENDS", many ],
				[ "DEPENDS", many ],
			]
		]
	);

	if (!defined($seen_Makefile_common) || $seen_Makefile_common) {
		return;
	}

	my ($lineno, $sectindex, $varindex) = (0, -1, 0);
	my ($next_section, $vars, $below, $below_what) = (true, undef, {}, undef);

	# In each iteration, one of the following becomes true:
	# - new.lineno > old.lineno
	# - new.sectindex > old.sectindex
	# - new.sectindex == old.sectindex && new.varindex > old.varindex
	# - new.next_section == true && old.next_section == false
	while ($lineno <= $#{$lines}) {
		my $line = $lines->[$lineno];
		my $text = $line->text;

		if ($next_section) {
			$next_section = false;
			$sectindex++;
			last if ($sectindex > $#sections);
			$vars = $sections[$sectindex]->[2];
			$varindex = 0;
		}

		if ($text =~ qr"^#") {
			$lineno++;

		} elsif ($text =~ regex_varassign) {
			my ($varname, $op, $value, $comment) = ($1, $2, $3, $4);

			if (exists($below->{$varname})) {
				if (defined($below->{$varname})) {
					$line->log_warning("${varname} appears too late. Please put it below $below->{$varname}.");
				} else {
					$line->log_warning("${varname} appears too late. It should be the very first definition.");
				}
				$lineno++;
				next;
			}

			while ($varindex <= $#{$vars} && $varname ne $vars->[$varindex]->[0] && $vars->[$varindex]->[1] != once) {
				$below->{$vars->[$varindex]->[0]} = $below_what;
				$varindex++;
			}
			if ($varindex > $#{$vars}) {
				if ($sections[$sectindex]->[1] != optional) {
					$line->log_warning("Empty line expected.");
				}
				$next_section = true;

			} elsif ($varname ne $vars->[$varindex]->[0]) {
				$line->log_warning(sprintf("Expected %s, but found %s.", $vars->[$varindex]->[0], $varname));
				$lineno++;

			} else {
				if ($vars->[$varindex]->[1] != many) {
					$below->{$vars->[$varindex]->[0]} = $below_what;
					$varindex++;
				}
				$lineno++;
			}
			$below_what = $varname;

		} else {
			while ($varindex <= $#{$vars}) {
				if ($vars->[$varindex]->[1] == once) {
					$line->log_warning(sprintf("%s should be set here.", $vars->[$varindex]->[0]));
				}
				$below->{$vars->[$varindex]->[0]} = $below_what;
				$varindex++;
			}
			$next_section = true;
			if ($text eq "") {
				$below_what = "the previous empty line";
				$lineno++;
			}
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

		if ($line->lineno eq "1") {
			checkline_rcsid_regex($line, qr"#\s+", "# ");
		}

		checkline_trailing_whitespace($line);

		if ($text =~ /^\040{8}/) {
			$line->log_warning("Use tab (not spaces) to make indentation.");
		}

		if ($text =~ qr"\$\{WRKSRC\}/\.\./") {
			$line->log_error("Using \"\${WRKSRC}/..\" is conceptually wrong. Use a combination of WRKSRC, CONFIGURE_DIRS and BUILD_DIRS instead.");
		}

		if ($text =~ regex_varassign) {
			my ($varname, $op, $value, $comment) = ($1, $2, $3, $4);

			if ($varname =~ qr"^_") {
				# TODO: enable this when lang/perl5 has been fixed.
				#$line->log_error("Variable names starting with an underscore are reserved for internal pkgsrc use.");
			}

			if ($varname eq "PERL5_PACKLIST" && defined($pkgname) && $pkgname =~ qr"^p5-(.*)-[0-9].*") {
				my ($guess) = ($1);
				$guess =~ s/-/\//g;
				$guess = "auto/${guess}/.packlist";

				my ($ucvalue, $ucguess) = (uc($value), uc($guess));
				if ($ucvalue ne $ucguess && $ucvalue ne "\${PERL5_SITEARCH\}/${ucguess}") {
					$line->log_warning("Unusual value for PERL5_PACKLIST -- \"${guess}\" expected.");
				}
			}

			if ($varname eq "SVR4_PKGNAME") {
				if ($value =~ regex_unresolved) {
					$line->log_error("SVR4_PKGNAME must not contain references to other variables.");
				} elsif (length($value) > 5) {
					$line->log_error("SVR4_PKGNAME must not be longer than 5 characters.");
				}
			}

			if (defined($comment) && $comment eq "# defined" && $varname !~ qr".*(?:_MK|_COMMON)$") {
				$line->log_warning("Please use \"# empty\", \"# none\" or \"yes\" instead of \"# defined\".");
			}

			if ($varname =~ qr"^NO_(.*)_ON_(.*)$") {
				my ($what, $where) = ($1, $2);
				if (($what ne "SRC" && $what ne "BIN") || ($where ne "FTP" && $where ne "CDROM")) {
					$line->log_error("Misspelled variable: Valid names are USE_{BIN,SRC}_ON_{FTP,CDROM}.");
				}
			}

			if ($value =~ qr"\$\{(PKGNAME|PKGVERSION)[:\}]") {
				my ($pkgvarname) = ($1);
				if ($varname =~ qr"^PKG_.*_REASON$") {
					# ok
				} elsif ($varname =~ qr"^(?:DIST_SUBDIR|WRKSRC)$") {
					$line->log_warning("${pkgvarname} should not be used in ${varname}, as it sometimes includes the PKGREVISION. Please use ${pkgvarname}_NOREV instead.");
				} else {
					$line->log_info("Use of PKGNAME in ${varname}.");
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
	if ($value =~ regex_unresolved) {
		log_subinfo("expand_variable", NO_FILE, NO_LINE_NUMBER, "The variable ${varname} could not be resolved completely. Its value is \"${value}\".");
	}
	return $value;
}

sub set_default_value($$) {
	my ($varref, $value) = @_;

	if (!defined(${$varref}) || ${$varref} =~ regex_unresolved) {
		${$varref} = $value;
	}
}

sub load_package_Makefile($$$$) {
	my ($subr) = "load_package_Makefile";
	my ($fname, $ref_whole, $ref_main_lines, $ref_all_lines) = @_;
	my ($whole, $main_lines, $all_lines);

	log_info($fname, NO_LINE_NUMBER, "Checking package Makefile.");

	$whole = readmakefile($fname, $main_lines = [], $all_lines = [], {});
	if (!$whole) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return false;
	}

	if ($opt_dumpmakefile) {
		print("OK: whole Makefile (with all included files) follows:\n");
		foreach my $line (@{$all_lines}) {
			printf("%s\n", $line->to_string());
		}
	}

	# HACK
	if ($whole =~ qr"\nPHPEXT_MK" && $whole !~ qr"\nUSE_PHP_EXT_PATCHES") {
		log_info($fname, NO_LINE_NUMBER, "[hack] USE_PHP_EXT_PATCHES");
		$whole =~ s,\nPATCHDIR=.*PHPPKGSRCDIR.*,,;
		$hack_php_patches = true;
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

	log_subinfo($subr, NO_FILE, NO_LINE_NUMBER, "DISTINFO_FILE=$distinfo_file");
	log_subinfo($subr, NO_FILE, NO_LINE_NUMBER, "FILESDIR=$filesdir");
	log_subinfo($subr, NO_FILE, NO_LINE_NUMBER, "PATCHDIR=$patchdir");
	log_subinfo($subr, NO_FILE, NO_LINE_NUMBER, "PKGDIR=$pkgdir");

	${$ref_whole} = $whole;
	${$ref_main_lines} = $main_lines;
	${$ref_all_lines} = $all_lines;
	return true;
}

sub checkfile_ALTERNATIVES($) {
	my ($fname) = @_;
	my ($lines);

	log_subinfo("checkfile_ALTERNATIVES", $fname, NO_LINE_NUMBER, undef);

	checkperms($fname);
	if (!($lines = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}
}

sub checkfile_INSTALL($) {
	my ($fname) = @_;
	my ($lines);

	log_subinfo("checkfile_INSTALL", $fname, NO_LINE_NUMBER, undef);

	checkperms($fname);
	if (!($lines = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}
}

sub checkfile_mk($) {
	my ($fname) = @_;
	my ($lines);

	log_subinfo("checkfile_mk", $fname, NO_LINE_NUMBER, undef);

	checkperms($fname);
	if (!($lines = load_lines($fname, true))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}

	checklines_deprecated_variables($lines);
	checklines_direct_tools($lines);
	checklines_package_Makefile($lines);
	checklines_Makefile_varuse($lines);
}

sub checkfile_package_Makefile($$$$) {
	my ($fname, $rawwhole, $main_lines, $lines) = @_;
	my ($distname, $category, $distfiles,
	    $extract_sufx, $wrksrc);
	my ($whole, $tmp, $idx, @sections);
	
	log_subinfo("checkfile_package_Makefile", $fname, NO_LINE_NUMBER, undef);

	checkperms($fname);

	$category = basename(dirname(Cwd::abs_path($current_dir)));
	$whole = "\n${rawwhole}";

	#
	# whole file: $(VARIABLE)
	#
	if ($opt_warn_paren) {
		if ($whole =~ /[^\$]\$\([\w\d]+\)/) {
			$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "Use \${VARIABLE} instead of \$(VARIABLE).");
		}
	}

	checklines_deprecated_variables($main_lines);

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
	    && !-f "${current_dir}/$pkgdir/PLIST"
	    && !-f "${current_dir}/$pkgdir/PLIST.common") {
		$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "No PLIST or PLIST.common, and PLIST_SRC and NO_PKG_REGISTER unset. Are you sure PLIST handling is ok?");
	}

	if ($whole =~ qr"\nNO_CHECKSUM") {
		if (-f "${current_dir}/${distinfo_file}") {
			log_warning("${current_dir}/${distinfo_file}", NO_LINE_NUMBER, "This file should not exist if NO_CHECKSUM is set.");
		}
	} else {
		if (!-f "${current_dir}/${distinfo_file}") {
			log_warning("${current_dir}/${distinfo_file}", NO_LINE_NUMBER, "File not found. Please run '".conf_make." makesum'.");
		}
	}

	$seen_USE_PKGLOCALEDIR = ($whole =~ /\nUSE_PKGLOCALEDIR/) ? true : false;

	if ($whole =~ m|\${MKDIR}.*(\${PREFIX}[/0-9a-zA-Z\${}]*)|) {
		$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "\${MKDIR} $1: consider using INSTALL_*_DIR.");
	}
	if ($whole =~ m|\${INSTALL}(.*)\n|) {
		my $args = $1;
		if ($args =~ /-d/) {
			if ($args !~ /-[ogm]/) {
				$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "\${INSTALL}$args: " .
					"consider using INSTALL_*_DIR.");
			}
		}
	}
	if ($whole =~ /\n\t-(.*(MKDIR|INSTALL.*-d|INSTALL_.*_DIR).*)/g) {
		$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "$1: no need to use '-' before command.");
	}

	checklines_direct_tools($main_lines);

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

	# check the URL
	if ($tmp =~ /\nMASTER_SITES[+?]?=[ \t]*([^\n]*)\n/
	 && $1 !~ /^[ \t]*$/) {
		if ($tmp =~ /\nDYNAMIC_MASTER_SITES[+?]?=/) {
			$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "MASTER_SITES and DYNAMIC_MASTER_SITES ".
				"found. Is this ok?");
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
	if ($opt_warn_vague && defined($pkgname) && $pkgname !~ regex_unresolved && $pkgname !~ regex_pkgname) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "PKGNAME should have the form packagename-version, where version consists only of digits, letters and dots.");
	}

	if ($opt_warn_vague && !defined($pkgname) && defined($distname) && $distname !~ regex_unresolved && $distname !~ regex_pkgname) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "As DISTNAME ist not a valid package name, please define the PKGNAME explicitly.");
	}

	if (!defined($pkgname)) {
		$pkgname = $distname;
	}

	#
	# section 3: PATCH_SITES/PATCHFILES(optional)
	#
	log_info($fname, NO_LINE_NUMBER, "Checking optional PATCH section.");
	$tmp = $sections[$idx];

	if ($tmp =~ /(PATCH_SITES|PATCH_SITE_SUBDIR|PATCHFILES|PATCH_DIST_STRIP|PATCH_DIST_CAT)/) {
		$idx++;
	}

	#
	# section 4: MAINTAINER
	#
	log_info($fname, NO_LINE_NUMBER, "Checking MAINTAINER section.");
	$tmp = $sections[$idx++];

	# warnings for missing or incorrect HOMEPAGE
	$tmp = "\n" . $tmp;
	if ($tmp !~ /\nHOMEPAGE[+?]?=[ \t]*([^\n]*)\n/ || $1 =~ /^[ \t]*$/) {
		$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "Please add HOMEPAGE if the package has one.");
	}

	# warnings for missing COMMENT
	if ($tmp !~ /\nCOMMENT=\s*(.*)$/) {
		$opt_warn_vague && log_error(NO_FILE, NO_LINE_NUMBER, "Please add a short COMMENT describing the package.");
	}

	$tmp = "\n" . $tmp;
	if ($tmp =~ /\nMAINTAINER=[^@]+\@netbsd.org/) {
		$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "\@netbsd.org should be \@NetBSD.org in MAINTAINER.");

	} elsif ($tmp =~ /\nMAINTAINER=[^\n]+/) {
		$tmp =~ s/\nMAINTAINER=[^\n]+//;

	} else {
		$opt_warn_vague && log_error($fname, NO_LINE_NUMBER, "No MAINTAINER found.");
	}
	$tmp =~ s/\n\n+/\n/g;

	#
	# section 5: *_DEPENDS (may not be there)
	#
	log_info($fname, NO_LINE_NUMBER, "Checking optional DEPENDS section.");
	$tmp = $sections[$idx];

	if ($tmp =~ qr"(?:BUILD_USED_MSGFMT|BUILD_DEPENDS|DEPENDS)") {
		$idx++;
	}

	#
	# Makefile 6: check the rest of file
	#
	log_info($fname, NO_LINE_NUMBER, "Checking the rest of the file.");
	$tmp = join("\n\n", @sections[$idx .. $#{sections}]);

	$tmp = "\n" . $tmp;	# to make the begin-of-line check easier

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

	checklines_package_Makefile($main_lines);
	# Disabled, as I don't like the current ordering scheme.
	#checklines_package_Makefile_varorder($lines);
	checklines_Makefile_varuse($main_lines);
}

sub checkfile($) {
	my ($fname) = @_;
	my ($st, $basename);

	log_subinfo("checkfile", $fname, NO_LINE_NUMBER, undef);

	$basename = basename($fname);
	if ($basename =~ qr"^(?:work.*|.*~|.*\.orig|.*\.rej)$") {
		if ($opt_import) {
			log_error($fname, NO_LINE_NUMBER, "Must be cleaned up before committing the package.");
		}
		return;
	}

	if (!($st = lstat($fname))) {
		log_error($fname, NO_LINE_NUMBER, "$!");
		return;
	}
	if (S_ISDIR($st->mode)) {
		if ($basename eq "files" || $basename eq "patches" || $basename eq "CVS") {
			# Ok

		} else {
			log_warning($fname, NO_LINE_NUMBER, "Unknown directory name.");
		}

	} elsif (!S_ISREG($st->mode)) {
		log_error($fname, NO_LINE_NUMBER, "Only files and directories are allowed in pkgsrc.");

	} elsif ($basename eq "ALTERNATIVES") {
		$opt_check_ALTERNATIVES and checkfile_ALTERNATIVES($fname);

	} elsif ($basename eq "buildlink3.mk") {
		$opt_check_bl3 and checkfile_mk($fname);

	} elsif ($basename =~ qr"^(?:.*\.mk|Makefile.*)$") {
		$opt_check_mk and checkfile_mk($fname);

	} elsif ($basename =~ qr"^DESCR") {
		$opt_check_DESCR and checkfile_DESCR($fname);

	} elsif ($basename =~ qr"^distinfo") {
		$opt_check_distinfo and checkfile_distinfo($fname);

	} elsif ($basename eq "DEINSTALL" || $basename eq "INSTALL") {
		$opt_check_INSTALL and checkfile_INSTALL($fname);

	} elsif ($basename =~ qr"^MESSAGE") {
		$opt_check_MESSAGE and checkfile_MESSAGE($fname);

	} elsif ($basename =~ qr"^patch-[A-Za-z0-9]*$") {
		$opt_check_patches and checkfile_patches_patch($fname);

	} elsif ($fname =~ qr"(?:^|/)patches/[^/]*$") {
		log_warning($fname, NO_LINE_NUMBER, "Patch files should be named \"patch-\", followed by letters and digits only.");

	} elsif ($basename =~ qr"^PLIST") {
		$opt_check_PLIST and checkfile_PLIST($fname);

	} elsif ($basename eq "TODO") {
		# Ok

	} elsif (!-T $fname) {
		log_warning($fname, NO_LINE_NUMBER, "Unexpectedly found a binary file.");

	} else {
		log_warning($fname, NO_LINE_NUMBER, "Unexpected file found.");
		$opt_check_extra and checkfile_extra($fname);
	}
}

sub checkdir_root() {
	my ($fname) = "${current_dir}/Makefile";
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

			if ($subdir =~ qr"\$" || !-f "${current_dir}/${subdir}/Makefile") {
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
				push(@subdirs, "${current_dir}/${subdir}");
			}
		}
	}

	if ($opt_recursive) {
		push(@todo_items, @subdirs);
	}
}

sub checkdir_category() {
	my $fname = "${current_dir}/Makefile";
	my ($lines, $lineno);

	if (!($lines = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return;
	}

	$lineno = 0;

	# The first line must contain the RCS Id
	if ($lineno <= $#{$lines} && checkline_rcsid_regex($lines->[$lineno], qr"#\s+", "# ")) {
		$lineno++;
	}

	# Then, arbitrary comments may follow
	while ($lineno <= $#{$lines} && $lines->[$lineno]->text =~ qr"^#") {
		$lineno++;
	}

	# Then we need an empty line
	if ($lineno <= $#{$lines} && $lines->[$lineno]->text eq "") {
		$lineno++;
	} else {
		$lines->[$lineno]->log_error("Empty line expected.");
	}

	# Then comes the COMMENT line
	if ($lineno <= $#{$lines} && $lines->[$lineno]->text =~ qr"^COMMENT=\t*(.*)") {
		my ($comment) = ($1);

		checkline_valid_characters_in_variable($lines->[$lineno], qr"[-\040'(),/0-9A-Za-z]");
		$lineno++;
	} else {
		$lines->[$lineno]->log_error("COMMENT= line expected.");
	}

	# Then we need an empty line
	if ($lineno <= $#{$lines} && $lines->[$lineno]->text eq "") {
		$lineno++;
	} else {
		$lines->[$lineno]->log_error("Empty line expected.");
	}

	# And now to the most complicated part of the category Makefiles,
	# the (hopefully) sorted list of SUBDIRs. The first step is to
	# collect the SUBDIRs in the Makefile and in the file system.

	my (@f_subdirs, @m_subdirs);

	@f_subdirs = sort(get_subdirs($current_dir));

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
				$line->append_before("SUBDIR+=\t${f_current}");
			}
			$f_neednext = true;

		} elsif (!$m_atend && ($f_atend || $m_current lt $f_current)) {
			if (!exists($f_check{$m_current})) {
				$line->log_error("${m_current} exists in the Makefile, but not in the file system.");
				$line->delete();
			}
			$m_neednext = true;

		} else { # $f_current eq $m_current
			$f_neednext = true;
			$m_neednext = true;
			if ($m_recurse) {
				push(@subdirs, "${current_dir}/${m_current}");
			}
		}
	}

	# the wip category Makefile may have its own targets for generating
	# indexes and READMEs. Just skip them.
	if ($is_wip) {
		while ($lineno <= $#{$lines} - 2) {
			$lineno++;
		}
	}

	# Then we need an empty line
	if ($lineno <= $#{$lines} && $lines->[$lineno]->text eq "") {
		$lineno++;
	} else {
		$lines->[$lineno]->log_error("Empty line expected.");
	}

	# And, last but not least, the .include line
	my $final_line = ".include \"../mk/bsd.pkg.subdir.mk\"";
	if ($lineno <= $#{$lines} && $lines->[$lineno]->text eq $final_line) {
		$lineno++;
	} else {
		$lines->[$lineno]->log_error("Expected this: ${final_line}.");
	}

	if ($lineno <= $#{$lines}) {
		$lines->[$lineno]->log_error("The file should end here.");
	}

	# If the user has requested automatic fixing and we can do it, we do it.
	if ($opt_autofix) {
		save_autofix_changes($lines);
	}

	if ($opt_recursive) {
		unshift(@todo_items, @subdirs);
	}
}

sub checkdir_package() {
	my ($whole, $main_lines, $lines, $have_distinfo, $have_patches);

	# we need to handle the Makefile first to get some variables
	if (!load_package_Makefile("${current_dir}/Makefile", \$whole, \$main_lines, $lines)) {
		log_error("${current_dir}/Makefile", NO_LINE_NUMBER, "Cannot be read.");
		return;
	}

	my @files = <${current_dir}/*>;
	if ($pkgdir ne ".") {
		push(@files, <${current_dir}/${pkgdir}/*>);
	}
	if ($opt_check_extra) {
		push(@files, <${current_dir}/${filesdir}/*>);
	}
	push(@files, <${current_dir}/${patchdir}/*>);
	if ($distinfo_file !~ qr"^(?:\./)?distinfo$") {
		push(@files, "${current_dir}/${distinfo_file}");
	}
	$have_distinfo = false;
	$have_patches = false;
	foreach my $fname (@files) {
		if ($fname eq "${current_dir}/Makefile") {
			$opt_check_Makefile and checkfile_package_Makefile($fname, $whole, $main_lines, $lines);
		} else {
			checkfile($fname);
		}
		if ($fname =~ qr"/patches/patch-[A-Za-z0-9]*$") {
			$have_patches = true;
		} elsif ($fname =~ qr"/distinfo$") {
			$have_distinfo = true;
		}
	}

	if ($opt_check_distinfo && $opt_check_patches) {
		if ($have_patches && ! $have_distinfo) {
			log_warning("${current_dir}/$distinfo_file", NO_LINE_NUMBER, "File not found. Please run '".conf_make." makepatchsum'.");
		}
	}

	if (!is_emptydir("${current_dir}/scripts")) {
		log_warning("${current_dir}/scripts", NO_LINE_NUMBER, "This directory and its contents are deprecated! Please call the script(s) explicitly from the corresponding target(s) in the pkg's Makefile.");
	}
}

sub checkitem($) {
	my ($item) = @_;
	my ($st, $is_dir, $is_reg);

	if (!($st = lstat($item))) {
		log_error($item, NO_LINE_NUMBER, "Does not exist.");
		return;
	}

	$is_dir = S_ISDIR($st->mode);
	$is_reg = S_ISREG($st->mode);
	if (!$is_reg && !$is_dir) {
		log_error($item, NO_LINE_NUMBER, "Must be a file or directory.");
		return;
	}

	# Initialize global variables.
	$pkgdir			= ".";
	$filesdir		= "files";
	$patchdir		= "patches";
	$distinfo_file		= "distinfo";
	$seen_USE_PKGLOCALEDIR	= undef;
	$seen_Makefile_common	= undef;
	$pkgname		= undef;
	$hack_php_patches	= false;

	$current_dir = $is_dir ? $item : dirname($item);
	$is_wip = !$opt_import && (Cwd::abs_path($current_dir) =~ qr"/wip(?:/|$)");

	if (-f "${current_dir}/../../mk/bsd.pkg.mk") {
		$pkgsrcdir = "${current_dir}/../..";
		if ($is_dir) {
			checkdir_package();
		}

	} elsif (-f "${current_dir}/../mk/bsd.pkg.mk") {
		$pkgsrcdir = "${current_dir}/..";
		if ($is_dir) {
			checkdir_category();
		}

	} elsif (-f "${current_dir}/mk/bsd.pkg.mk") {
		$pkgsrcdir = $current_dir;
		if ($is_dir) {
			checkdir_root();
		}
	} else {
		log_error($item, NO_LINE_NUMBER, sprintf("Don't know how to check this %s.", ($is_dir) ? "directory" : "file"));
		return;
	}

	if ($is_reg) {
		checkfile($item);
	}
}

#
# The main program
#

sub main() {

	parse_command_line();

	@todo_items = (@ARGV != 0) ? @ARGV : (".");
	while (@todo_items != 0) {
		checkitem(shift(@todo_items));
	}

	print_summary_and_exit($opt_quiet);
}

main();
