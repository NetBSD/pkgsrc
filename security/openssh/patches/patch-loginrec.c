$NetBSD: patch-loginrec.c,v 1.1 2013/05/01 19:58:26 imil Exp $

Interix support and related fixes

--- loginrec.c.orig	2013-02-22 22:12:24.000000000 +0000
+++ loginrec.c
@@ -429,8 +429,8 @@ login_set_addr(struct logininfo *li, con
 int
 login_write(struct logininfo *li)
 {
-#ifndef HAVE_CYGWIN
-	if (geteuid() != 0) {
+#if !defined(HAVE_CYGWIN) && !defined(HAVE_INTERIX)
+        if (geteuid() != ROOTUID) {
 		logit("Attempt to write login records by non-root user (aborting)");
 		return (1);
 	}
@@ -438,7 +438,7 @@ login_write(struct logininfo *li)
 
 	/* set the timestamp */
 	login_set_current_time(li);
-#ifdef USE_LOGIN
+#if defined(USE_LOGIN) && (HAVE_UTMP_H)
 	syslogin_write_entry(li);
 #endif
 #ifdef USE_LASTLOG
@@ -622,7 +622,7 @@ line_abbrevname(char *dst, const char *s
  ** into account.
  **/
 
-#if defined(USE_UTMP) || defined (USE_WTMP) || defined (USE_LOGIN)
+#if defined(USE_UTMP) || defined (USE_WTMP) || (defined (USE_LOGIN) && defined (HAVE_UTMP_H))
 
 /* build the utmp structure */
 void
@@ -759,10 +759,6 @@ construct_utmpx(struct logininfo *li, st
 	set_utmpx_time(li, utx);
 	utx->ut_pid = li->pid;
 
-	/* strncpy(): Don't necessarily want null termination */
-	strncpy(utx->ut_user, li->username,
-	    MIN_SIZEOF(utx->ut_user, li->username));
-
 	if (li->type == LTYPE_LOGOUT)
 		return;
 
@@ -771,6 +767,8 @@ construct_utmpx(struct logininfo *li, st
 	 * for logouts.
 	 */
 
+	/* strncpy(): Don't necessarily want null termination */
+	strncpy(utx->ut_name, li->username, MIN_SIZEOF(utx->ut_name, li->username));
 # ifdef HAVE_HOST_IN_UTMPX
 	strncpy(utx->ut_host, li->hostname,
 	    MIN_SIZEOF(utx->ut_host, li->hostname));
@@ -1406,7 +1404,7 @@ wtmpx_get_entry(struct logininfo *li)
  ** Low-level libutil login() functions
  **/
 
-#ifdef USE_LOGIN
+#if defined(USE_LOGIN) && defined(HAVE_UTMP_H)
 static int
 syslogin_perform_login(struct logininfo *li)
 {
