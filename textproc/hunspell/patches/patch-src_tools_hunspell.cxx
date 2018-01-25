$NetBSD: patch-src_tools_hunspell.cxx,v 1.1 2018/01/25 10:43:59 jperkin Exp $

C++11 requires a space between literal and identifier

--- src/tools/hunspell.cxx.orig	2018-01-24 18:44:15.895346290 +0000
+++ src/tools/hunspell.cxx
@@ -17,7 +17,7 @@
 #define HUNSPELL_VERSION VERSION
 #define INPUTLEN 50
 
-#define HUNSPELL_PIPE_HEADING "@(#) International Ispell Version 3.2.06 (but really Hunspell "VERSION")\n"
+#define HUNSPELL_PIPE_HEADING "@(#) International Ispell Version 3.2.06 (but really Hunspell " VERSION ")\n"
 #define HUNSPELL_HEADING "Hunspell "
 #define ODF_EXT "odt|ott|odp|otp|odg|otg|ods|ots"
 #define ENTITY_APOS "&apos;"
