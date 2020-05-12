$NetBSD: patch-gnucash_import-export_csv-imp_gnc-imp-settings-csv.hpp,v 1.2 2020/05/12 06:16:17 wiz Exp $

Add missing include.
https://bugs.gnucash.org/show_bug.cgi?id=797748

--- gnucash/import-export/csv-imp/gnc-imp-settings-csv.hpp.orig	2020-05-11 19:38:43.108485371 +0000
+++ gnucash/import-export/csv-imp/gnc-imp-settings-csv.hpp
@@ -34,6 +34,7 @@ extern "C" {
 #include "gnc-commodity.h"
 }
 
+#include <algorithm>
 #include <string>
 #include <vector>
 #include <boost/optional.hpp>
