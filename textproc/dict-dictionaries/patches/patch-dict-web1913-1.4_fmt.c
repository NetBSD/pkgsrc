$NetBSD: patch-dict-web1913-1.4_fmt.c,v 1.1 2026/01/04 14:08:23 wiz Exp $

Fix ctype(3) abuse.

--- dict-web1913-1.4/fmt.c.orig	1998-02-22 19:31:42.000000000 +0000
+++ dict-web1913-1.4/fmt.c
@@ -174,18 +174,18 @@ static void _fmt_line( int c, int ind, i
       }
       break;
    case FMT_LITERAL:
-      line[offset].c       = (isspace(c) && c != '\n') ? ' ' : c;
+      line[offset].c       = (isspace((unsigned char)c) && c != '\n') ? ' ' : c;
       line[offset].indent  = ind;
       line[offset].special = special;
       ++offset;
       break;
    default:
-      if (isspace(c) && offset
+      if (isspace((unsigned char)c) && offset
 	  && (line[offset-1].c == ' '
 	      || line[offset-1].special == FMT_NEWLINE)) {
 	    line[offset-1].indent  = ind;
       } else {
-	 line[offset].c       = isspace(c) ? ' ' : c;
+	 line[offset].c       = isspace((unsigned char)c) ? ' ' : c;
 	 line[offset].indent  = ind;
 	 line[offset].special = special;
 	 ++offset;
@@ -312,7 +312,7 @@ void fmt_add_index( const char *string )
       fmt_flush_index();
       stk = stk_create();
    }
-   while (isspace(*pt)) ++pt;	/* skip leading spaces */
+   while (isspace((unsigned char)*pt)) ++pt;	/* skip leading spaces */
 
    if (!*pt) return;		/* skip empties */
    stk_push(stk, (void *)pt);
