$NetBSD: patch-calendar_importers_icalendar-importer.c,v 1.1 2018/05/16 16:15:23 jperkin Exp $

Support current libical API.

--- calendar/importers/icalendar-importer.c.orig	2011-03-29 18:38:46.000000000 +0000
+++ calendar/importers/icalendar-importer.c
@@ -39,6 +39,7 @@
 #include <libecal/e-cal-time-util.h>
 #include <libedataserverui/e-source-selector.h>
 #include <libical/icalvcal.h>
+#include <libical/vcc.h>
 #include "evolution-calendar-importer.h"
 #include "shell/e-shell.h"
 #include "common/authentication.h"
