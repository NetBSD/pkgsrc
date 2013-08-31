$NetBSD: patch-modules_stimuli.cc,v 1.1 2013/08/31 14:48:07 joerg Exp $

--- modules/stimuli.cc.orig	2013-08-31 11:41:30.000000000 +0000
+++ modules/stimuli.cc
@@ -216,7 +216,7 @@ namespace ExtendedStimuli {
   //----------------------------------------------------------------------
   //----------------------------------------------------------------------
 
-  PulseGen::PulseGen(const char *_name=0)
+  PulseGen::PulseGen(const char *_name)
     : StimulusBase(_name, "\
 Pulse Generator\n\
  Attributes:\n\
