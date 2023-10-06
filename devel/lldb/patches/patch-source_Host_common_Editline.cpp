$NetBSD: patch-source_Host_common_Editline.cpp,v 1.1 2023/10/06 19:15:20 adam Exp $

Remove the hack for Darwin.

--- source/Host/common/Editline.cpp.orig	2023-06-05 11:41:28.000000000 +0000
+++ source/Host/common/Editline.cpp
@@ -37,12 +37,6 @@ using namespace lldb_private::line_edito
 // assumption that may not exist on other platforms.  The setupterm() function
 // would normally require headers that don't work gracefully in this context,
 // so the function declaration has been hoisted here.
-#if defined(__APPLE__)
-extern "C" {
-int setupterm(char *term, int fildes, int *errret);
-}
-#define USE_SETUPTERM_WORKAROUND
-#endif
 
 // Editline uses careful cursor management to achieve the illusion of editing a
 // multi-line block of text with a single line editor.  Preserving this
