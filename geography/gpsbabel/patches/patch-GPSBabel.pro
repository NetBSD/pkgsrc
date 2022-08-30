$NetBSD: patch-GPSBabel.pro,v 1.1 2022/08/30 23:47:05 gdt Exp $

Add netbsd as a unix-like system.

Not yet sent upstream.

--- GPSBabel.pro.orig	2022-01-19 21:08:42.000000000 +0000
+++ GPSBabel.pro
@@ -281,7 +281,7 @@ HEADERS += $$FILTER_HEADERS
 
 CONFIG(release, debug|release): DEFINES *= NDEBUG
 
-macx|linux|openbsd {
+macx|linux|netbsd|openbsd {
   if (equals(MAKEFILE_GENERATOR, XCODE)) {
     # "Configure tests are not supported with the XCODE Makefile generator"
     # assume we have the following headers
@@ -354,7 +354,7 @@ QMAKE_EXTRA_TARGETS += check-vtesto
 QMAKE_CLEAN += $${OUT_PWD}/testo.d/*.vglog
 
 # build the compilation data base used by clang tools including clang-tidy.
-macx|linux|openbsd{
+macx|linux|netbsd|openbsd{
   compile_command_database.target = compile_commands.json
   compile_command_database.commands = $(MAKE) clean; bear $(MAKE)
   QMAKE_EXTRA_TARGETS += compile_command_database
