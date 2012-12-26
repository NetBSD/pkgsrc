$NetBSD: patch-xmlrpc.m4,v 1.1 2012/12/26 06:50:28 mef Exp $

The original sed script eats space chars around '-lpthread',
getting g++: unrecognized option '-pthread-lrt'.
Thus work arround:

--- m4/xmlrpc.m4.orig	2012-12-25 08:59:11.337607000 +0900
+++ m4/xmlrpc.m4	2012-12-25 09:20:27.797219000 +0900
@@ -12,7 +12,7 @@
 
           test "x$XMLRPC_CFLAGS" = "x" && XMLRPC_CFLAGS=`$XMLRPC_C_CONFIG c++2 abyss-server --cflags`
           if test "x$XMLRPC_LIBS" = "x"; then
-              XMLRPC_LIBS=`$XMLRPC_C_CONFIG c++2 abyss-server --ldadd | sed s/.-lpthread.//`
+              XMLRPC_LIBS=`$XMLRPC_C_CONFIG c++2 abyss-server --ldadd | sed 's/.-lpthread./ /'`
               test "$ac_cv_static" = "yes" && XMLRPC_LIBS="-Wl,-Bstatic $XMLRPC_LIBS -Wl,-Bdynamic"
           fi
       fi
