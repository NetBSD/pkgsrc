$NetBSD: patch-config.m4,v 1.2 2021/06/06 07:20:05 taca Exp $

Recognize pkgsrc's ${PREFIX}.

--- config.m4.orig	2021-04-10 20:05:04.000000000 +0000
+++ config.m4
@@ -14,7 +14,7 @@ PHP_ARG_WITH(gnupg, for gnupg support,
 [  --with-gnupg[=dir]       Include gnupg support])
 
 if test "$PHP_GNUPG" != "no"; then
-  SEARCH_PATH="/usr/local /usr /opt"
+  SEARCH_PATH="${PREFIX} /usr/local /usr /opt"
   SEARCH_FOR="include/gpgme.h"
   SEARCH_FOR_ALT="include/gpgme/gpgme.h"
   if test -r $PHP_GNUPG/$SEARCH_FOR; then
