$NetBSD: patch-include_libtorrent_buffer.hpp,v 1.1 2019/12/16 18:00:51 nia Exp $

Support NetBSD.

--- include/libtorrent/buffer.hpp.orig	2019-09-24 09:52:01.000000000 +0000
+++ include/libtorrent/buffer.hpp
@@ -47,6 +47,8 @@ POSSIBILITY OF SUCH DAMAGE.
 #include <malloc.h>
 #elif defined _MSC_VER
 #include <malloc.h>
+#elif defined __NetBSD__
+#include <malloc.h>
 #elif defined __FreeBSD__
 #include <malloc_np.h>
 #elif defined TORRENT_BSD
@@ -85,7 +87,7 @@ public:
 
 		// the actual allocation may be larger than we requested. If so, let the
 		// user take advantage of every single byte
-#if (defined __GLIBC__ && !defined __UCLIBC__) || defined __FreeBSD__
+#if (defined __GLIBC__ && !defined __UCLIBC__) || defined __FreeBSD__ || defined __NetBSD__
 		m_size = static_cast<difference_type>(::malloc_usable_size(m_begin));
 #elif defined _MSC_VER
 		m_size = static_cast<difference_type>(::_msize(m_begin));
