$NetBSD: patch-funcs_func__env.c,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- funcs/func_env.c.orig	2019-09-05 13:09:20.000000000 +0000
+++ funcs/func_env.c
@@ -408,11 +408,11 @@ static int file_count_line(struct ast_ch
 
 	AST_STANDARD_APP_ARGS(args, data);
 	if (args.argc > 1) {
-		if (tolower(args.format[0]) == 'd') {
+		if (tolower((unsigned char)args.format[0]) == 'd') {
 			newline_format = FF_DOS;
-		} else if (tolower(args.format[0]) == 'm') {
+		} else if (tolower((unsigned char)args.format[0]) == 'm') {
 			newline_format = FF_MAC;
-		} else if (tolower(args.format[0]) == 'u') {
+		} else if (tolower((unsigned char)args.format[0]) == 'u') {
 			newline_format = FF_UNIX;
 		}
 	}
@@ -570,11 +570,11 @@ static int file_read(struct ast_channel 
 
 	/* Line-based read */
 	if (args.argc == 5) {
-		if (tolower(args.fileformat[0]) == 'd') {
+		if (tolower((unsigned char)args.fileformat[0]) == 'd') {
 			format = FF_DOS;
-		} else if (tolower(args.fileformat[0]) == 'm') {
+		} else if (tolower((unsigned char)args.fileformat[0]) == 'm') {
 			format = FF_MAC;
-		} else if (tolower(args.fileformat[0]) == 'u') {
+		} else if (tolower((unsigned char)args.fileformat[0]) == 'u') {
 			format = FF_UNIX;
 		}
 	}
@@ -935,11 +935,11 @@ static int file_write(struct ast_channel
 
 		/* Line mode */
 		if (args.argc == 5) {
-			if (tolower(args.format[0]) == 'u') {
+			if (tolower((unsigned char)args.format[0]) == 'u') {
 				newline_format = FF_UNIX;
-			} else if (tolower(args.format[0]) == 'm') {
+			} else if (tolower((unsigned char)args.format[0]) == 'm') {
 				newline_format = FF_MAC;
-			} else if (tolower(args.format[0]) == 'd') {
+			} else if (tolower((unsigned char)args.format[0]) == 'd') {
 				newline_format = FF_DOS;
 			}
 		}
