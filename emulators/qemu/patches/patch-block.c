$NetBSD: patch-block.c,v 1.2 2018/04/25 07:56:05 adam Exp $

Remove block driver whitelisting logic; reasons being:
- PkgSrc does not configure Qemu to use whitelisting
- sometimes CONFIG...WHITELIST macros contain ["", NULL],
  and bdrv_is_whitelisted() fails.

--- block.c.orig	2018-03-27 22:29:23.000000000 +0000
+++ block.c
@@ -373,31 +373,7 @@ BlockDriver *bdrv_find_format(const char
 
 int bdrv_is_whitelisted(BlockDriver *drv, bool read_only)
 {
-    static const char *whitelist_rw[] = {
-        CONFIG_BDRV_RW_WHITELIST
-    };
-    static const char *whitelist_ro[] = {
-        CONFIG_BDRV_RO_WHITELIST
-    };
-    const char **p;
-
-    if (!whitelist_rw[0] && !whitelist_ro[0]) {
-        return 1;               /* no whitelist, anything goes */
-    }
-
-    for (p = whitelist_rw; *p; p++) {
-        if (!strcmp(drv->format_name, *p)) {
-            return 1;
-        }
-    }
-    if (read_only) {
-        for (p = whitelist_ro; *p; p++) {
-            if (!strcmp(drv->format_name, *p)) {
-                return 1;
-            }
-        }
-    }
-    return 0;
+    return 1;
 }
 
 bool bdrv_uses_whitelist(void)
