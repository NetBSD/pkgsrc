$NetBSD: patch-gdb_dwarf2read.c,v 1.1 2012/11/20 23:13:04 tez Exp $

Patch for CVE-2006-4146 from https://bugzilla.redhat.com/show_bug.cgi?id=204841

--- gdb/dwarf2read.c.orig	2004-07-06 19:29:30.000000000 +0000
+++ gdb/dwarf2read.c
@@ -8027,8 +8027,7 @@ dwarf2_fundamental_type (struct objfile
    When the result is a register number, the global isreg flag is set,
    otherwise it is cleared.
 
-   Note that stack[0] is unused except as a default error return.
-   Note that stack overflow is not yet handled.  */
+   Note that stack[0] is unused except as a default error return. */
 
 static CORE_ADDR
 decode_locdesc (struct dwarf_block *blk, struct dwarf2_cu *cu)
@@ -8045,7 +8044,7 @@ decode_locdesc (struct dwarf_block *blk,
 
   i = 0;
   stacki = 0;
-  stack[stacki] = 0;
+  stack[++stacki] = 0;
   isreg = 0;
 
   while (i < size)
@@ -8227,6 +8226,16 @@ decode_locdesc (struct dwarf_block *blk,
 		     dwarf_stack_op_name (op));
 	  return (stack[stacki]);
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
