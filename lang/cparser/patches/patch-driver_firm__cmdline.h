$NetBSD: patch-driver_firm__cmdline.h,v 1.1 2014/06/29 04:53:26 dholland Exp $

Remove accidental global variable. On most Unix platforms such
variables become commons and don't get noticed, but on platforms
without commons or with commons disabled, this results in a multiply
defined symbol.

--- driver/firm_cmdline.h~	2009-05-15 11:27:34.000000000 +0000
+++ driver/firm_cmdline.h
@@ -16,7 +16,7 @@ enum an_os_support {
   OS_SUPPORT_LINUX,         /**< create code for Linux OS */
   OS_SUPPORT_MINGW,         /**< create code for MinGW WIN32 */
   OS_SUPPORT_MACHO          /**< create code for MacOS Mach-O */
-} an_os_support;
+};
 
 enum a_debug_mode {
   DBG_MODE_NONE      = 0,   /**< no special debug support */
