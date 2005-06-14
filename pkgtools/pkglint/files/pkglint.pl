#!@PERL@ -w
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
# $NetBSD: pkglint.pl,v 1.193 2005/06/14 03:52:01 rillig Exp $
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

sub print_table($$)
{
	my ($out, $table) = @_;
	my (@width) = ();
	foreach my $row (@$table) {
		foreach my $i (0..(scalar(@$row)-1)) {
			if (!defined($width[$i]) || length($row->[$i]) > $width[$i]) {
				$width[$i] = length($row->[$i]);
			}
		}
	}
	foreach my $row (@$table) {
		my ($max) = (scalar(@$row) - 1);
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
	return 1;
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
		log_error log_warning log_info
		print_summary_and_exit set_verbose is_verbose
	);
	import PkgLint::Util qw(false true);
}

use constant NO_FILE		=> "";
use constant NO_LINE_NUMBER	=> 0;

my $errors		= 0;
my $warnings		= 0;
my $verbose_flag	= false;

sub log_message($$$$)
{
	my ($file, $lineno, $type, $message) = @_;
	if ($file ne NO_FILE) {
		# strip "." path components
		$file =~ s,^(?:\./)+,,;
		$file =~ s,/(?:\./)+,/,g;
	}
	if ($file eq NO_FILE) {
		printf("%s: %s\n", $type, $message);
	} elsif ($lineno == NO_LINE_NUMBER) {
		printf("%s: %s: %s\n", $type, $file, $message);
	} else {
		printf("%s: %s:%d: %s\n", $type, $file, $lineno, $message);
	}
}

sub log_error($$$)
{
	my ($file, $lineno, $msg) = @_;
	log_message($file, $lineno, "FATAL", $msg);
	$errors++;
}

sub log_warning($$$)
{
	my ($file, $lineno, $msg) = @_;
	log_message($file, $lineno, "WARN", $msg);
	$warnings++;
}

sub log_info($$$)
{
	my ($file, $lineno, $msg) = @_;
	if ($verbose_flag) {
		log_message($file, $lineno, "OK", $msg);
	}
}

sub print_summary_and_exit($)
{
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

sub set_verbose($)
{
	my ($verbose) = @_;
	$verbose_flag = $verbose;
}

sub is_verbose()
{
	return $verbose_flag;
}
#== End of PkgLint::Logging ===============================================

package PkgLint::FileUtil;
#==========================================================================
# This package provides some file handling subroutines. The subroutine
# load_file reads a file into memory as an array of lines. A line is a
# record that contains the fields C<file>, C<lineno> and C<text>.
#==========================================================================

package PkgLint::FileUtil::Line;
	sub new($$$$) {
		my ($class, $file, $lineno, $text) = @_;
		my ($self) = ({});
		bless($self, $class);
		$self->_init($file, $lineno, $text);
		return $self;
	}
	sub _init($$$$) {
		my ($self, $file, $lineno, $text) = @_;
		$self->{"file"} = $file;
		$self->{"lineno"} = $lineno;
		$self->{"text"} = $text;
	}
	sub file($) {
		return shift(@_)->{"file"};
	}
	sub lineno($) {
		return shift(@_)->{"lineno"};
	}
	sub text($) {
		return shift(@_)->{"text"};
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
		return sprintf("%s:%d: %s", $self->file, $self->lineno, $self->text);
	}
# end of PkgLint::FileUtil::Line

package PkgLint::FileUtil;
BEGIN {
	use Exporter;
	use vars qw(@ISA @EXPORT_OK);
	@ISA = qw(Exporter);
	@EXPORT_OK = qw(load_file);

	import PkgLint::Util qw(false true);
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
		push(@$result, PkgLint::FileUtil::Line->new($fname, $lineno, $line));
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
	import PkgLint::Util qw(false true);
	import PkgLint::Logging qw(
		NO_FILE NO_LINE_NUMBER
		log_error log_warning log_info
		print_summary_and_exit
	);
	import PkgLint::FileUtil qw(
		load_file
	);
}

# Buildtime configuration
my $conf_rcsidstr	= 'NetBSD';
my $conf_pkgsrcdir	= '@PKGSRCDIR@';
my $conf_localbase	= '@PREFIX@';
my $conf_distver	= '@DISTVER@';
my $conf_make		= '@MAKE@';
my $conf_datadir	= '@DATADIR@';

# Command Line Options
my $opt_dumpmakefile	= false;
my $opt_contblank	= 1;
my $opt_quiet		= false;
my (%options) = (
	"-p"		=> "warn about use of \$(VAR) instead of \${VAR}",
	"-q"		=> "don't print a summary line when finishing",
	"-I"		=> "dump the Makefile after parsing",
	"-B#"		=> "allow # contiguous blank lines in Makefiles",
	"-C{check,...}"	=> "enable or disable specific checks",
	"-W{warn,...}"	=> "enable or disable specific warnings",
	"-h|--help"	=> "print a detailed help message",
	"-V|--version"	=> "print the version number of pkglint",
	"-v|--verbose"	=> "print progress messages on STDERR",
);

my $opt_check_distinfo	= true;
my $opt_check_extra	= true;
my $opt_check_bl3	= true;
my $opt_check_MESSAGE	= true;
my $opt_check_patches	= true;
my $opt_check_PLIST	= true;
my (%checks) = (
	"distinfo"	=> [\$opt_check_distinfo, "check distinfo file"],
	"bl3"		=> [\$opt_check_bl3, "check buildlink3 files"],
	"extra"		=> [\$opt_check_extra, "check various additional files"],
	"MESSAGE"	=> [\$opt_check_MESSAGE, "check MESSAGE files"],
	"patches"	=> [\$opt_check_patches, "check patches"],
	"PLIST"		=> [\$opt_check_PLIST, "check PLIST files"],
);

my $opt_warn_absname	= true;
my $opt_warn_directcmd	= true;
my $opt_warn_exec	= true;
my $opt_warn_order	= true;
my $opt_warn_paren	= true;
my $opt_warn_sort	= true;
my $opt_warn_types	= true;
my $opt_warn_vague	= true;
my $opt_warn_workdir	= true;
my (%warnings) = (
	"absname"	=> [\$opt_warn_absname, "warn about use of absolute file names"],
	"directcmd"	=> [\$opt_warn_directcmd, "warn about use of direct command names instead of Make variables"],
	"exec"		=> [\$opt_warn_exec, "warn if source files are executable"],
	"order"		=> [\$opt_warn_order, "warn if Makefile entries are unordered"],
	"paren"		=> [\$opt_warn_paren, "warn about use of \$(VAR) instead of \${VAR} in Makefiles"],
	"sort"		=> [\$opt_warn_sort, "warn about any unsorted entries in category Makefiles and PLISTs"],
	"types"		=> [\$opt_warn_types, "do some simple type checking in Makefiles"],
	"vague"		=> [\$opt_warn_vague, "show old (unreliable, vague) warnings"],
	"workdir"	=> [\$opt_warn_workdir, "warn that work* should not be committed into CVS"],
);

# Constants
my $regex_rcsidstr	= qr"\$($conf_rcsidstr)(?::[^\$]*|)\$";
my $regex_known_rcs_tag	= qr"\$(Author|Date|Header|Id|Locker|Log|Name|RCSfile|Revision|Source|State|$conf_rcsidstr)(?::[^\$]*?|)\$";
my $regex_validchars	= qr"[\011\040-\176]";
my $regex_boolean	= qr"^(?:YES|yes|NO|no)$";
my $regex_yes_or_undef	= qr"^(?:YES|yes)$";
my $regex_mail_address	= qr"^[-\w\d_.]+\@[-\w\d.]+$";
my $regex_url		= qr"^(?:http://|ftp://|#)"; # allow empty URLs
my $regex_url_directory	= qr"(?:http://|ftp://)\S+/";

# Global variables
my $opt_packagedir;
my $pkgsrc_rootdir;
my $pkgdir;
my $filesdir;
my $patchdir;
my $distinfo_file;
my $scriptdir;
my $seen_PLIST_SRC;
my $seen_NO_PKG_REGISTER;
my $seen_NO_CHECKSUM;
my $seen_USE_PKGLOCALEDIR;
my %seen_Makefile_include;
my $seen_Makefile_common;
my %predefined_sites;
my $pkgname;
my %make_vars_typemap;

# these subroutines return C<true> if the checking succeeded (that includes
# errors in the file) and C<false> if the file could not be checked.
sub checkfile_DESCR($);
sub checkfile_distinfo($);
sub checkfile_Makefile($);
sub checkfile_MESSAGE($);
sub checkfile_patches_patch($);
sub checkfile_PLIST($);
sub checkfile_other($);
sub check_category($);

sub checkperms($);
sub readmakefile($$);
sub checkextra($$);
sub checkorder($$@);
sub checkearlier($@);
sub check_predefined_sites($);
sub check_package();

sub init_global_vars() {
	$pkgsrc_rootdir		= undef;
	$pkgdir			= ".";
	$filesdir		= "files";
	$patchdir		= "patches";
	$distinfo_file		= "distinfo";
	$scriptdir		= "scripts";
	$seen_PLIST_SRC		= false;
	$seen_NO_PKG_REGISTER	= false;
	$seen_NO_CHECKSUM	= false;
	$seen_USE_PKGLOCALEDIR	= false;
	%seen_Makefile_include	= ();
	$seen_Makefile_common	= false;
	%predefined_sites	= ();
	$pkgname		= "";
	%make_vars_typemap	= ();
}

sub help($$$) {
	my ($out, $exitval, $show_all) = @_;
	my ($prog) = (basename($0));
	print $out ("usage: $prog [options] [package_directory]\n\n");

	my (@option_table) = ();
	foreach my $opt (sort keys %options) {
		push(@option_table, ["  ", $opt, $options{$opt}]);
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
			foreach my $key (keys %$optdefs) {
				${$optdefs->{$key}->[0]} = false;
			}
		} elsif ($opt eq "all") {
			foreach my $key (keys %$optdefs) {
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
	return true;
}

sub parse_command_line() {
	my (%options) = (
		"warning|W=s" => sub {
			my ($opt, $val) = @_;
			parse_multioption($val, \%warnings);
		},
		"check|C=s" => sub {
			my ($opt, $val) = @_;
			parse_multioption($val, \%checks);
		},
		"help|h" => sub { help(*STDOUT, 0, 1); },
		"verbose|v" => sub { PkgLint::Logging::set_verbose(true); },
		"version|V" => sub { print("$conf_distver\n"); exit(0); },
		"contblank|B=i" => \$opt_contblank,
		"dumpmakefile|I" => \$opt_dumpmakefile,
		"quiet|q" => \$opt_quiet,
	);
	{
		local $SIG{__WARN__} = sub {};
		if (!GetOptions(%options)) {
			help(*STDERR, 1, false);
		}
	}
	return true;
}

sub load_make_vars_typemap() {
	my ($lines) = (load_file("${conf_datadir}/makevars.map"));
	if (!$lines) {
		return false;
	}
	foreach my $line (@$lines) {
		if ($line->text =~ qr"^(?:#.*|\s*)$") {
			# ignore empty and comment lines
		} elsif ($line->text =~ qr"^([\w\d_.]+)\s+([\w_]+)$") {
			$make_vars_typemap{$1} = $2;
		} else {
			$line->log_error("[internal] Unknown line format.");
		}
	}
	return true;
}

sub load_predefined_sites() {
	my ($fname) = ("$pkgsrc_rootdir/mk/bsd.sites.mk");
	my ($lines) = load_file($fname);
	my ($varname) = undef;
	my ($ignoring) = false;

	if (!$lines) {
		log_error($fname, NO_LINE_NUMBER, "Could not be read.");
		return false;
	}
	foreach my $line (@{$lines}) {
		if ($line->text =~ qr"^(MASTER_SITE_\w+)\+=\s*\\$"o) {
			$varname = $1;
			$ignoring = false;
		} elsif ($line->text eq "MASTER_SITE_BACKUP?=\t\\") {
			$ignoring = true;
		} elsif ($line->text =~ qr"^\t($regex_url_directory)(?:|\s*\\)$"o) {
			if (!$ignoring) {
				if (defined($varname)) {
					$predefined_sites{$1} = $varname;
				} else {
					$line->log_error("Lonely URL found.");
				}
			}
		} elsif ($line->text =~ qr"^(?:#.*|\s*)$") {
			# ignore empty and comment lines
		} elsif ($line->text =~ qr"BSD_SITES_MK") {
			# ignore multiple inclusion guards
		} else {
			$line->log_error("Unknown line type.");
		}
	}
	log_info($fname, NO_LINE_NUMBER, sprintf("Loaded %d MASTER_SITE_* definitions.", scalar(keys(%predefined_sites))));
	return true;
}

sub check_directory($) {
	my ($dir) = @_;

	init_global_vars();
	if (-f "${dir}/../mk/bsd.pkg.mk") {
		$pkgsrc_rootdir = "${dir}/..";
		log_info(NO_FILE, NO_LINE_NUMBER, "Checking category Makefile.");
		check_category($dir);
	} elsif (-f "${dir}/../../mk/bsd.pkg.mk") {
		$pkgsrc_rootdir = "${dir}/../..";
		$opt_packagedir = $dir;
		if ($opt_warn_types) {
			load_make_vars_typemap();
		}
		load_predefined_sites();
		check_package();
	} else {
		log_error($dir, NO_LINE_NUMBER, "Neither a package nor a category.");
	}
}

sub main() {
	parse_command_line();

	if (@ARGV) {
		foreach my $dir (@ARGV) {
			check_directory($dir);
		}
	} else {
		check_directory(".");
	}
	print_summary_and_exit($opt_quiet);
}

sub check_package() {
	# we need to handle the Makefile first to get some variables
	if (!checkfile_Makefile("Makefile")) {
		log_error("$opt_packagedir/Makefile", NO_LINE_NUMBER, "Cannot be read.");
		return false;
	}

	checkfile_DESCR("$pkgdir/DESCR");

	if ($opt_check_MESSAGE) {
		foreach my $abs_msg (<$opt_packagedir/$filesdir/*>, <$opt_packagedir/$pkgdir/*>) {
			my ($msg) = (substr($abs_msg, length("$opt_packagedir/")));
			if ($msg =~ qr"MESSAGE") {
				checkfile_MESSAGE($msg);
			}
		}
	}
	if ($opt_check_PLIST) {
		foreach my $abs_plist (<$opt_packagedir/$filesdir/*>, <$opt_packagedir/$pkgdir/*>) {
			my ($plist) = (substr($abs_plist, length("$opt_packagedir/")));
			if ($plist =~ qr"PLIST") {
				checkfile_PLIST($plist);
			}
		}
	}
	if ($opt_check_patches) {
		foreach my $abs_patch (<$opt_packagedir/$patchdir/patch-*>) {
			my ($patch) = (substr($abs_patch, length("$opt_packagedir/")));
			checkfile_patches_patch($patch);
		}
	}
	if ($opt_check_distinfo) {
		if (-f "$opt_packagedir/$distinfo_file") {
			checkfile_distinfo($distinfo_file);
		}
	}
	if ($opt_check_distinfo && $opt_check_patches) {
		# Make sure there's a distinfo if there are patches
		my $patches = false;
		patch:
	    	    foreach my $i (<$opt_packagedir/$patchdir/patch-*>) {
			if ( -T "$i" ) { 
				$patches = true;
				last patch;
			}
		}
		if ($patches && ! -f "$opt_packagedir/$distinfo_file" ) {
			log_warning("$opt_packagedir/$distinfo_file", NO_LINE_NUMBER, "File not found. Please run '$conf_make makepatchsum'.");
		}
	}
	if ($opt_check_bl3) {
		foreach my $bl3 ("$opt_packagedir/$pkgdir/buildlink3.mk") {
			next unless -f $bl3;
			checkfile_buildlink3_mk($bl3);
		}
	}
	if ($opt_check_extra) {
		foreach my $abs_extra ((<$opt_packagedir/$filesdir/*>, <$opt_packagedir/$pkgdir/*>)) {
			my ($extra) = (substr($abs_extra, length("$opt_packagedir/")));
			next if ($extra =~ qr"(?:distinfo$|Makefile$|PLIST|MESSAGE)");
			next unless -f $extra && -T $extra;

			checkfile_other($extra);
		}
	}

	if (-f "$opt_packagedir/$distinfo_file") {
		if ( $seen_NO_CHECKSUM ) {
			log_warning("$opt_packagedir/$distinfo_file", NO_LINE_NUMBER, "This file should not exist if NO_CHECKSUM is set.");
		}
	} else {
		if ( ! $seen_NO_CHECKSUM ) {
			log_warning("$opt_packagedir/$distinfo_file", NO_LINE_NUMBER, "File not found. Please run '$conf_make makesum'.");
		}
	}
	if (-f "$opt_packagedir/$filesdir/md5") {
		log_error("$opt_packagedir/$filesdir/md5", NO_LINE_NUMBER, "This file is deprecated -- run '$conf_make mdi' to generate distinfo.");
	}
	if (-f "$opt_packagedir/$filesdir/patch-sum") {
		log_error("$opt_packagedir/$filesdir/patch-sum", NO_LINE_NUMBER, "This file is deprecated -- run '$conf_make mps' to generate distinfo.");
	}
	if (-f "$opt_packagedir/$pkgdir/COMMENT") {
		log_error("$opt_packagedir/$pkgdir/COMMENT", NO_LINE_NUMBER, "This file is deprecated -- please use a COMMENT variable instead.");
	}
	if (grep { $_ !~ qr"/CVS$" } <$opt_packagedir/pkg/*>) {
		log_error("$opt_packagedir/pkg", NO_LINE_NUMBER, "This directory and its contents are deprecated! Please 'mv $opt_packagedir/pkg/* $opt_packagedir' and 'rmdir $opt_packagedir/pkg'.");
	}
	if (-d "$opt_packagedir/scripts") {
		log_warning("$opt_packagedir/scripts", NO_LINE_NUMBER, "This directory and its contents are deprecated! Please call the script(s) explicitly from the corresponding target(s) in the pkg's Makefile.");
	}
	if (! -f "$opt_packagedir/$pkgdir/PLIST"
	    and ! -f "$opt_packagedir/$pkgdir/PLIST.common"
	    and ! $seen_PLIST_SRC
	    and ! $seen_NO_PKG_REGISTER ) {
		$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "No PLIST or PLIST.common, and PLIST_SRC and NO_PKG_REGISTER unset. Are you sure PLIST handling is ok?");
	}
	foreach my $wrkdir (<$opt_packagedir/work*>) {
		if ($opt_warn_workdir && -d $wrkdir) {
			log_warning($wrkdir, NO_LINE_NUMBER, "Should be cleaned up before committing the package.");
		}
	}
	foreach my $backup (<$opt_packagedir/*~>, <$opt_packagedir/*/*~>) {
		log_warning($backup, NO_LINE_NUMBER, "Should be cleaned up before committing the package.");
	}
	foreach my $orig (<$opt_packagedir/*/*.orig>, <$opt_packagedir/*.orig>, <$opt_packagedir/*/*.rej>, <$opt_packagedir/*.rej>) {
		log_warning($orig, NO_LINE_NUMBER, "Should be cleaned up before committing the package.");
	}
	return true;
} # check_package

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

#
# Subroutines common to all checking routines
#

sub checkline_length($$) {
	my ($line, $maxlength) = @_;

	if (length($line->text) > $maxlength) {
		$line->log_warning("Line too long (should be no more than $maxlength characters).");
	}
	return true;
}

sub checkline_valid_characters($$) {
	my ($line, $re_validchars) = @_;
	my ($rest);

	($rest = $line->text) =~ s/$re_validchars//g;
	if ($rest ne "") {
		my @chars = map { $_ = sprintf("0x%02x", ord($_)); } split(//, $rest);
		$line->log_warning(sprintf("Line contains invalid characters (%s).", join(", ", @chars)));
	}
	return true;
}

sub checkline_trailing_whitespace($) {
	my ($line) = @_;
	if ($line->text =~ /\s+$/) {
		$line->log_warning("Trailing white-space.");
	}
	return true;
}

sub checkline_rcsid_regex($$$) {
	my ($line, $prefix_regex, $prefix) = @_;

	if ($line->text !~ qr"^${prefix_regex}${regex_rcsidstr}$") {
		$line->log_error("\"${prefix}\$${conf_rcsidstr}\$\" expected.");
	}
	return true;
}

sub checkline_rcsid($$) {
	my ($line, $prefix) = @_;
	return checkline_rcsid_regex($line, quotemeta($prefix), $prefix);
}

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
	return true;
}

#
# Specific subroutines
#

sub checkfile_DESCR($) {
	my ($file) = @_;
	my ($maxchars, $maxlines, $fname) = (80, 24, "$opt_packagedir/$file");
	my ($descr);

	checkperms($fname);
	if (!defined($descr = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return false;
	}
	if (scalar(@{$descr}) == 0) {
		log_error($fname, NO_LINE_NUMBER, "Must not be empty.");
		return true;
	}

	foreach my $line (@$descr) {
		checkline_length($line, $maxchars);
		checkline_trailing_whitespace($line);
		checkline_valid_characters($line, $regex_validchars);
	}
	checklines_trailing_empty_lines($descr);

	if (scalar(@$descr) > $maxlines) {
		log_warning($fname, NO_LINE_NUMBER, "File too long (should be no more than $maxlines lines).");
	}

	return true;
}

sub checkfile_distinfo($) {
	my ($file) = @_;
	my ($fname) = ("$opt_packagedir/$file");
	my ($distinfo, %in_distinfo);

	checkperms($fname);
	if (!defined($distinfo = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return false;
	}

	if (scalar(@$distinfo) == 0) {
		log_error($fname, NO_LINE_NUMBER, "Must not be empty.");
		return true;
	}

	checkline_rcsid($distinfo->[0], "");

	foreach my $line (@$distinfo[1 .. scalar(@$distinfo)-1]) {
		next unless $line->text =~ /^(MD5|SHA1|RMD160) \(([^)]+)\) = (.*)$/;
		my ($alg, $patch, $sum) = ($1, $2, $3);

		if ($patch =~ /~$/) {
			$line->log_warning("Possible backup file \"$patch\"?");
		}

		if ($patch =~ /^patch-[-A-Za-z0-9_.]+$/) {
			if (-f "$opt_packagedir/$patchdir/$patch") {
				my $chksum = `sed -e '/\$NetBSD.*/d' $opt_packagedir/$patchdir/$patch | digest $alg`;
				$chksum =~ s/\r*\n*\z//;
				if ($sum ne $chksum) {
					$line->log_error("Checksum of $patch differs. Rerun '$conf_make makepatchsum'.");
				}
			} else {
				$line->log_error("$patch does not exist.");
			}
			$in_distinfo{$patch} = true;
		}
	}
	checklines_trailing_empty_lines($distinfo);

	foreach my $patch (<$opt_packagedir/$patchdir/patch-*>) {
		$patch = basename($patch);
		if (!exists($in_distinfo{$patch})) {
			log_error($fname, NO_LINE_NUMBER, "$patch is not recorded. Rerun '$conf_make makepatchsum'.");
		}
	}
	return true;
}

sub checkfile_MESSAGE($) {
	my ($file) = @_;
	my ($fname) = ("$opt_packagedir/$file");
	my ($message);

	checkperms($fname);
	if (!defined($message = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return false;
	}

	if (scalar(@$message) < 3) {
		log_warning($fname, NO_LINE_NUMBER, "File too short.");
		return true;
	}
	if ($message->[0]->text ne "=" x 75) {
		$message->[0]->log_warning("Expected a line of exactly 75 \"=\" characters.");
	}
	checkline_rcsid($message->[1], "");
	foreach my $line (@$message[2 .. scalar(@$message) - 2]) {
		checkline_length($line, 80);
		checkline_trailing_whitespace($line);
		checkline_valid_characters($line, $regex_validchars);
	}
	if ($message->[-1]->text ne "=" x 75) {
		$message->[-1]->log_warning("Expected a line of exactly 75 \"=\" characters.");
	}
	checklines_trailing_empty_lines($message);
	return true;
}

sub checkfile_PLIST($) {
	my ($file) = @_;
	my ($fname) = ("$opt_packagedir/$file");
	my ($plist, $curdir, $last_file_seen);
	
	checkperms($fname);
	if (!defined($plist = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return false;
	}
	if (scalar(@{$plist}) == 0) {
		log_error($fname, NO_LINE_NUMBER, "Must not be empty.");
		return false;
	}
	checkline_rcsid($plist->[0], "\@comment ");

	$curdir = $conf_localbase;
	line:
	foreach my $line (@$plist) {
		checkline_trailing_whitespace($line);

		if ($line->text =~ /<\$ARCH>/) {
			$line->log_warning("use of <\$ARCH> is deprecated, use \${MACHINE_ARCH} instead.");
		}
		if ($line->text =~ /^\@([a-z]+)\s+(.*)/) {
			my ($cmd, $arg) = ($1, $2);
			if ($cmd eq "cwd" || $cmd eq "cd") {
				$curdir = $arg;
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

		if ($line->text =~ /^\//) {
			$line->log_error("Use of full pathname disallowed.");
		}

		if ($opt_warn_sort && $line->text =~ qr"^\w") {
			if (defined($last_file_seen)) {
				if ($last_file_seen gt $line->text) {
					$line->log_warning($line->text . " should be sorted before ${last_file_seen}.");
				}
			}
			$last_file_seen = $line->text;
		}

		if ($line->text =~ /^doc/) {
			$line->log_error("Documentation must be installed under share/doc, not doc.");
		}

		if ($line->text =~ /^etc/ && $line->text !~ /^etc\/rc.d/) {
			$line->log_error("Configuration files must not be ".
				"registered in the PLIST. Please use the ".
				"PKG_SYSCONFDIR framework.");
		}

		if ($line->text =~ /^etc\/rc\.d/) {
			$line->log_error("RCD_SCRIPTS must not be ".
				"registered in the PLIST. Please use the ".
				"RCD_SCRIPTS framework.");
		}

		if ($line->text =~ /^info\/dir$/) {
			$line->log_error("\"info/dir\" should not be listed. Use install-info to add/remove an entry.");
		}

		if ($line->text =~ /^lib\/locale/) {
			$line->log_error("\"lib/locale\" should not be listed. Use \${PKGLOCALEDIR}/locale and set USE_PKGLOCALEDIR instead.");
		}

		if ($line->text =~ /^share\/locale/) {
			$line->log_warning("Use of \"share/locale\" is ".
				"deprecated.  Use \${PKGLOCALEDIR}/locale and set USE_PKGLOCALEDIR instead.");
		}

		if ($line->text =~ /\${PKGLOCALEDIR}/ && !$seen_USE_PKGLOCALEDIR) {
			$line->log_warning("PLIST contains \${PKGLOCALEDIR}, ".
				"but USE_PKGLOCALEDIR was not found.");
		}

		if ($curdir !~ m:^$conf_localbase: && $curdir !~ m:^/usr/X11R6:) {
			$line->log_warning("Installing to directory $curdir discouraged. could you please avoid it?");
		}
	}
	checklines_trailing_empty_lines($plist);
	return true;
}

sub checkfile_buildlink3_mk($) {
	my ($file) = @_;
	my ($fname) = ("$opt_packagedir/$file");
	my ($lines);

	if (!($lines = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return false;
	}
	checklines_deprecated_variables($lines);
	checklines_trailing_empty_lines($lines);
	checklines_direct_tools($lines);
	return true;
}

sub checkperms($) {
	my ($file) = @_;

	if ($opt_warn_exec && -f $file && -x $file && !is_committed($file)) {
		log_warning($file, NO_LINE_NUMBER, "Should not be executable.");
	}
	return true;
}

#
# misc files
#
sub checkfile_other($) {
	my ($file) = @_;
	my ($fname) = ("$opt_packagedir/$file");
	my ($lines);

	$lines = load_file($fname);
	if (!$lines) {
		log_error($fname, NO_LINE_NUMBER, "Could not be read.");
		return false;
	}
	checklines_trailing_empty_lines($lines);
	checkperms($fname);
	return true;
}

# $lines => an array of lines as returned by load_file().
sub check_for_multiple_patches($) {
	my ($lines) = @_;
	my ($files_in_patch, $patch_state, $line_type);

	$files_in_patch = 0;
	$patch_state = "";
	foreach my $line (@$lines) {
		if (index($line->text, "--- ") == 0 && $line->text !~ qr"^--- \d+(?:,\d+|) ----$") {
			$line_type = "-";
		} elsif (index($line->text, "*** ") == 0 && $line->text !~ qr"^\*\*\* \d+(?:,\d+|) \*\*\*\*$") {
			$line->log_warning("Please use unified diffs (diff -u) for patches.");
			$line_type = "*";
		} elsif (index($line->text, "+++ ") == 0) {
			$line_type = "+";
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
	return true;
}

sub checkfile_patches_patch($) {
	my ($file) = @_;
	my ($fname) = "$opt_packagedir/$file";
	my ($lines);

	if ($file =~ /.*~$/) {
		log_warning($fname, NO_LINE_NUMBER, "In case this is a backup file: please remove it and rerun '$conf_make makepatchsum'");
	}

	checkperms($fname);
	if (!defined($lines = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Could not be read.");
		return false;
	}
	if (scalar(@{$lines}) == 0) {
		log_error($fname, NO_LINE_NUMBER, "Must not be empty.");
		return true;
	}
	checkline_rcsid($lines->[0], "");

	foreach my $line (@{$lines}[1..$#{$lines}]) {
		if ($line->text =~ /$regex_known_rcs_tag/) {
			# XXX: see the pkgsrc guide how to fix that
			# TODO: that section still needs to be written
			$line->log_warning("Possible RCS tag \"\$$1\$\". Use no-keyword mode (-ko) on cvs add/import.");
		}
	}
	checklines_trailing_empty_lines($lines);

	check_for_multiple_patches($lines);
	return true;
}

sub readmakefile($$) {
	my ($file, $all_lines) = @_;
	my $contents = "";
	my ($includefile, $dirname, $savedln, $level, $lines);

	log_info($file, NO_LINE_NUMBER, "Reading Makefile.");

	$lines = load_file($file);
	if (!defined ($lines)) {
		return false;
	}
	if (scalar(@{$lines}) > 0) {
		checkline_rcsid_regex($lines->[0], qr"#\s+", "# ");
	}

	foreach my $line (@$lines) {
		checkline_trailing_whitespace($line);
		if ($line->text =~ /^\040{8}/) {
			$line->log_warning("Use tab (not spaces) to make indentation.");
		}
		push(@{$all_lines}, $line);
		# try to get any included file
		if ($line->text =~ /^.include\s+([^\n]+)$/) {
			$includefile = $1;
			if ($includefile =~ /\"([^\"]+)\"/) {
				$includefile = $1;
			}
			if (exists($seen_Makefile_include{$includefile})) {
				$contents .= "### pkglint ### skipped $includefile\n";
				next;
			}
			if (!$opt_check_bl3 && $includefile =~ qr"/buildlink3.mk$") {
				$contents .= "### pkglint ### skipped $includefile\n";
				next;
			}

			$seen_Makefile_include{$includefile} = true;
			if ($includefile =~ qr"Makefile\.common$") {
				$seen_Makefile_common = true;
			}
			if ($includefile =~ /\/mk\/texinfo\.mk/) {
				$line->log_error("Do not include $includefile.");
			}
			if ($includefile =~ /\/mk\/(?:bsd|java)/) {
				# skip these files
				$contents .= $line->text . "\n";
			} else {
				$dirname = dirname($file);
				# Only look in the directory relative to the
				# current file and in the current working directory.
				# We don't have an include dir list, like make(1) does.
				if (!-f "$dirname/$includefile") {
					$dirname = $opt_packagedir;
				}
				if (!-f "$dirname/$includefile") {
					$line->log_error("Cannot read $dirname/$includefile.");
				} else {
					$contents .= readmakefile("$dirname/$includefile", $all_lines);
				}
			}
		} else {
			$contents .= $line->text . "\n";
		}
	}
	checklines_trailing_empty_lines($lines);
	return $contents;
}

sub check_Makefile_vartype($) {
	my ($line) = @_;
	if ($line->text =~ qr"^([A-Z_a-z0-9.]+)\s*(=|\?=|\+=)\s*(.*)") {
		my ($varname, $op, $value) = ($1, $2, $3);
		if ($value =~ qr"\$") {
			# ignore values that contain other variables
		} elsif (exists($make_vars_typemap{$varname})) {
			my ($type) = ($make_vars_typemap{$varname});
			if ($type eq "Boolean") {
				if ($value !~ $regex_boolean) {
					$line->log_warning("$varname should be set to YES, yes, NO, or no.");
				}
			} elsif ($type eq "Yes_Or_Undefined") {
				if ($value !~ $regex_yes_or_undef) {
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
			} else {
				$line->log_error("[internal] Type $type unknown.");
			}
		}
	}
	return true;
}

sub check_Makefile_variables($) {
	my ($lines) = @_;

	# Check variable name quoting
	foreach my $line (@$lines) {
		if ($line->text =~ qr"^[^#]*[^\$]\$(\w+)") {
			my ($varname) = ($1);
			$line->log_warning("please write either \${$varname} or \$\$$varname instead of \$$varname.");
		}
	}

	# Check variable types
	if ($opt_warn_types) {
		foreach my $line (@$lines) {
			check_Makefile_vartype($line);
		}
	}

	return true;
}

sub checklines_deprecated_variables($) {
	my ($lines) = @_;
	my ($fname) = ("${conf_datadir}/deprecated.map");
	my ($deprecated) = load_file($fname);
	my %vars = ();

	if (!$deprecated) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return false;
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
		if ($line->text =~ qr"^([A-Z][A-Z0-9_]*)\s*[!+?]?=") {
			my ($varname) = ($1);
			if (exists($vars{$varname})) {
				$line->log_warning("${varname} is deprecated. $vars{$varname}");
			}
		}
	}

	return true;
}

sub checklines_direct_tools($) {
	my ($lines) = @_;

	if (!$opt_warn_directcmd) {
		return true;
	}
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
	my $regex_tools = qr"(?:^|\s|/)(${tools})(?:\s|$)";

	my @ok_vars = qw(
		BUILDLINK_TRANSFORM BUILD_DEPENDS
		COMMENT CONFLICTS
		DEPENDS DISTNAME
		EXTRACT_SUFX EXTRACT_USING
		INTERACTIVE_STAGE
		MANSOURCEPATH MASTER_SITES
		PKGNAME PKGSRC_USE_TOOLS
		SUBST_MESSAGE\\..*
		.*_TARGET
		USE_TOOLS);
	my @ok_shellcmds = (
		qr"(?:\./Build|\$\{JAM_COMMAND\})\s+(?:install|test)",
		qr"\"[^\"]*${regex_tools}[^\"]*\"");

	my %toolvar = ();
	foreach my $tool (@tools) {
		$toolvar{$tool} = uc($tool);
	}
	foreach my $tool (@cmd_tools) {
		$toolvar{$tool} = uc($tool)."_CMD";
	}

	my $ok_vars = join("|", @ok_vars);
	my $regex_ok_vars = qr"^(?:${ok_vars})$";
	my $ok_shellcmds = join("|", @ok_shellcmds);
	my $regex_ok_shellcmds = qr"(?:${ok_shellcmds})";
	log_info(NO_FILE, NO_LINE_NUMBER, "[checklines_direct_tools] regex_tools=${regex_tools}");
	log_info(NO_FILE, NO_LINE_NUMBER, "[checklines_direct_tools] regex_ok_vars=${regex_ok_vars}");
	log_info(NO_FILE, NO_LINE_NUMBER, "[checklines_direct_tools] regex_ok_shellcmds=${regex_ok_shellcmds}");

	foreach my $line (@{$lines}) {
		my $text = $line->text;

		next unless ($text =~ $regex_tools);
		my ($tool) = ($1);

		if ($text =~ qr"^#") {
			# skip comments
		} elsif ($text =~ qr"^([\w.]+?)\s*[?+:!]?=\s*(.*)") {
			my ($varname, $value) = ($1, $2);
			# process variable assignments
			if ($varname =~ $regex_ok_vars) {
				$line->log_info("Legitimate direct use of \"${tool}\" in variable ${varname}.");
			} else {
				$line->log_warning("Possible direct use of \"${tool}\" in variable ${varname}. Please use \$\{$toolvar{$tool}\} instead.");
			}
		} elsif ($text =~ qr"^\t(.*)") {
			my ($shellcmd) = ($1);
			# process shell commands
			if ($shellcmd =~ $regex_ok_shellcmds) {
				$line->log_info("Legitimate direct use of \"${tool}\" in shell command \"${shellcmd}\".");
			} else {
				$line->log_warning("Possible direct use of \"${tool}\" in shell command \"${shellcmd}\". Please use \$\{$toolvar{$tool}\} instead.");
			}
		} elsif ($text =~ qr"^\.") {
			# skip processing directives
		} elsif ($text =~ qr"^([-\w.]+):") {
			# skip dependency specifications
		} else {
			$line->log_error("[internal:checklines_direct_tools] unknown line format");
		}
	}
	return true;
}

sub checkfile_Makefile($) {
	my ($file) = @_;
	my ($fname) = ("$opt_packagedir/$file");
	my ($tmp, $rawwhole, $whole, $idx, @sections);
	my (@varnames) = ();
	my ($distfiles, $svrpkgname, $distname, $extractsufx) = ('', '', '', '', '');
	my ($bogusdistfiles) = (0);
	my ($realwrksrc, $wrksrc) = ('', '');
	my ($category, $lines);

	log_info($fname, NO_LINE_NUMBER, "Checking package Makefile.");

	$category = basename(dirname(Cwd::abs_path($opt_packagedir)));

	checkperms($fname);

	$tmp = 0;
	$rawwhole = readmakefile($fname, $lines = []);
	if (!$rawwhole) {
		log_error("$opt_packagedir/$file", NO_LINE_NUMBER, "Cannot be read.");
		return false;
	}
	if ($opt_dumpmakefile) {
		print("OK: whole Makefile (with all included files) follows:\n");
		foreach my $line (@{$lines}) {
			printf("%s\n", $line->to_string());
		}
	}

	{
		my $cont = 0;
		foreach my $line (@{$lines}) {
			$cont = ($line->text eq "") ? $cont + 1 : 0;
			if ($cont == $opt_contblank + 1) {
				$line->log_warning("${cont} contiguous blank lines, should be at most ${opt_contblank}.");
			}
		}
	}

	$whole = "\n" . $rawwhole;

	#
	# whole file: $(VARIABLE)
	#
	if ($opt_warn_paren) {
		if ($whole =~ /[^\$]\$\([\w\d]+\)/) {
			$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "Use \${VARIABLE} instead of \$(VARIABLE).");
		}
	}

	#
	# whole file: get FILESDIR, PATCHDIR, PKGDIR, SCRIPTDIR,
	# PATCH_SUM_FILE and DIGEST_FILE
	#

	$filesdir = "files";
	$filesdir = $1 if ($whole =~ /\nFILESDIR[+?]?=[ \t]*([^\n]+)\n/);
	$filesdir = $1 if ($whole =~ /\nFILESDIR:?=[ \t]*([^\n]+)\n/);
	$filesdir =~ s/\$\{.CURDIR\}/./;

	$patchdir = "patches";
	$patchdir = $1 if ($whole =~ /\nPATCHDIR[+?]?=[ \t]*([^\n]+)\n/);
	$patchdir = $1 if ($whole =~ /\nPATCHDIR:?=[ \t]*([^\n]+)\n/);
	$patchdir =~ s/\$\{.CURDIR\}/./;
	$patchdir =~ s/\${PKGSRCDIR}/..\/../;

	if (grep { $_ !~ qr"/CVS$" } <$opt_packagedir/pkg/*>) {
		$pkgdir = "pkg";
	}
	$pkgdir = $1 if ($whole =~ /\nPKGDIR[+?]?=[ \t]*([^\n]+)\n/);
	$pkgdir = $1 if ($whole =~ /\nPKGDIR:?=[ \t]*([^\n]+)\n/);
	$pkgdir =~ s/\$\{.CURDIR\}/./;

	$scriptdir = "scripts";
	$scriptdir = $1 if ($whole =~ /\nSCRIPTDIR[+?]?=[ \t]*([^\n]+)\n/);
	$scriptdir = $1 if ($whole =~ /\nSCRIPTDIR:?=[ \t]*([^\n]+)\n/);
	$scriptdir =~ s/\$\{.CURDIR\}/./;

	$distinfo_file = "distinfo";
	$distinfo_file = $1 if ($whole =~ /\nDISTINFO_FILE[+?]?=[ \t]*([^\n]+)\n/);
	$distinfo_file = $1 if ($whole =~ /\nDISTINFO_FILE:?=[ \t]*([^\n]+)\n/);
	$distinfo_file =~ s/\$\{.CURDIR\}/./;
	$distinfo_file =~ s/\${PKGSRCDIR}/..\/../;
	$distinfo_file =~ s/\${PKGDIR}/$pkgdir/;

	log_info(NO_FILE, NO_LINE_NUMBER, "[checkfile_Makefile] PATCHDIR=$patchdir");
	log_info(NO_FILE, NO_LINE_NUMBER, "[checkfile_Makefile] SCRIPTDIR=$scriptdir");
	log_info(NO_FILE, NO_LINE_NUMBER, "[checkfile_Makefile] FILESDIR=$filesdir");
	log_info(NO_FILE, NO_LINE_NUMBER, "[checkfile_Makefile] PKGDIR=$pkgdir");
	log_info(NO_FILE, NO_LINE_NUMBER, "[checkfile_Makefile] DISTINFO_FILE=$distinfo_file");

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

	if ($whole =~ /\nPLIST_SRC/) {
		$seen_PLIST_SRC = true;
	}
	if ($whole =~ /\nNO_PKG_REGISTER/) {
		$seen_NO_PKG_REGISTER = true;
	}
	if ($whole =~ /\nNO_CHECKSUM/) {
		$seen_NO_CHECKSUM = true;
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

	checklines_direct_tools($lines);

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

	#
	# section 1: comment lines.
	#
	$tmp = $sections[$idx++];
	if ($tmp =~ /#(\s+)\$$conf_rcsidstr([^\$]*)\$/) {
		if ($2 ne '') {
			if (!is_committed($fname)) {
				$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "\"\$$conf_rcsidstr\$\" expected.");
			}
		}
	}

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
		if ($tmp !~ /\n$i=/) {
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
				check_predefined_sites($i);
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
	$distname = $1 if ($tmp =~ /\nDISTNAME[+?]?=[ \t]*([^\n]+)\n/);
	$pkgname = $1 if ($tmp =~ /\nPKGNAME[+?]?=[ \t]*([^\n]+)\n/);
	$svrpkgname = $1 if ($tmp =~ /\nSVR4_PKGNAME[+?]?=[ \t]*([^\n]+)\n/);
	$extractsufx = $1 if ($tmp =~ /\nEXTRACT_SUFX[+?]?=[ \t]*([^\n]+)\n/);
	$distfiles = $1 if ($tmp =~ /\nDISTFILES[+?]?=[ \t]*([^\n]+)\n/);

	# check bogus EXTRACT_SUFX.
	if ($extractsufx ne '') {
		log_info(NO_FILE, NO_LINE_NUMBER, "Seen EXTRACT_SUFX, checking value.");
		if ($distfiles ne '' && ($extractsufx eq '.tar.gz')) {
			$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "no need to define EXTRACT_SUFX if ".
				"DISTFILES is defined.");
		}
		if ($extractsufx eq '.tar.gz') {
			$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "EXTRACT_SUFX is \".tar.gz.\" ".
				"by default. You don't need to specify it.");
		}
	} else {
		log_info(NO_FILE, NO_LINE_NUMBER, "No EXTRACT_SUFX seen, using default value.");
		$extractsufx = '.tar.gz';
	}

	if ($pkgname ne '' && $pkgname eq $distname) {
		$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "PKGNAME is \${DISTNAME} by default, ".
			"you don't need to define PKGNAME.");
	}
	if ($svrpkgname ne '') {
		if (length($svrpkgname) > 5) {
			$opt_warn_vague && log_error(NO_FILE, NO_LINE_NUMBER, "SVR4_PKGNAME should not be longer ".
				"than 5 characters.");
		}
	}
	my $i = ($pkgname eq '') ? $distname : $pkgname;
	$i =~ s/\${DISTNAME[^}]*}/$distname/g;
	if ($i =~ /-([^-]+)$/) {
		my ($j, $k) = ($`, $1);
		# Be very smart. Kids, don't do this at home.
		if ($k =~ /\$(\(|\{)([A-Z_-]+)(\)|\})/) {
			my $k1 = $2;
			$k = $1 if ($rawwhole =~ /\n$k1[ \t]*?=[ \t]*([^\n]+)\n/);
		}
		if ($k =~ /^pl[0-9]*$/
		 || $k =~ /^[0-9]*[A-Za-z]*[0-9]*(\.[0-9]*[A-Za-z]*[0-9]*)*$/) {
			log_info(NO_FILE, NO_LINE_NUMBER, "Trailing part of PKGNAME\"-$k\" ".
				"looks fine.");
		} else {
			$opt_warn_vague && log_error(NO_FILE, NO_LINE_NUMBER, "Version number part of PKGNAME".
				(($pkgname eq '')
					? ', which is derived from DISTNAME, '
					: ' ').
				"looks illegal. You should modify \"-$k\".");
		}
	} else {
		$opt_warn_vague && log_error(NO_FILE, NO_LINE_NUMBER, "PKGNAME".
			(($pkgname eq '')
				? ', which is derived from DISTNAME, '
				: ' ').
			"must come with version number, like \"foobaa-1.0\".");
		if ($i =~ /_pl[0-9]*$/
		 || $i =~ /_[0-9]*[A-Za-z]?[0-9]*(\.[0-9]*[A-Za-z]?[0-9]*)*$/) {
			$opt_warn_vague && log_error(NO_FILE, NO_LINE_NUMBER, "You seem to be using underline ".
				"before version number in PKGNAME. ".
				"it has to be hyphen.");
		}
	}
	if ($distname =~ /(nb\d*)/) {
			$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "Is '$1' really ok on DISTNAME, ".
				"or is it intended for PKGNAME?");
	}

	# if DISTFILES have only single item, it is better to avoid DISTFILES
	# and to use combination of DISTNAME and EXTRACT_SUFX.
	# example:
	#	DISTFILES=package-1.0.tgz
	# should be
	#	DISTNAME=     package-1.0
	#	EXTRACT_SUFX= .tgz
	if ($distfiles =~ /^\S+$/) {
		$bogusdistfiles++;
		log_info(NO_FILE, NO_LINE_NUMBER, "Seen DISTFILES with single item, checking value.");
		$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "Use of DISTFILES with single file ".
			"is discouraged. Distribution filename should be set by ".
			"DISTNAME and EXTRACT_SUFX.");
		if ($distfiles eq $distname . $extractsufx) {
			$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "Definition of DISTFILES not necessary. ".
				"DISTFILES is \${DISTNAME}/\${EXTRACT_SUFX} by default.");
		}

		# make an advice only in certain cases.
		if ($pkgname ne '' && $distfiles =~ /^$pkgname([-\.].+)$/) {
			$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "How about \"DISTNAME=$pkgname\"".
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

	if ($tmp =~ /(PATCH_SITES|PATCH_SITE_SUBDIR|PATCHFILES|PATCH_DIST_STRIP)/) {
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
        my @tocheck = qw(MAINTAINER HOMEPAGE COMMENT);

        &checkorder('MAINTAINER', $tmp, @tocheck);

	# warnings for missing or incorrect HOMEPAGE
	$tmp = "\n" . $tmp;
	if ($tmp !~ /\nHOMEPAGE[+?]?=[ \t]*([^\n]*)\n/ || $1 =~ /^[ \t]*$/) {
		$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "Please add HOMEPAGE if the package has one.");
	} else {
		$i = $1;
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
	} else {
		# and its properties:
		my $tmp2 = $1;
		if ($tmp2 =~ /\.$/i) {
			$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "COMMENT should not end with a '.' (period).");
		}
		if ($tmp2 =~ /^(a|an) /i) {
			$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "COMMENT should not begin with '$1 '.");
		}
		if ($tmp2 =~ /^[a-z]/) {
			$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "COMMENT should start with a capital letter.");
		}
		if (length($tmp2) > 70) {
			$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "COMMENT should not be longer than 70 characters.");
		}
	}

	checkearlier($tmp, @varnames);
	$tmp = "\n" . $tmp;
	if ($tmp =~ /\nMAINTAINER=[^@]+\@netbsd.org/) {
		$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "\@netbsd.org should be \@NetBSD.org in MAINTAINER.");
	} elsif ($tmp =~ /\nMAINTAINER=[^\n]+/) {
		$tmp =~ s/\nMAINTAINER=[^\n]+//;
	} else {
		$opt_warn_vague && log_error(NO_FILE, NO_LINE_NUMBER, "No MAINTAINER listed in $file.");
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
					if (! -d "$opt_packagedir/$m[1]") {
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
	$tmp = join("\n\n", @sections[$idx .. scalar(@sections)-1]);

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
	$realwrksrc = $wrksrc ? "$wrksrc/$distname"
			      : "\${WRKDIR}/$distname";
	log_info(NO_FILE, NO_LINE_NUMBER, "WRKSRC seems to be $realwrksrc.");

	if ($bogusdistfiles) {
		if ($distname ne '' && $wrksrc eq '') {
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

	return check_Makefile_variables($lines);
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
		return true;
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
	while (scalar(@items)) {
		my $i = pop(@items);
		my $k = 0;
		while ($k < scalar(@order) && $order[$k] ne $i) {
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
		return true;
	}

	log_info(NO_FILE, NO_LINE_NUMBER, "Checking items that have to appear earlier.");
	foreach my $i (@varnames) {
		if ($str =~ /\n$i[?+]?=/) {
			$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "\"$i\" has to appear earlier.");
		}
	}
}

sub check_predefined_sites($) {
	my ($url) = @_;

	foreach my $site (keys(%predefined_sites)) {
		next unless (index($url, $site) == 0);
		my $subdir = substr($url, length($site));
		$opt_warn_vague && log_warning(NO_FILE, NO_LINE_NUMBER, "Please use \${$predefined_sites{$site}:=$subdir} instead of \"$url\".");
		return true;
	}
	log_info(NO_FILE, NO_LINE_NUMBER, "URL does not match any of the predefined URLS. Good.");
	return true;
}

sub check_category($) {
	my ($dir) = @_;
	my $fname = "${dir}/Makefile";
	my ($lines);
	my (@makefile_subdirs) = ();
	my (@filesys_subdirs) = ();

	if (!defined($lines = load_file($fname))) {
		log_error($fname, NO_LINE_NUMBER, "Cannot be read.");
		return false;
	}
	if (scalar(@$lines) == 0) {
		log_error($fname, NO_LINE_NUMBER, "Must not be empty.");
		return true;
	}
	checkline_rcsid($lines->[0], "# ");

	@filesys_subdirs = grep { ($_ = substr($_, length($dir) + 1, -1)) ne "CVS"; } glob("${dir}/*/");
	
	my ($first, $last_subdir, $comment_seen) = (true, undef, false);
	foreach my $line (@$lines) {
		if ($line->text =~ qr"^(#?)SUBDIR(.*?)=\s*(\S+)\s*(?:#\s*(.*?)\s*|)$") {
			my ($comment_flag, $operator, $subdir, $comment) = ($1, $2, $3, $4);
			if ($comment_flag eq "#") {
				if (defined($comment) && $comment eq "") {
					$line->log_warning("$subdir commented out without giving a reason.");
				}
				push(@makefile_subdirs, $subdir);
			} elsif ($first) {
				$first = false;
				if ($operator ne "" && $operator ne "+") {
					$line->log_error("SUBDIR= or SUBDIR+= expected.");
				}
				push(@makefile_subdirs, $subdir);
				$last_subdir = $subdir;
			} else {
				if ($operator ne "+") {
					$line->log_error("SUBDIR+= expected.");
				}
				push(@makefile_subdirs, $subdir);
				if ($opt_warn_sort && $last_subdir ge $subdir) {
					$line->log_error("$subdir should come before $last_subdir.");
				}
				$last_subdir = $subdir;
			}
		} elsif ($line->text =~ qr"^COMMENT\s*=\s*([^#]*?)") {
			my ($comment) = ($1);
			$comment_seen = true;
		}
	}

	@filesys_subdirs = sort(@filesys_subdirs);
	@makefile_subdirs = sort(@makefile_subdirs);
	my ($findex, $mindex) = (0, 0);
	my ($fmax, $mmax) = (scalar(@filesys_subdirs), scalar(@makefile_subdirs));
	while ($findex < $fmax || $mindex < $mmax) {
		my $f = ($findex < $fmax) ? $filesys_subdirs[$findex] : undef;
		my $m = ($mindex < $mmax) ? $makefile_subdirs[$mindex] : undef;

		if ($findex < $fmax && ($mindex == $mmax || $f lt $m)) {
			log_error($fname, NO_LINE_NUMBER, "$f exists in the file system, but not in the Makefile.");
			$findex++;
		} elsif ($mindex < $mmax && ($findex == $fmax || $m lt $f)) {
			log_error($fname, NO_LINE_NUMBER, "$m exists in the Makefile, but not in the file system.");
			$mindex++;
		} else { # $findex < $fmax && $mindex < $mmax && $f eq $m
			$findex++;
			$mindex++;
		}
	}

	if (!$comment_seen) {
		log_error($fname, NO_LINE_NUMBER, "no COMMENT line found.");
	}
	checklines_trailing_empty_lines($lines);
	return true;
}

#
# The main program
#

main();
