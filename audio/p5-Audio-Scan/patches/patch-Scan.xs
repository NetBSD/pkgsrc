$NetBSD: patch-Scan.xs,v 1.1 2025/07/07 07:01:07 wiz Exp $

Fix compatibility with Perl 5.42.0
https://rt.cpan.org/Public/Bug/Display.html?id=167903

--- Scan.xs.orig	2025-07-07 06:58:32.291403812 +0000
+++ Scan.xs
@@ -214,7 +214,7 @@ _generate_hash(const char *file)
 MODULE = Audio::Scan		PACKAGE = Audio::Scan
 
 HV *
-_scan( char *, char *suffix, PerlIO *infile, SV *path, int filter, int md5_size, int md5_offset )
+_scan( char *a, char *suffix, PerlIO *infile, SV *path, int filter, int md5_size, int md5_offset )
 CODE:
 {
   taghandler *hdl;
@@ -266,7 +266,7 @@ OUTPUT:
   RETVAL
   
 int
-_find_frame( char *, char *suffix, PerlIO *infile, SV *path, int offset )
+_find_frame( char *a, char *suffix, PerlIO *infile, SV *path, int offset )
 CODE:
 {
   taghandler *hdl;
@@ -282,7 +282,7 @@ OUTPUT:
   RETVAL
 
 HV *
-_find_frame_return_info( char *, char *suffix, PerlIO *infile, SV *path, int offset )
+_find_frame_return_info( char *a, char *suffix, PerlIO *infile, SV *path, int offset )
 CODE:
 {
   taghandler *hdl = _get_taghandler(suffix);
@@ -306,7 +306,7 @@ OUTPUT:
   RETVAL
 
 int
-is_supported(char *, SV *path)
+is_supported(char *a, SV *path)
 CODE:
 {
   char *suffix = strrchr( SvPVX(path), '.' );
@@ -322,7 +322,7 @@ OUTPUT:
   RETVAL
 
 SV *
-type_for(char *, SV *suffix)
+type_for(char *a, SV *suffix)
 CODE:
 {
   taghandler *hdl = NULL;
@@ -360,7 +360,7 @@ OUTPUT:
   RETVAL
 
 AV *
-extensions_for(char *, SV *type)
+extensions_for(char *a, SV *type)
 CODE:
 {
   int i, j;
