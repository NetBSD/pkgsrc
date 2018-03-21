$NetBSD: patch-src_old__main_settings.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/old_main/settings.cc.orig	2014-08-17 08:45:12.000000000 +0000
+++ src/old_main/settings.cc
@@ -286,19 +286,19 @@ void settings_debugdump(struct settings 
 
 			switch (settings->presentation_format[i]) {
 			case SETTINGS_FORMAT_DECIMAL:
-				printf("%"PRIi64, value);
+				printf("%" PRIi64, value);
 				break;
 			case SETTINGS_FORMAT_HEX8:
-				printf("0x%02"PRIx8, (int8_t) value);
+				printf("0x%02" PRIx8, (int8_t) value);
 				break;
 			case SETTINGS_FORMAT_HEX16:
-				printf("0x%04"PRIx16, (int16_t) value);
+				printf("0x%04" PRIx16, (int16_t) value);
 				break;
 			case SETTINGS_FORMAT_HEX32:
-				printf("0x%08"PRIx32, (int32_t) value);
+				printf("0x%08" PRIx32, (int32_t) value);
 				break;
 			case SETTINGS_FORMAT_HEX64:
-				printf("0x%016"PRIx64, (int64_t) value);
+				printf("0x%016" PRIx64, (int64_t) value);
 				break;
 			case SETTINGS_FORMAT_BOOL:
 				printf(value? "true" : "false");
@@ -503,4 +503,3 @@ int settings_access(struct settings *set
 
 	return SETTINGS_NAME_NOT_FOUND;
 }
-
