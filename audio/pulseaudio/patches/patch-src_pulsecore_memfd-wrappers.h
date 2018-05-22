$NetBSD: patch-src_pulsecore_memfd-wrappers.h,v 1.1 2018/05/22 18:16:42 maya Exp $

If glibc provides memfd_create, pulseaudio must not define it,
otherwise building fails due to conflict between the two implementations
of the same function.

memfd_create is included in >=glibc-2.27.

Bug: https://bugs.freedesktop.org/show_bug.cgi?id=104733
Commit: https://github.com/pulseaudio/pulseaudio/commit/dfb0460fb4743aec047cdf755a660a9ac2d0f3fb

--- src/pulsecore/memfd-wrappers.h.orig	2016-08-23 12:50:11.000000000 +0000
+++ src/pulsecore/memfd-wrappers.h
@@ -20,7 +20,7 @@
   License along with PulseAudio; if not, see <http://www.gnu.org/licenses/>.
 ***/
 
-#ifdef HAVE_MEMFD
+#if defined(HAVE_MEMFD) && !defined(HAVE_MEMFD_CREATE)
 
 #include <sys/syscall.h>
 #include <fcntl.h>
@@ -63,6 +63,6 @@ static inline int memfd_create(const cha
 #define F_SEAL_WRITE    0x0008  /* prevent writes */
 #endif
 
-#endif /* HAVE_MEMFD */
+#endif /* HAVE_MEMFD && !HAVE_MEMFD_CREATE */
 
 #endif
