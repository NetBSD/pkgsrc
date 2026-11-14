$NetBSD: patch-src_main.cc,v 1.1 2026/11/14 21:36:38 drixter Exp $

SunOS Fix: Move const into proper place

--- src/main.cc.orig	Tue Mar 10 17:37:18 2026
+++ src/main.cc	Wed Oct 14 19:56:02 2026
@@ -53,6 +53,7 @@
 #include "Workspace.hh"
 #include "UserPreferences.hh"
 
+
 #if HAVE_IOCTL_TIOCGWINSZ   // platform has ioctl(fd, TIOCGWINSZ. ...)
 # include <sys/ioctl.h>
 #endif
@@ -422,11 +423,12 @@
    sigaction(SIGHUP,   &new_HUP_action,       &old_HUP_action);
    signal(SIGCHLD, SIG_IGN);   // do not create zombies
 
+   const UserPreferences & uprefs = UserPreferences::uprefs;
+
 #if HAVE_IOCTL_TIOCGWINSZ
    // Enable the ability to change ⎕PW on window resize only if the
    // platform supports ioctl TIOCGWINSZ
    //
-const UserPreferences & uprefs = UserPreferences::uprefs;    
    if (uprefs.WINCH_sets_pw)
       {
         // IF WINCH_sets_pw preference is enabled, set up a handler for the
