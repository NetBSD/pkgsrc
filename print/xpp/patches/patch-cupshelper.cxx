$NetBSD: patch-cupshelper.cxx,v 1.2 2020/03/05 14:57:59 bouyer Exp $

update for new cups API

--- cupshelper.cxx.orig	2002-05-28 17:49:45.000000000 +0200
+++ cupshelper.cxx	2020-03-04 15:02:34.300403189 +0100
@@ -34,6 +34,7 @@
 #include "cupshelper.h"
 #include "passworddialog.h"
 
+#include <stdio.h>
 #include <stdlib.h>
 #include <cups/language.h>
 
@@ -90,7 +91,7 @@
 
 ipp_t* CupsHelper::newIppRequest(){
 	ipp_t	*request = ippNew();
-	request->request.op.request_id = 1;
+	ippSetRequestId(request, 1);
 	cups_lang_t	*lang = cupsLangDefault();
 	ippAddString(request,IPP_TAG_OPERATION,IPP_TAG_CHARSET,"attributes-charset",NULL,cupsLangEncoding(lang));
 	ippAddString(request,IPP_TAG_OPERATION,IPP_TAG_LANGUAGE,"attributes-natural-language",NULL,lang->language);
@@ -108,7 +109,7 @@
 	httpClose(HTTP);
 	if (!answer)
 		return 0;
-	if (answer->state == IPP_ERROR || answer->state == IPP_IDLE)
+	if (ippGetState(answer) == IPP_ERROR || ippGetState(answer) == IPP_IDLE)
 	{
 		ippDelete(answer);
 		return 0;
@@ -151,15 +152,15 @@
 	char      str[256];
 	int	  value(-1);
 
-	request->request.op.operation_id = IPP_GET_PRINTER_ATTRIBUTES;
+	ippSetOperation(request, IPP_GET_PRINTER_ATTRIBUTES);
 	sprintf(str,"ipp://%s:%d/printers/%s",host(),port(),name);
 	ippAddString(request,IPP_TAG_OPERATION,IPP_TAG_URI,"printer-uri",NULL,str);
 	//sprintf(str,"/printers/%s",name);
 	sprintf(str,"/printers/");
 	request = processRequest(request,str);
-	if (request && request->curtag == IPP_TAG_PRINTER) {
+	if (request) {
 		ipp_attribute_t	*attr = ippFindAttribute(request,"printer-type",IPP_TAG_ENUM);
-		if (attr) value = attr->values[0].integer;
+		if (attr) value = ippGetInteger(attr, 0);
 	}
 	ippDelete(request);
 	return value;
