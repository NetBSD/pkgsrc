$NetBSD: patch-src_lisp.c,v 1.1 2025/09/30 14:29:17 gutteridge Exp $

Use ctype.h correctly.

--- src/lisp.c.orig	2017-08-25 19:59:05.000000000 +0000
+++ src/lisp.c
@@ -639,7 +639,7 @@ read_symbol(repv strm, int *c_p, repv ob
 			    {
 				radix = 0;
 			    }
-			    else if(radix == 16 && !isxdigit(c))
+			    else if(radix == 16 && !isxdigit((unsigned char)c))
 				radix = 0;
 			}
 		    }
@@ -1007,20 +1007,20 @@ readl(repv strm, register int *c_p, repv
 		    if (c == EOF)
 			return signal_reader_error (Qpremature_end_of_stream,
 						    strm, "During #\\ syntax");
-		    if (!isalpha (c))
+		    if (!isalpha ((unsigned char)c))
 		    {
 			*c_p = rep_stream_getc (strm);
 			return rep_MAKE_INT (c);
 		    }
 		    c2 = rep_stream_getc (strm);
-		    if (!isalpha (c2) || c2 == EOF)
+		    if (!isalpha ((unsigned char)c2) || c2 == EOF)
 		    {
 			*c_p = c2;
 			return rep_MAKE_INT (c);
 		    }
 
-		    c = tolower (c);
-		    c2 = tolower (c2);
+		    c = tolower ((unsigned char)c);
+		    c2 = tolower ((unsigned char)c2);
 		    for (i = 0; char_names[i].name != 0; i++)
 		    {
 			if (char_names[i].name[0] == c
@@ -1035,7 +1035,7 @@ readl(repv strm, register int *c_p, repv
 				    *c_p = c;
 				    return rep_MAKE_INT (char_names[i].value);
 				}
-				if (c == EOF || tolower (c) != *ptr++)
+				if (c == EOF || tolower ((unsigned char)c) != *ptr++)
 				    return signal_reader_error (Qinvalid_read_syntax, strm, "Unknown character name");
 			    }
 			}
@@ -1075,7 +1075,7 @@ readl(repv strm, register int *c_p, repv
 
 	    case 't': case 'T':
 	    case 'f': case 'F':
-		form = (tolower (*c_p) == 't') ? rep_scm_t : rep_scm_f;
+		form = (tolower ((unsigned char)*c_p) == 't') ? rep_scm_t : rep_scm_f;
 		*c_p = rep_stream_getc (strm);
 		return form;
 
