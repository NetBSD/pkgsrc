$NetBSD: patch-tp_Texinfo_XS_parsetexi_parser.c,v 1.1 2025/10/05 01:58:37 js Exp $

--- tp/Texinfo/XS/parsetexi/parser.c.orig	2025-10-05 01:57:07.522519730 +0000
+++ tp/Texinfo/XS/parsetexi/parser.c
@@ -2133,9 +2133,10 @@ process_remaining_on_line (ELEMENT **cur
         {
            int whitespaces_len;
            int additional_newline = 0;
+           int i;
            whitespaces_len = strspn (line, whitespace_chars);
 
-           for (int i = 0; i < whitespaces_len; i++)
+           for (i = 0; i < whitespaces_len; i++)
              {
                if (*(line + i) == '\n')
                  {
