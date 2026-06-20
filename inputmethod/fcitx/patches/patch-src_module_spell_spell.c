$NetBSD: patch-src_module_spell_spell.c,v 1.1 2026/06/20 09:29:04 nia Exp $

Fix implicit declaration of index(3) by including the correct header.

--- src/module/spell/spell.c.orig	2026-06-20 09:18:28.799075383 +0000
+++ src/module/spell/spell.c
@@ -22,6 +22,7 @@
 #include "config.h"
 
 #include <libintl.h>
+#include <strings.h>
 #include <errno.h>
 
 #include "fcitx/ime.h"
