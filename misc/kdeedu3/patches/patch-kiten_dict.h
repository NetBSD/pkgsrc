$NetBSD: patch-kiten_dict.h,v 1.1 2012/06/25 11:31:20 joerg Exp $

--- kiten/dict.h.orig	2012-06-18 20:23:20.000000000 +0000
+++ kiten/dict.h
@@ -65,12 +65,12 @@ template<class T> Array<T>::Array(T *d, 
 	, data(d)
 	, dataSize(s)
 {
-	setRawData(data, dataSize / sizeof(T));
+	this->setRawData(data, dataSize / sizeof(T));
 }
 
 template<class T> Array<T>::~Array()
 {
-	resetRawData(data, dataSize / sizeof(T));
+	this->resetRawData(data, dataSize / sizeof(T));
 }
 
 // File manages all the files, pointers, and memory management associated
