$NetBSD: patch-calma_CalmaRead.c,v 1.2 2013/03/07 22:05:12 joerg Exp $

--- calma/CalmaRead.c.orig	2013-03-02 22:21:53.000000000 +0000
+++ calma/CalmaRead.c
@@ -24,6 +24,7 @@ static char rcsid[] __attribute__ ((unus
 #include <string.h>
 #include <sys/types.h>
 #include <unistd.h>
+#include <stdarg.h>
 
 #include <netinet/in.h>
 
@@ -77,6 +78,8 @@ extern void calmaUnexpected();
 
 bool calmaParseUnits();
 
+void calmaReadError(char *format, ...);
+
 /*
  * Scaling.
  * Multiply all coordinates by calmaReadScale1, then divide them
@@ -437,10 +440,10 @@ calmaRecordName(rtype)
  */
 
     /*VARARGS1*/
-calmaReadError(format, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10)
-    char *format;
-    char *a1, *a2, *a3, *a4, *a5, *a6, *a7, *a8, *a9, *a10;
+void calmaReadError(char *format, ...)
 {
+    va_list ap;
+    va_start(ap, format);
     calmaTotalErrors++;
     if (CIFWarningLevel == CIF_WARN_NONE) return;
 
@@ -453,20 +456,20 @@ calmaReadError(format, a1, a2, a3, a4, a
 	    {
 		fprintf(calmaErrorFile, "Error while reading cell \"%s\": ",
 				cifReadCellDef->cd_name);
-		fprintf(calmaErrorFile, format, a1, a2, a3, a4, a5, a6, a7,
-				a8, a9, a10);
+		vfprintf(calmaErrorFile, format, ap);
 	    }
 	}
 	else
 	{
 	    TxError("Error while reading cell \"%s\": ", cifReadCellDef->cd_name);
-	    TxError(format, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
+	    VTxError(format, ap);
 	}
     }
     else if ((calmaTotalErrors == 100) && (CIFWarningLevel == CIF_WARN_LIMIT))
     {
 	TxError("Error limit set:  Remaining errors will not be reported.\n");
     }
+    va_end(ap);
 }
 
 /*
