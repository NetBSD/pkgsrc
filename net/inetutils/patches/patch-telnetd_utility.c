$NetBSD: patch-telnetd_utility.c,v 1.2.2.2 2026/05/07 22:37:51 maya Exp $

Sanitize the USER environment variable before passing it to login(1).
Fixes CVE-2026-24061. Reference:
https://lists.gnu.org/archive/html/bug-inetutils/2026-01/msg00004.html

--- telnetd/utility.c.orig	2025-12-14 15:12:20.000000000 +0000
+++ telnetd/utility.c
@@ -1684,6 +1684,17 @@ static void _expand_cond (struct line_ex
 static void _skip_block (struct line_expander *exp);
 static void _expand_block (struct line_expander *exp);
 
+static char *
+sanitize (const char *u)
+{
+  /* Ignore values starting with '-' or containing shell metachars, as
+     they can cause trouble.  */
+  if (u && *u != '-' && !u[strcspn (u, "\t\n !\"#$&'()*;<=>?[\\^`{|}~")])
+    return u;
+  else
+    return "";
+}
+
 /* Expand a variable referenced by its short one-symbol name.
    Input: exp->cp points to the variable name.
    FIXME: not implemented */
@@ -1710,13 +1721,13 @@ _var_short_name (struct line_expander *e
       return xstrdup (timebuf);
 
     case 'h':
-      return xstrdup (remote_hostname);
+      return xstrdup (sanitize (remote_hostname));
 
     case 'l':
-      return xstrdup (local_hostname);
+      return xstrdup (sanitize (local_hostname));
 
     case 'L':
-      return xstrdup (line);
+      return xstrdup (sanitize (line));
 
     case 't':
       q = strchr (line + 1, '/');
@@ -1733,7 +1744,7 @@ _var_short_name (struct line_expander *e
       return user_name ? xstrdup (user_name) : NULL;
 
     case 'U':
-      return getenv ("USER") ? xstrdup (getenv ("USER")) : xstrdup ("");
+      return user_name ? xstrdup (sanitize (user_name)) : NULL;
 
     default:
       exp->state = EXP_STATE_ERROR;
