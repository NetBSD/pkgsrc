$NetBSD: patch-src_cgalutils-polyhedron.cc,v 1.1 2025/02/02 00:41:13 mef Exp $

Upstream patch for cgal 5.3
https://github.com/openscad/openscad/commit/71f2831c0484c3f35cbf44e1d1dc2c857384100b

--- src/cgalutils-polyhedron.cc.orig	2021-01-31 17:41:09.000000000 +0000
+++ src/cgalutils-polyhedron.cc
@@ -337,19 +337,6 @@ namespace CGALUtils {
     }
 	};
 
-	template <typename Polyhedron>
-	std::string printPolyhedron(const Polyhedron &p) {
-		std::ostringstream sstream;
-		sstream.precision(20);
-
-    Polyhedron_writer writer;
-    generic_print_polyhedron(sstream, p, writer);
-		
-		return sstream.str();
-	}
-
-	template std::string printPolyhedron(const CGAL_Polyhedron &p);
-
 }; // namespace CGALUtils
 
 #endif /* ENABLE_CGAL */
