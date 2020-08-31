$NetBSD: patch-cflags.SH,v 1.4 2020/08/31 18:00:37 wiz Exp $

Don't add -std=c89 or -ansi, requires c99.

--- cflags.SH.orig	2020-06-14 23:01:24.000000000 +0000
+++ cflags.SH
@@ -178,7 +178,7 @@ Intel*) ;; # # Is that you, Intel C++?
 # -std=c89 before -ansi
 # -pedantic* before -Werror=d-a-s
 #
-*) warns="-std=c89 -ansi $pedantic \
+*) warns="$pedantic \
 	-Werror=pointer-arith \
 	-Wextra -W \
 	-Wc++-compat -Wwrite-strings"
