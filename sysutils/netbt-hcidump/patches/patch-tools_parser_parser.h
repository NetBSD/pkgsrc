$NetBSD: patch-tools_parser_parser.h,v 1.3 2023/06/04 09:06:16 plunky Exp $

the device ID is a string on netbt stack

--- tools/parser/parser.h.orig	2021-10-13 18:38:35.000000000 +0000
+++ tools/parser/parser.h
@@ -24,7 +24,7 @@ struct frame {
 	uint32_t	data_len;
 	void		*ptr;
 	uint32_t	len;
-	uint16_t	dev_id;
+	char		*dev_id;
 	uint8_t		in;
 	uint8_t		central;
 	uint16_t	handle;
@@ -122,9 +122,9 @@ static inline void p_indent(int level, s
 				localtime_r(&t, &tm);
 				printf("%04d-%02d-%02d %02d:%02d:%02d.%06lu ",
 					tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
-					tm.tm_hour, tm.tm_min, tm.tm_sec, f->ts.tv_usec);
+					tm.tm_hour, tm.tm_min, tm.tm_sec, (unsigned long)f->ts.tv_usec);
 			} else
-				printf("%8lu.%06lu ", f->ts.tv_sec, f->ts.tv_usec);
+				printf("%8ju.%06lu ", (uintmax_t)f->ts.tv_sec, (unsigned long)f->ts.tv_usec);
 		}
 		printf("%c ", (f->in ? '>' : '<'));
 		parser.state = 1;
