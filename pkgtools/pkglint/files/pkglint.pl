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
# $NetBSD: pkglint.pl,v 1.108 2004/06/26 18:53:17 hubertf Exp $
#
# This version contains lots of changes necessary for NetBSD packages
# done by Hubert Feyrer <hubertf@netbsd.org>,
# Thorsten Frueauf <frueauf@netbsd.org>, Thomas Klausner <wiz@netbsd.org>,
# Roland Illig <roland.illig@gmx.de> and others.
#

use Getopt::Std;
use File::Basename;
use FileHandle;
use Cwd;

# Start of configuration area
my $conf_rcsidstr	= 'NetBSD';
my $conf_portsdir	= '@PORTSDIR@';
my $conf_localbase	= '@PREFIX@';
my $conf_distver	= '@DISTVER@';
my $conf_make		= '@MAKE@';
# End of configuration area

# Command line options
my $opt_extrafile	= 1; #
my $opt_parenwarn	= 1; #
my $opt_committer	= 1; #
my $opt_verbose		= 0; #
my $opt_newpackage	= 0; #
my $opt_dumpmakefile	= 0; #
my $opt_contblank	= 1; # number of allowed contigoous blank lines
my $opt_packagedir	= "."; #

# Global variables that should be eliminated by the next refactoring.
my %definesfound	= ();
my $errors		= 0; # number of errors
my $warnings		= 0; # number of warnings

# == Output of messages to the user ==
# The log_* routines take the parameters ($file, $lineno, $msg).
# $file is the file where the message originated or NO_FILE.
# $lineno is the line number if applicable or NO_LINE_NUMBER.
# $msg is the text of the message.
sub NO_FILE();
sub NO_LINE_NUMBER();
sub log_error($$$);
sub log_warning($$$);
sub log_info($$$);
sub print_summary_and_exit();

sub checkfile_DESCR($);
sub checkfile_distinfo($);
sub checkfile_Makefile($);
sub checkfile_MESSAGE($);
sub checkfile_patches_patch($);
sub checkfile_PLIST($);

sub print_summary_and_exit();
sub checkperms($);
sub checkpathname($);
sub checklastline($);
sub readmakefile($);
sub checkextra($$);
sub checkorder($$@);
sub checkearlier($@);
sub abspathname($$);
sub is_predefined($);
sub category_check();

sub parse_command_line() {
	my %opts = ();
	getopts('hINB:qvV', \%opts);
	if ($opts{"h"}) {
		my $prog = basename($0);
		print STDERR <<EOF;
usage: $prog [-qvIN] [-B#] [package_directory]
	-v	verbose mode
	-V	version ($conf_distver)
	-I	show Makefile (with all included files)
	-N	writing a new package
	-B#	allow # contiguous blank lines (default: $opt_contblank line)
EOF
		exit 0;
	}
	if ($opts{"v"}) { $opt_verbose = 1; }
	if ($opts{"N"}) { $opt_newpackage = 1; }
	if ($opts{"I"}) { $opt_dumpmakefile = 1; }
	if ($opts{"B"}) { $opt_contblank = $opts{"B"}; }
	if (scalar(@ARGV)) { $opt_packagedir = shift(@ARGV); }
	if ($opts{"V"}) {
		print "$conf_distver\n";
		exit;
	}
}
parse_command_line();

log_info(NO_FILE, NO_LINE_NUMBER, "config: portsdir: \"$conf_portsdir\" ".
	"rcsidstr: \"$conf_rcsidstr\" ".
	"localbase: $conf_localbase");

#
# just for safety.
#
if (! -d $opt_packagedir) {
	print STDERR "FATAL: invalid directory $opt_packagedir specified.\n";
	exit 1;
}

if (-e <$opt_packagedir/../Packages.txt>) {
	log_info(NO_FILE, NO_LINE_NUMBER, "checking category Makefile.");
	category_check();
	print_summary_and_exit();
}

if (-e <$opt_packagedir/../../Packages.txt>) {
	if ($opt_packagedir eq ".") {
		$category = basename(dirname(cwd()));
	} else {
		$category = basename(dirname($opt_packagedir));
	}
}

#
# variables for global checks.
#
$sharedocused = 0;
$seen_PLIST_SRC = 0;
$seen_NO_PKG_REGISTER = 0;
$seen_NO_CHECKSUM = 0;
$seen_USE_PKGLOCALEDIR = 0;
$seen_USE_BUILDLINK2 = 0;

%predefined = ();
foreach $i (split("\n", <<EOF)) {
XCONTRIB	ftp://crl.dec.com/pub/X11/contrib/
XCONTRIB	ftp://ftp.sunsite.auc.dk/pub/X/X.org/contrib/
XCONTRIB	ftp://ftp.uni-paderborn.de/pub/X11/contrib/
XCONTRIB	ftp://ftp.x.org/contrib/
GNU		ftp://ftp.gnu.org/pub/gnu/
GNU		ftp://ftp.wustl.edu/systems/gnu/
GNU		ftp://ftp.informatik.tu-muenchen.de/pub/comp/os/unix/gnu/
PERL_CPAN	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/
PERL_CPAN	ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/
TEX_CTAN	ftp://ftp.cdrom.com/pub/tex/ctan/
TEX_CTAN	ftp://ftp.wustl.edu/packages/TeX/
TEX_CTAN	ftp://ftp.funet.fi/pub/TeX/CTAN/
TEX_CTAN	ftp://ftp.tex.ac.uk/public/ctan/tex-archive/
TEX_CTAN	ftp://ftp.dante.de/tex-archive/
SUNSITE		ftp://metalab.unc.edu/pub/Linux/
SUNSITE		ftp://sunsite.unc.edu/pub/Linux/
SUNSITE		ftp://ftp.infomagic.com/pub/mirrors/linux/sunsite/
SUNSITE		ftp://ftp.funet.fi/pub/mirrors/sunsite.unc.edu/pub/Linux/
GNOME		ftp://ftp.gnome.org/pub/GNOME/
GNOME		ftp://ftp.sunet.se/pub/X11/GNOME/
GNOME		ftp://ftp.informatik.uni-bonn.de/pub/os/unix/gnome/
GNOME		ftp://ftp.tuwien.ac.at/hci/gnome.org/GNOME/
SOURCEFORGE	ftp://download.sourceforge.net/
SOURCEFORGE	http://download.sourceforge.net/
EOF
	($j, $k) = split(/\t+/, $i);
	$predefined{$k} = $j;
}

# we need to handle the Makefile first to get some variables
log_info(NO_FILE, NO_LINE_NUMBER, "checking Makefile.");
if (! -f "$opt_packagedir/Makefile") {
	log_error(NO_FILE, NO_LINE_NUMBER, "no Makefile in \"$opt_packagedir\".");
} else {
    	checkfile_Makefile("Makefile") || log_error(NO_FILE, NO_LINE_NUMBER, "Cannot open the file $i\n");
}


#
# check for files.
#
@checker = ("$pkgdir/DESCR");
%checker = ("$pkgdir/DESCR", \&checkfile_DESCR);

if ($opt_extrafile) {
	foreach $i ((<$opt_packagedir/$filesdir/*>, <$opt_packagedir/$pkgdir/*>)) {
		next if (! -T $i);
		next if ($i =~ /distinfo$/);
		next if ($i =~ /Makefile$/);
		$i =~ s/^\Q$opt_packagedir\E\///;
		next if (defined $checker{$i});
		if ($i =~ /MESSAGE/) {
			unshift(@checker, $i);
			$checker{$i} = \&checkfile_MESSAGE;
		} elsif ($i =~ /PLIST/) {
		        unshift(@checker, $i);
			$checker{$i} = \&checkfile_PLIST;
		} else {
		        push(@checker, $i);
			$checker{$i} = \&checkpathname;
		}
	}
}
foreach $i (<$opt_packagedir/$patchdir/patch-*>) {
	next if (! -T $i);
	$i =~ s/^\Q$opt_packagedir\E\///;
	next if (defined $checker{$i});
	push(@checker, $i);
	$checker{$i} = \&checkfile_patches_patch;
}
if (-e <$opt_packagedir/$distinfo>) {
	$i = "$distinfo";
	next if (defined $checker{$i});
	push(@checker, $i);
	$checker{$i} = \&checkfile_distinfo;
}
{
	# Make sure there's a distinfo if there are patches
	$patches=0;
	patch:
    	    foreach $i (<$opt_packagedir/$patchdir/patch-*>) {
		if ( -T "$i" ) { 
			$patches=1;
			last patch;
		}
	}
	if ($patches && ! -f "$opt_packagedir/$distinfo" ) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "no $opt_packagedir/$distinfo file. Please run '$conf_make makepatchsum'.");
	}
}
foreach $i (@checker) {
	log_info(NO_FILE, NO_LINE_NUMBER, "checking $i.");
	if (! -f "$opt_packagedir/$i") {
		log_error(NO_FILE, NO_LINE_NUMBER, "no $i in \"$opt_packagedir\".");
	} else {
		$checker{$i}->($i) || log_warning(NO_FILE, NO_LINE_NUMBER, "Cannot open the file $i\n");
		if ($i !~ /patches\/patch/) {
			&checklastline($i) ||
				log_warning(NO_FILE, NO_LINE_NUMBER, "Cannot open the file $i\n");
		}
	}
}
if (-e <$opt_packagedir/$distinfo> ) {
	if ( $seen_NO_CHECKSUM ) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "NO_CHECKSUM set, but $opt_packagedir/$distinfo exists. Please remove it.");
	}
} else {
	if ( ! $seen_NO_CHECKSUM ) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "no $opt_packagedir/$distinfo file. Please run '$conf_make makesum'.");
	}
}
if (-e <$opt_packagedir/$filesdir/md5> ) {
	log_error(NO_FILE, NO_LINE_NUMBER, "$filesdir/md5 is deprecated -- run '$conf_make mdi' to generate distinfo.");
}
if (-e <$opt_packagedir/$filesdir/patch-sum> ) {
	log_error(NO_FILE, NO_LINE_NUMBER, "$filesdir/patch-sum is deprecated -- run '$conf_make mps' to generate distinfo.");
}
if (-e <$pkgdir/COMMENT> ) {
	log_error(NO_FILE, NO_LINE_NUMBER, "$pkgdir/COMMENT is deprecated -- please use a COMMENT variable instead.");
}
if (-d "$opt_packagedir/pkg" ) {
	log_error(NO_FILE, NO_LINE_NUMBER, "$opt_packagedir/pkg and its contents are deprecated!\n".
		"\tPlease 'mv $opt_packagedir/pkg/* $opt_packagedir' and 'rmdir $opt_packagedir/pkg'.");
}
if (-d "$opt_packagedir/scripts" ) {
	log_warning(NO_FILE, NO_LINE_NUMBER, "$opt_packagedir/scripts and its contents are deprecated! Please call the script(s)\n".
		"\texplicitly from the corresponding target(s) in the pkg's Makefile.");
}
if (! -f "$opt_packagedir/$pkgdir/PLIST"
    and ! -f "$opt_packagedir/$pkgdir/PLIST-mi"
    and ! $seen_PLIST_SRC
    and ! $seen_NO_PKG_REGISTER ) {
	log_warning(NO_FILE, NO_LINE_NUMBER, "no PLIST or PLIST-mi, and PLIST_SRC and NO_PKG_REGISTER unset.\n     Are you sure PLIST handling is ok?");
}
if ($opt_committer) {
	if (scalar(@_ = <$opt_packagedir/work*/*>) || -d "$opt_packagedir/work*") {
		log_warning(NO_FILE, NO_LINE_NUMBER, "be sure to cleanup $opt_packagedir/work* ".
			"before committing the package.");
	}
	if (scalar(@_ = <$opt_packagedir/*/*~>) || scalar(@_ = <$opt_packagedir/*~>)) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "for safety, be sure to cleanup ".
			"emacs backup files before committing the package.");
	}
	if (scalar(@_ = <$opt_packagedir/*/*.orig>) || scalar(@_ = <$opt_packagedir/*.orig>)
	 || scalar(@_ = <$opt_packagedir/*/*.rej>) || scalar(@_ = <$opt_packagedir/*.rej>)) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "for safety, be sure to cleanup ".
			"patch backup files before committing the package.");
	}
}
print_summary_and_exit();

sub checkfile_DESCR($) {
	local($file) = @_;
	local(%maxchars) = ('DESCR', 80);
	local(%maxlines) = ('DESCR', 24);
	local(%errmsg) = ('DESCR', "exceeds $maxlines{'DESCR'} ".
			  	   "lines, make it shorter if possible");
	local($longlines, $linecnt, $tmp) = (0, 0, "");
	my ($line);

	&checkperms("$opt_packagedir/$file");

	$shortname = basename($file);
	open(IN, "< $opt_packagedir/$file") || return 0;

	while (defined($line = <IN>)) {
		$linecnt++;
		$longlines++ if ($maxchars{$shortname} < length($line));
		$tmp .= $line;
	}
	close(IN);

	if ($linecnt > $maxlines{$shortname}) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "$file $errmsg{$shortname} ".
			"(currently $linecnt lines).");
	} else {
		log_info(NO_FILE, NO_LINE_NUMBER, "$file has $linecnt lines.");
	}
	if ($longlines > 0) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "$file includes lines that exceed ".
			"$maxchars{$shortname} characters.");
	}
	if ($tmp =~ /[\033\200-\377]/) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "$file includes iso-8859-1, or ".
			"other local characters.  $file should be ".
			"plain ascii file.");
	}
	return 1;
}

sub checkfile_distinfo($) {
	local($file) = @_;	# distinfo
	local(%indistinfofile);
	my $line;

	checkperms("$opt_packagedir/$file");

	open(SUM,"<$opt_packagedir/$file") || return 0;
	$line = <SUM>;
	if ($line !~ /^\$NetBSD(:.*|)\$$/) {
	    log_error(NO_FILE, NO_LINE_NUMBER, "missing RCS Id in distinfo file: $_");
	}
	while(defined($line = <SUM>)) {
		next unless $line =~ /^(MD5|SHA1|RMD160) \(([^)]+)\) = (.*)$/;
		$alg=$1;
		$patch=$2;
		$sum=$3;

		# bitch about *~
		if ($patch =~ /~$/) {
			log_warning(NO_FILE, NO_LINE_NUMBER, "possible backup file '$patch' in $opt_packagedir/$file?");
		}

		if (-T "$opt_packagedir/$patchdir/$patch") {
			$calcsum=`sed -e '/\$NetBSD.*/d' $opt_packagedir/$patchdir/$patch | digest $alg`;
			chomp($calcsum);
			if ( "$sum" ne "$calcsum" ) {
				log_error(NO_FILE, NO_LINE_NUMBER, "checksum of $patch differs between $opt_packagedir/$file and\n"
				       ."       $opt_packagedir/$patchdir/$patch. Rerun '$conf_make makepatchsum'.");
			}
		} elsif ($patch =~ /^patch-[a-z0-9]+$/)  {
			log_error(NO_FILE, NO_LINE_NUMBER, "patchfile '$patch' is in $file\n"
			       ."       but not in $opt_packagedir/$patchdir/$patch. Rerun '$conf_make makepatchsum'.");
		}

		$indistinfofile{$patch} = 1;
	}
	close(SUM);

	foreach $patch ( <$opt_packagedir/$patchdir/patch-*> ) {
		$patch =~ /\/([^\/]+)$/;
		if (! $indistinfofile{$1}) {
			log_error(NO_FILE, NO_LINE_NUMBER, "patchsum of '$1' is in $opt_packagedir/$patchdir/$1 but not in\n"
			       ."       $file. Rerun '$conf_make makepatchsum'.");
		}
	}

	return 1;
}

sub checkfile_MESSAGE($) {
	local($file) = @_;
	local($longlines, $lastline, $tmp) = (0, "", "");
	my ($line);

	&checkperms("$opt_packagedir/$file");

	$shortname = basename($file);
	open(IN, "< $opt_packagedir/$file") || return 0;

	$line = <IN>;
	if ($line !~ /^={75}$/) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "$file should begin with a 75-character ".
			"double-dashed line.");
	}
	$line = <IN>;
	if ($line !~ /^\$NetBSD(:.*|)\$$/) {
		log_error(NO_FILE, NO_LINE_NUMBER, "missing RCS Id in MESSAGE file: $file");
	}
	while (defined($line = <IN>)) {
		$longlines++ if (80 < length($line));
		$lastline = $line;
		$tmp .= $line;
	}
	if ($lastline !~ /^={75}$/) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "$file should end with a 75-character ".
			"double-dashed line.");
	}
	if ($longlines > 0) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "$file includes lines that exceed ".
			"80 characters.");
	}
	if ($tmp =~ /[\033\200-\377]/) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "$file includes iso-8859-1, or ".
			"other local characters.  $file should be ".
			"plain ascii file.");
	}
	close(IN);
	return 1;
}

sub checkfile_PLIST($) {
	local($file) = @_;
	local($curdir) = ($conf_localbase);
	local($installinfoseen) = 0;
	local($rcsidseen) = 0;
	local($docseen) = 0;
	local($etcseen) = 0;
	my ($line);

	&checkperms("$opt_packagedir/$file");

	open(IN, "< $opt_packagedir/$file") || return 0;
	while (defined($line = <IN>)) {
		if ($line =~ /[ \t]+\n?$/) {
			log_warning(NO_FILE, NO_LINE_NUMBER, "$file $.: whitespace before end ".
				"of line.");
		}

		# make it easier to handle.
		$line =~ s/\s+$//;
		$line =~ s/\n$//;
		
	        if ($line =~ /<\$ARCH>/) {
		    log_warning(NO_FILE, NO_LINE_NUMBER, "$file $.: use of <\$ARCH> ".
			    "deprecated, use \${MACHINE_ARCH instead}.");
		}

		if ($line =~ /^\@/) {
			if ($line =~ /^\@(cwd|cd)[ \t]+(\S+)/) {
				$curdir = $2;
			} elsif ($line =~ /^\@unexec[ \t]+rmdir/) {
				log_warning(NO_FILE, NO_LINE_NUMBER, "use \"\@dirrm\" ".
					"instead of \"\@unexec rmdir\".");
			} elsif ($line =~ /^\@(un)?exec[ \t]+(.*\/)?(install-info|\$\{INSTALL_INFO\})/) {
				$installinfoseen = $.
			} elsif ($line =~ /^\@(exec|unexec)/) {
				if ($line =~ /ldconfig/ && $line !~ /\/usr\/bin\/true/) {
					log_error(NO_FILE, NO_LINE_NUMBER, "$file $.: ldconfig ".
						"must be used with ".
						"\"||/usr/bin/true\".");
				}
			} elsif ($line =~ /^\@(comment)/) {
				$rcsidseen++ if ($line =~ /\$$conf_rcsidstr[:\$]/);
			} elsif ($line =~ /^\@(dirrm|option)/) {
				; # no check made
			} elsif ($line =~ /^\@(mode|owner|group)/) {
				log_warning(NO_FILE, NO_LINE_NUMBER, "\"\@mode/owner/group\" are ".
					"deprecated, please use chmod/".
					"chown/chgrp in the pkg Makefile ".
					"and let tar do the rest.");
			} else {
				log_warning(NO_FILE, NO_LINE_NUMBER, "$file $.: ".
					"unknown PLIST directive \"$line\"");
			}
			next;
		}

		if ($line =~ /^\//) {
			log_error(NO_FILE, NO_LINE_NUMBER, "$file $.: use of full pathname ".
				"disallowed.");
		}

		if ($line =~ /^doc/ and !$docseen) {
			log_error(NO_FILE, NO_LINE_NUMBER, "documentation must be installed under ".
				"share/doc, not doc.");
			$docseen = 1;
		}

		if ($line =~ /^etc/ && $line !~ /^etc\/rc.d/ and !$etcseen) {
			log_error(NO_FILE, NO_LINE_NUMBER, "configuration files must not be ".
				"registered in the PLIST (don't you use the ".
				"PKG_SYSCONFDIR framework?)");
			$etcseen = 1;
		}

		if ($line =~ /etc\/rc\.d/ and !$etcrcdseen) {
			log_error(NO_FILE, NO_LINE_NUMBER, "RCD_SCRIPTS must not be ".
				"registered in the PLIST (don't you use the ".
				"RCD_SCRIPTS framework?)");
			$etcrcdseen = 1;
		}

		if ($line =~ /^info\/dir$/) {
			log_error(NO_FILE, NO_LINE_NUMBER, "\"info/dir\" should not be listed in ".
				"$file. use install-info to add/remove ".
				"an entry.");
		}

		if ($line =~ /^lib\/locale/) {
			log_error(NO_FILE, NO_LINE_NUMBER, "\"lib/locale\" should not be listed ".
				"in $file. Use \${PKGLOCALEDIR}/locale and ".
				"set USE_PKGLOCALEDIR instead.");
		}

		if ($line =~ /^share\/locale/) {
			log_warning(NO_FILE, NO_LINE_NUMBER, "use of \"share/locale\" in $file is ".
				"deprecated.  Use \${PKGLOCALEDIR}/locale and ".
				"set USE_PKGLOCALEDIR instead.");
		}

		if ($line =~ /\${PKGLOCALEDIR}/ && $seen_USE_BUILDLINK2 && ! $seen_USE_PKGLOCALEDIR) {
			log_warning(NO_FILE, NO_LINE_NUMBER, "PLIST contains \${PKGLOCALEDIR}, ".
				"but USE_PKGLOCALEDIR was not found.");
		}

		if ($curdir !~ m#^$conf_localbase#
		 && $curdir !~ m#^/usr/X11R6#) {
			log_warning(NO_FILE, NO_LINE_NUMBER, "$file $.: installing to ".
				"directory $curdir discouraged. ".
				"could you please avoid it?");
		}

		if ("$curdir/$line" =~ m#^$conf_localbase/share/doc#) {
			log_info(NO_FILE, NO_LINE_NUMBER, "seen installation to share/doc in $file. ".
				"($curdir/$line)");
			$sharedocused++;
		}
	}

	if (!$rcsidseen) {
		log_error(NO_FILE, NO_LINE_NUMBER, "RCS tag \"\$$conf_rcsidstr\$\" must be present ".
			"in $file as \@comment.")
	}
	if ($installinfoseen) {
		log_error(NO_FILE, NO_LINE_NUMBER, "\"\@exec install-info ...\" or \"\@unexec ".
			"install-info ...\" is deprecated.");
	}
	close(IN);
	return 1;
}

sub checkperms($) {
	local($file) = @_;

	if (-f $file && -x $file) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "\"$file\" is executable.");
	}
	return 1;
}

#
# misc files
#
sub checkpathname($) {
	local($file) = @_;
	local($whole);

	checkperms("$opt_packagedir/$file");

	if ($file =~ /$filesdir\//) {
		return 1;
	}

	open(IN, "< $opt_packagedir/$file") || return 0;
	{ local $/; $whole = <IN>; }
	close(IN);
	abspathname($whole, $file);
	return 1;
}

sub checklastline($) {
	local($file) = @_;
	local($whole);

	open(IN, "< $opt_packagedir/$file") || return 0;
	{ local $/; $whole = <IN>; }
	close(IN);
	if ($whole eq "") {
		log_error(NO_FILE, NO_LINE_NUMBER, "$file is empty.");
	}
	else 
	{
		if ($whole !~ /\n$/) {
			log_error(NO_FILE, NO_LINE_NUMBER, "the last line of $file has to be ".
				"terminated by \\n.");
		}
		if ($whole =~ /\n([ \t]*\n)+$/) {
			log_warning(NO_FILE, NO_LINE_NUMBER, "$file seems to have unnecessary ".
				"blank lines at the bottom.");
		}
	}
	return 1;
}

sub checkfile_patches_patch($) {
	my ($file) = @_;
	my ($rcsidseen, $whole, @lines, $line);
	$rcsidseen = 0;

	if ($file =~ /.*~$/) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "is $file a backup file? If so, please remove it \n"
		       ."      and rerun '$conf_make makepatchsum'");
	}

	&checkperms("$opt_packagedir/$file");

	open(IN, "< $opt_packagedir/$file") || return 0;
	$whole = '';
	while (defined($line = <IN>)) {
		$rcsidseen++ if ($line =~ /\$$conf_rcsidstr[:\$]/);
		$whole .= $line;
		push(@lines, $line);
	}
	if ($opt_committer && $whole =~ /.\$(Author|Date|Header|Id|Locker|Log|Name|RCSfile|Revision|Source|State|NetBSD)(:.*\$|\$)/) { # XXX
	        # RCS ID in very first line is ok, to identify version
	        # of patch (-> only warn if there's something before the
	        # actual $RCS_ID$, not on BOF - '.' won't match there)
		log_warning(NO_FILE, NO_LINE_NUMBER, "$file includes possible RCS tag \"\$$1\$\". ".
			"use binary mode (-ko) on commit/import.");
	}
	if (!$rcsidseen) {
		log_error(NO_FILE, NO_LINE_NUMBER, "RCS tag \"\$$conf_rcsidstr\$\" must be present ".
			"in patch $file.")
	}
	close(IN);

	$files_in_patch = 0;
	$patch_state = "";
	foreach my $patch_line (@lines) {
	    chomp($patch_line);
	    if (index($patch_line, "--- ") == 0 && $patch_line !~ qr"^--- \d+,\d+ ----$") {
	        $line_type = "-";
	    } elsif (index($patch_line, "*** ") == 0 && $patch_line !~ qr"^\*\*\* \d+,\d+ \*\*\*\*$") {
	        $line_type = "*";
	    } elsif (index($patch_line, "+++ ") == 0) {
	        $line_type = "+";
	    } else {
	        $line_type = "";
	    }
	    if ($patch_state eq "*") {
	        if ($line_type eq "-") {
		    $files_in_patch++;
		    $patch_state = "";
		} else {
	            log_warning(NO_FILE, NO_LINE_NUMBER, "$i:$.: unknown patch format (might be an internal error)");
		}
	    } elsif ($patch_state eq "-") {
	        if ($line_type eq "+") {
		    $files_in_patch++;
		    $patch_state = "";
		} else {
		    log_warning(NO_FILE, NO_LINE_NUMBER, "$i:$.: unknown patch format (might be an internal error)");
		}
	    } elsif ($patch_state eq "") {
	        $patch_state = $line_type;
	    }
	    #printf("%s:%d: state=(%s), line=(%s)\n", $i, $., $patch_state, $line_type);
	}
	if ($files_in_patch > 1) {
	    log_warning(NO_FILE, NO_LINE_NUMBER, "patch `$i' contains patches for more than one file, namely $files_in_patch");
	} elsif ($files_in_patch == 0) {
	    log_warning(NO_FILE, NO_LINE_NUMBER, "patch `$i' contains no patch");
	}
	return 1;
}

sub readmakefile($) {
	local ($file) = @_;
	local $contents = "";
	local $includefile;
	local $dirname;
	local $savedln;
	local $level;
	my $handle = new FileHandle;
	my $line;

	$savedln = $.;
	$. = 0;
	open($handle, "< $file") || return 0;
	log_info($file, NO_LINE_NUMBER, "called readmakefile");
	while (defined($line = <$handle>)) {
		if ($line =~ /[ \t]+\n?$/ && $line !~ /^#/) {
			log_warning(NO_FILE, NO_LINE_NUMBER, "$file $.: whitespace before ".
				"end of line.");
		}
		if ($line =~ /^\040{8}/) {
			log_warning(NO_FILE, NO_LINE_NUMBER, "$file $.: use tab (not spaces) to".
				" make indentation.");
		}
		if ($line =~ /^\.\s*if\s+!defined\s*\((\w+)\)/) {
			if ($definesfound{$1}) {
				$level = 1;
				log_info($file, $., "omitting contents of !defined($1)\n");
				$contents .= "# omitted inclusion for !defined($1) here\n";
				while (defined($line = <$handle>)) {
					if ($line =~ /^\.\s*if\s+/) {
						$level++;
					}
					elsif ($line =~ /^\.\s*endif\s+/) {
						$level--;
					}
					if ($level eq 0) {
						last;
					}
				}
				if ($level > 0) {
					log_warning(NO_FILE, NO_LINE_NUMBER, "missing .endif.");
				}
				next;
			}
			else {
				log_info($file, $., "defining $1");
				$definesfound{$1} = 1;
			}
		}
		# try to get any included file
		if ($line =~ /^.include\s+([^\n]+)\n/) {
			$includefile = $1;
			if ($includefile =~ /\"([^\"]+)\"/) {
				$includefile = $1;
			}
			if ($includefile =~ /\/mk\/texinfo\.mk/) {
				log_error(NO_FILE, NO_LINE_NUMBER, "do not include $includefile");
			}
			if ($includefile =~ /\/mk\/bsd/) {
				# we don't want to include the whole
				# bsd.pkg.mk or bsd.prefs.mk files
				$contents .= $line;
			} else {
				$dirname = dirname($file);
                                if (-e "$dirname/$includefile") {
                                    log_info($file, $., "including $dirname/$includefile");
                                    $contents .= readmakefile("$dirname/$includefile");
                                }
                                else {
                                    log_error(NO_FILE, NO_LINE_NUMBER, "can't read $dirname/$includefile");
                                }
			}
		} else {
			# we don't want the include Makefile.common lines
			# to be pkglinted
			$contents .= $line;
		}
	}
	close($handle);

	$. = $savedln;
	return $contents;
}

sub checkfile_Makefile($) {
	local($file) = @_;
	local($rawwhole, $whole, $idx, @sections);
	local($tmp, $tmp2);
	local($i, $j, $k, $l);
	local(@varnames) = ();
	local($distfiles, $pkgname, $svrpkgname, $distname,
	      $extractsufx) = ('', '', '', '', '');
	local($bogusdistfiles) = (0);
	local($realwrksrc, $wrksrc, $nowrksubdir) = ('', '', '');
	local($includefile);

	&checkperms("$opt_packagedir/$file");

	$tmp = 0;
	$rawwhole = readmakefile("$opt_packagedir/$file");
	if ($rawwhole eq '') {
		log_error(NO_FILE, NO_LINE_NUMBER, "can't read $opt_packagedir/$file");
		return 0;
	}
	else {
		print("OK: whole Makefile (with all included files):\n".
		      "$rawwhole\n") if ($opt_dumpmakefile);
	}

	#
	# whole file: blank lines.
	#
	$whole = "\n" . $rawwhole;
	log_info(NO_FILE, NO_LINE_NUMBER, "checking contiguous blank lines in $file.");
	$i = "\n" x ($opt_contblank + 2);
	if ($whole =~ /$i/) {
		log_error(NO_FILE, NO_LINE_NUMBER, "contiguous blank lines (> $opt_contblank lines) found ".
			"in $file at line " . int(@_ = split(/\n/, $`)) . ".");
	}

	#
	# whole file: $(VARIABLE)
	#
	if ($opt_parenwarn) {
		log_info(NO_FILE, NO_LINE_NUMBER, "checking for \$(VARIABLE).");
		if ($whole =~ /\$\([\w\d]+\)/) {
			log_warning(NO_FILE, NO_LINE_NUMBER, "use \${VARIABLE}, instead of ".
				"\$(VARIABLE).");
		}
	}

	#
	# whole file: get FILESDIR, PATCHDIR, PKGDIR, SCRIPTDIR,
	# PATCH_SUM_FILE and DIGEST_FILE
	#
	log_info(NO_FILE, NO_LINE_NUMBER, "checking for PATCHDIR, SCRIPTDIR, FILESDIR, PKGDIR,".
	    " DIGEST_FILE.");

	$filesdir = "files";
	$filesdir = $1 if ($whole =~ /\nFILESDIR[+?]?=[ \t]*([^\n]+)\n/);
	$filesdir = $1 if ($whole =~ /\nFILESDIR:?=[ \t]*([^\n]+)\n/);
	$filesdir =~ s/\$\{.CURDIR\}/./;

	$patchdir = "patches";
	$patchdir = $1 if ($whole =~ /\nPATCHDIR[+?]?=[ \t]*([^\n]+)\n/);
	$patchdir = $1 if ($whole =~ /\nPATCHDIR:?=[ \t]*([^\n]+)\n/);
	$patchdir =~ s/\$\{.CURDIR\}/./;
	$patchdir =~ s/\${PKGSRCDIR}/..\/../;

	$pkgdir = "pkg";
	if (! -d "$opt_packagedir/$pkgdir") {
	    $pkgdir = ".";
	}
	$pkgdir = $1 if ($whole =~ /\nPKGDIR[+?]?=[ \t]*([^\n]+)\n/);
	$pkgdir = $1 if ($whole =~ /\nPKGDIR:?=[ \t]*([^\n]+)\n/);
	$pkgdir =~ s/\$\{.CURDIR\}/./;

	$scriptdir = "scripts";
	$scriptdir = $1 if ($whole =~ /\nSCRIPTDIR[+?]?=[ \t]*([^\n]+)\n/);
	$scriptdir = $1 if ($whole =~ /\nSCRIPTDIR:?=[ \t]*([^\n]+)\n/);
	$scriptdir =~ s/\$\{.CURDIR\}/./;

	$distinfo = "distinfo";
	$distinfo = $1 if ($whole =~ /\nDISTINFO_FILE[+?]?=[ \t]*([^\n]+)\n/);
	$distinfo = $1 if ($whole =~ /\nDISTINFO_FILE:?=[ \t]*([^\n]+)\n/);
	$distinfo =~ s/\$\{.CURDIR\}/./;
	$distinfo =~ s/\${PKGSRCDIR}/..\/../;

	log_info(NO_FILE, NO_LINE_NUMBER, "PATCHDIR: $patchdir, SCRIPTDIR: $scriptdir, ".
	      "FILESDIR: $filesdir, PKGDIR: $pkgdir, ".
	      "DISTINFO: $distinfo\n");

	#
	# whole file: INTERACTIVE_STAGE
	#
	$whole =~ s/\n#[^\n]*/\n/g;
	$whole =~ s/\n\n+/\n/g;
	log_info(NO_FILE, NO_LINE_NUMBER, "checking INTERACTIVE_STAGE.");
	if ($whole =~ /\nINTERACTIVE_STAGE/) {
		if ($whole !~ /defined\((BATCH|FOR_CDROM)\)/) {
			log_warning(NO_FILE, NO_LINE_NUMBER, "use of INTERACTIVE_STAGE discouraged. ".
				"provide batch mode by using BATCH and/or ".
				"FOR_CDROM.");
		}
	}
	log_info(NO_FILE, NO_LINE_NUMBER, "checking IS_INTERACTIVE.");
	if ($whole =~ /\nIS_INTERACTIVE/) {
		log_error(NO_FILE, NO_LINE_NUMBER, "IS_INTERACTIVE is deprecated, ".
			"use INTERACTIVE_STAGE instead.");
	}
	log_info(NO_FILE, NO_LINE_NUMBER, "checking for PLIST_SRC.");
	if ($whole =~ /\nPLIST_SRC/) {
		$seen_PLIST_SRC=1;
	}
	log_info(NO_FILE, NO_LINE_NUMBER, "checking for NO_PKG_REGISTER.");
	if ($whole =~ /\nNO_PKG_REGISTER/) {
		$seen_NO_PKG_REGISTER=1;
	}
	log_info(NO_FILE, NO_LINE_NUMBER, "checking for NO_CHECKSUM.");
	if ($whole =~ /\nNO_CHECKSUM/) {
		$seen_NO_CHECKSUM=1;
	}
	log_info(NO_FILE, NO_LINE_NUMBER, "checking USE_PERL usage.");
	if ($whole =~ /\nUSE_PERL[^5]/) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "USE_PERL found -- you probably mean USE_PERL5.");
	}
	log_info(NO_FILE, NO_LINE_NUMBER, "checking USE_PKGLIBTOOL.");
	if ($whole =~ /\nUSE_PKGLIBTOOL/) {
		log_error(NO_FILE, NO_LINE_NUMBER, "USE_PKGLIBTOOL is deprecated, ".
			"use USE_LIBTOOL instead.");
	}
	log_info(NO_FILE, NO_LINE_NUMBER, "checking for USE_BUILDLINK2.");
	if ($whole =~ /\nUSE_BUILDLINK2/) {
		$seen_USE_BUILDLINK2=1;
	}
	log_info(NO_FILE, NO_LINE_NUMBER, "checking for USE_PKGLOCALEDIR.");
	if ($whole =~ /\nUSE_PKGLOCALEDIR/) {
		$seen_USE_PKGLOCALEDIR=1;
	}
	log_info(NO_FILE, NO_LINE_NUMBER, "checking USE_SSL.");
	if ($whole =~ /\nUSE_SSL/) {
		log_error(NO_FILE, NO_LINE_NUMBER, "USE_SSL is deprecated, ".
			"use the openssl buildlink2.mk instead.");
	}
	log_info(NO_FILE, NO_LINE_NUMBER, "checking NO_WRKSUBDIR.");
	if ($whole =~ /\nNO_WRKSUBDIR/) {
		log_error(NO_FILE, NO_LINE_NUMBER, "NO_WRKSUBDIR is deprecated, ".
			"use WRKSRC=\$\{WRKDIR\} instead.");
	}
	log_info(NO_FILE, NO_LINE_NUMBER, "checking MD5_FILE, DIGEST_FILE and PATCH_SUM_FILE.");
	if ($whole =~ /\n(MD5_FILE)/ or $whole =~ /\n(DIGEST_FILE)/ or
		$whole =~ /\n(PATCH_SUM_FILE)/) {
		log_error(NO_FILE, NO_LINE_NUMBER, "$1 is deprecated, ".
			"use DISTINFO_FILE instead.");
	}
	log_info(NO_FILE, NO_LINE_NUMBER, "checking MIRROR_DISTFILE.");
	if ($whole =~ /\nMIRROR_DISTFILE/) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "use of MIRROR_DISTFILE deprecated, ".
			"use NO_BIN_ON_FTP and/or NO_SRC_ON_FTP instead.");
	}
	log_info(NO_FILE, NO_LINE_NUMBER, "checking NO_CDROM.");
	if ($whole =~ /\nNO_CDROM/) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "use of NO_CDROM discouraged, ".
			"use NO_BIN_ON_CDROM and/or NO_SRC_ON_CDROM instead.");
	}
	log_info(NO_FILE, NO_LINE_NUMBER, "checking NO_PACKAGE.");
	if ($whole =~ /\nNO_PACKAGE/) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "use of NO_PACKAGE to enforce license ".
			"restrictions is deprecated.");
	}
	log_info(NO_FILE, NO_LINE_NUMBER, "checking NO_PATCH.");
	if ($whole =~ /\nNO_PATCH/) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "use of NO_PATCH deprecated.");
	}
	log_info(NO_FILE, NO_LINE_NUMBER, "checking IGNORE.");
	if ($whole =~ /\nIGNORE/) {
		log_error(NO_FILE, NO_LINE_NUMBER, "use of IGNORE deprecated, ".
			"use PKG_FAIL_REASON or PKG_SKIP_REASON instead.");
	}
	log_info(NO_FILE, NO_LINE_NUMBER, "checking USE_GMAKE.");
	if ($whole =~ /\nUSE_GMAKE/) {
		log_error(NO_FILE, NO_LINE_NUMBER, "use of USE_GMAKE deprecated, ".
			"use USE_GNU_TOOLS+=make instead.");
	}
	log_info(NO_FILE, NO_LINE_NUMBER, "checking for MKDIR.");
	if ($whole =~ m|\${MKDIR}.*(\${PREFIX}[/0-9a-zA-Z\${}]*)|) {
	    	log_warning(NO_FILE, NO_LINE_NUMBER, "\${MKDIR} $1: consider using INSTALL_*_DIR");
	}
	log_info(NO_FILE, NO_LINE_NUMBER, "checking for unneeded INSTALL -d.");
	if ($whole =~ m|\${INSTALL}(.*)\n|) {
	    $args = $1;
	    	if ($args =~ /-d/) {
		        if ($args !~ /-[ogm]/) {
		    		log_warning(NO_FILE, NO_LINE_NUMBER, "\${INSTALL}$args: " .
					"consider using INSTALL_*_DIR");
		        }
		}
	}
	log_info(NO_FILE, NO_LINE_NUMBER, "checking for unneeded failure check on directory creation.");
	if ($whole =~ /\n\t-(.*(MKDIR|INSTALL.*-d|INSTALL_.*_DIR).*)/g) {
	    	log_warning(NO_FILE, NO_LINE_NUMBER, "$1: no need to use '-' before command");
	}

	#
	# whole file: direct use of command names
	#
	log_info(NO_FILE, NO_LINE_NUMBER, "checking direct use of command names.");
	foreach $i (split(/\s+/, <<EOF)) {
awk basename cat chmod chown chgrp cmp cp cut digest dirname echo egrep false
file find gmake grep gtar gzcat id ident install ldconfig ln md5 mkdir mtree mv
patch pax pkg_add pkg_create pkg_delete pkg_info rm rmdir sed setenv sh sort
su tail test touch tr true type wc xmkmf
EOF
		$cmdnames{$i} = "\$\{\U$i\E\}";
	}
	$cmdnames{'file'} = '${FILE_CMD}';
	$cmdnames{'gunzip'} = '${GUNZIP_CMD}';
	$cmdnames{'gzip'} = '${GZIP_CMD}';
	#
	# ignore parameter string to echo command.
	# note that we leave the command as is, since we need to check the
	# use of echo itself.
	$j = $whole;
	$j =~ s/([ \t][\@-]?)(echo|\$[\{\(]ECHO[\}\)]|\$[\{\(]ECHO_MSG[\}\)])[ \t]+("(\\'|\\"|[^"])*"|'(\\'|\\"|[^'])*')[ \t]*[;\n]/$1$2;/;
	# no need to check comments...
	$j =~ s/\n#[\n]*/\n#/;
	# ...nor COMMENTs
	$j =~ s/\nCOMMENT[\t ]*=[\t ]*[^\n]*\n/\nCOMMENT=#replaced\n/;
	foreach $i (keys %cmdnames) {
		if ($j =~ /[ \t\/@]$i[ \t\n;]/) {
			log_warning(NO_FILE, NO_LINE_NUMBER, "possible direct use of command \"$i\" ".
				"found. Use $cmdnames{$i} instead.");
		}
	}

	#
	# whole file: ldconfig must come with "true" command
	#
	if ($j =~ /(ldconfig|\$[{(]LDCONFIG[)}])/
	 && $j !~ /(\/usr\/bin\/true|\$[{(]TRUE[)}])/) {
		log_error(NO_FILE, NO_LINE_NUMBER, "ldconfig must be used with \"||\${TRUE}\".");
	}

	#
	# whole file: ${MKDIR} -p
	#
	if ($j =~ /\${MKDIR}\s+-p/) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "possible use of \"\${MKDIR} -p\" ".
			"found. \${MKDIR} includes \"-p\" by default.");
	}
	#
	# whole file: continuation line in DEPENDS
	#
	if ($whole =~ /\n(BUILD_|)DEPENDS[^\n]*\\\n/) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "Please don't use continuation lines in".
			" (BUILD_)DEPENDS, use (BUILD_)DEPENDS+= instead.");
	}

	# whole file: check for pkgsrc-wip remnants
	#
	if ($whole =~ /\/wip\//
	 && $category ne "wip") {
		log_error(NO_FILE, NO_LINE_NUMBER, "possible pkgsrc-wip pathname detected.");
	}

	if ($whole =~ /etc\/rc\.d/) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "Use RCD_SCRIPTS mechanism to install rc.d ".
			"scripts automatically to \${RCD_SCRIPTS_EXAMPLEDIR}.");
	}

	#
	# whole file: full path name
	#
	&abspathname($whole, $file);

	#
	# break the makefile into sections.
	#
	@sections = split(/\n\n+/, $rawwhole);
	for ($i = 0; $i < scalar(@sections); $i++) {
		if ($sections[$i] !~ /\n$/) {
			$sections[$i] .= "\n";
		}
	}
	$idx = 0;

	#
	# section 1: comment lines.
	#
	log_info(NO_FILE, NO_LINE_NUMBER, "checking comment section of $file.");
	$tmp = $sections[$idx++];
	if ($tmp !~ /#(\s+)\$$conf_rcsidstr([^\$]*)\$/) {
		log_error(NO_FILE, NO_LINE_NUMBER, "no \$$conf_rcsidstr\$ line in $file comment ".
			"section.");
	} else {
		log_info(NO_FILE, NO_LINE_NUMBER, "\$$conf_rcsidstr\$ seen in $file.");
		if ($1 ne ' ') {
			log_warning(NO_FILE, NO_LINE_NUMBER, "please use single whitespace ".
				"right before \$$conf_rcsidstr\$ tag.");
		}
		if ($2 ne '') {
			if ($opt_verbose || $opt_newpackage) {	# XXX
				log_warning(NO_FILE, NO_LINE_NUMBER, "".
				    ($opt_newpackage ? 'for new package, '
					      : 'is it a new package? if so, ').
				    "make \$$conf_rcsidstr\$ tag in comment ".
				    "section empty, to make CVS happy.");
			}
		}
	}

	#
	# for the rest of the checks, comment lines are not important.
	#
	for ($i = 0; $i < scalar(@sections); $i++) {
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
	log_info(NO_FILE, NO_LINE_NUMBER, "checking first section of $file. (DISTNAME/...)");
	$tmp = $sections[$idx++];

	# check the order of items.
        @tocheck=split(/\s+/, <<EOF);
DISTNAME PKGNAME PKGREVISION SVR4_PKGNAME CATEGORIES MASTER_SITES
DYNAMIC_MASTER_SITES MASTER_SITE_SUBDIR EXTRACT_SUFX DISTFILES
EOF
	push(@tocheck,"ONLY_FOR_ARCHS");
	push(@tocheck,"NO_SRC_ON_FTP");
	push(@tocheck,"NO_BIN_ON_FTP");
        &checkorder('DISTNAME', $tmp, @tocheck);

	# check the items that has to be there.
	$tmp = "\n" . $tmp;
	foreach $i ('DISTNAME', 'CATEGORIES') {
		if ($tmp !~ /\n$i=/) {
			log_error(NO_FILE, NO_LINE_NUMBER, "$i has to be there.");
		}
		if ($tmp =~ /\n$i(\?=)/) {
			log_error(NO_FILE, NO_LINE_NUMBER, "$i has to be set by \"=\", ".
				"not by \"$1\".");
		}
	}

	# check for pkgsrc-wip remnants in CATEGORIES
	if ($tmp =~ /\nCATEGORIES=[ \t]*.*wip.*\n/
	 && $category ne "wip") {
		log_error(NO_FILE, NO_LINE_NUMBER, "don't forget to remove \"wip\" from CATEGORIES.");
	}

	# check the URL
	if ($tmp =~ /\nMASTER_SITES[+?]?=[ \t]*([^\n]*)\n/
	 && $1 !~ /^[ \t]*$/) {
		log_info(NO_FILE, NO_LINE_NUMBER, "seen MASTER_SITES, sanity checking URLs.");
		@sites = split(/\s+/, $1);
		foreach $i (@sites) {
			if ($i =~ m#^\w+://#) {
				if ($i !~ m#/$#) {
					log_error(NO_FILE, NO_LINE_NUMBER, "URL \"$i\" should ".
						"end with \"/\".");
				}
				if ($i =~ m#://[^/]*:/#) {
					log_error(NO_FILE, NO_LINE_NUMBER, "URL \"$i\" contains ".
						"extra \":\".");
				}
				unless (&is_predefined($i)) {
					log_info(NO_FILE, NO_LINE_NUMBER, "URL \"$i\" ok.");
				}
			} else {
				log_info(NO_FILE, NO_LINE_NUMBER, "non-URL \"$i\" ok.\n");
			}
		if ($tmp =~ /\nDYNAMIC_MASTER_SITES[+?]?=/) {
			log_warning(NO_FILE, NO_LINE_NUMBER, "MASTER_SITES and DYNAMIC_MASTER_SITES ".
				"found. Is this ok?");
			}
		}
	} elsif ($tmp !~ /\nDYNAMIC_MASTER_SITES[+?]?=/) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "no MASTER_SITES or DYNAMIC_MASTER_SITES found. ".
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
		log_info(NO_FILE, NO_LINE_NUMBER, "seen EXTRACT_SUFX, checking value.");
		if ($distfiles ne '' && ($extractsufx eq '.tar.gz')) {
			log_warning(NO_FILE, NO_LINE_NUMBER, "no need to define EXTRACT_SUFX if ".
				"DISTFILES is defined.");
		}
		if ($extractsufx eq '.tar.gz') {
			log_warning(NO_FILE, NO_LINE_NUMBER, "EXTRACT_SUFX is \".tar.gz.\" ".
				"by default. you don't need to specify it.");
		}
	} else {
		log_info(NO_FILE, NO_LINE_NUMBER, "no EXTRACT_SUFX seen, using default value.");
		$extractsufx = '.tar.gz';
	}

	log_info(NO_FILE, NO_LINE_NUMBER, "sanity checking PKGNAME.");
	if ($pkgname ne '' && $pkgname eq $distname) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "PKGNAME is \${DISTNAME} by default, ".
			"you don't need to define PKGNAME.");
	}
	if ($svrpkgname ne '') {
		if (length($svrpkgname) > 5) {
			log_error(NO_FILE, NO_LINE_NUMBER, "SVR4_PKGNAME should not be longer ".
				"than 5 characters.");
		}
	}
	$i = ($pkgname eq '') ? $distname : $pkgname;
	$i =~ s/\${DISTNAME[^}]*}/$distname/g;
	if ($i =~ /-([^-]+)$/) {
		$j = $`;
		$k = $1;
		if ($j =~ /[0-9]$/) {
			log_warning(NO_FILE, NO_LINE_NUMBER, "is \"$j\" sane as package name ".
				"WITHOUT version number? ".
				"if not, avoid \"-\" in version number ".
				"part of ".
				(($pkgname eq '') ? "DISTNAME." : "PKGNAME."));
		}
		# Be very smart. Kids, don't do this at home.
		if ($k =~ /\$(\(|\{)([A-Z_-]+)(\)|\})/) {
			$k1 = $2;
			$k = $1 if ($rawwhole =~ /\n$k1[ \t]*?=[ \t]*([^\n]+)\n/);
		}
		if ($k =~ /^pl[0-9]*$/
		 || $k =~ /^[0-9]*[A-Za-z]*[0-9]*(\.[0-9]*[A-Za-z]*[0-9]*)*$/) {
			log_info(NO_FILE, NO_LINE_NUMBER, "trailing part of PKGNAME\"-$k\" ".
				"looks fine.");
		} else {
			log_error(NO_FILE, NO_LINE_NUMBER, "version number part of PKGNAME".
				(($pkgname eq '')
					? ', which is derived from DISTNAME, '
					: ' ').
				"looks illegal. You should modify \"-$k\"");
		}
	} else {
		log_error(NO_FILE, NO_LINE_NUMBER, "PKGNAME".
			(($pkgname eq '')
				? ', which is derived from DISTNAME, '
				: ' ').
			"must come with version number, like \"foobaa-1.0\".");
		if ($i =~ /_pl[0-9]*$/
		 || $i =~ /_[0-9]*[A-Za-z]?[0-9]*(\.[0-9]*[A-Za-z]?[0-9]*)*$/) {
			log_error(NO_FILE, NO_LINE_NUMBER, "you seem to be using underline ".
				"before version number in PKGNAME. ".
				"it has to be hyphen.");
		}
	}
	if ($distname =~ /(nb\d*)/) {
			log_warning(NO_FILE, NO_LINE_NUMBER, "is '$1' really ok on DISTNAME, ".
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
		log_info(NO_FILE, NO_LINE_NUMBER, "seen DISTFILES with single item, checking value.");
		log_warning(NO_FILE, NO_LINE_NUMBER, "use of DISTFILES with single file ".
			"discouraged. distribution filename should be set by ".
			"DISTNAME and EXTRACT_SUFX.");
		if ($distfiles eq $distname . $extractsufx) {
			log_warning(NO_FILE, NO_LINE_NUMBER, "definition of DISTFILES not necessary. ".
				"DISTFILES is \${DISTNAME}/\${EXTRACT_SUFX} ".
				"by default.");
		}

		# make an advice only in certain cases.
		if ($pkgname ne '' && $distfiles =~ /^$pkgname([-\.].+)$/) {
			log_warning(NO_FILE, NO_LINE_NUMBER, "how about \"DISTNAME=$pkgname\"".
				(($1 eq '.tar.gz')
					? ""
					: " and \"EXTRACT_SUFX=$1\"").
				", instead of DISTFILES?");
		}
	}

	# additional checks for committer.
	$i = ($pkgname eq '') ? $distname : $pkgname;
	if ($opt_committer && -f "$opt_packagedir/$i.tgz") {
		log_warning(NO_FILE, NO_LINE_NUMBER, "be sure to remove $opt_packagedir/$i.tgz ".
			"before committing the package.");
	}

	push(@varnames, split(/\s+/, <<EOF));
DISTNAME PKGNAME SVR4_PKGNAME CATEGORIES MASTER_SITES MASTER_SITE_SUBDIR
EXTRACT_SUFX DISTFILES
EOF

	#
	# section 3: PATCH_SITES/PATCHFILES(optional)
	#
	log_info(NO_FILE, NO_LINE_NUMBER, "checking second section of $file, (PATCH*: optional).");
	$tmp = $sections[$idx];

	if ($tmp =~ /(PATCH_SITES|PATCH_SITE_SUBDIR|PATCHFILES|PATCH_DIST_STRIP)/) {
		&checkearlier($tmp, @varnames);

                $tmp = "\n$tmp";

		if ($tmp =~ /\n(PATCH_SITES)=/) {
			log_info(NO_FILE, NO_LINE_NUMBER, "seen PATCH_SITES.");
			$tmp =~ s/$1[^\n]+\n//;
		}
		if ($tmp =~ /\n(PATCH_SITE_SUBDIR)=/) {
			log_info(NO_FILE, NO_LINE_NUMBER, "seen PATCH_SITE_SUBDIR.");
			$tmp =~ s/$1[^\n]+\n//;
		}
		if ($tmp =~ /\n(PATCHFILES)=/) {
			log_info(NO_FILE, NO_LINE_NUMBER, "seen PATCHFILES.");
			$tmp =~ s/$1[^\n]+\n//;
		}
		if ($tmp =~ /\n(PATCH_DIST_ARGS)=/) {
			log_info(NO_FILE, NO_LINE_NUMBER, "seen PATCH_DIST_ARGS.");
			$tmp =~ s/$1[^\n]+\n//;
		}
		if ($tmp =~ /\n(PATCH_DIST_STRIP)=/) {
			log_info(NO_FILE, NO_LINE_NUMBER, "seen PATCH_DIST_STRIP.");
			$tmp =~ s/$1[^\n]+\n//;
		}

		&checkextra($tmp, 'PATCH_SITES');

		$idx++;
	}

	push(@varnames, split(/\s+/, <<EOF));
PATCH_SITES PATCHFILES PATCH_DIST_STRIP
EOF

	#
	# section 4: MAINTAINER
	#
	log_info(NO_FILE, NO_LINE_NUMBER, "checking third section of $file (MAINTAINER).");
	$tmp = $sections[$idx++];

	# check the order of items.
        @tocheck=split(/\s+/, <<EOF);
MAINTAINER HOMEPAGE COMMENT
EOF

        &checkorder('MAINTAINER', $tmp, @tocheck);

	# warnings for missing or incorrect HOMEPAGE
	$tmp = "\n" . $tmp;
	if ($tmp !~ /\nHOMEPAGE[+?]?=[ \t]*([^\n]*)\n/ || $1 =~ /^[ \t]*$/) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "please add HOMEPAGE if the package has one.");
	} else {
		$i = $1;
		if ($i =~ m#^\w+://#) {
			if ($i !~ m#^\w+://[^\n/]+/#) {
				log_warning(NO_FILE, NO_LINE_NUMBER, "URL \"$i\" does not ".
						"end with \"/\".");
			}
		}
	}

	# warnings for missing COMMENT
	if ($tmp !~ /\nCOMMENT=\s*(.*)$/) {
		log_error(NO_FILE, NO_LINE_NUMBER, "please add a short COMMENT describing the package.");
	}
	# and its properties:
	$tmp2 = $1;
	if ($tmp2 =~ /\.$/i) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "COMMENT should not end with a '.' (period).");
	}
	if ($tmp2 =~ /^(a|an) /i) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "COMMENT should not begin with '$1 '.");
	}
	if ($tmp2 =~ /^[a-z]/) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "COMMENT should start with a capital letter.");
	}
	if (length($tmp2) > 70) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "COMMENT should not be longer than 70 characters.");
	}

	&checkearlier($tmp, @varnames);
	$tmp = "\n" . $tmp;
	if ($tmp =~ /\nMAINTAINER=[^@]+\@netbsd.org/) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "\@netbsd.org should be \@NetBSD.org in MAINTAINER.");
	} elsif ($tmp =~ /\nMAINTAINER=[^\n]+/) {
		$tmp =~ s/\nMAINTAINER=[^\n]+//;
	} else {
		log_error(NO_FILE, NO_LINE_NUMBER, "no MAINTAINER listed in $file.");
                # Why is this fatal? There's a default in bsd.pkg.mk - HF
	}
	$tmp =~ s/\n\n+/\n/g;

	push(@varnames, split(/\s+/, <<EOF));
MAINTAINER HOMEPAGE COMMENT
EOF

	#
	# section 5: *_DEPENDS (may not be there)
	#
	log_info(NO_FILE, NO_LINE_NUMBER, "checking fourth section of $file(*_DEPENDS).");
	$tmp = $sections[$idx];

	@linestocheck = split(/\s+/, <<EOF);
BUILD_USES_MSGFMT BUILD_DEPENDS DEPENDS
EOF
        if ($tmp =~ /(DEPENDS_TARGET|FETCH_DEPENDS|LIB_DEPENDS|RUN_DEPENDS).*=/) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "$1 is deprecated, please use DEPENDS.");
	}
	if ($tmp =~ /(LIB_|BUILD_|RUN_|FETCH_)?DEPENDS/ or
	    $tmp =~ /BUILD_USES_MSGFMT/) {
		&checkearlier($tmp, @varnames);

		if (!defined $ENV{'PORTSDIR'}) {
			$ENV{'PORTSDIR'} = $conf_portsdir;
		}
		foreach $i (grep(/^[A-Z_]*DEPENDS[?+]?=/, split(/\n/, $tmp))) {
			$i =~ s/^([A-Z_]*DEPENDS)[?+]?=[ \t]*//;
			$j = $1;
			log_info(NO_FILE, NO_LINE_NUMBER, "checking packages listed in $j.");
			foreach $k (split(/\s+/, $i)) {
				$l = (split(':', $k))[0];

				# check BUILD_USES_MSGFMT
				if ($l =~ /^(msgfmt|gettext)$/) {
					log_warning(NO_FILE, NO_LINE_NUMBER, "dependency to $1 ".
						"listed in $j. Consider using".
						" BUILD_USES_MSGFMT.");
				}
				# check USE_PERL5
				if ($l =~ /^perl(\.\d+)?$/) {
					log_warning(NO_FILE, NO_LINE_NUMBER, "dependency to perl ".
						"listed in $j. Consider using".
						" USE_PERL5.");
				}

				# check USE_GMAKE
				if ($l =~ /^(gmake|\${GMAKE})$/) {
					log_warning(NO_FILE, NO_LINE_NUMBER, "dependency to $1 ".
						"listed in $j. Consider using".
						" USE_GMAKE.");
				}

				# check direct dependencies on -dirs packages
				if ($l =~ /^([-a-zA-Z0-9]+)-dirs[-><=]+(.*)/) {
					log_warning(NO_FILE, NO_LINE_NUMBER, "dependency to $1-dirs ".
						"listed in $j. Consider using".
						" USE_DIRS+=$1-$2.");
				}

				# check pkg dir existence
				$k = (split(':', $k))[1];
				$k =~ s/\${PKGSRCDIR}/$ENV{'PKGSRCDIR'}/;
				if (! -d "$opt_packagedir/$k") {
					log_warning(NO_FILE, NO_LINE_NUMBER, "no package directory $k ".
						"found, even though it is ".
						"listed in $j.");
				} else {
					log_info(NO_FILE, NO_LINE_NUMBER, "package directory $k found.");
				}
			}
		}
		foreach $i (@linestocheck) {
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
	log_info(NO_FILE, NO_LINE_NUMBER, "checking the rest of the $file.");
	$tmp = join("\n\n", @sections[$idx .. scalar(@sections)-1]);

	$tmp = "\n" . $tmp;	# to make the begin-of-line check easier

	&checkearlier($tmp, @varnames);

	# check WRKSRC/NO_WRKSUBDIR
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
	log_info(NO_FILE, NO_LINE_NUMBER, "checking WRKSRC.");
	$wrksrc = $nowrksubdir = '';
	$wrksrc = $1 if ($tmp =~ /\nWRKSRC[+?]?=[ \t]*([^\n]*)\n/);
	$nowrksubdir = $1 if ($tmp =~ /\nNO_WRKSUBDIR[+?]?=[ \t]*([^\n]*)\n/);
	if ($nowrksubdir eq '') {
		$realwrksrc = $wrksrc ? "$wrksrc/$distname"
				      : "\${WRKDIR}/$distname";
	} else {
		$realwrksrc = $wrksrc ? $wrksrc : '${WRKDIR}';
	}
	log_info(NO_FILE, NO_LINE_NUMBER, "WRKSRC seems to be $realwrksrc.");

	if ($nowrksubdir eq '') {
		log_info(NO_FILE, NO_LINE_NUMBER, "no NO_WRKSUBDIR, checking value of WRKSRC.");
		if ($wrksrc eq 'work' || $wrksrc =~ /^$[\{\(]WRKDIR[\}\)]/) {
			log_warning(NO_FILE, NO_LINE_NUMBER, "WRKSRC is set to meaningless value ".
				"\"$1\".".
				($nowrksubdir eq ''
					? " use \"NO_WRKSUBDIR=yes\" instead."
					: ""));
		}
		if ($bogusdistfiles) {
			if ($distname ne '' && $wrksrc eq '') {
			    log_warning(NO_FILE, NO_LINE_NUMBER, "do not use DISTFILES and DISTNAME ".
				"to control WRKSRC. how about ".
				"\"WRKSRC=\${WRKDIR}/$distname\"?");
			} else {
			    log_warning(NO_FILE, NO_LINE_NUMBER, "DISTFILES/DISTNAME affects WRKSRC. ".
				"Use caution when changing them.");
			}
		}
	} else {
		log_info(NO_FILE, NO_LINE_NUMBER, "seen NO_WRKSUBDIR, checking value of WRKSRC.");
		if ($wrksrc eq 'work' || $wrksrc =~ /^$[\{\(]WRKDIR[\}\)]/) {
			log_warning(NO_FILE, NO_LINE_NUMBER, "definition of WRKSRC not necessary. ".
				"WRKSRC is \${WRKDIR} by default.");
		}
	}

	foreach $i (grep(/^(\W+_ENV)[?+]?=/, split(/\n/, $tmp))) {
		$i =~ s/^(\W+_ENV)[?+]?=[ \t]*//;
		$j = $1;
		foreach $k (split(/\s+/, $i)) {
			if ($k !~/^".*"$/ && $k =~ /\${/ && $k !~/:Q}/) {
				log_warning(NO_FILE, NO_LINE_NUMBER, "definition of $k in $j. ".
				"should use :Q or be quoted.");
			}
		}
	}

	# check USE_X11 and USE_IMAKE
	if ($tmp =~ /\nUSE_IMAKE[?+]?=/ && $tmp =~ /\nUSE_X11[?+]?=/) {
		log_warning(NO_FILE, NO_LINE_NUMBER, "since you already have USE_IMAKE, ".
			"you don't need USE_X11.");
	}

	# check direct use of important make targets.
	if ($tmp =~ /\n(fetch|extract|patch|configure|build|install):/) {
		log_error(NO_FILE, NO_LINE_NUMBER, "direct redefinition of make target \"$1\" ".
			"discouraged. redefine \"do-$1\" instead.");
	}

	1;
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
		log_warning(NO_FILE, NO_LINE_NUMBER, "extra item placed in the ".
			"$section section, ".
			"for example, \"$1\".");
	} else {
		log_warning(NO_FILE, NO_LINE_NUMBER, "extra item placed in the ".
			"$section section.");
	}
}

sub checkorder($$@) {
	my ($section, $str, @order) = @_;

	log_info(NO_FILE, NO_LINE_NUMBER, "checking the order of $section section.");

	my @items = ();
	foreach my $i (split("\n", $tmp)) {
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
		if ($order[$k] eq $i) {
			if ($k < $j) {
				log_error(NO_FILE, NO_LINE_NUMBER, "$i appears out-of-order.");
				$invalidorder++;
			} else {
				log_info(NO_FILE, NO_LINE_NUMBER, "seen $i, in order.");
			}
			$j = $k;
		} else {
			log_error(NO_FILE, NO_LINE_NUMBER, "extra item \"$i\" placed in".
				" the $section section.");
		}
	}
	if ($invalidorder) {
		log_error(NO_FILE, NO_LINE_NUMBER, "order must be " . join('/', @order) . '.');
	} else {
		log_info(NO_FILE, NO_LINE_NUMBER, "$section section is ordered properly.");
	}
}

sub checkearlier($@) {
	local($str, @varnames) = @_;
	local($i);

	log_info(NO_FILE, NO_LINE_NUMBER, "checking items that have to appear earlier.");
	foreach $i (@varnames) {
		if ($str =~ /\n$i[?+]?=/) {
			log_warning(NO_FILE, NO_LINE_NUMBER, "\"$i\" has to appear earlier in $file.");
		}
	}
}

sub abspathname($$) {
	local($str, $file) = @_;
	local($s, $i, %cmdnames);
	local($pre);

	# ignore parameter string to echo command
	$str =~ s/[ \t][\@-]?(echo|\$[\{\(]ECHO[\}\)]|\$[\{\(]ECHO_MSG[\}\)])[ \t]+("(\\'|\\"|[^"])*"|'(\\'|\\"|[^"])*')[ \t]*[;\n]//;

	log_info(NO_FILE, NO_LINE_NUMBER, "checking direct use of full pathnames in $file.");
	foreach $s (split(/\n+/, $str)) {
		$i = '';
		if ($s =~ /(^|[ \t\@'"-])(\/[\w\d])/) {
			# suspected pathnames are recorded.
			$i = $2 . $';
			$pre = $` . $1;

			if ($pre =~ /MASTER_SITE_SUBDIR/) {
				# MASTER_SITE_SUBDIR lines are ok.
				$i = '';
			}
		}
		if ($i ne '') {
			$i =~ s/\s.*$//;
			$i =~ s/['"].*$//;
			$i = substr($i, 0, 20) . '...' if (20 < length($i));
			log_warning(NO_FILE, NO_LINE_NUMBER, "possible use of absolute pathname ".
				"\"$i\", in $file.");
		}
	}

	log_info(NO_FILE, NO_LINE_NUMBER, "checking direct use of pathnames, phase 1.");
%cmdnames = split(/\n|\t+/, <<EOF);
/usr/opt	\${PORTSDIR} instead
$conf_portsdir	\${PORTSDIR} instead
$conf_localbase	\${PREFIX} or \${LOCALBASE}, as appropriate
/usr/X11	\${PREFIX} or \${X11BASE}, as appropriate
/usr/X11R6	\${PREFIX} or \${X11BASE}, as appropriate
EOF
	foreach $i (keys %cmdnames) {
		if ($str =~ /$i/) {
			log_warning(NO_FILE, NO_LINE_NUMBER, "possible direct use of \"$&\" ".
				"found in $file. if so, use $cmdnames{$i}.");
		}
	}

	log_info(NO_FILE, NO_LINE_NUMBER, "checking direct use of pathnames, phase 2.");
%cmdnames = split(/\n|\t+/, <<EOF);
distfiles	\${DISTDIR} instead
pkg		\${PKGDIR} instead
files		\${FILESDIR} instead
scripts		\${SCRIPTDIR} instead
patches		\${PATCHDIR} instead
work		\${WRKDIR} instead
EOF
	foreach $i (keys %cmdnames) {
		if ($str =~ /(\.\/|\$[\{\(]\.CURDIR[\}\)]\/|[ \t])(\b$i)\//) {
			log_warning(NO_FILE, NO_LINE_NUMBER, "possible direct use of \"$i\" ".
				"found in $file. if so, use $cmdnames{$i}.");
		}
	}
}

sub is_predefined($) {
	local($url) = @_;
	local($site);
	local($subdir);
	if ($site = (grep($url =~ $_, keys %predefined))[0]) {
		$url =~ /$site/;
		$subdir = $';
		$subdir =~ s/\/$//;
		log_warning(NO_FILE, NO_LINE_NUMBER, "how about using ".
			"\${MASTER_SITE_$predefined{$site}:=$subdir/} instead of \"$url\?");
		return 1;
	}
	return 0;
}

sub category_check() {
	local($file) = "Makefile";
	local($first) = 1;
	local($lastsub) = "";
	local($sub) = "";
	local($contents);
	local(@dirlist);
	local($i);

	$contents = readmakefile("$opt_packagedir/$file") or
		log_error(NO_FILE, NO_LINE_NUMBER, "can't read $opt_packagedir/$file") and return 0;
	if ($contents !~ /#(\s+)\$$conf_rcsidstr([^\$]*)\$/) {
		log_error(NO_FILE, NO_LINE_NUMBER, "no \$$conf_rcsidstr\$ line in $file");
	}
	if ($contents !~ /COMMENT=\s+\w/) {
		log_error(NO_FILE, NO_LINE_NUMBER, "no COMMENT line in $file");
	}

	# get list of dirs to compare against
	@dirlist=glob("*/");
	foreach $i (@dirlist) {
		# drop trailing slash and enter into hash
		$i =~ s/\/$//;
		$hash{$i} = 1;
	}
	# we expect the CVS dir to be here
	$hash{CVS} = 0;
	# remove comments
	foreach $n (split "\n", $contents) {
		if ($n =~ /^(#?)SUBDIR(\+*)=\s*(\S+)(\s*#.*|\s*)$/) {
			$sub = $3;
			if ($first == 0) {
				if ($2 ne "+") {
					log_error(NO_FILE, NO_LINE_NUMBER, "use SUBDIR+=, not SUBDIR$2=");
				}
				if ($lastsub ge $sub) {
					log_error(NO_FILE, NO_LINE_NUMBER, "$sub should come before $lastsub");
				}
			}
			else {
				$first = 0;
			}
			$lastsub = $sub;
			if ($hash{$sub} == 1) {
				$hash{$sub} = 0;
			}
			else {
				$hash{$sub} = -1;
			}
			if ($1 eq "#" and not $4 =~ /#\s*\w+/) {
				log_warning(NO_FILE, NO_LINE_NUMBER, "$3 commented out without giving a reason");
			}
		}
	}

	foreach $i (sort(keys(%hash))) {
	    if ($hash{$i} gt 0) {
		log_error(NO_FILE, NO_LINE_NUMBER, "directory $i not in Makefile");
	    }
	    elsif ($hash{$i} lt 0) {
		log_error(NO_FILE, NO_LINE_NUMBER, "non-existing directory $i listed in Makefile");
	    }
	}
}

#
# Output of various log messages
#


sub log_message($$$$)
{
	my ($file, $lineno, $type, $message) = @_;
	if ($file eq NO_FILE) {
		printf("%s: %s\n", $type, $message);
	} elsif ($lineno == NO_LINE_NUMBER) {
		printf("%s: %s: %s\n", $type, $file, $message);
	} else {
		printf("%s: %s:%d: %s\n", $type, $file, $lineno, $message);
	}
}

sub NO_FILE() { return ""; }
sub NO_LINE_NUMBER() { return 0; }

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
	if ($opt_verbose) {
		log_message($file, $lineno, "OK", $msg);
	}
}

sub print_summary_and_exit()
{
	if ($errors != 0 || $warnings != 0) {
		print("$errors errors and $warnings warnings found.\n");
	} else {
		print "looks fine.\n";
	}
	exit($errors != 0);
}
