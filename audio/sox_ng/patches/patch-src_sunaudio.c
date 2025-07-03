$NetBSD: patch-src_sunaudio.c,v 1.1 2025/07/03 15:46:59 wiz Exp $

- Make the now unused (in the audio driver's case) void *fp member of the
  sox_format_t structure a pointer to the filedescriptor of the audio
  device in the driver and reference it in adjust_volume() with an
  additional check for NULL. (PR pkg/56800)

- Fix segfault when playing (PR pkg/49929).

--- src/sunaudio.c.orig	2025-05-26 15:24:07.000000000 +0000
+++ src/sunaudio.c
@@ -334,6 +334,8 @@ static int sunstartwrite(sox_format_t * 
     pPriv->cOutput = sox_globals.bufsiz >> pPriv->sample_shift;
     pPriv->pOutput = lsx_malloc((size_t)pPriv->cOutput << pPriv->sample_shift);
 
+    ft->fp = &pPriv->device;
+
     return (SOX_SUCCESS);
 }
 
@@ -346,6 +348,7 @@ static int sunstop(sox_format_t* ft)
     if (pPriv->pOutput) {
         free(pPriv->pOutput);
     }
+    ft->fp = NULL;
     return SOX_SUCCESS;
 }
 
@@ -441,7 +444,7 @@ static size_t sunwrite(
         size_t cbStride;
         int cbWritten;
 
-        cStride = cInput;
+        cStride = cInputRemaining;
         if (cStride > pPriv->cOutput) {
             cStride = pPriv->cOutput;
         }
