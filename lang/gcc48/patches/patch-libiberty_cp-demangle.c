$NetBSD: patch-libiberty_cp-demangle.c,v 1.1 2014/05/31 13:06:25 ryoon Exp $

--- libiberty/cp-demangle.c.orig	2013-04-03 17:25:03.000000000 +0000
+++ libiberty/cp-demangle.c
@@ -3736,7 +3736,7 @@ static inline void
 d_append_num (struct d_print_info *dpi, long l)
 {
   char buf[25];
-  sprintf (buf,"%ld", l);
+  snprintf (buf, 25, "%ld", l);
   d_append_string (dpi, buf);
 }
 
@@ -5561,7 +5561,7 @@ __cxa_demangle (const char *mangled_name
     {
       if (strlen (demangled) < *length)
 	{
-	  strcpy (output_buffer, demangled);
+	  strlcpy (output_buffer, demangled, *length);
 	  free (demangled);
 	  demangled = output_buffer;
 	}
