$NetBSD: patch-src_datesearch.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use "std" qualification

--- src/datesearch.cxx~	2000-10-15 03:46:31.000000000 +0000
+++ src/datesearch.cxx
@@ -271,30 +271,30 @@ INDEX::DateRangeSearch(const STRING& Que
 			    DURING);
     INT nhits;
     nhits = pirset->GetTotalEntries();
-    cerr << "Got " << nhits << " with start dates after " 
-	 << QueryStartDate.GetValue() << endl;
+    std::cerr << "Got " << nhits << " with start dates after " 
+	 << QueryStartDate.GetValue() << std::endl;
     /*
     other_pirset =
       SingleDateSearchBefore(QueryEndDate, FieldName, SEARCH_START, 
 			    DURING);
     nhits = other_pirset->GetTotalEntries();
-    cerr << "Got " << nhits << " with start dates before " 
-	 << QueryEndDate.GetValue() << endl;
+    std::cerr << "Got " << nhits << " with start dates before " 
+	 << QueryEndDate.GetValue() << std::endl;
     //pirset->And(*other_pirset);
 
     other_pirset =
       SingleDateSearchAfter(QueryStartDate, FieldName, SEARCH_END, 
 			    DURING);
     nhits = other_pirset->GetTotalEntries();
-    cerr << "Got " << nhits << " with end dates after " 
-	 << QueryStartDate.GetValue() << endl;
+    std::cerr << "Got " << nhits << " with end dates after " 
+	 << QueryStartDate.GetValue() << std::endl;
 
     another_pirset =
       SingleDateSearchBefore(QueryEndDate, FieldName, SEARCH_END, 
 			    DURING);
     nhits = another_pirset->GetTotalEntries();
-    cerr << "Got " << nhits << " with end dates before " 
-	 << QueryEndDate.GetValue() << endl;
+    std::cerr << "Got " << nhits << " with end dates before " 
+	 << QueryEndDate.GetValue() << std::endl;
     //    other_pirset->And(*another_pirset);
     //    pirset->Or(*other_pirset);
     */
