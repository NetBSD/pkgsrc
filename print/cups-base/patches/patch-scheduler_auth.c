$NetBSD: patch-scheduler_auth.c,v 1.2 2018/04/05 16:31:45 leot Exp $

- Don't pull in sys/ucred.h on Solaris as it results in procfs.h being
  included and conflicts between _FILE_OFFSET_BITS=64 and 32-bit procfs.
- OpenBSD defines SO_PEERCRED, but it is different from Linux's one.
- Backport commit `570933a6a3597371bae1beeb754ee8711d6305ab' to fix builds
  without PAM (issue #5283). It will not be needed in cups-2.2.8.

--- scheduler/auth.c.orig	2018-04-05 16:07:04.209662684 +0000
+++ scheduler/auth.c
@@ -1,8 +1,8 @@
 /*
  * Authorization routines for the CUPS scheduler.
  *
- * Copyright 2007-2016 by Apple Inc.
- * Copyright 1997-2007 by Easy Software Products, all rights reserved.
+ * Copyright © 2007-2018 by Apple Inc.
+ * Copyright © 1997-2007 by Easy Software Products, all rights reserved.
  *
  * This file contains Kerberos support code, copyright 2006 by
  * Jelmer Vernooij.
@@ -47,7 +47,7 @@ extern const char *cssmErrorString(int e
 #ifdef HAVE_SYS_PARAM_H
 #  include <sys/param.h>
 #endif /* HAVE_SYS_PARAM_H */
-#ifdef HAVE_SYS_UCRED_H
+#if defined(HAVE_SYS_UCRED_H) && !defined(__sun) && !defined(__OpenBSD__)
 #  include <sys/ucred.h>
 typedef struct xucred cupsd_ucred_t;
 #  define CUPSD_UCRED_UID(c) (c).cr_uid
@@ -71,9 +71,6 @@ static int		check_authref(cupsd_client_t
 static int		compare_locations(cupsd_location_t *a,
 			                  cupsd_location_t *b);
 static cupsd_authmask_t	*copy_authmask(cupsd_authmask_t *am, void *data);
-#if !HAVE_LIBPAM
-static char		*cups_crypt(const char *pw, const char *salt);
-#endif /* !HAVE_LIBPAM */
 static void		free_authmask(cupsd_authmask_t *am, void *data);
 #if HAVE_LIBPAM
 static int		pam_func(int, const struct pam_message **,
@@ -402,7 +399,7 @@ cupsdAuthorize(cupsd_client_t *con)	/* I
     con->type = CUPSD_AUTH_BASIC;
   }
 #endif /* HAVE_AUTHORIZATION_H */
-#if defined(SO_PEERCRED) && defined(AF_LOCAL)
+#if defined(SO_PEERCRED) && defined(AF_LOCAL) && !defined(__OpenBSD__)
   else if (!strncmp(authorization, "PeerCred ", 9) &&
            con->http->hostaddr->addr.sa_family == AF_LOCAL && con->best)
   {
@@ -694,14 +691,14 @@ cupsdAuthorize(cupsd_client_t *con)	/* I
 	    * client...
 	    */
 
-	    pass = cups_crypt(password, pw->pw_passwd);
+	    pass = crypt(password, pw->pw_passwd);
 
 	    if (!pass || strcmp(pw->pw_passwd, pass))
 	    {
 #  ifdef HAVE_SHADOW_H
 	      if (spw)
 	      {
-		pass = cups_crypt(password, spw->sp_pwdp);
+		pass = crypt(password, spw->sp_pwdp);
 
 		if (pass == NULL || strcmp(spw->sp_pwdp, pass))
 		{
@@ -839,7 +836,7 @@ cupsdAuthorize(cupsd_client_t *con)	/* I
 
     gss_delete_sec_context(&minor_status, &context, GSS_C_NO_BUFFER);
 
-#  if defined(SO_PEERCRED) && defined(AF_LOCAL)
+#  if defined(SO_PEERCRED) && defined(AF_LOCAL) && !defined(__OpenBSD__)
    /*
     * Get the client's UID if we are printing locally - that allows a backend
     * to run as the correct user to get Kerberos credentials of its own.
@@ -1995,129 +1992,6 @@ copy_authmask(cupsd_authmask_t *mask,	/*
 }
 
 
-#if !HAVE_LIBPAM
-/*
- * 'cups_crypt()' - Encrypt the password using the DES or MD5 algorithms,
- *                  as needed.
- */
-
-static char *				/* O - Encrypted password */
-cups_crypt(const char *pw,		/* I - Password string */
-           const char *salt)		/* I - Salt (key) string */
-{
-  if (!strncmp(salt, "$1$", 3))
-  {
-   /*
-    * Use MD5 passwords without the benefit of PAM; this is for
-    * Slackware Linux, and the algorithm was taken from the
-    * old shadow-19990827/lib/md5crypt.c source code... :(
-    */
-
-    int			i;		/* Looping var */
-    unsigned long	n;		/* Output number */
-    int			pwlen;		/* Length of password string */
-    const char		*salt_end;	/* End of "salt" data for MD5 */
-    char		*ptr;		/* Pointer into result string */
-    _cups_md5_state_t	state;		/* Primary MD5 state info */
-    _cups_md5_state_t	state2;		/* Secondary MD5 state info */
-    unsigned char	digest[16];	/* MD5 digest result */
-    static char		result[120];	/* Final password string */
-
-
-   /*
-    * Get the salt data between dollar signs, e.g. $1$saltdata$md5.
-    * Get a maximum of 8 characters of salt data after $1$...
-    */
-
-    for (salt_end = salt + 3; *salt_end && (salt_end - salt) < 11; salt_end ++)
-      if (*salt_end == '$')
-        break;
-
-   /*
-    * Compute the MD5 sum we need...
-    */
-
-    pwlen = strlen(pw);
-
-    _cupsMD5Init(&state);
-    _cupsMD5Append(&state, (unsigned char *)pw, pwlen);
-    _cupsMD5Append(&state, (unsigned char *)salt, salt_end - salt);
-
-    _cupsMD5Init(&state2);
-    _cupsMD5Append(&state2, (unsigned char *)pw, pwlen);
-    _cupsMD5Append(&state2, (unsigned char *)salt + 3, salt_end - salt - 3);
-    _cupsMD5Append(&state2, (unsigned char *)pw, pwlen);
-    _cupsMD5Finish(&state2, digest);
-
-    for (i = pwlen; i > 0; i -= 16)
-      _cupsMD5Append(&state, digest, i > 16 ? 16 : i);
-
-    for (i = pwlen; i > 0; i >>= 1)
-      _cupsMD5Append(&state, (unsigned char *)((i & 1) ? "" : pw), 1);
-
-    _cupsMD5Finish(&state, digest);
-
-    for (i = 0; i < 1000; i ++)
-    {
-      _cupsMD5Init(&state);
-
-      if (i & 1)
-        _cupsMD5Append(&state, (unsigned char *)pw, pwlen);
-      else
-        _cupsMD5Append(&state, digest, 16);
-
-      if (i % 3)
-        _cupsMD5Append(&state, (unsigned char *)salt + 3, salt_end - salt - 3);
-
-      if (i % 7)
-        _cupsMD5Append(&state, (unsigned char *)pw, pwlen);
-
-      if (i & 1)
-        _cupsMD5Append(&state, digest, 16);
-      else
-        _cupsMD5Append(&state, (unsigned char *)pw, pwlen);
-
-      _cupsMD5Finish(&state, digest);
-    }
-
-   /*
-    * Copy the final sum to the result string and return...
-    */
-
-    memcpy(result, salt, (size_t)(salt_end - salt));
-    ptr = result + (salt_end - salt);
-    *ptr++ = '$';
-
-    for (i = 0; i < 5; i ++, ptr += 4)
-    {
-      n = ((((unsigned)digest[i] << 8) | (unsigned)digest[i + 6]) << 8);
-
-      if (i < 4)
-        n |= (unsigned)digest[i + 12];
-      else
-        n |= (unsigned)digest[5];
-
-      to64(ptr, n, 4);
-    }
-
-    to64(ptr, (unsigned)digest[11], 2);
-    ptr += 2;
-    *ptr = '\0';
-
-    return (result);
-  }
-  else
-  {
-   /*
-    * Use the standard crypt() function...
-    */
-
-    return (crypt(pw, salt));
-  }
-}
-#endif /* !HAVE_LIBPAM */
-
-
 /*
  * 'free_authmask()' - Free function for auth masks.
  */
