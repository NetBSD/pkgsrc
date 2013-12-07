$NetBSD: patch-common_stack.cc,v 1.1 2013/12/07 21:07:56 dholland Exp $

Fix build with the latest C++ "standard".

--- common/stack.cc~	2009-06-25 16:00:55.000000000 +0000
+++ common/stack.cc
@@ -24,7 +24,7 @@ static int
 find_stack_direction ()
 {
     static char *addr = 0;
-    auto char dummy;
+    char dummy;
     if (addr == 0)
     {
 	addr = &dummy;
@@ -47,7 +47,7 @@ variable_is_on_stack(void *p)
 	return false;
     if (stack_direction == 0)
 	stack_direction = find_stack_direction();
-    auto char dummy = 0;
+    char dummy = 0;
     char *cp = (char *)p;
     return (stack_direction < 0 ?  (&dummy < cp) : (&dummy > cp));
 }
