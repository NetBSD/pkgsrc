$NetBSD: patch-xymond_rrd_do__temperature.c,v 1.1 2019/11/24 20:16:55 spz Exp $

from https://sourceforge.net/p/xymon/code/8073/
Really fix do_temperature.c report parsing for parentheses (Thanks, Tom Schmidt)

--- xymond/rrd/do_temperature.c.orig	2019-04-17 23:56:30.000000000 +0000
+++ xymond/rrd/do_temperature.c
@@ -41,4 +41,17 @@ Device				Temp	High	Crit
 -----------------------------------------------------
 
+Device                   Temp(C)  Temp(F)    Lo(C)  LoWarn(C)  HiWarn(C)  Hi(C)
+-------------------------------------------------------------------------------
+&green CPU 0 Die                79      174     (-10        0         88      90)
+&green CPU 0 Ambient            23       73     (-10        0         40      60)
+-------------------------------------------------------------------------------
+
+Device                  Temp(C)  Temp(F)  Threshold(C)
+------------------------------------------------------
+&green System Board Inlet Temp    21       69     ( 42)
+&green CPU1 Temp               32       89     ( 93)
+&green CPU2 Temp               31       87     ( 93)
+------------------------------------------------------
+
 */
 
@@ -51,5 +64,5 @@ int do_temperature_rrd(char *hostname, c
 	static void *temperature_tpl	  = NULL;
 
-	char *bol, *eol, *p;
+	char *bol, *eol, *comment, *p;
 	int tmpC;
 
@@ -63,4 +76,9 @@ int do_temperature_rrd(char *hostname, c
 		eol = strchr(bol, '\n'); if (eol) *eol = '\0';
 
+		/* See if there's a comment in parenthesis */
+		comment = strchr(bol, '('); /* Begin comment */
+		p = strchr(bol, ')');       /* End comment */
+		if (comment && p && (comment < p)) *comment = '\0'; /* Cut off the comment */
+
 		if	(strncmp(bol, "&green", 6) == 0)  { bol += 6; gotone = 1; }
 		else if (strncmp(bol, "&yellow", 7) == 0) { bol += 7; gotone = 1; }
@@ -71,4 +89,10 @@ int do_temperature_rrd(char *hostname, c
 			char savech;
 
+			/* Strip off any leading bold and italic HTML tags */
+			if      (strncasecmp(bol, "<i><b>", 6) == 0)  { bol += 6; }
+			else if (strncasecmp(bol, "<i>", 3) == 0)  { bol += 3; }
+			else if (strncasecmp(bol, "<b><i>", 6) == 0)  { bol += 6; }
+			else if (strncasecmp(bol, "<b>", 3) == 0)  { bol += 3; }
+
 			bol += strspn(bol, " \t");
 
@@ -84,4 +108,5 @@ int do_temperature_rrd(char *hostname, c
 		}
 
+		if (comment) *comment = '(';
 		if (eol) *eol = '\n';
 	}
