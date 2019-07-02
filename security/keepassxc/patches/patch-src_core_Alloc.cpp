$NetBSD: patch-src_core_Alloc.cpp,v 1.1 2019/07/02 13:13:01 ryoon Exp $

* Restrict jemalloc-specific malloc_usable_size() to newer NetBSD

--- src/core/Alloc.cpp.orig	2019-06-11 23:08:03.000000000 +0000
+++ src/core/Alloc.cpp
@@ -15,6 +15,10 @@
  *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
+
 #include <QtGlobal>
 #include <cstdint>
 #include <sodium.h>
@@ -61,7 +65,7 @@ void operator delete(void* ptr) noexcept
     ::operator delete(ptr, _msize(ptr));
 #elif defined(Q_OS_MACOS)
     ::operator delete(ptr, malloc_size(ptr));
-#elif defined(Q_OS_UNIX)
+#elif (defined(Q_OS_UNIX) && !defined(__NetBSD__)) || (defined(__NetBSD__) && (__NetBSD_Version__ >= 899003600))
     ::operator delete(ptr, malloc_usable_size(ptr));
 #else
     // whatever OS this is, give up and simply free stuff
