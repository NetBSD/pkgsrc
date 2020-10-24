$NetBSD: patch-src_swap.c,v 1.6 2020/10/24 22:39:45 wiz Exp $

Extend support for NetBSD, and add per-swap-device
reporting for HAVE_SWAPCTL_THREE_ARGS.

--- src/swap.c.orig	2020-03-08 16:57:09.000000000 +0100
+++ src/swap.c	2020-07-06 20:21:18.416804717 +0200
@@ -80,9 +80,12 @@ static bool report_bytes;
 static bool report_by_device;
 /* #endif KERNEL_LINUX */
 
-#elif HAVE_SWAPCTL && HAVE_SWAPCTL_TWO_ARGS
+#elif HAVE_SWAPCTL && (HAVE_SWAPCTL_TWO_ARGS || HAVE_SWAPCTL_THREE_ARGS)
 #define SWAP_HAVE_REPORT_BY_DEVICE 1
 static derive_t pagesize;
+#if KERNEL_NETBSD
+static _Bool report_bytes = 0;
+#endif
 static bool report_by_device;
 /* #endif HAVE_SWAPCTL && HAVE_SWAPCTL_TWO_ARGS */
 
@@ -120,7 +123,7 @@ static int swap_config(oconfig_item_t *c
   for (int i = 0; i < ci->children_num; i++) {
     oconfig_item_t *child = ci->children + i;
     if (strcasecmp("ReportBytes", child->key) == 0)
-#if KERNEL_LINUX
+#if KERNEL_LINUX || KERNEL_NETBSD
       cf_util_get_boolean(child, &report_bytes);
 #else
       WARNING("swap plugin: The \"ReportBytes\" option "
@@ -154,7 +157,7 @@ static int swap_init(void) /* {{{ */
   pagesize = (derive_t)sysconf(_SC_PAGESIZE);
   /* #endif KERNEL_LINUX */
 
-#elif HAVE_SWAPCTL && HAVE_SWAPCTL_TWO_ARGS
+#elif HAVE_SWAPCTL && (HAVE_SWAPCTL_TWO_ARGS || HAVE_SWAPCTL_THREE_ARGS)
   /* getpagesize(3C) tells me this does not fail.. */
   pagesize = (derive_t)getpagesize();
   /* #endif HAVE_SWAPCTL */
@@ -212,7 +215,7 @@ static void swap_submit_usage(char const
                                free, other_name, other_value, NULL);
 } /* }}} void swap_submit_usage */
 
-#if KERNEL_LINUX || HAVE_PERFSTAT
+#if KERNEL_LINUX || HAVE_PERFSTAT || KERNEL_NETBSD
 __attribute__((nonnull(1))) static void
 swap_submit_derive(char const *type_instance, /* {{{ */
                    derive_t value) {
@@ -549,6 +552,43 @@ static int swap_read(void) /* {{{ */
   /* #endif HAVE_SWAPCTL && HAVE_SWAPCTL_TWO_ARGS */
 
 #elif HAVE_SWAPCTL && HAVE_SWAPCTL_THREE_ARGS
+#if KERNEL_NETBSD
+#include <uvm/uvm_extern.h>
+
+static int
+swap_read_io (void) /* {{{ */
+{
+  static int uvmexp_mib[] = { CTL_VM, VM_UVMEXP2 };
+  struct uvmexp_sysctl uvmexp;
+  size_t ssize;
+  derive_t swap_in, swap_out;
+
+  ssize = sizeof(uvmexp);
+  memset(&uvmexp, 0, ssize);
+  if (sysctl(uvmexp_mib, __arraycount(uvmexp_mib), &uvmexp,
+    &ssize, NULL, 0) == -1) {
+      char errbuf[1024];
+      WARNING ("swap: sysctl for uvmexp failed: %s",
+        sstrerror (errno, errbuf, sizeof (errbuf)));
+      return (-1);
+  }
+
+  swap_in  = uvmexp.pgswapin;
+  swap_out = uvmexp.pgswapout;
+
+  if (report_bytes)
+  {
+    swap_in = swap_in * pagesize;
+    swap_out = swap_out * pagesize;
+  }
+
+  swap_submit_derive ("in",  swap_in);
+  swap_submit_derive ("out", swap_out);
+
+  return (0);
+} /* }}} */
+#endif
+
 static int swap_read(void) /* {{{ */
 {
   struct swapent *swap_entries;
@@ -587,12 +627,32 @@ static int swap_read(void) /* {{{ */
   /* TODO: Report per-device stats. The path name is available from
    * swap_entries[i].se_path */
   for (int i = 0; i < swap_num; i++) {
+    char path[PATH_MAX];
+    gauge_t this_used;
+    gauge_t this_total;
+
     if ((swap_entries[i].se_flags & SWF_ENABLE) == 0)
       continue;
 
-    used += ((gauge_t)swap_entries[i].se_inuse) * C_SWAP_BLOCK_SIZE;
-    total += ((gauge_t)swap_entries[i].se_nblks) * C_SWAP_BLOCK_SIZE;
-  }
+    this_used = ((gauge_t) swap_entries[i].se_inuse)
+      * C_SWAP_BLOCK_SIZE;
+    this_total = ((gauge_t) swap_entries[i].se_nblks)
+      * C_SWAP_BLOCK_SIZE;
+
+    /* Shortcut for the "combined" setting (default) */
+    if (!report_by_device)
+    {
+      used  += this_used;
+      total += this_total;
+      continue;
+    }
+
+    sstrncpy (path, swap_entries[i].se_path, sizeof (path));
+    escape_slashes (path, sizeof (path));
+
+    swap_submit_usage (path, this_used, this_total - this_used,
+                       NULL, NAN);
+  } /* for (swap_num) */
 
   if (total < used) {
     ERROR(
@@ -603,8 +663,15 @@ static int swap_read(void) /* {{{ */
   }
 
   swap_submit_usage(NULL, used, total - used, NULL, NAN);
+  /* If the "separate" option was specified (report_by_device == 1), all
+   * values have already been dispatched from within the loop. */
+  if (!report_by_device)
+    swap_submit_usage (NULL, used, total - used, NULL, NAN);
 
   sfree(swap_entries);
+#if KERNEL_NETBSD
+  swap_read_io ();
+#endif
   return 0;
 } /* }}} int swap_read */
   /* #endif HAVE_SWAPCTL && HAVE_SWAPCTL_THREE_ARGS */
