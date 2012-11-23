$NetBSD: patch-src_qalculateeditfunctiondialog.cpp,v 1.1 2012/11/23 12:10:29 joerg Exp $

--- src/qalculateeditfunctiondialog.cpp.orig	2012-11-19 17:10:32.000000000 +0000
+++ src/qalculateeditfunctiondialog.cpp
@@ -377,10 +377,10 @@ MathFunction *QalculateEditFunctionDialo
 				str = defarg.printlong().c_str();
 				str2 = "";
 			}
-			QListViewItem *i = new KListViewItem(argumentsView, i_prev, str2, str);
-			i_prev = i;
-			argumentsItems[i] = arg;
-			argumentsItemsEdited[i] = false;
+			QListViewItem *i2 = new KListViewItem(argumentsView, i_prev, str2, str);
+			i_prev = i2;
+			argumentsItems[i2] = arg;
+			argumentsItemsEdited[i2] = false;
 		}
 	}
 	argumentsView->setResizeMode(KListView::AllColumns);
