$NetBSD: patch-src_Makefile.mk,v 1.1 2013/10/17 15:41:10 ryoon Exp $

http://www.falu.nl/~rhialto/klh-diffs2

--- src/Makefile.mk.orig	2005-02-21 23:16:14.000000000 +0000
+++ src/Makefile.mk
@@ -249,20 +249,7 @@ clean:
 #
 install-unix:
 	@echo "Copying binaries into ${KLH10_HOME}"
-	@-rm -rf ${KLH10_HOME}/flushed
-	@-mkdir  ${KLH10_HOME}/flushed
-	@if [ -x ${KLH10_HOME}/kn10-ks ]; then \
-		mv ${KLH10_HOME}/kn10-ks ${KLH10_HOME}/flushed; fi
-	@if [ -x ${KLH10_HOME}/kn10-kl ]; then \
-		mv ${KLH10_HOME}/kn10-kl ${KLH10_HOME}/flushed; fi
-	@if [ -x ${KLH10_HOME}/dprpxx ]; then \
-		mv ${KLH10_HOME}/dprpxx ${KLH10_HOME}/flushed; fi
-	@if [ -x ${KLH10_HOME}/dptm03 ]; then \
-		mv ${KLH10_HOME}/dptm03 ${KLH10_HOME}/flushed; fi
-	@if [ -x ${KLH10_HOME}/dpni20 ]; then \
-		mv ${KLH10_HOME}/dpni20 ${KLH10_HOME}/flushed; fi
-	@if [ -x ${KLH10_HOME}/dpimp  ]; then \
-		mv ${KLH10_HOME}/dpimp  ${KLH10_HOME}/flushed; fi
+	@-mkdir  ${KLH10_HOME}
 	@if [ -x kn10-ks  ]; then cp -p kn10-ks  ${KLH10_HOME}/; fi
 	@if [ -x kn10-kl  ]; then cp -p kn10-kl  ${KLH10_HOME}/; fi
 	@if [ -x dprpxx   ]; then cp -p dprpxx   ${KLH10_HOME}/; fi
