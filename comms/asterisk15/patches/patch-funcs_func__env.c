$NetBSD: patch-funcs_func__env.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- funcs/func_env.c.orig	2018-05-01 20:12:26.000000000 +0000
+++ funcs/func_env.c
@@ -307,7 +307,7 @@ static int stat_read(struct ast_channel 
 			snprintf(buf, len, "%d", (int) s.st_ctime);
 			break;
 		case 'm':
-			snprintf(buf, len, "%o", s.st_mode);
+			snprintf(buf, len, "%o", (unsigned int) s.st_mode);
 			break;
 		}
 	}
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
