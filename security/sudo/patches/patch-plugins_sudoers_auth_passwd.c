$NetBSD: patch-plugins_sudoers_auth_passwd.c,v 1.2.2.2 2022/11/11 19:59:12 bsiegert Exp $

Fix CVE-2022-43995 from upstream commit.

--- plugins/sudoers/auth/passwd.c.orig	2022-06-12 18:46:46.000000000 +0000
+++ plugins/sudoers/auth/passwd.c
@@ -63,7 +63,7 @@ sudo_passwd_init(struct passwd *pw, sudo
 int
 sudo_passwd_verify(struct passwd *pw, char *pass, sudo_auth *auth, struct sudo_conv_callback *callback)
 {
-    char sav, *epass;
+    char des_pass[9], *epass;
     char *pw_epasswd = auth->data;
     size_t pw_len;
     int matched = 0;
@@ -75,12 +75,12 @@ sudo_passwd_verify(struct passwd *pw, ch
 
     /*
      * Truncate to 8 chars if standard DES since not all crypt()'s do this.
-     * If this turns out not to be safe we will have to use OS #ifdef's (sigh).
      */
-    sav = pass[8];
     pw_len = strlen(pw_epasswd);
-    if (pw_len == DESLEN || HAS_AGEINFO(pw_epasswd, pw_len))
-	pass[8] = '\0';
+    if (pw_len == DESLEN || HAS_AGEINFO(pw_epasswd, pw_len)) {
+	strlcpy(des_pass, pass, sizeof(des_pass));
+	pass = des_pass;
+    }
 
     /*
      * Normal UN*X password check.
@@ -88,7 +88,6 @@ sudo_passwd_verify(struct passwd *pw, ch
      * only compare the first DESLEN characters in that case.
      */
     epass = (char *) crypt(pass, pw_epasswd);
-    pass[8] = sav;
     if (epass != NULL) {
 	if (HAS_AGEINFO(pw_epasswd, pw_len) && strlen(epass) == DESLEN)
 	    matched = !strncmp(pw_epasswd, epass, DESLEN);
