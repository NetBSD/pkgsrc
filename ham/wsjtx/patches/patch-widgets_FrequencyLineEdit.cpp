$NetBSD: patch-widgets_FrequencyLineEdit.cpp,v 1.1 2026/01/19 13:40:54 mef Exp $

From FreeBSD ports 2.5.4

--- wsjtx/widgets/FrequencyLineEdit.cpp.orig	2021-11-03 19:53:01.000000000 -0400
+++ widgets/FrequencyLineEdit.cpp	2021-12-31 07:48:03.411740000 -0500
@@ -39,7 +39,8 @@
 FrequencyLineEdit::FrequencyLineEdit (QWidget * parent)
   : QLineEdit (parent)
 {
-  setValidator (new MHzValidator {0., std::numeric_limits<Radio::Frequency>::max () / 10.e6, this});
+#define MAXDOUBLEFREQUENCY 18446744073709551616.0
+  setValidator (new MHzValidator {0., MAXDOUBLEFREQUENCY / 10.e6, this});
 }
 
 auto FrequencyLineEdit::frequency () const -> Frequency
