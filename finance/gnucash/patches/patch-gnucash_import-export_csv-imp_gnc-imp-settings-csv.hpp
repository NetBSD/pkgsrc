$NetBSD: patch-gnucash_import-export_csv-imp_gnc-imp-settings-csv.hpp,v 1.1 2020/05/12 05:35:28 adam Exp $

Add missing include.

--- gnucash/import-export/csv-imp/gnc-imp-settings-csv.hpp.orig	2020-05-11 19:38:43.108485371 +0000
+++ gnucash/import-export/csv-imp/gnc-imp-settings-csv.hpp
@@ -34,6 +34,7 @@ extern "C" {
 #include "gnc-commodity.h"
 }
 
+#include <algorithm>
 #include <string>
 #include <vector>
 #include <boost/optional.hpp>
