$NetBSD: patch-src_hist_val.cpp,v 1.1 2016/07/16 03:32:32 markd Exp $

--- src/hist_val.cpp.orig	2012-06-28 06:39:35.000000000 +0000
+++ src/hist_val.cpp
@@ -113,7 +113,7 @@ HistoryValidator::TransferToWindow()
       }
 
       // if we have an entry, select it
-      if (!comboBox->IsEmpty())
+      if (!comboBox->wxItemContainerImmutable::IsEmpty())
         comboBox->SetSelection(0, 0);
     }
 
