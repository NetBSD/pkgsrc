$NetBSD: patch-doc_21-development.md,v 1.1 2021/01/17 13:22:26 wiz Exp $

Rename VERSION to ICINGA2_VERSION to avoid name clashes on case-insensitive file systems.
Upstream Pull Request #8596

--- doc/21-development.md.orig	2020-12-15 12:30:19.000000000 +0100
+++ doc/21-development.md	2021-01-15 16:09:28.000000000 +0100
@@ -2305,7 +2305,7 @@
 
 CMake determines the Icinga 2 version number using `git describe` if the
 source directory is contained in a Git repository. Otherwise the version number
-is extracted from the [VERSION](VERSION) file. This behavior can be
+is extracted from the [ICINGA2_VERSION](ICINGA2_VERSION) file. This behavior can be
 overridden by creating a file called `icinga-version.h.force` in the source
 directory. Alternatively the `-DICINGA2_GIT_VERSION_INFO=OFF` option for CMake
 can be used to disable the usage of `git describe`.
