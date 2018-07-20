$NetBSD: patch-foomatic-combo-xml.c,v 1.1 2018/07/20 19:14:00 leot Exp $

Avoid strcpy(3) undefined behaviour when *dst and *src overlaps.

--- foomatic-combo-xml.c.orig	2018-03-02 19:15:50.000000000 +0000
+++ foomatic-combo-xml.c
@@ -316,6 +316,7 @@ parse(char **data, /* I/O - Data to proc
   double        minnumvalue = 0;
   int           csense = 0;
   char          cprinter[256];
+  char          ctid[256];
   char          cmake[256];
   char          cmodel[256];
   char          cdriver[256];
@@ -1483,7 +1484,7 @@ parse(char **data, /* I/O - Data to proc
 		  inid = 0;
 		  /* Get the short printer ID (w/o "printer/") */
 		  strcpy(cprinter, currtagbody + 8);
-		  strcpy(cprinter, translateid(cprinter, idlist));
+		  strcpy(cprinter, translateid(currtagbody + 8, idlist));
 		  if (debug)
 		    fprintf(stderr,
 			    "    Overview: Printer: %s Driver: %s\n",
@@ -1970,7 +1971,8 @@ parse(char **data, /* I/O - Data to proc
 	    cprinter, cmake, cmodel, cfunctionality, cdriver,cautodetectentry);
     if ((cprinter[0]) && (cmake[0]) && (cmodel[0]) && (cfunctionality[0])) 
     /* ?PRINTER_ENTRY Y */ {
-      strcpy(cprinter, translateid(cprinter, idlist));
+      strcpy(ctid, translateid(cprinter, idlist));
+      strcpy(cprinter, ctid);
       strcat((char *)(*data), "  <printer>\n    <id>");
       strcat((char *)(*data), cprinter);
       strcat((char *)(*data), "</id>\n    <make>");
