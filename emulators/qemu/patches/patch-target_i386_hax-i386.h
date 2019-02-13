$NetBSD: patch-target_i386_hax-i386.h,v 1.1 2019/02/13 05:16:12 kamil Exp $

Cherry-pick:
 - hax: Support for Linux hosts [modified for pkgsrc]
   b65cc8dec07fec77dbda7bc5daf1defcb7c411d9

--- target/i386/hax-i386.h.orig	2018-12-11 17:44:34.000000000 +0000
+++ target/i386/hax-i386.h
@@ -16,7 +16,7 @@
 #include "cpu.h"
 #include "sysemu/hax.h"
 
-#ifdef CONFIG_DARWIN
+#ifdef CONFIG_POSIX
 typedef int hax_fd;
 #endif
 
@@ -82,7 +82,7 @@ hax_fd hax_mod_open(void);
 void hax_memory_init(void);
 
 
-#ifdef CONFIG_DARWIN
+#ifdef CONFIG_POSIX
 #include "target/i386/hax-darwin.h"
 #endif
 
