$NetBSD: patch-Makefile.PL,v 1.2 2015/12/10 18:54:12 tron Exp $

1.) Handle the pkgsrc "krb5-config" wrapper for SunOS.
2.) Strip trailing linefeeds and other whitespace from the output of
    the "krb5-config" wrapper to avoid generation of a broken makefile.

--- Makefile.PL.orig	2010-04-24 13:37:38.000000000 +0100
+++ Makefile.PL	2015-12-10 18:50:38.000000000 +0000
@@ -115,7 +115,7 @@
     unless ($libconf) {
        die "$krb5cmd does not respond libconf!";
     } else {
-      if ($libconf =~ /Unknown/ && $implementation =~ /Solaris Kerberos/) {
+      if ($implementation =~ /Solaris Kerberos/) {
             $libconf = "-L/usr/lib -R/usr/lib -lgss";
       }
 
@@ -153,7 +153,7 @@
        #
        $incconf = '-I/usr/include';
     }
-    if ($incconf =~ /Unknown/ && $implementation =~ /Solaris Kerberos/) {
+    if ($implementation =~ /Solaris Kerberos/) {
           $incconf = "-I/usr/include/kerberosv5";
           push @EXTRADEFINES,  '-DSEAM';
     }
@@ -240,20 +240,26 @@
 sub krb5_libconfig {
    my ($cfgcmd) = @_;
    $cfgcmd || die 'no $cfgcmd ';
-   return `$cfgcmd --libs gssapi`;
+   my $output = `$cfgcmd --libs gssapi`;
+   chomp( $output );
+   return $output;
 }
 #-------------------------------------------------
 #-------------------------------------------------
 sub krb5_cflags  {
    my ($cfgcmd) = @_;
    $cfgcmd || die 'no $cfgcmd ';
-   return `$cfgcmd --cflags gssapi`;
+   my $output = `$cfgcmd --cflags gssapi`;
+   chomp( $output );
+   return $output;
 }
 #-------------------------------------------------
 sub krb5_version {
    my ($cfgcmd) = @_;
    $cfgcmd || die 'no $cfgcmd ';
-   return `$cfgcmd --version`;
+   my $output = `$cfgcmd --version`;
+   chomp( $output );
+   return $output;
 }
 #-------------------------------------------------
 #-------------------------------------------------
