$NetBSD: patch-sublime_aggregatemodel.cpp,v 1.2 2014/02/01 09:54:23 markd Exp $

--- sublime/aggregatemodel.cpp.orig	2013-12-07 18:45:39.000000000 +0000
+++ sublime/aggregatemodel.cpp
@@ -81,7 +81,7 @@ Qt::ItemFlags AggregateModel::flags(cons
 {
     if (!index.isValid())
         return 0;
-    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
+    return Qt::ItemFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
 }
 
 QVariant AggregateModel::headerData(int section, Qt::Orientation orientation, int role) const
