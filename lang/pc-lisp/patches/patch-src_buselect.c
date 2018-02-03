$NetBSD: patch-src_buselect.c,v 1.1 2018/02/03 20:26:31 kamil Exp $

Port to NetBSD.

--- src/buselect.c.orig	2015-07-22 00:49:58.000000000 +0000
+++ src/buselect.c
@@ -48,7 +48,7 @@ struct conscell *form;
            if (port->celltype == FILECELL) {                        /* if argument is a port */
                fp = port->atom;                                     /* extract FILE * from atom */
                if (fp == NULL) ioerror(fp);                         /* a null 'atom' indicates file closed */
-#if defined(__linux__) ||  defined(__APPLE__)  /* _cnt & _flag are no longer available; this code will have to be updated  */
+#if defined(__linux__) ||  defined(__APPLE__) || defined(__NetBSD__)  /* _cnt & _flag are no longer available; this code will have to be updated  */
 	       return(LIST(port));
 #else
                if ((fp->_cnt > 0) && (fp->_flag & _IOREAD))         /* a read only port with data pending causes an immediate return */
@@ -117,5 +117,3 @@ struct conscell *form;
   er:  ierror("*select");  /*  doesn't return  */
        return NULL;   /*  keep compiler happy  */
 }
-
-
