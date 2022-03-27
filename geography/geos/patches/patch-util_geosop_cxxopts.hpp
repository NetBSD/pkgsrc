$NetBSD: patch-util_geosop_cxxopts.hpp,v 1.1 2022/03/27 13:33:21 tnn Exp $

On at least modern SunOS, int8_t is typedef'd to char, so parse_value()
that operates on int8_t& conflicts with the one that operates on char&.

--- util/geosop/cxxopts.hpp.orig	2022-01-15 21:14:55.000000000 +0000
+++ util/geosop/cxxopts.hpp
@@ -677,12 +677,14 @@ namespace cxxopts
       integer_parser(text, value);
     }
 
+#if !defined(__sun)
     inline
     void
     parse_value(const std::string& text, int8_t& value)
     {
       integer_parser(text, value);
     }
+#endif
 
     inline
     void
