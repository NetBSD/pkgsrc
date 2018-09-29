$NetBSD: patch-src_busopen.c,v 1.2 2018/09/29 21:19:13 kamil Exp $

Port to NetBSD.

--- src/busopen.c.orig	2015-07-22 00:49:58.000000000 +0000
+++ src/busopen.c
@@ -40,6 +40,7 @@
  *************************************************************************/
 
 #include <stdio.h>
+#include <unistd.h>
 #include "lisp.h"
 
 #if HASTCP                            /* only compile busopen/busopenP if TCP/IP available */
@@ -76,7 +77,7 @@ static int fd_port = -1;
  ** default is 'anybody' i.e. INADDR_ANY.                               **
  ** implies no port currently in use.                                   **
  *************************************************************************/
-static long fd_addr = INADDR_ANY;
+static struct in_addr fd_addr = { INADDR_ANY };
 
 /*************************************************************************
  ** fdwait(fd, sec, usec) return 1 iff and only if there is activity on **
@@ -102,7 +103,7 @@ static int fdwait(fd, sec, usec)
  ** any forked children to inherit this file descriptor because that can**
  ** stop listens from working so we set the close-on-exec flag on the fd**
  *************************************************************************/
-static int fdasync(fd)
+static void fdasync(fd)
        int fd;
 {
        fcntl(fd, F_SETFL, FASYNC);
@@ -164,7 +165,8 @@ static int addrok(cl_addr, m_addr)
 static FILE *sopen(addr, port, wait, caddr)
        long addr, port, wait; char *caddr;
 {
-       int len, on = 1, s1, s2 = -1; FILE *fp;
+       int on = 1, s1, s2 = -1; FILE *fp;
+       socklen_t len;
        struct sockaddr_in server, client;
        if ((s1 = socket(AF_INET, SOCK_STREAM, 0)) < 0) goto er;                /* allocate a new socket using TCP/IP */
        bzero(&server, sizeof(server));
@@ -179,11 +181,11 @@ static FILE *sopen(addr, port, wait, cad
               for(;;) {                                                        /* repeat while getting EINTR's */
                   if (!fdwait(s1, wait, 0)) goto er;                           /* wait at most wait seconds for activity on s1 */
                   len = sizeof(client);
-                  if ((s2 = accept(s1,&client,&len)) >= 0) break;              /* if activity on s1 and got connection exit loop */
+                  if ((s2 = accept(s1,(struct sockaddr *)&client,&len)) >= 0) break;              /* if activity on s1 and got connection exit loop */
                   if (len != sizeof(client)) goto er;                          /* did we conenct to AF_INET addressee? */
                   if (errno != EINTR) goto er;                                 /* error occured, only one we expect is EINTR */
               }
-              if (!addrok(client.sin_addr.s_addr, addr)) goto er;
+              if (!addrok(client.sin_addr.s_addr, (struct sockaddr *)addr)) goto er;
               if (caddr) {strcpy(caddr, inet_ntoa(client.sin_addr));}          /* construct clients address for as a return parameter */
               close(s1);                                                       /* all ok, have a new fd s2 so can close s1 now */
           } else {                                                             /* we are not to wait (ie wait = -2), will process on SIGIO */
@@ -191,7 +193,7 @@ static FILE *sopen(addr, port, wait, cad
               s2 = s1;
           }
        } else {                                                                /* this is the active side of the connection ie wait = 0 */
-          if (connect(s1, &server, sizeof(server)) < 0) goto er;               /* so try to make an active connect */
+          if (connect(s1, (struct sockaddr *)&server, sizeof(server)) < 0) goto er;               /* so try to make an active connect */
           s2 = s1;                                                             /* just copy s1 to s2 so that we end in same state as passive */
        }
        fp = fdopen(s2, "r+");                                                  /* convert the file descriptor s2 into a FILE * */
@@ -226,7 +228,7 @@ struct conscell *busopen(form)
 struct conscell *form;
 {      char *iaddr; FILE *fd;
        struct conscell *fcell;
-       struct hostent *host;
+//       struct hostent *host;
        char addr[MAXATOMSIZE + 1];
        long port, wait = 0, haddr;
        errno = 0;
@@ -250,6 +252,7 @@ struct conscell *form;
   er:  ierror("socketopen");
   er2: ierror("socketopen:bad address");
   er3: ierror("socketopen:reserved port");
+  return NULL; // XXX
 }
 
 /***************************************************************************************************
@@ -264,7 +267,7 @@ struct conscell *form;
 int    busopenP(op)
        int op;
 {
-       static FILE *fd_listen = NULL, *fd_talk = NULL; static int old_mask;
+       static FILE *fd_listen = NULL, *fd_talk = NULL; // static int old_mask;
 
       /*
        | Must reset errno to see if I/O routines triggered an error.
@@ -279,7 +282,7 @@ int    busopenP(op)
            fd_port = op;
            if (fd_listen) { fclose(fd_listen); fd_listen = NULL; }
            if (fd_talk)   { fclose(fd_talk); fd_talk = NULL; }
-           fd_listen = sopen(fd_addr, fd_port, -2, NULL);             /* open but don't wait for accept, set SIGIO tell us */
+           fd_listen = sopen(fd_addr.s_addr, fd_port, -2, NULL);             /* open but don't wait for accept, set SIGIO tell us */
            Dprintf(("\n\n*** busopenP reopen fd_listen = %x errno = %d ***\n", fd_listen, errno));
            return(fd_listen == NULL);                                 /* return 0 for success -1 for failure */
        }
@@ -311,13 +314,13 @@ int    busopenP(op)
                Dprintf(("\tbusopenP accepting fd_listen & opening fd_talk\n"));
                if (fdwait(fdl, 0, 10) == 1) {                                 /* if activity on socket try to accept */
                   struct sockaddr_in client;
-                  int len = sizeof(client);
+                  socklen_t len = sizeof(client);
                   Dprintf(("\tbusopenP data available on fd_listen\n"));
-                  if ((fdt = accept(fdl, &client, &len)) >= 0) {              /* accept the connection, if error drop out */
+                  if ((fdt = accept(fdl, (struct sockaddr *)&client, &len)) >= 0) {              /* accept the connection, if error drop out */
                       Dprintf(("\tbusopenP connection accepted\n"));
                       fclose(fd_listen);                                      /* got accept don't need listner socket now so close it down */
                       fd_listen = NULL;                                       /* and clear FILE * so we do not enter this code on next liio(-1) */
-                      if (addrok(client.sin_addr.s_addr, fd_addr)) {          /* if client address matches mask */
+                      if (addrok(client.sin_addr.s_addr, fd_addr.s_addr)) {          /* if client address matches mask */
                           fdasync(fdt);                                       /* set up so that on I/O event send signal SIGIO */
                           fd_talk = fdopen(fdt, "r+");                        /* and open a FILE * equivalent to this talk file fd */
                       } else
@@ -423,7 +426,7 @@ int    busopenP(op)
            if ((fd_talk == NULL) && (fd_listen == NULL)) {
                int i;
                for(i = 0; i < 30; i++) {
-                   fd_listen = sopen(fd_addr, fd_port, -2, NULL);                                          /* open but don't wait for accept, let SIGIO tell us */
+                   fd_listen = sopen(fd_addr.s_addr, fd_port, -2, NULL);                                          /* open but don't wait for accept, let SIGIO tell us */
                    Dprintf(("\n\n*** busopenP reopen fd_listen = %x errno = %d ***\n", fd_listen, errno));
                    if (fd_listen != NULL) break;                                                           /* if opened ok the break out of retry loop */
                    sleep(1);                                                                               /* sleep for one second then retry */
@@ -446,7 +449,7 @@ struct conscell *buREPsopen(form)
        struct conscell *form;
 {
        int  isdflt, last_fd_port = fd_port;
-       long addr, last_fd_addr = fd_addr;
+       struct in_addr addr, last_fd_addr = fd_addr;
        long port; void (*f)();
 
       /*
@@ -457,7 +460,7 @@ struct conscell *buREPsopen(form)
        */
        if (form == NULL) {
            if (last_fd_port <= IPPORT_RESERVED) return(NULL);
-           fd_addr = INADDR_ANY;                              /* restore default addr mask to 'anyone' */
+           fd_addr.s_addr = INADDR_ANY;                              /* restore default addr mask to 'anyone' */
            busopenP(1);
            goto ret;
        }
@@ -485,7 +488,7 @@ struct conscell *buREPsopen(form)
           if (form->cdrp) goto er;
           if (!name2addr(addr_s, &addr)) goto er4;
        } else
-          addr = INADDR_ANY;
+          addr.s_addr = INADDR_ANY;
 
       /*
        | Now, try to open the new port/addr as a REP server. If we suceed all is well, just return the previous
@@ -510,7 +513,7 @@ ret:   form = new(CONSCELL);
        form->cdrp = new(CONSCELL);
        if (last_fd_port > IPPORT_RESERVED) {
            form->carp = newintop((long) last_fd_port);
-           form->cdrp->carp = LIST(insertstring((last_fd_addr == INADDR_ANY) ? "*" : inet_ntoa(last_fd_addr)));
+           form->cdrp->carp = LIST(insertstring((last_fd_addr.s_addr == INADDR_ANY) ? "*" : inet_ntoa(last_fd_addr)));
        }
        xpop(1);
        return(form);
@@ -522,6 +525,7 @@ ret:   form = new(CONSCELL);
  er1:  ierror("REP-socketopen: illegal port");
  er2:  ierror("REP-socketopen: no SIGIO handler present");
  er4:  ierror("REP-socketopen: bad address mask");
+ return NULL; // XXX
 }
 
 #else  /* dummy out these routines on machines that do not support TCP/IP */
