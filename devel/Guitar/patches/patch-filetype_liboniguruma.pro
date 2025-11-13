$NetBSD: patch-filetype_liboniguruma.pro,v 1.1 2025/11/13 22:28:18 wiz Exp $

config.h does not exist.

--- filetype/liboniguruma.pro.orig	2025-10-31 14:38:04.000000000 +0000
+++ filetype/liboniguruma.pro
@@ -10,7 +10,6 @@ CONFIG -= app_bundle
 CONFIG -= qt
 
 DEFINES += ONIG_STATIC=1 USE_POSIX_API=1
-DEFINES += HAVE_CONFIG_H=1
 msvc:INCLUDEPATH += oniguruma-msvc
 
 HEADERS += \
