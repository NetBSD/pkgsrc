$NetBSD: patch-include_libtorrent_config.hpp,v 1.1 2020/05/14 19:14:38 joerg Exp $

Uses std::size_t.

--- include/libtorrent/config.hpp.orig	2020-05-13 19:10:58.243827028 +0000
+++ include/libtorrent/config.hpp
@@ -37,6 +37,7 @@ POSSIBILITY OF SUCH DAMAGE.
 
 #define _FILE_OFFSET_BITS 64
 
+#include <cstddef>
 #include <boost/config.hpp>
 #include <boost/version.hpp>
 
