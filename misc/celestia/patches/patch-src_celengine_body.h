$NetBSD: patch-src_celengine_body.h,v 1.1 2023/01/16 03:03:57 dholland Exp $

#undef sun before using it as an identifier, because Solaris.

--- src/celengine/body.h~	2011-06-05 16:11:09.000000000 +0000
+++ src/celengine/body.h
@@ -24,6 +24,8 @@
 #include <celengine/rotation.h>
 #include <celengine/timeline.h>
 
+#undef sun
+
 class ReferenceFrame;
 class Body;
 class FrameTree;
