$NetBSD: patch-krecipes_src_dialogs_ingredientsdialog.cpp,v 1.1 2012/10/26 20:19:40 joerg Exp $

--- krecipes/src/dialogs/ingredientsdialog.cpp.orig	2012-10-26 18:14:37.000000000 +0000
+++ krecipes/src/dialogs/ingredientsdialog.cpp
@@ -551,12 +551,12 @@ void IngredientsDialog::reloadWeightList
 			QListViewItem * lastElement = weightsListView->listView() ->lastItem();
 
 			Weight w = *weight_it;
-			WeightListItem *weight_it = new WeightListItem( weightsListView->listView(), lastElement, w );
-			weight_it->setAmountUnit( w.perAmount,
+			WeightListItem *weight_it2 = new WeightListItem( weightsListView->listView(), lastElement, w );
+			weight_it2->setAmountUnit( w.perAmount,
 			  database->unitName(w.perAmountUnitID),
 			  Element((w.prepMethodID==-1)?QString::null:database->prepMethodName(w.prepMethodID),w.prepMethodID)
 			);
-			weight_it->setWeightUnit( w.weight, database->unitName(w.weightUnitID) );
+			weight_it2->setWeightUnit( w.weight, database->unitName(w.weightUnitID) );
 		}
 	}
 }
