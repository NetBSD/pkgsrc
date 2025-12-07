$NetBSD: patch-src_module_unicode_charselectdata.c,v 1.2 2025/12/07 03:00:56 maya Exp $

Illumos has endian.h just like Linux
Fix ctype abuse by casting to unsigned char

--- src/module/unicode/charselectdata.c.orig	2017-12-22 18:02:24.000000000 +0000
+++ src/module/unicode/charselectdata.c
@@ -11,7 +11,7 @@
 #include <fcitx-utils/utils.h>
 #include <fcitx-config/xdg.h>
 #include <fcitx/fcitx.h>
-#if defined(__linux__) || defined(__GLIBC__)
+#if defined(__linux__) || defined(__GLIBC__) || defined(__illumos__)
 #include <endian.h>
 #else
 #include <sys/endian.h>
@@ -290,7 +290,7 @@ char* Simplified(const char* src)
     while(*s) {
         char c = *s;
 
-        if (isspace(c)) {
+        if (isspace((unsigned char) c)) {
             if (!lastIsSpace) {
                 *p = ' ';
                 p ++;
@@ -321,7 +321,7 @@ int IsHexString(const char* s)
 
     s += 2;
     while (*s) {
-        if (!isxdigit(*s))
+        if (!isxdigit((unsigned char) *s))
             return 0;
         s++;
     }
@@ -622,7 +622,7 @@ UT_array* SplitString(const char* s)
     int end = 0;
     int length = strlen(s);
     while (end < length) {
-        while (end < length && (isdigit(s[end]) || isalpha(s[end]) || s[end] == '+')) {
+        while (end < length && (isdigit((unsigned char) s[end]) || isalpha((unsigned char) s[end]) || s[end] == '+')) {
             end++;
         }
         if (start != end) {
@@ -631,7 +631,7 @@ UT_array* SplitString(const char* s)
             free(p);
         }
         start = end;
-        while (end < length && !(isdigit(s[end]) || isalpha(s[end]) || s[end] == '+')) {
+        while (end < length && !(isdigit((unsigned char) s[end]) || isalpha((unsigned char) s[end]) || s[end] == '+')) {
             end++;
             start++;
         }
