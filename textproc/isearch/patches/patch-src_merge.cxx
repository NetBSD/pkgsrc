$NetBSD: patch-src_merge.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

In C++, deleting void pointers is undefined.

--- src/merge.cxx~	1998-11-04 05:12:25.000000000 +0000
+++ src/merge.cxx
@@ -125,7 +125,7 @@ void buildHeap(void *data, size_t heapsi
       if (cmpstatus > 0) {
 	memcpy( ((char *)data + (position * width) ), value, width);
 	//	free(value);
-	delete [] value;
+	delete [] (CHR *)value;
 	return;
       } //child is bigger or same size, back through the loop 
       //again to find a place for value
@@ -140,7 +140,7 @@ void buildHeap(void *data, size_t heapsi
     else {
       memcpy(((char *)data+ (position * width) ), value, width);
       //      free(value);
-      delete [] value;
+      delete [] (CHR *)value;
       return;
     }
   }
@@ -188,6 +188,6 @@ void hsort(void *data, size_t nel, size_
     buildHeap(data, i, width, compar, 0, 0);
   }
   //  free(tmp);
-  delete [] tmp;
+  delete [] (CHR *)tmp;
 }
 
