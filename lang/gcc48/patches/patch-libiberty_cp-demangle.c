$NetBSD: patch-libiberty_cp-demangle.c,v 1.2 2014/11/28 09:57:32 obache Exp $

* OpenBSD dislike using sprintf(3) and strcpy(3).

--- libiberty/cp-demangle.c.orig	2013-04-03 17:25:03.000000000 +0000
+++ libiberty/cp-demangle.c
@@ -3736,7 +3736,11 @@ static inline void
 d_append_num (struct d_print_info *dpi, long l)
 {
   char buf[25];
-  sprintf (buf,"%ld", l);
+#ifdef __OpenBSD__
+  snprintf (buf, 25, "%ld", l);
+#else
+  sprintf (buf, "%ld", l);
+#endif
   d_append_string (dpi, buf);
 }
 
@@ -5561,7 +5565,11 @@ __cxa_demangle (const char *mangled_name
     {
       if (strlen (demangled) < *length)
 	{
+#ifdef __OpenBSD__
+	  strlcpy (output_buffer, demangled, *length);
+#else
 	  strcpy (output_buffer, demangled);
+#endif
 	  free (demangled);
 	  demangled = output_buffer;
 	}
