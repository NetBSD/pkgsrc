$NetBSD: patch-include_libtorrent_buffer.hpp,v 1.2 2020/01/10 11:52:05 nia Exp $

On second thought, let's not peek into internal malloc properties.

--- include/libtorrent/buffer.hpp.orig	2019-12-19 00:51:16.000000000 +0000
+++ include/libtorrent/buffer.hpp
@@ -49,8 +49,6 @@ POSSIBILITY OF SUCH DAMAGE.
 #include <malloc.h>
 #elif defined __FreeBSD__
 #include <malloc_np.h>
-#elif defined TORRENT_BSD
-#include <malloc/malloc.h>
 #endif
 
 namespace libtorrent {
@@ -89,8 +87,6 @@ public:
 		m_size = static_cast<difference_type>(::malloc_usable_size(m_begin));
 #elif defined _MSC_VER
 		m_size = static_cast<difference_type>(::_msize(m_begin));
-#elif defined TORRENT_BSD
-		m_size = static_cast<difference_type>(::malloc_size(m_begin));
 #else
 		m_size = size;
 #endif
