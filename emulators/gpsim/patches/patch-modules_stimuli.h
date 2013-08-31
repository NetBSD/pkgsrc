$NetBSD: patch-modules_stimuli.h,v 1.1 2013/08/31 14:48:07 joerg Exp $

--- modules/stimuli.h.orig	2013-08-31 11:42:40.000000000 +0000
+++ modules/stimuli.h
@@ -48,10 +48,10 @@ namespace ExtendedStimuli {
     gint64 time;
     Value  *v;
 
-    inline bool operator < (ValueStimulusData &rValue) {
+    inline bool operator < (const ValueStimulusData &rValue) const {
       return time < rValue.time;
     }
-    inline bool operator == (ValueStimulusData rValue) {
+    inline bool operator == (const ValueStimulusData rValue) const {
       return time == rValue.time;
     }
   };
