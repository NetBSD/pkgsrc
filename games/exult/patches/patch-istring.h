$NetBSD: patch-istring.h,v 1.1 2015/04/25 00:56:04 joerg Exp $

append does not depend on the template, so make reference explicit.

--- istring.h.orig	2015-04-24 23:56:35.000000000 +0000
+++ istring.h
@@ -162,19 +162,19 @@ public:
 
 	_Myt& operator+=(const _Myt& _Right)
 		{	// append _Right
-		append(_Right);
+		this->append(_Right);
 		return (*this);
 		}
 
 	_Myt& operator+=(const _Elem *_Ptr)
 		{	// append [_Ptr, <null>)
-		append(_Ptr);
+		this->append(_Ptr);
 		return (*this);
 		}
 
 	_Myt& operator+=(_Elem _Ch)
 		{	// append 1 * _Ch
-		append(static_cast<size_type>(1), _Ch);
+		this->append(static_cast<size_type>(1), _Ch);
 		return (*this);
 		}
 
