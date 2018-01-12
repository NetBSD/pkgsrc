$NetBSD: patch-cflags.SH,v 1.1 2018/01/12 11:32:21 jperkin Exp $

Don't add -std=c89, requires c99.

--- cflags.SH.orig	2017-07-18 22:49:30.000000000 +0000
+++ cflags.SH
@@ -186,7 +186,7 @@ Intel*) ;; # # Is that you, Intel C++?
 # -std=c89 before -ansi
 # -pedantic* before -Werror=d-a-s
 #
-*)  for opt in -std=c89 -ansi $pedantic \
+*)  for opt in -ansi $pedantic \
 		-Werror=declaration-after-statement \
 		-Wextra -W \
 		-Wc++-compat -Wwrite-strings
