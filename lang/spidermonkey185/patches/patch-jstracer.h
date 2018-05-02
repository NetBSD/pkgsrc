$NetBSD: patch-jstracer.h,v 1.1 2018/05/02 12:42:51 jperkin Exp $

Implement Debian disable-static-strings-on-ia64.patch fix.

--- jstracer.h.orig	2011-03-31 19:08:36.000000000 +0000
+++ jstracer.h
@@ -1394,10 +1394,12 @@ class TraceRecorder
     JS_REQUIRES_STACK RecordingStatus getCharCodeAt(JSString *str,
                                                     nanojit::LIns* str_ins, nanojit::LIns* idx_ins,
                                                     nanojit::LIns** out_ins);
+#ifdef JS_HAS_STATIC_STRINGS
     JS_REQUIRES_STACK nanojit::LIns* getUnitString(nanojit::LIns* str_ins, nanojit::LIns* idx_ins);
     JS_REQUIRES_STACK RecordingStatus getCharAt(JSString *str,
                                                 nanojit::LIns* str_ins, nanojit::LIns* idx_ins,
                                                 JSOp mode, nanojit::LIns** out_ins);
+#endif
 
     JS_REQUIRES_STACK RecordingStatus initOrSetPropertyByName(nanojit::LIns* obj_ins,
                                                               Value* idvalp, Value* rvalp,
