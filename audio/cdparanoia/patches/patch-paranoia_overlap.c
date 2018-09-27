$NetBSD: patch-paranoia_overlap.c,v 1.1 2018/09/27 19:35:08 triaxx Exp $

Fix lossy conversion with abs() on FreeBSD.

--- paranoia/overlap.c.orig	2008-08-06 18:27:41.000000000 +0000
+++ paranoia/overlap.c
@@ -107,7 +107,11 @@ void offset_adjust_settings(cdrom_parano
        sector, frob it.  We just want a little hysteresis [sp?]*/
     long av=(p->stage2.offpoints?p->stage2.offaccum/p->stage2.offpoints:0);
     
+#if defined(__FreeBSD__)
+    if(labs(av)>p->dynoverlap/4){
+#else
     if(abs(av)>p->dynoverlap/4){
+#endif
       av=(av/MIN_SECTOR_EPSILON)*MIN_SECTOR_EPSILON;
       
       if(callback)(*callback)(ce(p->root.vector),PARANOIA_CB_DRIFT);
@@ -207,7 +211,11 @@ void offset_add_value(cdrom_paranoia *p,
   if(o->offpoints!=-1){
 
     /* Track the average magnitude of jitter (in either direction) */
+#if defined(__FreeBSD__)
+    o->offdiff+=labs(value);
+#else
     o->offdiff+=abs(value);
+#endif
     o->offpoints++;
     o->newpoints++;
 
