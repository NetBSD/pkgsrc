$NetBSD: patch-etc_papd_print_cups.c,v 1.3 2019/11/23 17:55:02 hauke Exp $

Deprecated functions: Remove obsolete define, and disable compiler
errors for deprecation warnings, as seen in the darktable print code.

Accessors: Cups has abstracted away access to ipp_t fields, use
accessor functions.

--- etc/papd/print_cups.c.orig	2017-07-09 11:03:31.000000000 +0000
+++ etc/papd/print_cups.c
@@ -39,11 +39,11 @@
 
 #ifdef HAVE_CUPS
 
-/* enable pre-1.6 CUPS API for now */
-#define _PPD_DEPRECATED
-
-/* expose structs that are private post-1.5 CUPS */
-#define _IPP_PRIVATE_STRUCTURES 1
+/*
+ * Do not error out on deprecation messages
+ * -- darktable does this in their "src/common/cups_print.c"
+ */
+#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
 
 #include <cups/ipp.h>
 #include <cups/cups.h>
@@ -61,6 +61,11 @@
 #define MAXCHOOSERLEN 31
 #define HTTP_MAX_URI 1024
 
+/* Deal with post-1.7 deprecated httpConnect() */
+#define httpConnect(host, port)		httpConnect2(host, port, NULL, AF_UNSPEC, HTTP_ENCRYPTION_IF_REQUESTED, 1, 1000, NULL)
+
+/* XXX Also: cupsGetPPD() */
+
 static const char* cups_status_msg[] = {
         "status: busy; info: \"%s\" is rejecting jobs; ",
         "status: idle; info: \"%s\" is stopped, accepting jobs ;",
@@ -136,12 +141,8 @@ cups_printername_ok(char *name)         
         *    requested-attributes
         *    printer-uri
         */
-
-        request = ippNew();
-
-        request->request.op.operation_id = IPP_GET_PRINTER_ATTRIBUTES;
-        request->request.op.request_id   = 1;
-
+	request = ippNewRequest(IPP_OP_GET_PRINTER_ATTRIBUTES);
+	
         language = cupsLangDefault();
 
         ippAddString(request, IPP_TAG_OPERATION, IPP_TAG_CHARSET,
@@ -172,10 +173,11 @@ cups_printername_ok(char *name)         
 
         httpClose(http);
 
-        if (response->request.status.status_code >= IPP_OK_CONFLICT)
+	if ( cupsLastError() >= IPP_OK_CONFLICT)	
         {
       		LOG(log_error, logtype_papd, "Unable to get printer status for %s - %s", name,
-                         ippErrorString(response->request.status.status_code));
+		    ippErrorString(cupsLastError()));
+
                 ippDelete(response);
                 return (0);
         }
@@ -249,10 +251,7 @@ cups_get_printer_status (struct printer 
         *    printer-uri
         */
 
-        request = ippNew();
-
-        request->request.op.operation_id = IPP_GET_PRINTER_ATTRIBUTES;
-        request->request.op.request_id   = 1;
+	request = ippNewRequest(IPP_OP_GET_PRINTER_ATTRIBUTES);
 
         language = cupsLangDefault();
 
@@ -282,10 +281,11 @@ cups_get_printer_status (struct printer 
                 return (0);
         }
 
-        if (response->request.status.status_code >= IPP_OK_CONFLICT)
+	if (cupsLastError() >= IPP_OK_CONFLICT)
         {
-      		LOG(log_error, logtype_papd, "Unable to get printer status for %s - %s", pr->p_printer,
-                         ippErrorString(response->request.status.status_code));
+		LOG(log_error, logtype_papd, "Unable to get printer status for %s - %s", pr->p_printer,
+		         ippErrorString(cupsLastError()));
+
                 ippDelete(response);
                 httpClose(http);
                 return (0);
@@ -299,9 +299,9 @@ cups_get_printer_status (struct printer 
 
         if ((attr = ippFindAttribute(response, "printer-state", IPP_TAG_ENUM)) != NULL)
         {
-                if (attr->values[0].integer == IPP_PRINTER_STOPPED)
+		if (ippGetInteger(attr, 0) == IPP_PRINTER_STOPPED)
 			status = 1;
-                else if (attr->values[0].integer == IPP_NOT_ACCEPTING)
+		else if (ippGetInteger(attr,0) == IPP_NOT_ACCEPTING)
 			status = 0;
 		else
 			status = 2;
@@ -309,14 +309,14 @@ cups_get_printer_status (struct printer 
 
 	if ((attr = ippFindAttribute(response, "printer-is-accepting-jobs", IPP_TAG_BOOLEAN)) != NULL)
 	{
-		if ( attr->values[0].integer == 0 ) 
+		if ( ippGetInteger(attr, 0) == 0 )	
 			status = 0;
 	}
 		
 	snprintf ( pr->p_status, 255, cups_status_msg[status], pr->p_printer );
 
         if ((attr = ippFindAttribute(response, "printer-state-message", IPP_TAG_TEXT)) != NULL)
-		strncat ( pr->p_status, attr->values[0].string.text, 255-strlen(pr->p_status));
+		strncat ( pr->p_status, ippGetString(attr, 0, NULL), 255-strlen(pr->p_status));	
 
         ippDelete(response);
 
