$NetBSD: patch-src_gettext.h,v 1.1 2016/04/03 12:48:38 joerg Exp $

--- src/gettext.h.orig	2016-04-02 21:13:28.754215955 +0000
+++ src/gettext.h
@@ -93,6 +93,8 @@
 
 #endif
 
+#include <locale.h>
+
 /* A pseudo function call that serves as a marker for the automated
    extraction of messages, but does not call gettext().  The run-time
    translation is done at a different place in the code.
