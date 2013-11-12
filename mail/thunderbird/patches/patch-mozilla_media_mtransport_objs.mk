$NetBSD: patch-mozilla_media_mtransport_objs.mk,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/media/mtransport/objs.mk.orig	2013-10-23 22:09:11.000000000 +0000
+++ mozilla/media/mtransport/objs.mk
@@ -23,12 +23,16 @@ LOCAL_INCLUDES += \
  -I$(topsrcdir)/media/mtransport/third_party/nrappkit/src/event \
  $(NULL)
 
-ifeq ($(OS_TARGET), Darwin)
+ifneq (,$(filter Darwin DragonFly FreeBSD NetBSD OpenBSD,$(OS_TARGET)))
 LOCAL_INCLUDES += \
   -I$(topsrcdir)/media/mtransport/third_party/nrappkit/src/port/darwin/include \
   -I$(topsrcdir)/media/mtransport/third_party/nrappkit/src/port/generic/include \
   $(NULL)
+ifeq ($(OS_TARGET), Darwin)
 DEFINES += -DDARWIN
+else
+DEFINES += -DBSD
+endif
 endif
 
 ifeq ($(OS_TARGET), Linux)
