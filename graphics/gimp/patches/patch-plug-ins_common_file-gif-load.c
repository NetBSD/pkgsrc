$NetBSD: patch-plug-ins_common_file-gif-load.c,v 1.1 2012/08/20 12:54:01 wiz Exp $

From: Jan Lieskovsky <jlieskov@redhat.com>
Date: Tue, 14 Aug 2012 12:18:22 +0200
Subject: [PATCH 1/2] file-gif-load: limit len and height (CVE-2012-3481)

Ensure values of len and height can't overflow g_malloc() argument type.
(cherry picked from commit d95c2f0bcb6775bdee2bef35b7d84f6dfd490783)

From: Nils Philippsen <nils@redhat.com>
Date: Tue, 14 Aug 2012 15:27:39 +0200
Subject: [PATCH 2/2] file-gif-load: fix type overflow (CVE-2012-3481)

Cast variables properly to avoid overflowing when computing how much
memory to allocate.
(cherry picked from commit 43fc9dbd8e2196944c8a71321e525b89b7df9f5c)

--- plug-ins/common/file-gif-load.c.orig	2012-03-12 19:18:10.000000000 +0000
+++ plug-ins/common/file-gif-load.c
@@ -1057,10 +1057,17 @@ ReadImage (FILE        *fd,
   cur_progress = 0;
   max_progress = height;
 
+  if (len > (G_MAXSIZE / height / (alpha_frame ? (promote_to_rgb ? 4 : 2) : 1)))
+  {
+    g_message ("'%s' has a larger image size than GIMP can handle.",
+               gimp_filename_to_utf8 (filename));
+    return -1;
+  }
+
   if (alpha_frame)
-    dest = (guchar *) g_malloc (len * height * (promote_to_rgb ? 4 : 2));
+    dest = (guchar *) g_malloc ((gsize)len * (gsize)height * (promote_to_rgb ? 4 : 2));
   else
-    dest = (guchar *) g_malloc (len * height);
+    dest = (guchar *) g_malloc ((gsize)len * (gsize)height);
 
 #ifdef GIFDEBUG
     g_print ("GIF: reading %d by %d%s GIF image, ncols=%d\n",
