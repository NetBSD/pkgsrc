--- lib/types.h.orig	2011-01-08 06:04:28.000000000 +0900
+++ lib/types.h	2017-02-16 13:37:32.460850605 +0900
@@ -7,6 +7,7 @@
  */
 
 #include <sys/types.h>
+#include <limits.h>
 
 #ifndef PCI_HAVE_Uxx_TYPES
 
@@ -20,22 +21,19 @@ typedef DWORD u32;
 typedef uint8_t u8;
 typedef uint16_t u16;
 typedef uint32_t u32;
+typedef uint64_t u64;
 #else
 typedef u_int8_t u8;
 typedef u_int16_t u16;
 typedef u_int32_t u32;
+typedef u_int64_t u64;
 #endif
 
-#ifdef PCI_HAVE_64BIT_ADDRESS
-#include <limits.h>
 #if ULONG_MAX > 0xffffffff
-typedef unsigned long u64;
 #define PCI_U64_FMT "l"
 #else
-typedef unsigned long long u64;
 #define PCI_U64_FMT "ll"
 #endif
-#endif
 
 #endif	/* PCI_HAVE_Uxx_TYPES */
 
