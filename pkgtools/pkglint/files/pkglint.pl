#!@PREFIX@/bin/perl
#
# pkglint - lint for package directory
#
# implemented by:
#	Jun-ichiro itojun Itoh <itojun@itojun.org>
#	Yoshishige Arai <ryo2@on.rim.or.jp>
# visit ftp://ftp.foretune.co.jp/pub/tools/portlint/ for latest version.
#
# Copyright(c) 1997 by Jun-ichiro Itoh <itojun@itojun.org>.
# All rights reserved.
# Freely redistributable.  Absolutely no warranty.
#
# From Id: portlint.pl,v 1.64 1998/02/28 02:34:05 itojun Exp
# $NetBSD: pkglint.pl,v 1.62 2001/11/11 05:04:28 hubertf Exp $
#
# This version contains lots of changes necessary for NetBSD packages
# done by Hubert Feyrer <hubertf@netbsd.org>,
# Thorsten Frueauf <frueauf@netbsd.org>, Thomas Klausner <wiz@netbsd.org>
# and others.
#

use Getopt::Std;
use File::Basename;
use FileHandle;

$err = $warn = 0;
$extrafile = $parenwarn = $committer = 1;	# -abc
$verbose = $newpkg = 0;				# -vN
$showmakefile = 0;				# -I
$contblank = 1;
$portdir = '.';

# default settings for NetBSD
$portsdir = '@PORTSDIR@';
$rcsidstr = 'NetBSD';
$localbase = '@PREFIX@';

getopts('hINB:vV');

if ($opt_h) {
		($prog) = ($0 =~ /([^\/]+)$/);
		print STDERR <<EOF;
usage: $prog [-vIN] [-B#] [package_directory]
	-v	verbose mode
	-V	version (@DISTVER@)
	-I	show Makefile (with all included files)
	-N	writing a new package
	-B#	allow # contiguous blank lines (default: $contblank line)
EOF
		exit 0;
};
$verbose = 1	if $opt_v;
$newpkg = 1	if $opt_N;
$showmakefile = 1	if $opt_I;
$contblank = $opt_B	if $opt_B;

$portdir = shift || ".";

if ($opt_V) {
	print "@DISTVER@\n";
	exit;
}

if ($verbose) {
	print "OK: config: portsdir: \"$portsdir\" ".
		"rcsidstr: \"$rcsidstr\" ".
		"localbase: $localbase\n";
}

#
# just for safety.
#
if (! -d $portdir) {
	print STDERR "FATAL: invalid directory $portdir specified.\n";
	exit 1;
}

#
# variables for global checks.
#
$sharedocused = 0;
$seen_PLIST_SRC = 0;
$seen_NO_PKG_REGISTER = 0;
$seen_NO_CHECKSUM = 0;

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
print "OK: checking Makefile.\n";
if (! -f "$portdir/Makefile") {
	&perror("FATAL: no Makefile in \"$portdir\".");
} else {
    	checkmakefile("Makefile") || &perror("Cannot open the file $i\n");
}


#
# check for files.
#
@checker = ("$pkgdir/DESCR");
%checker = ("$pkgdir/DESCR", 'checkdescr');

if ($extrafile) {
	foreach $i ((<$portdir/$scriptdir/*>, <$portdir/$pkgdir/*>)) {
		next if (! -T $i);
		next if ($i =~ /distinfo$/);
		next if ($i =~ /Makefile$/);
		$i =~ s/^\Q$portdir\E\///;
		next if (defined $checker{$i});
		if ($i =~ /PLIST/) {
		        unshift(@checker, $i);
			$checker{$i} = 'checkplist';
		} else {
		        push(@checker, $i);
			$checker{$i} = 'checkpathname';
		}
	}
}
foreach $i (<$portdir/$patchdir/patch-*>) {
	next if (! -T $i);
	$i =~ s/^\Q$portdir\E\///;
	next if (defined $checker{$i});
	push(@checker, $i);
	$checker{$i} = 'checkpatch';
}
if (-e <$portdir/$distinfo>) {
	$i = "$distinfo";
	next if (defined $checker{$i});
	push(@checker, $i);
	$checker{$i} = 'checkdistinfo';
}
{
	# Make sure there's a distinfo if there are patches
	$patches=0;
	patch:
    	    foreach $i (<$portdir/$patchdir/patch-*>) {
		if ( -T "$i" ) { 
			$patches=1;
			last patch;
		}
	}
	if ($patches && ! -f "$portdir/$distinfo" ) {
		&perror("WARN: no $portdir/$distinfo file. Please run 'make makepatchsum'.");
	}
}
foreach $i (@checker) {
	print "OK: checking $i.\n";
	if (! -f "$portdir/$i") {
		&perror("FATAL: no $i in \"$portdir\".");
	} else {
		$proc = $checker{$i};
		&$proc($i) || &perror("WARN: Cannot open the file $i\n");
		if ($i !~ /patches\/patch/) {
			&checklastline($i) ||
				&perror("WARN: Cannot open the file $i\n");
		}
	}
}
if (-e <$portdir/$distinfo> ) {
	if ( $seen_NO_CHECKSUM ) {
		&perror("WARN: NO_CHECKSUM set, but $portdir/$distinfo exists. Please remove it.");
	}
} else {
	if ( ! $seen_NO_CHECKSUM ) {
		&perror("WARN: no $portdir/$distinfo file. Please run 'make makesum'.");
	}
}
if (-e <$portdir/$filesdir/md5> ) {
	&perror("FATAL: $filesdir/md5 is deprecated -- run 'make mdi' to generate distinfo.");
}
if (-e <$portdir/$filesdir/patch-sum> ) {
	&perror("FATAL: $filesdir/patch-sum is deprecated -- run 'make mps' to generate distinfo.");
}
if (-e <$pkgdir/COMMENT> ) {
	&perror("FATAL: $pkgdir/COMMENT is deprecated -- please use a COMMENT variable instead.");
}
if (-d "$portdir/pkg" ) {
	&perror("FATAL: $portdir/pkg and its contents are deprecated!\n".
		"\tPlease 'mv $portdir/pkg/* $portdir' and 'rmdir $portdir/pkg'.");
}
if (-d "$portdir/scripts" ) {
	&perror("WARN: $portdir/scripts and its contents are deprecated! Please call the script(s)\n".
		"\texplicitly from the corresponding target(s) in the pkg's Makefile.");
}
if (! -f "$portdir/$pkgdir/PLIST"
    and ! -f "$portdir/$pkgdir/PLIST-mi"
    and ! $seen_PLIST_SRC
    and ! $seen_NO_PKG_REGISTER ) {
	&perror("WARN: no PLIST or PLIST-mi, and PLIST_SRC and NO_PKG_REGISTER unset.\n     Are you sure PLIST handling is ok?");
}
if ($committer) {
	if (scalar(@_ = <$portdir/work*/*>) || -d "$portdir/work*") {
		&perror("WARN: be sure to cleanup $portdir/work* ".
			"before committing the package.");
	}
	if (scalar(@_ = <$portdir/*/*~>) || scalar(@_ = <$portdir/*~>)) {
		&perror("WARN: for safety, be sure to cleanup ".
			"emacs backup files before committing the package.");
	}
	if (scalar(@_ = <$portdir/*/*.orig>) || scalar(@_ = <$portdir/*.orig>)
	 || scalar(@_ = <$portdir/*/*.rej>) || scalar(@_ = <$portdir/*.rej>)) {
		&perror("WARN: for safety, be sure to cleanup ".
			"patch backup files before committing the package.");
	}
}
if ($err || $warn) {
	print "$err fatal errors and $warn warnings found.\n"
} else {
	print "looks fine.\n";
}
exit $err;

#
# DESCR
#
sub checkdescr {
	local($file) = @_;
	local(%maxchars) = ('DESCR', 80);
	local(%maxlines) = ('DESCR', 24);
	local(%errmsg) = ('DESCR', "exceeds $maxlines{'DESCR'} ".
			  	   "lines, make it shorter if possible");
	local($longlines, $linecnt, $tmp) = (0, 0, "");

	$shortname = basename($file);
	open(IN, "< $portdir/$file") || return 0;

	while (<IN>) {
		$linecnt++;
		$longlines++ if ($maxchars{$shortname} < length($_));
		$tmp .= $_;
	}
	if ($linecnt > $maxlines{$shortname}) {
		&perror("WARN: $file $errmsg{$shortname} ".
			"(currently $linecnt lines).");
	} else {
		print "OK: $file has $linecnt lines.\n" if ($verbose);
	}
	if ($longlines > 0) {
		&perror("WARN: $file includes lines that exceed ".
			"$maxchars{$shortname} characters.");
	}
	if ($tmp =~ /[\033\200-\377]/) {
		&perror("WARN: $file includes iso-8859-1, or ".
			"other local characters.  $file should be ".
			"plain ascii file.");
	}
	close(IN);
}

#
# distinfo
#
sub checkdistinfo {
	local($file) = @_;	# distinfo
	local(%indistinfofile);

	open(SUM,"<$portdir/$file") || return 0;
	while(<SUM>) {
		next if !/^(MD5|SHA1|RMD160) \(([^)]+)\) = (.*)$/;
		$alg=$1;
		$patch=$2;
		$sum=$3;

		# bitch about *~
		if ($patch =~ /~$/) {
			&perror("WARN: possible backup file '$patch' in $portdir/$file?");
		}

		if (-T "$portdir/$patchdir/$patch") {
			$calcsum=`sed -e '/\$NetBSD.*/d' $portdir/$patchdir/$patch | digest $alg`;
			chomp($calcsum);
			if ( "$sum" ne "$calcsum" ) {
				&perror("FATAL: checksum of $patch differs between $portdir/$file and\n"
				       ."       $portdir/$patchdir/$patch. Rerun 'make makepatchsum'.");
			}
		} elsif ($patch =~ /^patch-[a-z0-9]+$/)  {
			&perror("FATAL: patchfile '$patch' is in $file\n"
			       ."       but not in $portdir/$patchdir/$patch. Rerun 'make makepatchsum'.");
		}

		$indistinfofile{$patch} = 1;
	}
	close(SUM);

	foreach $patch ( <$portdir/$patchdir/patch-*> ) {
		$patch =~ /\/([^\/]+)$/;
		if (! $indistinfofile{$1}) {
			&perror("FATAL: patchsum of '$1' is in $portdir/$patchdir/$1 but not in\n"
			       ."       $file. Rerun 'make makepatchsum'.");
		}
	}

	return 1;
}

#
# PLIST
#
sub checkplist {
	local($file) = @_;
	local($curdir) = ($localbase);
	local($inforemoveseen, $infoinstallseen, $infoseen) = (0, 0, 0);
	local($infobeforeremove, $infoafterinstall) = (0, 0);
	local($infooverwrite) = (0);
	local($rcsidseen) = 0;

	open(IN, "< $portdir/$file") || return 0;
	while (<IN>) {
		if ($_ =~ /[ \t]+\n?$/) {
			&perror("WARN: $file $.: whitespace before end ".
				"of line.");
		}

		# make it easier to handle.
		$_ =~ s/\s+$//;

		$_ =~ s/\n$//;
		
	        if ($_ =~ /<\$ARCH>/) {
		    &perror("WARN: $file $.: use of <\$ARCH> ".
			    "deprecated, use \${MACHINE_ARCH instead}.");
		}

		if ($_ =~ /^\@/) {
			if ($_ =~ /^\@(cwd|cd)[ \t]+(\S+)/) {
				$curdir = $2;
			} elsif ($_ =~ /^\@unexec[ \t]+rmdir/) {
				&perror("WARN: use \"\@dirrm\" ".
					"instead of \"\@unexec rmdir\".");
			} elsif ($_ =~ /^\@exec[ \t]+(.*\/)?install-info/) {
				$infoinstallseen = $.
			} elsif ($_ =~ /^\@unexec[ \t]+(.*\/)?install-info[ \t]+--delete/) {
				$inforemoveseen = $.
			} elsif ($_ =~ /^\@(exec|unexec)/) {
				if (/ldconfig/
				 && !/\/usr\/bin\/true/) {
					&perror("FATAL: $file $.: ldconfig ".
						"must be used with ".
						"\"||/usr/bin/true\".");
				}
			} elsif ($_ =~ /^\@(comment)/) {
				$rcsidseen++ if (/\$$rcsidstr[:\$]/);
			} elsif ($_ =~ /^\@(dirrm|option)/) {
				; # no check made
			} elsif ($_ =~ /^\@(mode|owner|group)/) {
				&perror("WARN: \"\@mode/owner/group\" are ".
					"deprecated, please use chmod/".
					"chown/chgrp in the pkg Makefile ".
					"and let tar do the rest.");
			} else {
				&perror("WARN: $file $.: ".
					"unknown PLIST directive \"$_\"");
			}
			next;
		}

		if ($_ =~ /^\//) {
			&perror("FATAL: $file $.: use of full pathname ".
				"disallowed.");
		}

		if ($_ =~ /^info\/.*info(-[0-9]+)?$/) {
			$infoseen = $.;
			$infoafterinstall++ if ($infoinstallseen);
			$infobeforeremove++ if (!$inforemoveseen);
		}

		if ($_ =~ /^info\/dir$/) {
			&perror("FATAL: \"info/dir\" should not be listed in ".
				"$file. use install-info to add/remove ".
				"an entry.");
			$infooverwrite++;
		}

		if ($curdir !~ m#^$localbase#
		 && $curdir !~ m#^/usr/X11R6#) {
			&perror("WARN: $file $.: installing to ".
				"directory $curdir discouraged. ".
				"could you please avoid it?");
		}

		if ("$curdir/$_" =~ m#^$localbase/share/doc#) {
			print "OK: seen installation to share/doc in $file. ".
				"($curdir/$_)\n" if ($verbose);
			$sharedocused++;
		}
	}

	if (!$rcsidseen) {
		&perror("FATAL: RCS tag \"\$$rcsidstr\$\" must be present ".
			"in $file as \@comment.")
	}

	if (!$infoseen) {
		close(IN);
		return 1;
	}
	if (!$infoinstallseen) {
		if ($infooverwrite) {
			&perror("FATAL: \"\@exec install-info\" must be used ".
				"to add/delete entries into \"info/dir\".");
		}
		&perror("FATAL: \"\@exec install-info\" must be placed ".
			"after all the info files.");
	} elsif ($infoafterinstall) {
		&perror("FATAL: move \"\@exec install-info\" line to make ".
			"sure that it is placed after all the info files. ".
			"(currently on line $infoinstallseen in $file)");
	}
	if (!$inforemoveseen) {
		&perror("FATAL: \"\@unexec install-info --delete\" must ".
			"be placed before any of the info files listed.");
	} elsif ($infobeforeremove) {
		&perror("FATAL: move \"\@exec install-info --delete\" ".
			"line to make sure ".
			"that it is placed before any of the info files. ".
			"(currently on line $inforemoveseen in $file)");
	}
	close(IN);
}

#
# misc files
#
sub checkpathname {
	local($file) = @_;
	local($whole);

	open(IN, "< $portdir/$file") || return 0;
	$whole = '';
	while (<IN>) {
		$whole .= $_;
	}
	&abspathname($whole, $file);
	close(IN);
}

sub checklastline {
	local($file) = @_;
	local($whole);

	open(IN, "< $portdir/$file") || return 0;
	$whole = '';
	while (<IN>) {
		$whole .= $_;
	}
	if ($whole eq "") {
		&perror("FATAL: $file is empty.");
	}
	else 
	{
		if ($whole !~ /\n$/) {
			&perror("FATAL: the last line of $file has to be ".
				"terminated by \\n.");
		}
		if ($whole =~ /\n([ \t]*\n)+$/) {
			&perror("WARN: $file seems to have unnecessary ".
				"blank lines at the bottom.");
		}
	}

	close(IN);
}

sub checkpatch {
	local($file) = @_;
	local($rcsidseen) = 0;
	local($whole);

	if ($file =~ /.*~$/) {
		&perror("WARN: is $file a backup file? If so, please remove it \n"
		       ."      and rerun 'make makepatchsum'");
	}

	open(IN, "< $portdir/$file") || return 0;
	$whole = '';
	while (<IN>) {
		$rcsidseen++ if /\$$rcsidstr[:\$]/;
		$whole .= $_;
	}
	if ($committer && $whole =~ /.\$(Author|Date|Header|Id|Locker|Log|Name|RCSfile|Revision|Source|State|NetBSD)[:\$]/) { # XXX
	        # RCS ID in very first line is ok, to identify version
	        # of patch (-> only warn if there's something before the
	        # actual $RCS_ID$, not on BOF - '.' won't match there)
		&perror("WARN: $file includes possible RCS tag \"\$$1\$\". ".
			"use binary mode (-ko) on commit/import.");
	}
	if (!$rcsidseen) {
		&perror("FATAL: RCS tag \"\$$rcsidstr\$\" must be present ".
			"in patch $file.")
	}
	close(IN);
}

sub readmakefile {
	local ($file) = @_;
	local $contents = "";
	local $includefile;
	local $dirname;
	local $savedln;
	local $_;
	my $handle = new FileHandle;

	$savedln = $.;
	$. = 0;
	open($handle, "< $file") || return 0;
	print("OK: reading Makefile '$file'\n") if ($verbose);
	while (<$handle>) {
		if ($_ =~ /[ \t]+\n?$/ && !/^#/) {
			&perror("WARN: $file $.: whitespace before ".
				"end of line.");
		}
		if ($_ =~ /^        /) {	# 8 spaces here!
			&perror("WARN: $file $.: use tab (not spaces) to".
				" make indentation.");
		}
		# try to get any included file
		if ($_ =~ /^.include\s+([^\n]+)\n/) {
			$includefile = $1;
			if ($includefile =~ /\"([^\"]+)\"/) {
				$includefile = $1;
			}
			if ($includefile =~ /\/mk\//) {
				# we don't want to include the whole
				# bsd.pkg.mk or bsd.prefs.mk files
				$contents .= $_;
			} else {
				$dirname = dirname($file);
				print("OK: including $dirname/$includefile\n");
				$contents .= readmakefile("$dirname/$includefile");
			}
		} else {
			# we don't want the include Makefile.common lines
			# to be pkglinted
			$contents .= $_;
		}
	}
	close($handle);

	$. = $savedln;
	return $contents;
}

#
# Makefile
#
sub checkmakefile {
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

	$tmp = 0;
	$rawwhole = readmakefile("$portdir/$file");
	if ($rawwhole eq '') {
		&perror("FATAL: can't read $portdir/$file");
		return 0;
	}
	else {
		print("OK: whole Makefile (with all included files):\n".
		      "$rawwhole\n") if ($showmakefile);
	}

	#
	# whole file: blank lines.
	#
	$whole = "\n" . $rawwhole;
	print "OK: checking contiguous blank lines in $file.\n"
		if ($verbose);
	$i = "\n" x ($contblank + 2);
	if ($whole =~ /$i/) {
		&perror("FATAL: contiguous blank lines (> $contblank lines) found ".
			"in $file at line " . int(split(/\n/, $`)) . ".");
	}

	#
	# whole file: $(VARIABLE)
	#
	if ($parenwarn) {
		print "OK: checking for \$(VARIABLE).\n" if ($verbose);
		if ($whole =~ /\$\([\w\d]+\)/) {
			&perror("WARN: use \${VARIABLE}, instead of ".
				"\$(VARIABLE).");
		}
	}

	#
	# whole file: get FILESDIR, PATCHDIR, PKGDIR, SCRIPTDIR,
	# PATCH_SUM_FILE and DIGEST_FILE
	#
	print "OK: checking for PATCHDIR, SCRIPTDIR, FILESDIR, PKGDIR,".
	    " DIGEST_FILE.\n" if ($verbose);

	$filesdir = "files";
	$filesdir = $1 if ($whole =~ /\nFILESDIR[+?]?=[ \t]*([^\n]+)\n/);
	$filesdir =~ s/\$\{.CURDIR\}/./;

	$patchdir = "patches";
	$patchdir = $1 if ($whole =~ /\nPATCHDIR[+?]?=[ \t]*([^\n]+)\n/);
	$patchdir =~ s/\$\{.CURDIR\}/./;
	$patchdir =~ s/\${PKGSRCDIR}/..\/../;

	$pkgdir = "pkg";
	if (! -d "$portdir/$pkgdir") {
	    $pkgdir = ".";
	}
	$pkgdir = $1 if ($whole =~ /\nPKGDIR[+?]?=[ \t]*([^\n]+)\n/);
	$pkgdir =~ s/\$\{.CURDIR\}/./;

	$scriptdir = "scripts";
	$scriptdir = $1 if ($whole =~ /\nSCRIPTDIR[+?]?=[ \t]*([^\n]+)\n/);
	$scriptdir =~ s/\$\{.CURDIR\}/./;

	$distinfo = "distinfo";
	$distinfo = $1 if ($whole =~ /\nDISTINFO_FILE[+?]?=[ \t]*([^\n]+)\n/);
	$distinfo =~ s/\$\{.CURDIR\}/./;
	$distinfo =~ s/\${PKGSRCDIR}/..\/../;

	print("OK: PATCHDIR: $patchdir, SCRIPTDIR: $scriptdir, ".
	      "FILESDIR: $filesdir, PKGDIR: $pkgdir, ".
	      "DISTINFO: $distinfo\n") if ($verbose);

	#
	# whole file: IS_INTERACTIVE
	#
	$whole =~ s/\n#[^\n]*/\n/g;
	$whole =~ s/\n\n+/\n/g;
	print "OK: checking IS_INTERACTIVE.\n" if ($verbose);
	if ($whole =~ /\nIS_INTERACTIVE/) {
		if ($whole !~ /defined\((BATCH|FOR_CDROM)\)/) {
			&perror("WARN: use of IS_INTERACTIVE discouraged. ".
				"provide batch mode by using BATCH and/or ".
				"FOR_CDROM.");
		}
	}
	print "OK: checking for PLIST_SRC.\n" if ($verbose);
	if ($whole =~ /\nPLIST_SRC/) {
		$seen_PLIST_SRC=1;
	}
	print "OK: checking for NO_PKG_REGISTER.\n" if ($verbose);
	if ($whole =~ /\nNO_PKG_REGISTER/) {
		$seen_NO_PKG_REGISTER=1;
	}
	print "OK: checking for NO_CHECKSUM.\n" if ($verbose);
	if ($whole =~ /\nNO_CHECKSUM/) {
		$seen_NO_CHECKSUM=1;
	}
	print "OK: checking USE_PERL usage.\n" if ($verbose);
	if ($whole =~ /\nUSE_PERL[^5]/) {
		&perror("WARN: USE_PERL found -- you probably mean USE_PERL5.");
	}
	print "OK: checking USE_PKGLIBTOOL.\n" if ($verbose);
	if ($whole =~ /\nUSE_PKGLIBTOOL/) {
		&perror("FATAL: USE_PKGLIBTOOL is deprecated, ".
			"use USE_LIBTOOL instead.");
	}
	print "OK: checking NO_WRKSUBDIR.\n" if ($verbose);
	if ($whole =~ /\nNO_WRKSUBDIR/) {
		&perror("FATAL: NO_WRKSUBDIR is deprecated, ".
			"use WRKSRC=\$\{WRKDIR\} instead.");
	}
	print "OK: checking MD5_FILE, DIGEST_FILE and PATCH_SUM_FILE.\n" if ($verbose);
	if ($whole =~ /\n(MD5_FILE)/ or $whole =~ /\n(DIGEST_FILE)/ or
		$whole =~ /\n(PATCH_SUM_FILE)/) {
		&perror("FATAL: $1 is deprecated, ".
			"use DISTINFO_FILE instead.");
	}
	print "OK: checking MIRROR_DISTFILE.\n" if ($verbose);
	if ($whole =~ /\nMIRROR_DISTFILE/) {
		&perror("WARN: use of MIRROR_DISTFILE deprecated, ".
			"use NO_BIN_ON_FTP and/or NO_SRC_ON_FTP instead.");
	}
	print "OK: checking NO_CDROM.\n" if ($verbose);
	if ($whole =~ /\nNO_CDROM/) {
		&perror("WARN: use of NO_CDROM discouraged, ".
			"use NO_BIN_ON_CDROM and/or NO_SRC_ON_CDROM instead.");
	}
	print "OK: checking NO_PACKAGE.\n" if ($verbose);
	if ($whole =~ /\nNO_PACKAGE/) {
		&perror("WARN: use of NO_PACKAGE to enforce license ".
			"restrictions is deprecated.");
	}
	print "OK: checking for MKDIR.\n" if ($verbose);
	if ($whole =~ m|\${MKDIR}.*(\${PREFIX}[/0-9a-zA-Z\${}]*)|) {
	    	&perror("WARN: \${MKDIR} $1: consider using INSTALL_*_DIR");
	}
	print "OK: checking for unneeded INSTALL -d.\n" if ($verbose);
	if ($whole =~ m|\${INSTALL}(.*)\n|) {
	    $args = $1;
	    	if ($args =~ /-d/) {
		        if ($args !~ /-[ogm]/) {
		    		&perror("WARN: \${INSTALL}$args: " .
					"consider using INSTALL_*_DIR");
		        }
		}
	}
	print "OK: checking for unneeded failure check on directory creation.\n" if ($verbose);
	if ($whole =~ /\n\t-(.*(MKDIR|INSTALL.*-d|INSTALL_.*_DIR).*)/g) {
	    	&perror("WARN: $1: no need to use '-' before command");
	}

	#
	# whole file: direct use of command names
	#
	print "OK: checking direct use of command names.\n" if ($verbose);
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
			&perror("WARN: possible direct use of command \"$i\" ".
				"found. Use $cmdnames{$i} instead.");
		}
	}

	#
	# whole file: ldconfig must come with "true" command
	#
	if ($j =~ /(ldconfig|\$[{(]LDCONFIG[)}])/
	 && $j !~ /(\/usr\/bin\/true|\$[{(]TRUE[)}])/) {
		&perror("FATAL: ldconfig must be used with \"||\${TRUE}\".");
	}

	#
	# whole file: ${MKDIR} -p
	#
	if ($j =~ /\${MKDIR}\s+-p/) {
		&perror("WARN: possible use of \"\${MKDIR} -p\" ".
			"found. \${MKDIR} includes \"-p\" by default.");
	}
	#
	# whole file: continuation line in DEPENDS
	#
	if ($whole =~ /\n(BUILD_|)DEPENDS[^\n]*\\\n/) {
		&perror("WARN: Please don't use continuation lines in".
			" (BUILD_)DEPENDS, use (BUILD_)DEPENDS+= instead.");
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
	print "OK: checking comment section of $file.\n" if ($verbose);
	$tmp = $sections[$idx++];
	if ($tmp !~ /#(\s+)\$$rcsidstr([^\$]*)\$/) {
		&perror("FATAL: no \$$rcsidstr\$ line in $file comment ".
			"section.");
	} else {
		print "OK: \$$rcsidstr\$ seen in $file.\n" if ($verbose);
		if ($1 ne ' ') {
			&perror("WARN: please use single whitespace ".
				"right before \$$rcsidstr\$ tag.");
		}
		if ($2 ne '') {
			if ($verbose || $newpkg) {	# XXX
				&perror("WARN: ".
				    ($newpkg ? 'for new package, '
					      : 'is it a new package? if so, ').
				    "make \$$rcsidstr\$ tag in comment ".
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
	print "OK: checking first section of $file. (DISTNAME/...)\n"
		if ($verbose);
	$tmp = $sections[$idx++];

	# check the order of items.
        @tocheck=split(/\s+/, <<EOF);
DISTNAME PKGNAME SVR4_PKGNAME WRKSRC NO_WRKSUBDIR CATEGORIES MASTER_SITES
MASTER_SITE_SUBDIR EXTRACT_SUFX DISTFILES
EOF
	push(@tocheck,"ONLY_FOR_ARCHS");
	push(@tocheck,"NO_SRC_ON_FTP");
	push(@tocheck,"NO_BIN_ON_FTP");
        &checkorder('DISTNAME', $tmp, @tocheck);

	# check the items that has to be there.
	$tmp = "\n" . $tmp;
	foreach $i ('DISTNAME', 'CATEGORIES') {
		if ($tmp !~ /\n$i=/) {
			&perror("FATAL: $i has to be there.");
		}
		if ($tmp =~ /\n$i(\?=)/) {
			&perror("FATAL: $i has to be set by \"=\", ".
				"not by \"$1\".");
		}
	}

	# check the URL
	if ($tmp =~ /\nMASTER_SITES[+?]?=[ \t]*([^\n]*)\n/
	 && $1 !~ /^[ \t]*$/) {
		print "OK: seen MASTER_SITES, sanity checking URLs.\n"
			if ($verbose);
		@sites = split(/\s+/, $1);
		foreach $i (@sites) {
			if ($i =~ m#^\w+://#) {
				if ($i !~ m#/$#) {
					&perror("FATAL: URL \"$i\" should ".
						"end with \"/\".");
				}
				if ($i =~ m#://[^/]*:/#) {
					&perror("FATAL: URL \"$i\" contains ".
						"extra \":\".");
				}
				unless (&is_predefined($i)) {
					print "OK: URL \"$i\" ok.\n"
						if ($verbose);
				}
			} else {
				print "OK: non-URL \"$i\" ok.\n"
					if ($verbose);
			}
		}
	} else {
		&perror("WARN: no MASTER_SITES found. Is this ok?");
	}

	# check DISTFILES and related items.
	$distname = $1 if ($tmp =~ /\nDISTNAME[+?]?=[ \t]*([^\n]+)\n/);
	$pkgname = $1 if ($tmp =~ /\nPKGNAME[+?]?=[ \t]*([^\n]+)\n/);
	$svrpkgname = $1 if ($tmp =~ /\nSVR4_PKGNAME[+?]?=[ \t]*([^\n]+)\n/);
	$extractsufx = $1 if ($tmp =~ /\nEXTRACT_SUFX[+?]?=[ \t]*([^\n]+)\n/);
	$distfiles = $1 if ($tmp =~ /\nDISTFILES[+?]?=[ \t]*([^\n]+)\n/);

	# check bogus EXTRACT_SUFX.
	if ($extractsufx ne '') {
		print "OK: seen EXTRACT_SUFX, checking value.\n" if ($verbose);
		if ($distfiles ne '' && ($extractsufx eq '.tar.gz')) {
			&perror("WARN: no need to define EXTRACT_SUFX if ".
				"DISTFILES is defined.");
		}
		if ($extractsufx eq '.tar.gz') {
			&perror("WARN: EXTRACT_SUFX is \".tar.gz.\" ".
				"by default. you don't need to specify it.");
		}
	} else {
		print "OK: no EXTRACT_SUFX seen, using default value.\n"
			if ($verbose);
		$extractsufx = '.tar.gz';
	}

	print "OK: sanity checking PKGNAME.\n" if ($verbose);
	if ($pkgname ne '' && $pkgname eq $distname) {
		&perror("WARN: PKGNAME is \${DISTNAME} by default, ".
			"you don't need to define PKGNAME.");
	}
	if ($svrpkgname ne '') {
		if (length($svrpkgname) > 5) {
			&perror("FATAL: SVR4_PKGNAME should not be longer ".
				"than 5 characters.");
		}
	}
	$i = ($pkgname eq '') ? $distname : $pkgname;
	$i =~ s/\${DISTNAME[^}]*}/$distname/g;
	if ($i =~ /-([^-]+)$/) {
		$j = $`;
		$k = $1;
		if ($j =~ /[0-9]$/) {
			&perror("WARN: is \"$j\" sane as package name ".
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
			print "OK: trailing part of PKGNAME\"-$k\" ".
				"looks fine.\n" if ($verbose);
		} else {
			&perror("FATAL: version number part of PKGNAME".
				(($pkgname eq '')
					? ', which is derived from DISTNAME, '
					: ' ').
				"looks illegal. You should modify \"-$k\"");
		}
	} else {
		&perror("FATAL: PKGNAME".
			(($pkgname eq '')
				? ', which is derived from DISTNAME, '
				: ' ').
			"must come with version number, like \"foobaa-1.0\".");
		if ($i =~ /_pl[0-9]*$/
		 || $i =~ /_[0-9]*[A-Za-z]?[0-9]*(\.[0-9]*[A-Za-z]?[0-9]*)*$/) {
			&perror("FATAL: you seem to using underline ".
				"before version number in PKGNAME. ".
				"it has to be hyphen.");
		}
	}
	if ($distname =~ /(nb\d*)/) {
			&perror("WARN: is '$1' really ok on DISTNAME, ".
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
		print "OK: seen DISTFILES with single item, checking value.\n"
			if ($verbose);
		&perror("WARN: use of DISTFILES with single file ".
			"discouraged. distribution filename should be set by ".
			"DISTNAME and EXTRACT_SUFX.");
		if ($distfiles eq $distname . $extractsufx) {
			&perror("WARN: definition of DISTFILES not necessary. ".
				"DISTFILES is \${DISTNAME}/\${EXTRACT_SUFX} ".
				"by default.");
		}

		# make an advice only in certain cases.
		if ($pkgname ne '' && $distfiles =~ /^$pkgname([-\.].+)$/) {
			&perror("WARN: how about \"DISTNAME=$pkgname\"".
				(($1 eq '.tar.gz')
					? ""
					: " and \"EXTRACT_SUFX=$1\"").
				", instead of DISTFILES?");
		}
	}

	# additional checks for committer.
	$i = ($pkgname eq '') ? $distname : $pkgname;
	if ($committer && $i =~ /^(de|ja|ko|ru|vi|zh)-/) {
		&perror("WARN: be sure to include country code \"$1-\" ".
			"in the module alias name.");
	}
	if ($committer && -f "$portdir/$i.tgz") {
		&perror("WARN: be sure to remove $portdir/$i.tgz ".
			"before committing the package.");
	}

	push(@varnames, split(/\s+/, <<EOF));
DISTNAME PKGNAME SVR4_PKGNAME CATEGORIES MASTER_SITES MASTER_SITE_SUBDIR
EXTRACT_SUFX DISTFILES
EOF

	#
	# section 3: PATCH_SITES/PATCHFILES(optional)
	#
	print "OK: checking second section of $file, (PATCH*: optional).\n"
		if ($verbose);
	$tmp = $sections[$idx];

	if ($tmp =~ /(PATCH_SITES|PATCH_SITE_SUBDIR|PATCHFILES|PATCH_DIST_STRIP)/) {
		&checkearlier($tmp, @varnames);

                $tmp = "\n$tmp";

		if ($tmp =~ /\n(PATCH_SITES)=/) {
			print "OK: seen PATCH_SITES.\n" if ($verbose);
			$tmp =~ s/$1[^\n]+\n//;
		}
		if ($tmp =~ /\n(PATCH_SITE_SUBDIR)=/) {
			print "OK: seen PATCH_SITE_SUBDIR.\n" if ($verbose);
			$tmp =~ s/$1[^\n]+\n//;
		}
		if ($tmp =~ /\n(PATCHFILES)=/) {
			print "OK: seen PATCHFILES.\n" if ($verbose);
			$tmp =~ s/$1[^\n]+\n//;
		}
		if ($tmp =~ /\n(PATCH_DIST_ARGS)=/) {
			print "OK: seen PATCH_DIST_ARGS.\n" if ($verbose);
			$tmp =~ s/$1[^\n]+\n//;
		}
		if ($tmp =~ /\n(PATCH_DIST_STRIP)=/) {
			print "OK: seen PATCH_DIST_STRIP.\n" if ($verbose);
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
	print "OK: checking third section of $file (MAINTAINER).\n"
		if ($verbose);
	$tmp = $sections[$idx++];

	# check the order of items.
        @tocheck=split(/\s+/, <<EOF);
MAINTAINER HOMEPAGE COMMENT
EOF

        &checkorder('MAINTAINER', $tmp, @tocheck);

	# warnings for missing HOMEPAGE
	$tmp = "\n" . $tmp;
	if ($tmp !~ /\nHOMEPAGE=/) {
		&perror("WARN: please add HOMEPAGE if the package has one.");
	}

	# warnings for missing COMMENT
	if ($tmp !~ /\nCOMMENT=\s*(.*)$/) {
		&perror("FATAL: please add a short COMMENT describing the package.");
	}
	# and its properties:
	$tmp2 = $1;
	if ($tmp2 =~ /\.$/i) {
		&perror("WARN: COMMENT should not end with a '.' (period).");
	}
	if ($tmp2 =~ /^(a|an) /i) {
		&perror("WARN: COMMENT should not begin with '$1 '.");
	}
	if (length($tmp2) > 70) {
		&perror("WARN: COMMENT should not be longer than 70 characters.");
	}

	&checkearlier($tmp, @varnames);
	$tmp = "\n" . $tmp;
	if ($tmp =~ /\nMAINTAINER=[^\n]+/) {
		$tmp =~ s/\nMAINTAINER=[^\n]+//;
	} else {
		&perror("FATAL: no MAINTAINER listed in $file.");
                # Why is this fatal? There's a default in bsd.pkg.mk - HF
	}
	$tmp =~ s/\n\n+/\n/g;

	push(@varnames, split(/\s+/, <<EOF));
MAINTAINER HOMEPAGE COMMENT
EOF

	#
	# section 5: *_DEPENDS (may not be there)
	#
	print "OK: checking fourth section of $file(*_DEPENDS).\n"
		if ($verbose);
	$tmp = $sections[$idx];

	@linestocheck = split(/\s+/, <<EOF);
BUILD_USES_MSGFMT BUILD_DEPENDS DEPENDS
EOF
        if ($tmp =~ /(DEPENDS_TARGET|FETCH_DEPENDS|LIB_DEPENDS|RUN_DEPENDS).*=/) {
		&perror("WARN: $1 is deprecated, please use DEPENDS.");
	}
	if ($tmp =~ /(LIB_|BUILD_|RUN_|FETCH_)?DEPENDS/ or
	    $tmp =~ /BUILD_USES_MSGFMT/) {
		&checkearlier($tmp, @varnames);

		if (!defined $ENV{'PORTSDIR'}) {
			$ENV{'PORTSDIR'} = $portsdir;
		}
		foreach $i (grep(/^[A-Z_]*DEPENDS[?+]?=/, split(/\n/, $tmp))) {
			$i =~ s/^([A-Z_]*DEPENDS)[?+]?=[ \t]*//;
			$j = $1;
			print "OK: checking packages listed in $j.\n"
				if ($verbose);
			foreach $k (split(/\s+/, $i)) {
				# check BUILD_USES_MSGFMT
				if ($l =~ /^(msgfmt|gettext)$/) {
					&perror("WARN: dependency to $1 ".
						"listed in $j. Consider using".
						" BUILD_USES_MSGFMT.");
				}
				# check USE_PERL5
				$l = (split(':', $k))[0];
				if ($l =~ /^perl(\.\d+)?$/) {
					&perror("WARN: dependency to perl ".
						"listed in $j. Consider using".
						" USE_PERL5.");
				}

				# check USE_GMAKE
				if ($l =~ /^(gmake|\${GMAKE})$/) {
					&perror("WARN: dependency to $1 ".
						"listed in $j. Consider using".
						" USE_GMAKE.");
				}

				# check pkg dir existence
				$k = (split(':', $k))[1];
				$k =~ s/\${PKGSRCDIR}/$ENV{'PKGSRCDIR'}/;
				if (! -d "$portdir/$k") {
					&perror("WARN: no package directory $k ".
						"found, even though it is ".
						"listed in $j.");
				} else {
					print "OK: package directory $k found.\n"
						if ($verbose);
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
	print "OK: checking the rest of the $file.\n" if ($verbose);
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
	print "OK: checking WRKSRC.\n" if ($verbose);
	$wrksrc = $nowrksubdir = '';
	$wrksrc = $1 if ($tmp =~ /\nWRKSRC[+?]?=[ \t]*([^\n]*)\n/);
	$nowrksubdir = $1 if ($tmp =~ /\nNO_WRKSUBDIR[+?]?=[ \t]*([^\n]*)\n/);
	if ($nowrksubdir eq '') {
		$realwrksrc = $wrksrc ? "$wrksrc/$distname"
				      : "\${WRKDIR}/$distname";
	} else {
		$realwrksrc = $wrksrc ? $wrksrc : '${WRKDIR}';
	}
	print "OK: WRKSRC seems to be $realwrksrc.\n" if ($verbose);

	if ($nowrksubdir eq '') {
		print "OK: no NO_WRKSUBDIR, checking value of WRKSRC.\n"
			if ($verbose);
		if ($wrksrc eq 'work' || $wrksrc =~ /^$[\{\(]WRKDIR[\}\)]/) {
			&perror("WARN: WRKSRC is set to meaningless value ".
				"\"$1\".".
				($nowrksubdir eq ''
					? " use \"NO_WRKSUBDIR=yes\" instead."
					: ""));
		}
		if ($bogusdistfiles) {
			if ($distname ne '' && $wrksrc eq '') {
			    &perror("WARN: do not use DISTFILES and DISTNAME ".
				"to control WRKSRC. how about ".
				"\"WRKSRC=\${WRKDIR}/$distname\"?");
			} else {
			    &perror("WARN: DISTFILES/DISTNAME affects WRKSRC. ".
				"Use caution when changing them.");
			}
		}
	} else {
		print "OK: seen NO_WRKSUBDIR, checking value of WRKSRC.\n"
			if ($verbose);
		if ($wrksrc eq 'work' || $wrksrc =~ /^$[\{\(]WRKDIR[\}\)]/) {
			&perror("WARN: definition of WRKSRC not necessary. ".
				"WRKSRC is \${WRKDIR} by default.");
		}
	}

	# check USE_X11 and USE_IMAKE
	if ($tmp =~ /\nUSE_IMAKE[?+]?=/ && $tmp =~ /\nUSE_X11[?+]?=/) {
		&perror("WARN: since you already have USE_IMAKE, ".
			"you don't need USE_X11.");
	}

	# check direct use of important make targets.
	if ($tmp =~ /\n(fetch|extract|patch|configure|build|install):/) {
		&perror("FATAL: direct redefinition of make target \"$1\" ".
			"discouraged. redefine \"do-$1\" instead.");
	}

	1;
}

sub perror {
	local(@msg) = @_;
	if ($msg[0] =~ /^FATAL/) {
		$err++;
	} else {
		$warn++;
	}
	print join("\n", @msg) . "\n";
}

sub checkextra {
	local($str, $section) = @_;

	$str = "\n" . $str if ($str !~ /^\n/);
	$str =~ s/\n#[^\n]*/\n/g;
	$str =~ s/\n\n+/\n/g;
	$str =~ s/^\s+//;
	$str =~ s/\s+$//;
	return if ($str eq '');

	if ($str =~ /^([\w\d]+)/) {
		&perror("WARN: extra item placed in the ".
			"$section section, ".
			"for example, \"$1\".");
	} else {
		&perror("WARN: extra item placed in the ".
			"$section section.");
	}
}

sub checkorder {
	local($section, $str, @order) = @_;
	local(@items, $i, $j, $k, $invalidorder);

	print "OK: checking the order of $section section.\n" if ($verbose);

	@items = ();
	foreach $i (split("\n", $tmp)) {
		$i =~ s/[+?]?=.*$//;
		push(@items, $i);
	}

	@items = reverse(@items);
	$j = -1;
	$invalidorder = 0;
	while (scalar(@items)) {
		$i = pop(@items);
		$k = 0;
		while ($k < scalar(@order) && $order[$k] ne $i) {
			$k++;
		}
		if ($order[$k] eq $i) {
			if ($k < $j) {
				&perror("FATAL: $i appears out-of-order.");
				$invalidorder++;
			} else {
				print "OK: seen $i, in order.\n" if ($verbose);
			}
			$j = $k;
		} else {
			&perror("FATAL: extra item \"$i\" placed in".
				" the $section section.");
		}
	}
	if ($invalidorder) {
		&perror("FATAL: order must be " . join('/', @order) . '.');
	} else {
		print "OK: $section section is ordered properly.\n"
			if ($verbose);
	}
}

sub checkearlier {
	local($str, @varnames) = @_;
	local($i);

	print "OK: checking items that have to appear earlier.\n" if ($verbose);
	foreach $i (@varnames) {
		if ($str =~ /\n$i[?+]?=/) {
			&perror("WARN: \"$i\" has to appear earlier in $file.");
		}
	}
}

sub abspathname {
	local($str, $file) = @_;
	local($s, $i, %cmdnames);
	local($pre);

	# ignore parameter string to echo command
	$str =~ s/[ \t][\@-]?(echo|\$[\{\(]ECHO[\}\)]|\$[\{\(]ECHO_MSG[\}\)])[ \t]+("(\\'|\\"|[^"])*"|'(\\'|\\"|[^"])*')[ \t]*[;\n]//;

	print "OK: checking direct use of full pathnames in $file.\n"
		if ($verbose);
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
			&perror("WARN: possible use of absolute pathname ".
				"\"$i\", in $file.");
		}
	}

	print "OK: checking direct use of pathnames, phase 1.\n" if ($verbose);
%cmdnames = split(/\n|\t+/, <<EOF);
/usr/opt	\${PORTSDIR} instead
$portsdir	\${PORTSDIR} instead
$localbase	\${PREFIX} or \${LOCALBASE}, as appropriate
/usr/X11	\${PREFIX} or \${X11BASE}, as appropriate
/usr/X11R6	\${PREFIX} or \${X11BASE}, as appropriate
EOF
	foreach $i (keys %cmdnames) {
		if ($str =~ /$i/) {
			&perror("WARN: possible direct use of \"$&\" ".
				"found in $file. if so, use $cmdnames{$i}.");
		}
	}

	print "OK: checking direct use of pathnames, phase 2.\n" if ($verbose);
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
			&perror("WARN: possible direct use of \"$i\" ".
				"found in $file. if so, use $cmdnames{$i}.");
		}
	}
}

sub is_predefined {
	local($url) = @_;
	local($site);
	local($subdir);
	if ($site = (grep($url =~ $_, keys %predefined))[0]) {
		$url =~ /$site/;
		$subdir = $';
		$subdir =~ s/\/$//;
		&perror("WARN: how about using ".
			"\${MASTER_SITE_$predefined{$site}:=$subdir/} instead of \"$url\?");
		return &TRUE;
	}
	undef;
}

sub TRUE {1;}
