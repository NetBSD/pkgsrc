$NetBSD: patch-libyara_re.c,v 1.1 2019/12/14 10:46:08 khorben Exp $

Ensure we adhere to valid value domain for isxxxx() function/macro.

--- libyara/re.c.orig	2019-10-10 11:10:50.000000000 +0000
+++ libyara/re.c
@@ -2063,14 +2063,14 @@ int yr_re_exec(
 
         case RE_OPCODE_DIGIT:
           prolog;
-          match = isdigit(*input);
+          match = isdigit((unsigned char)*input);
           action = match ? ACTION_NONE : ACTION_KILL;
           fiber->ip += 1;
           break;
 
         case RE_OPCODE_NON_DIGIT:
           prolog;
-          match = !isdigit(*input);
+          match = !isdigit((unsigned char)*input);
           action = match ? ACTION_NONE : ACTION_KILL;
           fiber->ip += 1;
           break;
