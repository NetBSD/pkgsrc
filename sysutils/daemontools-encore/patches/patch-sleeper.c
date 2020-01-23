$NetBSD: patch-sleeper.c,v 1.1 2020/01/23 16:49:59 schmonz Exp $

Apply https://github.com/bruceg/daemontools-encore/pull/54 to fix tests.

--- sleeper.c.orig	2018-10-14 00:48:50.000000000 +0000
+++ sleeper.c
@@ -1,39 +1,84 @@
+#include <unistd.h>
 #include <signal.h>
+#include "ndelay.h"
+#include "strerr.h"
+#include "error.h"
 #include "byte.h"
 #include "sig.h"
 #include "str.h"
-#include <unistd.h>
+
+static int selfpipe[2];
 
 static void catch_sig(int sig)
 {
+  int ignored;
+  char c;
+
+  c = (char)sig;
+  ignored = write(selfpipe[1],&c,1);
+  (void)ignored;
+}
+
+static void show_sig(int sig)
+{
   char buf[7+14+2] = "Caught ";
   const char *name;
   int ignored;
   int i;
+
   switch (sig) {
-  case SIGALRM: name = "ALRM"; break;
-  case SIGCONT: name = "CONT"; break;
-  case SIGHUP: name = "HUP"; break;
-  case SIGINT: name = "INT"; break;
-  case SIGQUIT: name = "QUIT"; break;
-  case SIGTERM: name = "TERM"; break;
-  case SIGUSR1: name = "USR1"; break;
-  case SIGUSR2: name = "USR2"; break;
-  case SIGWINCH: name = "WINCH"; break;
-  default: name = "unknown signal";
+    case SIGALRM: name = "ALRM"; break;
+    case SIGCONT: name = "CONT"; break;
+    case SIGHUP: name = "HUP"; break;
+    case SIGINT: name = "INT"; break;
+    case SIGQUIT: name = "QUIT"; break;
+    case SIGTERM: name = "TERM"; break;
+    case SIGUSR1: name = "USR1"; break;
+    case SIGUSR2: name = "USR2"; break;
+    case SIGWINCH: name = "WINCH"; break;
+    default: name = "unknown signal";
   }
   i = str_len(name);
   byte_copy(buf+7,i,name);
   i += 7;
   buf[i++] = '\n';
   ignored = write(1,buf,i);
-  if (sig != SIGCONT)
-    _exit(1);
   (void)ignored;
 }
 
+static void show_err()
+{
+  int ignored;
+
+  ignored = write(1,"invalid signal\n",15);
+  return;
+  (void)ignored;
+}
+
+static void show_one(int sig)
+{
+  show_sig(sig);
+  return;
+}
+
+static void show_two(int sig1, int sig2)
+{
+  show_sig(sig1);
+  show_sig(sig2);
+  return;
+}
+
 int main(void)
 {
+  int r;
+  int nc, nt, oc, ot;
+  int new_sig, old_sig=0;
+  char buf;
+
+  if (pipe(selfpipe) == -1)
+    strerr_die1sys(111,"sleeper: fatal: unable to create pipe");
+  ndelay_on(selfpipe[1]);
+
   sig_catch(SIGALRM,catch_sig);
   sig_catch(SIGCONT,catch_sig);
   sig_catch(SIGHUP,catch_sig);
@@ -43,6 +88,38 @@ int main(void)
   sig_catch(SIGUSR1,catch_sig);
   sig_catch(SIGUSR2,catch_sig);
   sig_catch(SIGWINCH,catch_sig);
-  sleep(9999);
-  return 0;
+
+  for (;;) {
+    r = read(selfpipe[0],&buf,1);
+    if (!r) break;
+    if (r == -1) {
+      if (errno == error_intr) continue;
+      break;
+    }
+
+    new_sig = (int)buf;
+
+    nc = new_sig == SIGCONT;
+    nt = new_sig == SIGTERM;
+    oc = old_sig == SIGCONT;
+    ot = old_sig == SIGTERM;
+
+    if (!nc && !nt && !oc && !ot) {show_one(new_sig);          break;   }
+    if (!nc && !nt && !oc &&  ot) {show_two(SIGTERM, new_sig); break;   }
+    if (!nc && !nt &&  oc && !ot) {show_two(SIGCONT, new_sig); break;   }
+    if (!nc && !nt &&  oc &&  ot) {show_err();                 break;   }
+    if (!nc &&  nt && !oc && !ot) {old_sig = SIGTERM;          continue;}
+    if (!nc &&  nt && !oc &&  ot) {show_one(SIGTERM);          continue;}
+    if (!nc &&  nt &&  oc && !ot) {show_two(SIGCONT, SIGTERM); break;   }
+    if (!nc &&  nt &&  oc &&  ot) {show_err();                 break;   }
+    if ( nc && !nt && !oc && !ot) {old_sig = SIGCONT;          continue;}
+    if ( nc && !nt && !oc &&  ot) {show_two(SIGCONT, SIGTERM); break;   }
+    if ( nc && !nt &&  oc && !ot) {show_one(SIGCONT);          continue;}
+    if ( nc && !nt &&  oc &&  ot) {show_err();                 break;   }
+    if ( nc &&  nt && !oc && !ot) {show_err();                 break;   }
+    if ( nc &&  nt && !oc &&  ot) {show_err();                 break;   }
+    if ( nc &&  nt &&  oc && !ot) {show_err();                 break;   }
+    if ( nc &&  nt &&  oc &&  ot) {show_err();                 break;   }
+  }
+  _exit(0);
 }
