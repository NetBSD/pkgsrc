$NetBSD: patch-gdb_dwarfread.c,v 1.1 2012/11/20 23:13:04 tez Exp $

Patch for CVE-2006-4146 from https://bugzilla.redhat.com/show_bug.cgi?id=204841

--- gdb/dwarfread.c.orig	2004-07-17 14:16:14.000000000 +0000
+++ gdb/dwarfread.c
@@ -2137,9 +2137,7 @@ decode_line_numbers (char *linetable)
 
    NOTES
 
-   Note that stack[0] is unused except as a default error return.
-   Note that stack overflow is not yet handled.
- */
+   Note that stack[0] is unused except as a default error return. */
 
 static int
 locval (struct dieinfo *dip)
@@ -2159,7 +2157,7 @@ locval (struct dieinfo *dip)
   loc += nbytes;
   end = loc + locsize;
   stacki = 0;
-  stack[stacki] = 0;
+  stack[++stacki] = 0;
   dip->isreg = 0;
   dip->offreg = 0;
   dip->optimized_out = 1;
@@ -2223,6 +2221,16 @@ locval (struct dieinfo *dip)
 	  stacki--;
 	  break;
 	}
+      /* Enforce maximum stack depth of size-1 to avoid ++stacki writing
+         outside of the allocated space. Also enforce minimum > 0.
+         -- wad@google.com 14 Aug 2006 */
+      if (stacki >= sizeof (stack) / sizeof (*stack) - 1)
+	internal_error (__FILE__, __LINE__,
+	                _("location description stack too deep: %d"),
+	                stacki);
+      if (stacki <= 0)
+	internal_error (__FILE__, __LINE__,
+	                _("location description stack too shallow"));
     }
   return (stack[stacki]);
 }
