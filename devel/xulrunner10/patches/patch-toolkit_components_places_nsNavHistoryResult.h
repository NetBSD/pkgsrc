$NetBSD: patch-toolkit_components_places_nsNavHistoryResult.h,v 1.1 2013/08/29 12:56:15 joerg Exp $

--- toolkit/components/places/nsNavHistoryResult.h.orig	2013-08-28 19:35:17.000000000 +0000
+++ toolkit/components/places/nsNavHistoryResult.h
@@ -668,7 +668,7 @@ public:
   {
     nsCAutoString spec;
     if (NS_FAILED(aURI->GetSpec(spec)))
-      return false;
+      return nsnull;
     return FindChildURI(spec, aNodeIndex);
   }
   nsNavHistoryResultNode* FindChildURI(const nsACString& aSpec,
