$NetBSD: patch-module_ffdecode.c,v 1.1 2017/06/24 19:39:47 adam Exp $

Fix for duplicate symbol PyGAME_C_API.
Fix for deprecated AVCODEC_MAX_AUDIO_FRAME_SIZE.

--- module/ffdecode.c.orig	2014-07-06 14:22:40.000000000 +0000
+++ module/ffdecode.c
@@ -19,7 +19,7 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
  */
 
-#include <pygame/pygame.h>
+#include <pygame/_pygame.h>
 #include <math.h>
 #include <limits.h>
 #include <libavutil/avstring.h>
@@ -101,6 +101,7 @@ typedef struct VideoState {
        compensation */
 
 #ifndef HAS_RESAMPLE
+#define AVCODEC_MAX_AUDIO_FRAME_SIZE 19200
     uint8_t audio_buf1[(AVCODEC_MAX_AUDIO_FRAME_SIZE * 3) / 2] __attribute__ ((aligned (16))) ;
     uint8_t audio_buf2[(AVCODEC_MAX_AUDIO_FRAME_SIZE * 3) / 2] __attribute__ ((aligned (16))) ;
 #else
