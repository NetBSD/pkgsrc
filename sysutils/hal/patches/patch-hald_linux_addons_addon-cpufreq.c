$NetBSD: patch-hald_linux_addons_addon-cpufreq.c,v 1.1 2012/05/14 03:12:01 sbd Exp $

--- hald/linux/addons/addon-cpufreq.c.orig	2009-08-24 12:42:30.000000000 +0000
+++ hald/linux/addons/addon-cpufreq.c
@@ -32,7 +32,6 @@
 #include <unistd.h>
 #include <signal.h>
 #include <getopt.h>
-#include <glib/gprintf.h>
 
 #include "addon-cpufreq.h"
 #include "addon-cpufreq-userspace.h"
