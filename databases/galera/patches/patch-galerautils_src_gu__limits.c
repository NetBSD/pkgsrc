$NetBSD: patch-galerautils_src_gu__limits.c,v 1.1 2023/01/13 16:08:03 wiz Exp $

NetBSD support.
https://github.com/codership/galera/pull/632

--- galerautils/src/gu_limits.c.orig	2022-11-02 06:09:14.000000000 +0000
+++ galerautils/src/gu_limits.c
@@ -94,13 +94,33 @@ static inline size_t page_size()    { re
 static inline size_t phys_pages()   { return sysconf(_SC_PHYS_PAGES);   }
 static inline size_t avphys_pages() { return freebsd_avphys_pages();    }
 
-#else /* !__APPLE__ && !__FreeBSD__ */
+#elif defined(__NetBSD__)
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/vmmeter.h>
+
+static long netbsd_avphys_pages (void)
+{
+    struct vmtotal total;
+    static const int vmmeter_mib[] = { CTL_VM, VM_METER };
+    size_t size = sizeof(total);
+    if (sysctl(vmmeter_mib, 2, &total, &size, NULL, 0) == -1) {
+        gu_error("Can't get vmtotals");
+	return 0;
+    }
+    return (long)total.t_free;
+}
+
+static inline size_t page_size()    { return sysconf(_SC_PAGESIZE);     }
+static inline size_t phys_pages()   { return sysconf(_SC_PHYS_PAGES);   }
+static inline size_t avphys_pages() { return netbsd_avphys_pages();    }
+#else /* !__APPLE__ && !__FreeBSD__ && !__NetBSD__ */
 
 static inline size_t page_size()    { return sysconf(_SC_PAGESIZE);     }
 static inline size_t phys_pages()   { return sysconf(_SC_PHYS_PAGES);   }
 static inline size_t avphys_pages() { return sysconf(_SC_AVPHYS_PAGES); }
 
-#endif /* !__APPLE__ && !__FreeBSD__ */
+#endif /* !__APPLE__ && !__FreeBSD__ && !__NetBSD__ */
 
 #define GU_DEFINE_FUNCTION(func)                \
     size_t gu_##func()                          \
