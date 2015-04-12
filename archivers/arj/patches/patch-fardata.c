$NetBSD: patch-fardata.c,v 1.2 2015/04/12 16:09:27 tnn Exp $

Rename strnlen -> _strnlen to avoid conflict in systems having strnlen.
Add patch from Debian (security_format.patch) to fix unsafe format string usage.

--- fardata.c.orig	2015-04-12 15:57:39.000000000 +0000
+++ fardata.c
@@ -52,7 +52,7 @@ int error_proc(FMSG *errmsg, ...)
   /* Check if the message could have a standard error code */
   if(errno!=0&&is_std_error(errmsg))
   {
-   msg_cprintf(0, lf);
+   msg_cprintf(0, "\n");
    error_report();
   }
  #endif
@@ -190,7 +190,7 @@ int msg_sprintf(char *str, FMSG *fmt, ..
 
 /* Length-limited strlen() */
 
-static int strnlen(const char FAR *s, int count)
+static int _strnlen(const char FAR *s, int count)
 {
  const char FAR *sc;
 
@@ -377,10 +377,10 @@ static void flush_cbuf(int ccode, char *
     {
      #if SFX_LEVEL>=ARJSFXV
       fprintf(new_stdout, strform, n_text);
-      fprintf(new_stdout, lf);
+      fprintf(new_stdout, "\n");
      #else
       printf(strform, n_text);
-      printf(lf);
+      printf("\n");
      #endif
     }
     else
@@ -391,13 +391,13 @@ static void flush_cbuf(int ccode, char *
      #ifdef NEED_CRLF
       scr_out("\r");
      #endif
-     scr_out(lf);
+     scr_out("\n");
     }
     if(!no_colors)
      textcolor(color_table[ccode&H_COLORMASK].color);
    #else
     printf(strform, n_text);
-    printf(lf);
+    printf("\n");
    #endif
    n_text=t_text+1;
    #if SFX_LEVEL>=ARJ
@@ -569,7 +569,7 @@ int vcprintf(int ccode, FMSG *fmt, va_li
     if(!s)
      s="(null)";
 #endif
-    len=strnlen(s, precision);
+    len=_strnlen(s, precision);
     if(!(flags&LEFT))
     {
      while(len<field_width--)
@@ -655,7 +655,7 @@ int vcprintf(int ccode, FMSG *fmt, va_li
     num=va_arg(args, unsigned long);
    else if(qualifier=='h')
    {
-#ifdef __linux__
+#if TARGET==UNIX
     if (flags&SIGN)
      num=va_arg(args, int);             /* num=va_arg(args, short);      */
     else
