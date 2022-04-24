$NetBSD: patch-src_sunaudio.c,v 1.2 2022/04/24 09:39:46 nia Exp $

- Make the now unused (in the audio driver's case) void *fp member of the
  sox_format_t structure a pointer to the filedescriptor of the audio
  device in the driver and reference it in adjust_volume() with an
  additional check for NULL. (PR pkg/56800)

- Fix segfault when playing (PR pkg/49929).

--- src/sunaudio.c.orig	2014-10-06 01:59:34.000000000 +0000
+++ src/sunaudio.c
@@ -336,6 +336,8 @@ static int sunstartwrite(sox_format_t * 
     pPriv->cOutput = sox_globals.bufsiz >> pPriv->sample_shift;
     pPriv->pOutput = lsx_malloc((size_t)pPriv->cOutput << pPriv->sample_shift);
 
+    ft->fp = &pPriv->device;
+
     return (SOX_SUCCESS);
 }
 
@@ -348,6 +350,7 @@ static int sunstop(sox_format_t* ft)
     if (pPriv->pOutput) {
         free(pPriv->pOutput);
     }
+    ft->fp = NULL;
     return SOX_SUCCESS;
 }
 
@@ -443,7 +446,7 @@ static size_t sunwrite(
         size_t cbStride;
         int cbWritten;
 
-        cStride = cInput;
+        cStride = cInputRemaining;
         if (cStride > pPriv->cOutput) {
             cStride = pPriv->cOutput;
         }
