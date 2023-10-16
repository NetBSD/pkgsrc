$NetBSD: patch-recode.scm,v 1.1 2023/10/16 14:04:53 ryoon Exp $

* Support iconv(1) of NetBSD.

--- recode.scm.orig	2008-10-16 10:10:04.000000000 +0000
+++ recode.scm
@@ -29,7 +29,7 @@
       string
       (with-temp-file-data (tmpfile string)
         (with-temp-file out-tmpfile
-          (system (format nil "iconv -c -f %s -t %s//TRANSLIT -o %s %s" from to out-tmpfile tmpfile))
+          (system (format nil "iconv -c -f %s -t %s %s > %s" from to tmpfile out-tmpfile))
           (read-file out-tmpfile)))))
 
 (defvar recode-special-utf8-translations
