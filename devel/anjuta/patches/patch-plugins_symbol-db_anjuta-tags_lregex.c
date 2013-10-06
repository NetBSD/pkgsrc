$NetBSD: patch-plugins_symbol-db_anjuta-tags_lregex.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/symbol-db/anjuta-tags/lregex.c.orig	2013-09-29 15:17:28.000000000 +0000
+++ plugins/symbol-db/anjuta-tags/lregex.c
@@ -538,11 +538,11 @@ extern void findRegexTags (void)
 #endif  /* HAVE_REGEX */
 
 extern void addTagRegex (
-		const langType language __unused__,
-		const char* const regex __unused__,
-		const char* const name __unused__,
-		const char* const kinds __unused__,
-		const char* const flags __unused__)
+		const langType language ,
+		const char* const regex ,
+		const char* const name ,
+		const char* const kinds ,
+		const char* const flags )
 {
 #ifdef HAVE_REGEX
 	Assert (regex != NULL);
@@ -564,10 +564,10 @@ extern void addTagRegex (
 }
 
 extern void addCallbackRegex (
-		const langType language __unused__,
-		const char* const regex __unused__,
-		const char* const flags __unused__,
-		const regexCallback callback __unused__)
+		const langType language ,
+		const char* const regex ,
+		const char* const flags ,
+		const regexCallback callback )
 {
 #ifdef HAVE_REGEX
 	Assert (regex != NULL);
@@ -581,7 +581,7 @@ extern void addCallbackRegex (
 }
 
 extern void addLanguageRegex (
-		const langType language __unused__, const char* const regex __unused__)
+		const langType language , const char* const regex )
 {
 #ifdef HAVE_REGEX
 	if (! regexBroken)
@@ -602,7 +602,7 @@ extern void addLanguageRegex (
 */
 
 extern boolean processRegexOption (const char *const option,
-								   const char *const parameter __unused__)
+								   const char *const parameter )
 {
 	boolean handled = FALSE;
 	const char* const dash = strchr (option, '-');
@@ -624,7 +624,7 @@ extern boolean processRegexOption (const
 	return handled;
 }
 
-extern void disableRegexKinds (const langType language __unused__)
+extern void disableRegexKinds (const langType language )
 {
 #ifdef HAVE_REGEX
 	if (language <= SetUpper  &&  Sets [language].count > 0)
@@ -639,8 +639,8 @@ extern void disableRegexKinds (const lan
 }
 
 extern boolean enableRegexKind (
-		const langType language __unused__,
-		const int kind __unused__, const boolean mode __unused__)
+		const langType language ,
+		const int kind , const boolean mode )
 {
 	boolean result = FALSE;
 #ifdef HAVE_REGEX
@@ -660,7 +660,7 @@ extern boolean enableRegexKind (
 	return result;
 }
 
-extern void printRegexKinds (const langType language __unused__, boolean indent __unused__)
+extern void printRegexKinds (const langType language , boolean indent )
 {
 #ifdef HAVE_REGEX
 	if (language <= SetUpper  &&  Sets [language].count > 0)
