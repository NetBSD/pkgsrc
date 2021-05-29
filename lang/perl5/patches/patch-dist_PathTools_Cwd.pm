$NetBSD: patch-dist_PathTools_Cwd.pm,v 1.1 2021/05/29 13:04:21 rin Exp $

Compare inode numbers as string to fix pkg/55997. Cherry-picked from
upstream. See https://github.com/Perl/perl5/pull/18788 for more details.

--- dist/PathTools/Cwd.pm.orig	2021-05-13 17:22:53.506472893 +0900
+++ dist/PathTools/Cwd.pm	2021-05-13 17:23:02.173970018 +0900
@@ -275,7 +275,7 @@
 	($odev, $oino) = ($cdev, $cino);
 	CORE::chdir('..') || return undef;
 	($cdev, $cino) = stat('.');
-	last if $odev == $cdev && $oino == $cino;
+	last if $odev == $cdev && $oino eq $cino;
 	opendir(DIR, '.') || return undef;
 	for (;;) {
 	    $direntry = readdir(DIR);
@@ -284,7 +284,7 @@
 	    next if $direntry eq '..';
 
 	    ($tdev, $tino) = lstat($direntry);
-	    last unless $tdev != $odev || $tino != $oino;
+	    last unless $tdev != $odev || $tino ne $oino;
 	}
 	closedir(DIR);
 	return undef unless defined $direntry; # should never happen
@@ -298,7 +298,7 @@
 	&& CORE::chdir($1) or return undef;
     ($cdev, $cino) = stat('.');
     die "Unstable directory path, current directory changed unexpectedly"
-	if $cdev != $orig_cdev || $cino != $orig_cino;
+	if $cdev != $orig_cdev || $cino ne $orig_cino;
     $path;
 }
 if (not defined &fastcwd) { *fastcwd = \&fastcwd_ }
@@ -315,7 +315,7 @@
     if ($ENV{'PWD'} and $^O ne 'os2' and $^O ne 'dos' and $^O ne 'MSWin32') {
 	my($dd,$di) = stat('.');
 	my($pd,$pi) = stat($ENV{'PWD'});
-	if (!defined $dd or !defined $pd or $di != $pi or $dd != $pd) {
+	if (!defined $dd or !defined $pd or $di ne $pi or $dd != $pd) {
 	    $ENV{'PWD'} = cwd();
 	}
     }
@@ -328,7 +328,7 @@
     if ($^O ne 'MSWin32' and $ENV{'PWD'} =~ m|(/[^/]+(/[^/]+/[^/]+))(.*)|s) {
 	my($pd,$pi) = stat($2);
 	my($dd,$di) = stat($1);
-	if (defined $pd and defined $dd and $di == $pi and $dd == $pd) {
+	if (defined $pd and defined $dd and $di eq $pi and $dd == $pd) {
 	    $ENV{'PWD'}="$2$3";
 	}
     }
@@ -430,7 +430,7 @@
 	    $! = $e;
 	    return undef;
 	}
-	if ($pst[0] == $cst[0] && $pst[1] == $cst[1])
+	if ($pst[0] == $cst[0] && $pst[1] eq $cst[1])
 	{
 	    $dir = undef;
 	}
@@ -448,7 +448,7 @@
 		$tst[0] = $pst[0]+1 unless (@tst = lstat("$dotdots/$dir"))
 	    }
 	    while ($dir eq '.' || $dir eq '..' || $tst[0] != $pst[0] ||
-		   $tst[1] != $pst[1]);
+		   $tst[1] ne $pst[1]);
 	}
 	$cwd = (defined $dir ? "$dir" : "" ) . "/$cwd" ;
 	closedir(PARENT);
