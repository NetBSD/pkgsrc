$NetBSD: patch-library_entropy__poll.c,v 1.1 2020/06/29 12:39:36 nia Exp $

Add KERN_ARND support.

Motivation: the default behaviour of reopening /dev/urandom repeatedly
for every 128 bytes of entropy required is _exceedingly_ slow on NetBSD.
Not helped is using fread(), which assumes a long-lived file and buffers
excessively. This change makes the standard gen_entropy tool run in
milliseconds instead of seconds when it generates 48K of randomness.

Not only that, but sysctl is a lot more robust in e.g. chroots, resource
limited processes, etc.

Upstreamed: https://github.com/ARMmbed/mbedtls/pull/3423

--- library/entropy_poll.c.orig	2020-04-09 13:12:23.000000000 +0000
+++ library/entropy_poll.c
@@ -114,6 +114,41 @@ static int getrandom_wrapper( void *buf,
 #endif /* SYS_getrandom */
 #endif /* __linux__ */
 
+/*
+ * Some BSD systems provide KERN_ARND.
+ * This is equivalent to reading from /dev/urandom, only it doesn't require an
+ * open file descriptor, and provides up to 256 bytes per call (basically the
+ * same as getentropy(), but with a longer history).
+ *
+ * Documentation: https://netbsd.gw.com/cgi-bin/man-cgi?sysctl+7
+ */
+#if (defined(__FreeBSD__) || defined(__NetBSD__)) && !defined(HAVE_GETRANDOM)
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#if defined(KERN_ARND)
+#define HAVE_SYSCTL_ARND
+
+static int sysctl_arnd_wrapper( unsigned char *buf, size_t buflen )
+{
+    int name[2];
+    size_t len;
+
+    name[0] = CTL_KERN;
+    name[1] = KERN_ARND;
+
+    while( buflen > 0 )
+    {
+        len = buflen > 256 ? 256 : buflen;
+        if( sysctl(name, 2, buf, &len, NULL, 0) == -1 )
+            return( -1 );
+        buflen -= len;
+        buf += len;
+    }
+    return( 0 );
+}
+#endif /* KERN_ARND */
+#endif /* __FreeBSD__ || __NetBSD__ */
+
 #include <stdio.h>
 
 int mbedtls_platform_entropy_poll( void *data,
@@ -138,6 +173,15 @@ int mbedtls_platform_entropy_poll( void 
     ((void) ret);
 #endif /* HAVE_GETRANDOM */
 
+#if defined(HAVE_SYSCTL_ARND)
+    ((void) file);
+    ((void) read_len);
+    if( sysctl_arnd_wrapper( output, len ) == -1 )
+        return( MBEDTLS_ERR_ENTROPY_SOURCE_FAILED );
+    *olen = len;
+    return( 0 );
+#else
+
     *olen = 0;
 
     file = fopen( "/dev/urandom", "rb" );
@@ -155,6 +199,7 @@ int mbedtls_platform_entropy_poll( void 
     *olen = len;
 
     return( 0 );
+#endif /* HAVE_SYSCTL_ARND */
 }
 #endif /* _WIN32 && !EFIX64 && !EFI32 */
 #endif /* !MBEDTLS_NO_PLATFORM_ENTROPY */
