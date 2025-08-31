$NetBSD: patch-fallback_const-c.inc,v 1.1 2025/08/31 12:45:24 wiz Exp $

Fix build with libcupsfilters 2.x. From
https://launchpadlibrarian.net/698897992/libnet-cups-perl_0.64-3_0.64-3ubuntu1.diff.gz

--- fallback/const-c.inc.orig	2008-05-08 02:43:32.000000000 +0000
+++ fallback/const-c.inc
@@ -651,7 +651,7 @@ static int
 constant_14 (pTHX_ const char *name, IV *iv_return) {
   /* When generated this function returned values for the list of names given
      here.  However, subsequent manual editing may have added or removed some.
-     CUPS_ADD_CLASS CUPS_FILE_GZIP CUPS_FILE_NONE CUPS_IMAGE_CMY CUPS_IMAGE_RGB
+     CUPS_ADD_CLASS CUPS_FILE_GZIP CUPS_FILE_NONE CF_IMAGE_CMY CF_IMAGE_RGB
      CUPS_ISO8859_1 CUPS_ISO8859_2 CUPS_ISO8859_3 CUPS_ISO8859_4 CUPS_ISO8859_5
      CUPS_ISO8859_6 CUPS_ISO8859_7 CUPS_ISO8859_8 CUPS_ISO8859_9 CUPS_MAC_ROMAN
      HTTP_AUTH_NONE HTTP_FIELD_MAX HTTP_FORBIDDEN HTTP_MAX_VALUE HTTP_NOT_FOUND
@@ -725,9 +725,9 @@ constant_14 (pTHX_ const char *name, IV 
     }
     break;
   case 'B':
-    if (memEQ(name, "CUPS_IMAGE_RG", 13)) {
+    if (memEQ(name, "CF_IMAGE_RG", 13)) {
     /*                            B      */
-      *iv_return = CUPS_IMAGE_RGB;
+      *iv_return = CF_IMAGE_RGB;
       return PERL_constant_ISIV;
     }
     if (memEQ(name, "IPP_CANCEL_JO", 13)) {
@@ -884,9 +884,9 @@ constant_14 (pTHX_ const char *name, IV 
     }
     break;
   case 'Y':
-    if (memEQ(name, "CUPS_IMAGE_CM", 13)) {
+    if (memEQ(name, "CF_IMAGE_CM", 13)) {
     /*                            Y      */
-      *iv_return = CUPS_IMAGE_CMY;
+      *iv_return = CF_IMAGE_CMY;
       return PERL_constant_ISIV;
     }
     if (memEQ(name, "HTTP_USE_PROX", 13)) {
@@ -903,7 +903,7 @@ static int
 constant_15 (pTHX_ const char *name, IV *iv_return) {
   /* When generated this function returned values for the list of names given
      here.  However, subsequent manual editing may have added or removed some.
-     CUPS_BACKEND_OK CUPS_IMAGE_CMYK CUPS_ISO8859_10 CUPS_ISO8859_11
+     CUPS_BACKEND_OK CF_IMAGE_CMYK CUPS_ISO8859_10 CUPS_ISO8859_11
      CUPS_ISO8859_13 CUPS_ISO8859_14 CUPS_ISO8859_15 CUPS_ISO8859_16
      CUPS_PRINTER_BW HTTP_AUTH_BASIC HTTP_FIELD_DATE HTTP_FIELD_HOST
      HTTP_FIELD_LINK HTTP_MAX_BUFFER HTTP_NO_CONTENT IPP_BAD_REQUEST
@@ -1029,9 +1029,9 @@ constant_15 (pTHX_ const char *name, IV 
       *iv_return = CUPS_BACKEND_OK;
       return PERL_constant_ISIV;
     }
-    if (memEQ(name, "CUPS_IMAGE_CMY", 14)) {
+    if (memEQ(name, "CF_IMAGE_CMY", 14)) {
     /*                             K      */
-      *iv_return = CUPS_IMAGE_CMYK;
+      *iv_return = CF_IMAGE_CMYK;
       return PERL_constant_ISIV;
     }
     if (memEQ(name, "HTTP_FIELD_LIN", 14)) {
@@ -1136,7 +1136,7 @@ constant_16 (pTHX_ const char *name, IV 
   /* When generated this function returned values for the list of names given
      here.  However, subsequent manual editing may have added or removed some.
      CUPS_ACCEPT_JOBS CUPS_ADD_PRINTER CUPS_GET_CLASSES CUPS_GET_DEFAULT
-     CUPS_GET_DEVICES CUPS_IMAGE_BLACK CUPS_IMAGE_WHITE CUPS_MAX_USTRING
+     CUPS_GET_DEVICES CF_IMAGE_BLACK CF_IMAGE_WHITE CUPS_MAX_USTRING
      CUPS_PRINTER_FAX CUPS_REJECT_JOBS CUPS_SET_DEFAULT CUPS_WINDOWS_874
      CUPS_WINDOWS_932 CUPS_WINDOWS_936 CUPS_WINDOWS_949 CUPS_WINDOWS_950
      HTTP_BAD_GATEWAY HTTP_BAD_REQUEST HTTP_FIELD_RANGE HTTP_URI_BAD_URI
@@ -1176,9 +1176,9 @@ constant_16 (pTHX_ const char *name, IV 
     }
     break;
   case 'A':
-    if (memEQ(name, "CUPS_IMAGE_BLACK", 16)) {
+    if (memEQ(name, "CF_IMAGE_BLACK", 16)) {
     /*                            ^         */
-      *iv_return = CUPS_IMAGE_BLACK;
+      *iv_return = CF_IMAGE_BLACK;
       return PERL_constant_ISIV;
     }
     if (memEQ(name, "IPP_TAG_LANGUAGE", 16)) {
@@ -1233,9 +1233,9 @@ constant_16 (pTHX_ const char *name, IV 
     }
     break;
   case 'I':
-    if (memEQ(name, "CUPS_IMAGE_WHITE", 16)) {
+    if (memEQ(name, "CF_IMAGE_WHITE", 16)) {
     /*                            ^         */
-      *iv_return = CUPS_IMAGE_WHITE;
+      *iv_return = CF_IMAGE_WHITE;
       return PERL_constant_ISIV;
     }
     if (memEQ(name, "CUPS_MAX_USTRING", 16)) {
@@ -1855,7 +1855,7 @@ constant_19 (pTHX_ const char *name, IV 
   /* When generated this function returned values for the list of names given
      here.  However, subsequent manual editing may have added or removed some.
      CUPS_BACKEND_CANCEL CUPS_BACKEND_FAILED CUPS_DELETE_PRINTER
-     CUPS_IMAGE_RGB_CMYK CUPS_PRINTER_COPIES CUPS_PRINTER_DELETE
+     CF_IMAGE_RGB_CMYK CUPS_PRINTER_COPIES CUPS_PRINTER_DELETE
      CUPS_PRINTER_DUPLEX CUPS_PRINTER_MEDIUM CUPS_PRINTER_REMOTE
      CUPS_PRINTER_STAPLE HTTP_ENCODE_CHUNKED HTTP_ENCRYPT_ALWAYS
      HTTP_FIELD_LOCATION HTTP_NOT_ACCEPTABLE HTTP_URI_BAD_SCHEME
@@ -1903,9 +1903,9 @@ constant_19 (pTHX_ const char *name, IV 
     }
     break;
   case 'C':
-    if (memEQ(name, "CUPS_IMAGE_RGB_CMYK", 19)) {
+    if (memEQ(name, "CF_IMAGE_RGB_CMYK", 19)) {
     /*                              ^          */
-      *iv_return = CUPS_IMAGE_RGB_CMYK;
+      *iv_return = CF_IMAGE_RGB_CMYK;
       return PERL_constant_ISIV;
     }
     if (memEQ(name, "PPD_CUSTOM_PASSCODE", 19)) {
@@ -3319,6 +3319,12 @@ use ExtUtils::Constant qw (constant_type
 my $types = {map {($_, 1)} qw(IV)};
 my @names = (qw(INET6),
             {name=>"AF_LOCAL", type=>"IV", macro=>"1"},
+            {name=>"CF_IMAGE_BLACK", type=>"IV", macro=>"1"},
+            {name=>"CF_IMAGE_CMY", type=>"IV", macro=>"1"},
+            {name=>"CF_IMAGE_CMYK", type=>"IV", macro=>"1"},
+            {name=>"CF_IMAGE_RGB", type=>"IV", macro=>"1"},
+            {name=>"CF_IMAGE_RGB_CMYK", type=>"IV", macro=>"1"},
+            {name=>"CF_IMAGE_WHITE", type=>"IV", macro=>"1"},
             {name=>"CUPS_ACCEPT_JOBS", type=>"IV", macro=>"1"},
             {name=>"CUPS_ADD_CLASS", type=>"IV", macro=>"1"},
             {name=>"CUPS_ADD_MODIFY_CLASS", type=>"IV", macro=>"1"},
@@ -3349,12 +3355,6 @@ my @names = (qw(INET6),
             {name=>"CUPS_GET_DEVICES", type=>"IV", macro=>"1"},
             {name=>"CUPS_GET_PPDS", type=>"IV", macro=>"1"},
             {name=>"CUPS_GET_PRINTERS", type=>"IV", macro=>"1"},
-            {name=>"CUPS_IMAGE_BLACK", type=>"IV", macro=>"1"},
-            {name=>"CUPS_IMAGE_CMY", type=>"IV", macro=>"1"},
-            {name=>"CUPS_IMAGE_CMYK", type=>"IV", macro=>"1"},
-            {name=>"CUPS_IMAGE_RGB", type=>"IV", macro=>"1"},
-            {name=>"CUPS_IMAGE_RGB_CMYK", type=>"IV", macro=>"1"},
-            {name=>"CUPS_IMAGE_WHITE", type=>"IV", macro=>"1"},
             {name=>"CUPS_ISO8859_1", type=>"IV", macro=>"1"},
             {name=>"CUPS_ISO8859_10", type=>"IV", macro=>"1"},
             {name=>"CUPS_ISO8859_11", type=>"IV", macro=>"1"},
