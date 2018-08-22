$NetBSD: patch-cflags.SH,v 1.3 2018/08/22 08:37:46 wiz Exp $

Don't add -std=c89 or -ansi, requires c99.

--- cflags.SH.orig	2018-05-21 12:29:23.000000000 +0000
+++ cflags.SH
@@ -178,7 +178,7 @@ Intel*) ;; # # Is that you, Intel C++?
 # -std=c89 before -ansi
 # -pedantic* before -Werror=d-a-s
 #
-*)  for opt in -std=c89 -ansi $pedantic \
+*)  for opt in $pedantic \
 		-Werror=declaration-after-statement \
 	        -Werror=pointer-arith \
 		-Wextra -W \
