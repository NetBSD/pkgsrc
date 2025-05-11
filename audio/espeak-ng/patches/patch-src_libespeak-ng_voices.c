$NetBSD: patch-src_libespeak-ng_voices.c,v 1.1 2025/05/11 12:31:23 ryoon Exp $

--- src/libespeak-ng/voices.c.orig	2024-12-12 13:28:01.000000000 +0000
+++ src/libespeak-ng/voices.c
@@ -98,7 +98,7 @@ static char *fgets_strip(char *buf, int 
 	}
 
 	len = strlen(buf);
-	while ((--len > 0) && isspace(buf[len]))
+	while ((--len > 0) && isspace((unsigned char)buf[len]))
 		buf[len] = 0;
 
 	if ((p = strstr(buf, "//")) != NULL)
@@ -188,7 +188,7 @@ static espeak_VOICE *ReadVoiceFile(FILE 
 		switch (LookupMnem(keyword_tab, linebuf))
 		{
 		case V_NAME:
-			while (isspace(*p)) p++;
+			while (isspace((unsigned char)*p)) p++;
 			strncpy0(vname, p, sizeof(vname));
 			break;
 		case V_LANGUAGE:
@@ -383,7 +383,7 @@ void ReadNumbers(char *p, int *flags, in
 	// the meaning of the  numbers is bit ordinals, not integer values
 	// give an error if number > maxValue is read
 	while (*p != 0) {
-		while (isspace(*p)) p++;
+		while (isspace((unsigned char)*p)) p++;
 		int n;
 		if ((n = atoi(p)) > 0) {
 			p++;
@@ -508,7 +508,7 @@ voice_t *LoadVoice(const char *vname, in
 
 	while ((f_voice != NULL) && (fgets_strip(buf, sizeof(buf), f_voice) != NULL)) {
 		// isolate the attribute name
-		for (p = buf; (*p != 0) && !isspace(*p); p++) ;
+		for (p = buf; (*p != 0) && !isspace((unsigned char)*p); p++) ;
 		*p++ = 0;
 
 		if (buf[0] == 0) continue;
@@ -561,7 +561,7 @@ voice_t *LoadVoice(const char *vname, in
                 break;
             case V_NAME:
                 if (tone_only == 0) {
-                    while (isspace(*p)) p++;
+                    while (isspace((unsigned char)*p)) p++;
                     strncpy0(voice_name, p, sizeof(voice_name));
                 }
                 break;
