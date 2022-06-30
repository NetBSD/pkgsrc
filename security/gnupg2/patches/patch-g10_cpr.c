$NetBSD: patch-g10_cpr.c,v 1.1 2022/06/30 14:48:55 wiz Exp $

g10: Fix garbled status messages in NOTATION_DATA

* g10/cpr.c (write_status_text_and_buffer): Fix off-by-one

Depending on the escaping and line wrapping the computed remaining
buffer length could be wrong. Fixed by always using a break to
terminate the escape detection loop. Might have happened for all
status lines which may wrap.

https://dev.gnupg.org/rG34c649b3601383cd11dbc76221747ec16fd68e1b

--- g10/cpr.c.orig	2022-02-24 13:06:37.000000000 +0000
+++ g10/cpr.c
@@ -328,20 +328,15 @@ write_status_text_and_buffer (int no, co
             }
           first = 0;
         }
-      for (esc=0, s=buffer, n=len; n && !esc; s++, n--)
+      for (esc=0, s=buffer, n=len; n; s++, n--)
         {
           if (*s == '%' || *(const byte*)s <= lower_limit
               || *(const byte*)s == 127 )
             esc = 1;
           if (wrap && ++count > wrap)
-            {
-              dowrap=1;
-              break;
-            }
-        }
-      if (esc)
-        {
-          s--; n++;
+            dowrap=1;
+          if (esc || dowrap)
+            break;
         }
       if (s != buffer)
         es_fwrite (buffer, s-buffer, 1, statusfp);
