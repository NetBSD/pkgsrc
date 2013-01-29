$NetBSD: patch-src_libkernsubr.pl,v 1.1 2013/01/29 15:48:55 taca Exp $

Allow e-mail address which contains '+' character in local-part.

--- src/libkernsubr.pl.orig	2003-12-17 14:46:54.000000000 +0000
+++ src/libkernsubr.pl
@@ -50,7 +50,7 @@ sub __SecureP 
     # XXX: and for permitting a special backward compatibility.
     # permit Email Address, 100.tar.gz, # command, # mget 100,last:10 mp ...
     # if ($s =~ /^[\#\s\w\-\[\]\?\*\.\,\@\:]+$/) {
-    if ($s =~ /^[\#\s\w\-\.\,\@\:]+$/) {
+    if ($s =~ /^[\#\s\w\-\+\.\,\@\:]+$/) {
 	1;
     }
     # since, this ; | is not checked when interact with shell in command.
