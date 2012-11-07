$NetBSD: patch-tools_genrb_derb.c,v 1.1 2012/11/07 20:59:51 adam Exp $

Changes "truncate" variable to "trunc" to avoid compilation error.

--- tools/genrb/derb.c.orig	2012-11-07 20:07:56.000000000 +0000
+++ tools/genrb/derb.c
@@ -54,7 +54,7 @@ static UConverter *defaultConverter = 0;
 
 static const int32_t indentsize = 4;
 static int32_t truncsize = DERB_DEFAULT_TRUNC;
-static UBool truncate = FALSE;
+static UBool trunc = FALSE;
 
 static const char *getEncodingName(const char *encoding);
 static void reportError(const char *pname, UErrorCode *status, const char *when);
@@ -152,14 +152,14 @@ main(int argc, char* argv[]) {
     }
 
     if(options[4].doesOccur) {
-        truncate = TRUE;
+        trunc = TRUE;
         if(options[4].value != NULL) {
             truncsize = atoi(options[4].value); /* user defined printable size */
         } else {
             truncsize = DERB_DEFAULT_TRUNC; /* we'll use default omitting size */
         }
     } else {
-        truncate = FALSE;
+        trunc = FALSE;
     }
 
     if(options[5].doesOccur) {
@@ -473,7 +473,7 @@ static void printOutAlias(FILE *out,  UC
     int32_t len = 0;
     const UChar* thestr = res_getAlias(&(parent->fResData), r, &len);
     UChar *string = quotedString(thestr);
-    if(truncate && len > truncsize) {
+    if(trunc && len > truncsize) {
         char msg[128];
         printIndent(out, converter, indent);
         sprintf(msg, "// WARNING: this resource, size %li is truncated to %li\n",
@@ -517,7 +517,7 @@ static void printOutBundle(FILE *out, UC
             UChar *string = quotedString(thestr);
 
             /* TODO: String truncation */
-            if(truncate && len > truncsize) {
+            if(trunc && len > truncsize) {
                 char msg[128];
                 printIndent(out, converter, indent);
                 sprintf(msg, "// WARNING: this resource, size %li is truncated to %li\n",
@@ -576,7 +576,7 @@ static void printOutBundle(FILE *out, UC
         {
             int32_t len = 0;
             const int8_t *data = (const int8_t *)ures_getBinary(resource, &len, status);
-            if(truncate && len > truncsize) {
+            if(trunc && len > truncsize) {
                 char msg[128];
                 printIndent(out, converter, indent);
                 sprintf(msg, "// WARNING: this resource, size %li is truncated to %li\n",
