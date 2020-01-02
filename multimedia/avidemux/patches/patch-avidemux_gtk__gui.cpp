$NetBSD: patch-avidemux_gtk__gui.cpp,v 1.1 2020/01/02 19:47:04 rhialto Exp $

gcc7: error: call of overloaded 'abs(__uint32_t)' is ambiguous

--- avidemux/gtk_gui.cpp.orig	2010-06-22 06:30:27.000000000 +0000
+++ avidemux/gtk_gui.cpp
@@ -1795,7 +1795,7 @@ uint8_t ADM_saveRaw (const char *name)
 	    }
 	  if (!found)
           {
-            if(abs(i-frameEnd)>2)
+            if(abs((int64_t)i-(int64_t)frameEnd)>2)
                 ret=0;
             else
                 ret=1;  // Good enough
