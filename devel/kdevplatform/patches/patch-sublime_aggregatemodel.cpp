$NetBSD: patch-sublime_aggregatemodel.cpp,v 1.1 2013/10/14 14:34:25 joerg Exp $

--- sublime/aggregatemodel.cpp.orig	2013-10-14 11:07:07.000000000 +0000
+++ sublime/aggregatemodel.cpp
@@ -81,7 +81,7 @@ Qt::ItemFlags AggregateModel::flags(cons
 {
     if (!index.isValid())
         return 0;
-    return Qt::ItemIsEnabled & Qt::ItemIsSelectable;
+    return Qt::ItemFlags(Qt::ItemIsEnabled & Qt::ItemIsSelectable);
 }
 
 QVariant AggregateModel::headerData(int section, Qt::Orientation orientation, int role) const
