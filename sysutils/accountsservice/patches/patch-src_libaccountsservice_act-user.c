$NetBSD: patch-src_libaccountsservice_act-user.c,v 1.2 2023/12/19 00:49:52 gutteridge Exp $

Add NetBSD backend.

--- src/libaccountsservice/act-user.c.orig	2016-01-11 15:42:43.000000000 +0000
+++ src/libaccountsservice/act-user.c
@@ -20,9 +20,15 @@
 
 #include <config.h>
 
+#include <sys/types.h>
+#ifdef __NetBSD__
+#include <err.h>
+#include <errno.h>
+#include <pwd.h>
+/* #include <util.h> XXX should be included, but this project has its own util.h! */
+#endif
 #include <float.h>
 #include <string.h>
-#include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
 
@@ -1818,8 +1824,29 @@ salt_char (GRand *rand)
 }
 
 static gchar *
-make_crypted (const gchar *plain)
+make_crypted (const gchar *username, const gchar *plain)
 {
+#ifdef __NetBSD__
+        char salt[_PASSWORD_LEN+1];
+        char option[LINE_MAX], *key, *opt;
+        struct passwd *pw;
+
+        if (!(pw = getpwnam(username))) {
+                errx(EXIT_FAILURE, "can't get pw for %s", username);
+        }
+
+
+        pw_getpwconf(option, sizeof(option), pw, "localcipher");
+        opt = option;
+        key = strsep(&opt, ",");
+
+        if (pw_gensalt(salt, _PASSWORD_LEN, key, opt) == -1) {
+                errx(EXIT_FAILURE, "Failed to pw_gensalt: %s", strerror(errno));
+        }
+
+	gchar *result = g_strdup (crypt (plain, salt));
+
+#else
         GString *salt;
         gchar *result;
         GRand *rand;
@@ -1830,6 +1857,7 @@ make_crypted (const gchar *plain)
 
         /* SHA 256 */
         g_string_append (salt, "$6$");
+
         for (i = 0; i < 16; i++) {
                 g_string_append_c (salt, salt_char (rand));
         }
@@ -1839,6 +1867,7 @@ make_crypted (const gchar *plain)
 
         g_string_free (salt, TRUE);
         g_rand_free (rand);
+#endif
 
         return result;
 }
@@ -1866,7 +1895,7 @@ act_user_set_password (ActUser          
         g_return_if_fail (password != NULL);
         g_return_if_fail (ACCOUNTS_IS_USER (user->accounts_proxy));
 
-        crypted = make_crypted (password);
+        crypted = make_crypted (user->user_name, password);
         if (!accounts_user_call_set_password_sync (user->accounts_proxy,
                                                    crypted,
                                                    hint,
