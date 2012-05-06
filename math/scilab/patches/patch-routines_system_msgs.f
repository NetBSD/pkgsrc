$NetBSD: patch-routines_system_msgs.f,v 1.1 2012/05/06 11:07:24 hans Exp $

--- routines/system/msgs.f.orig	2005-01-18 17:52:40.000000000 +0100
+++ routines/system/msgs.f	2012-05-06 11:35:56.483374475 +0200
@@ -81,7 +81,7 @@ c---------------------- message de matlu
       call showstack()
       goto 9999
  109  continue
-      write(buf(1:5),'(1pI5)') ierr
+      write(buf(1:5),'(I5)') ierr
       call basout(io, wte, 'rank defficient. rank = '//buf(1:5))
       goto 9999
  110  continue
