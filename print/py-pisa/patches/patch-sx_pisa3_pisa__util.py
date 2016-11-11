$NetBSD: patch-sx_pisa3_pisa__util.py,v 1.1 2016/11/11 12:47:52 joerg Exp $

--- sx/pisa3/pisa_util.py.orig	2010-06-16 13:43:35.000000000 +0000
+++ sx/pisa3/pisa_util.py
@@ -51,10 +51,10 @@ import shutil
 
 rgb_re = re.compile("^.*?rgb[(]([0-9]+).*?([0-9]+).*?([0-9]+)[)].*?[ ]*$")
 
-if not(reportlab.Version[0] == "2" and reportlab.Version[2] >= "1"):
+if int(reportlab.Version[0]) < 2 or (reportlab.Version[0] == "2" and reportlab.Version[2] == "0"):
     raise ImportError("Reportlab Version 2.1+ is needed!")
 
-REPORTLAB22 = (reportlab.Version[0] == "2" and reportlab.Version[2] >= "2")
+REPORTLAB22 = not(reportlab.Version[0] == "2" and reportlab.Version[2] == "1")
 # print "***", reportlab.Version, REPORTLAB22, reportlab.__file__
 
 import logging
