$NetBSD: patch-tools_ocaml_libs_eventchn_xeneventchn_stubs.c,v 1.1 2020/08/27 08:22:33 bouyer Exp $

--- ./tools/ocaml/libs/eventchn/xeneventchn_stubs.c.orig	2020-05-27 14:58:46.844387392 +0200
+++ ./tools/ocaml/libs/eventchn/xeneventchn_stubs.c	2020-05-27 14:58:15.278522159 +0200
@@ -22,7 +22,6 @@
 #include <stdint.h>
 #include <sys/ioctl.h>
 #include <xen/xen.h>
-#include <xen/sys/evtchn.h>
 #include <xenevtchn.h>
 
 #define CAML_NAME_SPACE
