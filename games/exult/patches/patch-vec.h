$NetBSD: patch-vec.h,v 1.1 2012/07/03 18:42:31 joerg Exp $

--- vec.h.orig	2012-07-03 12:50:54.000000000 +0000
+++ vec.h
@@ -33,7 +33,7 @@ public:
 	Exult_vector<T>() : baseClass()
 		{}
 	Exult_vector<T>(size_type n) : baseClass()
-		{ reserve(n); }
+		{ this->reserve(n); }
 
 #ifndef MACOS /* should be something like PROPER_STD_CPP_LIB or so */
 	T& at(int i) { return (*this)[i]; }
@@ -42,8 +42,8 @@ public:
 		{
 			if (i >= (int)this->size())
 				{
-				insert(this->begin() + this->size(), i - this->size(), 0);
-				push_back(v);
+				this->insert(this->begin() + this->size(), i - this->size(), 0);
+				this->push_back(v);
 				}
 			else
 				(*this)[i] = v;
@@ -69,7 +69,7 @@ public:
 
 	size_type	append( const T& obj )
 		{
-			push_back( obj );
+			this->push_back( obj );
 			return this->size() - 1;
 		}
 
@@ -80,7 +80,7 @@ public:
 			{
 				if( *X == obj )
 				{
-					erase(X);
+					this->erase(X);
 					return;
 				}
 			}
