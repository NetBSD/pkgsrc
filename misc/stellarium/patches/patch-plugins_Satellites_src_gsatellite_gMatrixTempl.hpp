$NetBSD: patch-plugins_Satellites_src_gsatellite_gMatrixTempl.hpp,v 1.1 2011/03/02 15:16:27 adam Exp $

Fix C++ error.

--- plugins/Satellites/src/gsatellite/gMatrixTempl.hpp.orig	2011-03-02 15:05:50.000000000 +0000
+++ plugins/Satellites/src/gsatellite/gMatrixTempl.hpp
@@ -50,7 +50,7 @@ public:
 
 		for(size_type i = 0; i < rows; ++i)
 			for(size_type j = 0; j < columns ; ++j)
-				operator[](i)[j] = right[ i][ j];
+				this->operator[](i)[j] = right[ i][ j];
 	}
 
 	size_type Rows() const
