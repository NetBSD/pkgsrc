$NetBSD: patch-erts_lib__src_common_erl__printf__format.c,v 1.1 2024/05/27 19:07:50 riastradh Exp $

Fix ctype(3) misuse.

--- erts/lib_src/common/erl_printf_format.c.orig	2024-03-06 15:30:18.000000000 +0000
+++ erts/lib_src/common/erl_printf_format.c
@@ -480,9 +480,9 @@ int erts_printf_format(fmtfn_t fn, void*
 		width = va_arg(ap, int);
 		ptr++;
 	    }
-	    else if (isdigit((int) *ptr)) {
+	    else if (isdigit((unsigned char) *ptr)) {
 		width = *ptr++ - '0';
-		while(isdigit((int) *ptr))
+		while(isdigit((unsigned char) *ptr))
 		    width = 10*width + (*ptr++ - '0');
 	    }
 
@@ -493,9 +493,9 @@ int erts_printf_format(fmtfn_t fn, void*
 		    precision = va_arg(ap, int);
 		    ptr++;
 		}
-		else if (isdigit((int) *ptr)) {
+		else if (isdigit((unsigned char) *ptr)) {
 		    precision = *ptr++ - '0';
-		    while(isdigit((int) *ptr))
+		    while(isdigit((unsigned char) *ptr))
 			precision = 10*precision + (*ptr++ - '0');
 		}
 	    }
@@ -528,7 +528,7 @@ int erts_printf_format(fmtfn_t fn, void*
 		}
 		else {
 		    int bits = 0;
-		    while(isdigit((int) *ptr))
+		    while(isdigit((unsigned char) *ptr))
 			bits = 10*bits + (*ptr++ - '0');
 		    switch (bits) {
 		    case 64:
