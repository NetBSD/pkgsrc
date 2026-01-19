$NetBSD: patch-widgets_FrequencyDeltaLineEdit.cpp,v 1.1 2026/01/19 13:40:54 mef Exp $

From FreeBSD ports 2.5.4

--- wsjtx/widgets/FrequencyDeltaLineEdit.cpp.orig	2021-11-03 19:53:01.000000000 -0400
+++ widgets/FrequencyDeltaLineEdit.cpp	2021-12-31 07:48:03.412129000 -0500
@@ -39,8 +39,8 @@
 FrequencyDeltaLineEdit::FrequencyDeltaLineEdit (QWidget * parent)
   : QLineEdit (parent)
 {
-  setValidator (new MHzValidator {-std::numeric_limits<FrequencyDelta>::max () / 10.e6,
-        std::numeric_limits<FrequencyDelta>::max () / 10.e6, this});
+  setValidator (new MHzValidator {(-(std::numeric_limits<FrequencyDelta>::max ())&-0xF) / 10.e6,
+		  (std::numeric_limits<FrequencyDelta>::max ()&~0xF) / 10.e6, this});
 }
 
 auto FrequencyDeltaLineEdit::frequency_delta () const -> FrequencyDelta
