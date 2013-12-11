$NetBSD: patch-Makefile.PL,v 1.1 2013/12/11 10:29:45 jperkin Exp $

Handle the pkgsrc krb5-config wrapper for SunOS.

--- Makefile.PL.orig	2010-04-24 12:37:38.000000000 +0000
+++ Makefile.PL
@@ -115,7 +115,7 @@ if (exists $options{gssapi_libs} || exis
     unless ($libconf) {
        die "$krb5cmd does not respond libconf!";
     } else {
-      if ($libconf =~ /Unknown/ && $implementation =~ /Solaris Kerberos/) {
+      if ($implementation =~ /Solaris Kerberos/) {
             $libconf = "-L/usr/lib -R/usr/lib -lgss";
       }
 
@@ -153,7 +153,7 @@ if (exists $options{gssapi_libs} || exis
        #
        $incconf = '-I/usr/include';
     }
-    if ($incconf =~ /Unknown/ && $implementation =~ /Solaris Kerberos/) {
+    if ($implementation =~ /Solaris Kerberos/) {
           $incconf = "-I/usr/include/kerberosv5";
           push @EXTRADEFINES,  '-DSEAM';
     }
