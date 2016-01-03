$NetBSD: patch-f.meta.cc,v 1.1 2016/01/03 04:33:49 ryoon Exp $

--- f.meta.cc.orig	2016-01-01 08:20:29.000000000 +0000
+++ f.meta.cc
@@ -4836,7 +4836,11 @@ cchar * web_geocode(char *location[2], c
    snprintf(URI,299,"\"%s&location=%s,%s\"",query,location[0],location[1]);
 
    err = shell_quiet("wget -T 10 -o /dev/null -O %s %s",outfile,URI);
+#if defined(__linux__)
    if (err == 4) err = ECOMM;                                                    //  replace "interrupted system call"
+#else
+   if (err == 4) err = EIO;                                                    //  replace "interrupted system call"
+#endif
    if (err) return strerror(err);
 
    fid = fopen(outfile,"r");                                                     //  get response
