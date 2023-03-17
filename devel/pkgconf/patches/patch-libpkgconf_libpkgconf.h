$NetBSD: patch-libpkgconf_libpkgconf.h,v 1.1 2023/03/17 20:20:45 riastradh Exp $

Fix ctype(3) misuse.
https://github.com/pkgconf/pkgconf/issues/291
https://github.com/pkgconf/pkgconf/pull/292

--- libpkgconf/libpkgconf.h.orig	2023-01-22 04:55:57.000000000 +0000
+++ libpkgconf/libpkgconf.h
@@ -249,7 +249,7 @@ PKGCONF_API pkgconf_cross_personality_t 
 PKGCONF_API pkgconf_cross_personality_t *pkgconf_cross_personality_find(const char *triplet);
 PKGCONF_API void pkgconf_cross_personality_deinit(pkgconf_cross_personality_t *personality);
 
-#define PKGCONF_IS_MODULE_SEPARATOR(c) ((c) == ',' || isspace ((unsigned int)(c)))
+#define PKGCONF_IS_MODULE_SEPARATOR(c) ((c) == ',' || isspace ((unsigned char)(c)))
 #define PKGCONF_IS_OPERATOR_CHAR(c) ((c) == '<' || (c) == '>' || (c) == '!' || (c) == '=')
 
 #define PKGCONF_PKG_PKGF_NONE				0x0000
