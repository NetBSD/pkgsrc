$NetBSD: patch-curvecp_curvecpmessage.c,v 1.1 2022/01/05 13:51:19 schmonz Exp $

Debian patch 0007-fix-collecting-zombies.patch:
Fix collecting zombies.

--- curvecp/curvecpmessage.c.orig	2011-02-21 01:49:34.000000000 +0000
+++ curvecp/curvecpmessage.c
@@ -135,6 +135,9 @@ long long rtt_phase = 0;
 
 long long lastpanic = 0;
 
+int childdied = 0;
+int pollret;
+
 void earliestblocktime_compute(void) /* XXX: use priority queue */
 {
   long long i;
@@ -304,7 +307,10 @@ int main(int argc,char **argv)
     else
       timeout = (nextaction - recent) / 1000000 + 1;
 
-    if (poll(p,q - p,timeout) < 0) {
+    /* XXX */
+    if (childdied) timeout = 10;
+    pollret = poll(p,q - p,timeout);
+    if (pollret < 0) {
       watch8 = 0;
       watchtochild = 0;
       watchfromchild = 0;
@@ -314,6 +320,11 @@ int main(int argc,char **argv)
       if (watchfromchild) if (!watchfromchild->revents) watchfromchild = 0;
     }
 
+    /* XXX */
+    if (childdied && !pollret) {
+      if (childdied++ > 999) goto finish;
+    }
+
     /* XXX: keepalives */
 
     do { /* try receiving data from child: */
@@ -642,12 +653,23 @@ int main(int argc,char **argv)
       tochild[1] = -1;
     } while(0);
 
+    /* XXX */
+    if (!childdied){
+      if (waitpid(child,&childstatus, WNOHANG) > 0) {
+        close(tochild[1]);
+        tochild[1] = -1;
+        childdied = 1;
+      }
+    }
   }
 
+  if (!childdied) {
+    do {
+      r = waitpid(child,&childstatus,0);
+    } while (r == -1 && errno == EINTR);
+  }
 
-  do {
-    r = waitpid(child,&childstatus,0);
-  } while (r == -1 && errno == EINTR);
+finish:
 
   if (!WIFEXITED(childstatus)) { errno = 0; die_fatal("process killed by signal",0,0); }
   return WEXITSTATUS(childstatus);
