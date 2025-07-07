$NetBSD: patch-src_formail.c,v 1.1 2025/07/07 03:36:51 dholland Exp $

Fix ctype abuse.

--- src/formail.c~	2022-03-02 09:52:56.000000000 +0000
+++ src/formail.c
@@ -897,7 +897,7 @@ int breakfield(line,len)const char*const
   while(len)
    { switch(*p)
       { default:len--;
-	   if(iscntrl(*p))		    /* no control characters allowed */
+	   if(iscntrl((unsigned char)*p))		    /* no control characters allowed */
 	      break;
 	   p++;
 	   continue;
