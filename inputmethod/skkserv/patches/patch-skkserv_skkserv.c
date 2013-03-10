$NetBSD: patch-skkserv_skkserv.c,v 1.1 2013/03/10 18:53:32 hiramatsu Exp $

Add IPv6 support and binary search capability.

--- skkserv/skkserv.c.orig	2013-03-11 01:53:23.000000000 +0900
+++ skkserv/skkserv.c	2013-03-11 01:53:24.000000000 +0900
@@ -100,14 +100,16 @@
 #define SERVER_NOT_FOUND "4"
 #define SERVER_FULL	"9"
 
+#define warn(m)	\
+	{if (debug) fprintf(errout, "%s: %s\n", pgmnm, m);}
 #define err(m)	\
-	{if (debug) fprintf(errout, "%s: %s\n", pgmnm, m); exit(1);}
+	{warn(m); exit(1);}
 
 /*
  *	Global Variables
  */
 
-char	pgmver[] = "3.9.4 ";	/* version number */
+char	pgmver[] = "3.9.4nb7 (binary search) ";	/* version number */
 
 char	*pgmnm;		/* program name */
 char	*jname;		/* name of shared dictionary */
@@ -121,6 +123,9 @@
 int	jtab1[KANAMOJI]; /* index-table by 1st letter (1st part)*/
 int	jtab2[KANAMOJI]; /* index-table by 1st letter (2nd part)*/
 int	initsock;	/* socket for waiting requests */
+#ifdef PF_INET6
+int	initsock6;	/* IPv6 socket for waiting requests */
+#endif
 int	clientsock[MAXCLNT];	/* socket for each client */
 int	nclients;	/* max index for active clients */
 
@@ -130,8 +135,18 @@
   int	parg;
   int	setjisho = 0;
   int	ctlterm;	/* fildes for control terminal */
-  void	reread();
+  RETSIGTYPE 	req_reread();
+
+#ifdef SKKSERV_UID
+  gid_t	gid = SKKSERV_GID;
 
+  /* revoke privilege if any */
+  if (geteuid() == 0) {
+    setgroups(1, &gid);
+    setgid(SKKSERV_GID);
+    setuid(SKKSERV_UID);
+  }
+#endif
   pgmnm = argv[0];
   debug = 0;
   errout = stderr;
@@ -200,7 +215,10 @@
     fclose(stderr);
 
     /* detach child process from control terminal */
-#ifdef HAVE_TIOCNOTTY
+#ifdef HAVE_SETSID
+    setsid();
+#else
+#ifdef TIOCNOTTY
     if ((ctlterm = open("/dev/tty", 2)) >= 0) { 
       ioctl(ctlterm, TIOCNOTTY, 0);
       close(ctlterm);
@@ -215,6 +233,7 @@
     signal(SIGHUP, SIG_IGN);
     if (fork() != 0) exit(0);
 #endif
+#endif
   } else { /* debug mode */
     fprintf(errout, "SKK-JISYO is %s\n", jname);
     fflush(errout);
@@ -222,7 +241,7 @@
     if (errout != stderr) fclose(stderr);
   }
 
-  signal(SIGINT, reread);
+  signal(SIGINT, req_reread);
   /* 1993/6/5 by kam, re-read dictionary by "INT" signal */
 
   nclients = 0;
@@ -244,8 +263,11 @@
 mksock()
 {
   struct sockaddr_in	sin;
+#ifdef PF_INET6
+  struct sockaddr_in6	sin6;
+#endif
   struct servent	*sp;
-  int	optbuf = 1; /* enable socket REUSEADDR */
+  int	optbuf;		/* enable socket REUSEADDR */
   
   bzero((char*)&sin, sizeof(sin));
   sin.sin_family = AF_INET;
@@ -262,16 +284,54 @@
   sin.sin_port = htons(portnum); 
 
   if ((initsock = socket(PF_INET, SOCK_STREAM, 0)) < 0)
-    err("socket error; socket cannot be created");
-  if (setsockopt(initsock, SOL_SOCKET, SO_REUSEADDR, 
+    warn("socket error; socket cannot be created");
+#ifdef PF_INET6
+  bzero((char*)&sin6, sizeof(sin6));
+  sin6.sin6_family = AF_INET6;
+  /* sin6.sin6_addr.s6_addr = IN6ADDR_ANY_INIT;  ... all-zero pattern */
+  sin6.sin6_port = htons(portnum); 
+  if ((initsock6 = socket(PF_INET6, SOCK_STREAM, 0)) < 0)
+    warn("socket error; IPv6 socket cannot be created");
+#endif
+  optbuf = 1;
+  if (initsock >= 0 && setsockopt(initsock, SOL_SOCKET, SO_REUSEADDR, 
+		 &optbuf, sizeof(optbuf)) < 0)
+    warn("socket error; cannot set socket option");
+#ifdef PF_INET6
+  optbuf = 1;
+  if (initsock6 >= 0 && setsockopt(initsock6, SOL_SOCKET, SO_REUSEADDR, 
 		 &optbuf, sizeof(optbuf)) < 0)
-    err("socket error; cannot set socket option");
-  if (bind(initsock, (struct sockaddr *)&sin, sizeof(sin))< 0) 
-    err("bind error; the socket is already used");
-  if (listen(initsock, MAXQUE) < 0) 
+    warn("socket error; cannot set socket option");
+#endif
+  if (initsock >= 0 && bind(initsock, (struct sockaddr *)&sin, sizeof(sin))< 0)  {
+    warn("bind error; the socket is already used");
+    close(initsock);
+    initsock = -1;
+  }
+#ifdef PF_INET6
+  if (initsock6 >= 0 && bind(initsock6, (struct sockaddr *)&sin6, sizeof(sin6))< 0) {
+    warn("bind error; the socket is already used");
+    close(initsock6);
+    initsock6 = -1;
+  }
+#endif
+  if (initsock < 0
+#ifdef PF_INET6
+      && initsock6 < 0
+#endif
+	)
+    exit(1);
+  if (initsock >= 0 && listen(initsock, MAXQUE) < 0) 
     err("listen error; something wrong happened with the socket");
+#ifdef PF_INET6
+  if (initsock6 >= 0 && listen(initsock6, MAXQUE) < 0) 
+    err("listen error; something wrong happened with the IPv6 socket");
+#endif
   if (debug) {
     fprintf(errout, "file descriptor for initsock is %d\n", initsock);
+#ifdef PF_INET6
+    fprintf(errout, "file descriptor for initsock6 is %d\n", initsock6);
+#endif
     fflush(errout);
   }
 }
@@ -303,8 +363,19 @@
     mkoldjtab(buf);
 }
 
+/* using stdio in signal handler is unsafe */
+#ifdef __STDC__
+volatile
+#endif
+int reread_requested;
+
+RETSIGTYPE req_reread()
+{
+  reread_requested = 1;
+}
+
 /* 1993/6/5 by kam, re-read dictionary by "INT" signal */
-RETSIGTYPE reread()
+void reread()
 {
   if (fclose(jisho) < 0) {
     fprintf(stderr, 
@@ -382,6 +453,10 @@
   code = KANA_END;
 
   while ((c = fgetc(jisho)) != EOF) {
+    if (c == '>') {
+      fgets(buf, BUFSIZE, jisho);
+      continue;
+    }
     target = ((c & 0xff)<< 8) | (fgetc(jisho) & 0xff);
     if (target == STRMARK) {
       fgets(buf, BUFSIZE, jisho);
@@ -455,15 +530,22 @@
 main_loop()
 {
   fd_set 		readfds, writefds, exceptfds;
-  fd_set 		getrfds();
+  void	 		getrfds();
   struct sockaddr_in	from;
+#ifdef PF_INET6
+  struct sockaddr_in6	from6;
+#endif
   int			len;
   register int		i;
 
   FD_ZERO(&writefds);
   FD_ZERO(&exceptfds);
   for(;;) {	/* infinite loop; waiting for client's request */
-    readfds = getrfds();
+    if (reread_requested) {
+      reread();
+      reread_requested = 0;
+    }
+    getrfds(&readfds);
     if (select(MAXDTAB, &readfds, &writefds, &exceptfds, NULL) < 0) {
       if (errno == EINTR) /* if signal happens */
 	continue;
@@ -474,16 +556,32 @@
       fflush(errout);
     }
 
-    if (FD_ISSET(initsock, &readfds)) {
+    if (initsock >= 0 && FD_ISSET(initsock, &readfds)) {
       len = sizeof(from);
       if ((clientsock[nclients ++] = accept(initsock, &from, &len)) < 0) {
 	err("accept error; something wrong happened with the socket");
       }
-      if (nclients >= MAXDTAB - 3 - debug * 2) {
+      if (nclients >= MAXDTAB - 3
+#ifdef PF_INET6
+		-1
+#endif
+		- debug * 2) {
 	write(clientsock[--nclients], SERVER_FULL, 1);
 	close(clientsock[nclients]);
       }
     }
+#ifdef PF_INET6
+    if (initsock6 >= 0 && FD_ISSET(initsock6, &readfds)) {
+      len = sizeof(from6);
+      if ((clientsock[nclients ++] = accept(initsock6, &from6, &len)) < 0) {
+	err("accept error; something wrong happened with the socket");
+      }
+      if (nclients >= MAXDTAB - 4 - debug * 2) {
+	write(clientsock[--nclients], SERVER_FULL, 1);
+	close(clientsock[nclients]);
+      }
+    }
+#endif
 
     /*	naiive scheduling */
     for (i = 0; i < nclients; i ++)
@@ -511,20 +609,24 @@
  *	get bit pattern of read file descriptor
  */
 
-fd_set getrfds()
+void getrfds(rfds)
+fd_set	*rfds;
 {
-  fd_set		rfds;
   register int		i;
 
-  FD_ZERO(&rfds);
-  FD_SET(initsock, &rfds);
+  FD_ZERO(rfds);
+  if (initsock >= 0)
+    FD_SET(initsock, rfds);
+#ifdef PF_INET6
+  if (initsock6 >= 0)
+    FD_SET(initsock6, rfds);
+#endif
   for (i = 0; i < nclients; i ++)
-    FD_SET(clientsock[i], &rfds);
-  return (rfds);
+    FD_SET(clientsock[i], rfds);
 }
 
 /*
- *	reply to client: linear search
+ *	reply to client: binary search
  */
 
 search(commsock)
@@ -537,6 +639,7 @@
   int		n; 	 	 /* number of characters from client */
   int		sttpnt; 	 /* start point of searching */
   int		endpnt; 	 /* end point of searching */
+  int		curpnt;		 /* current point of searching */
   int		errcod = 0; 	 /* error flag */
   int		sstyle;		 /* search style */
 
@@ -645,18 +748,36 @@
       endpnt = jtab1[KANA_END - code + 1];
     }
   }
-  fseek(jisho, sttpnt, 0);
   if (debug)
-    fprintf(stderr, "from %d to %d\n", sttpnt, endpnt);
+    fprintf(errout, "from %d to %d\n", sttpnt, endpnt);
   
+  for (;;) {
+    if ((sstyle & 0x4) == 0) {	/* binary search? */
+      curpnt = (sttpnt + endpnt) / 2;
+      fseek(jisho, curpnt, 0);
   while ((c = fgetc(jisho)) != EOF) {
+	curpnt++;
+	if (c == EOL) break;
+      }
+      if (c == EOF) break;
+      if (curpnt >= endpnt) {
+	fseek(jisho, sttpnt, 0);
+	sstyle |= 0x4;	/* linear search */
+      }
+    }
+
+    if (debug) {fprintf(errout, "%d:%d\t%d\t%d\t", sstyle, sttpnt, curpnt, endpnt);}
+    c = fgetc(jisho);
     pbuf = &combuf[1]; /* ' ' is end-symbol */
     while (c == *pbuf && c != ' ' && c != EOL) {
-      if (debug) {fprintf(errout, "1:%d:%d:%d:%d:\n", c, *pbuf, ' ', EOL);}
+/*    if (debug) {fprintf(errout, "1:%d:%d:%d:%d:", c, *pbuf, ' ', EOL);}*/
+      if (debug) {fprintf(errout, "%c", c);}
       c = fgetc(jisho); pbuf++;
     } 
-    if (debug) {fprintf(errout, "1:%d:%d:%d:%d:\n", c, *pbuf, ' ', EOL);}
+/*    if (debug) {fprintf(errout, "1:%d:%d:%d:%d:", c, *pbuf, ' ', EOL);}*/
+    if (debug) {fprintf(errout, "%c", c);}
     if (c == ' ' && (*pbuf == ' ' || *pbuf == '\n')) { /* found */
+      if (debug) {fprintf(errout, "found\n");}
       if ((errcod = write(commsock, SERVER_FOUND, 1)) >= 0)
 	while ((c = fgetc(jisho)) != EOF) {
 	  *pbuf = c;
@@ -672,7 +793,18 @@
       }
       return(0);
     }
-    if (comp(*pbuf, c, sstyle)) {
+    if (debug) {
+      int ch;
+
+      if (c != ' ')
+	do {
+	  ch = fgetc(jisho);
+	  fprintf(errout, "%c", ch);
+	} while (ch != ' ' && ch != EOL);
+      fprintf(errout, "unmatched\n");
+    }
+    if (sstyle & 0x4) {
+      if (comp(*pbuf, c, sstyle&~0x4)) {
       if (debug) {
 	fprintf(stderr, "comp break %d \n", ftell(jisho));
       }
@@ -684,6 +816,12 @@
       if (c == EOL) break;
     }
     if (ftell(jisho) >= endpnt) break;
+    } else {
+      if (comp(*pbuf, c, sstyle&~0x4))
+	endpnt = curpnt;
+      else
+	sttpnt = curpnt;
+    }
   }
 
   if ((errcod = write(commsock, SERVER_NOT_FOUND, 1)) >= 0) {
@@ -724,6 +862,9 @@
     exit(1);
   }
   hentry = gethostbyname(hname);
+  if (hentry == NULL) {
+    fprintf(errout, "%s: WARNING: gethostbyname(%s) failed\n", pgmnm, hname);
+  } else {
 #ifdef NO_ADDR_LIST
   strcat(hname, ":");
   strcat(hname, hentry->h_addr);
@@ -736,6 +877,7 @@
     strcat(hname, inet_ntoa(*(struct in_addr *)*p++));
   }
 #endif
+  }
   strcat(hname, ": ");
 }
 
