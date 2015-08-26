$NetBSD: patch-src_gettext.h,v 1.1 2015/08/26 22:03:38 joerg Exp $

--- src/gettext.h.orig	2015-08-23 14:11:04.000000000 +0000
+++ src/gettext.h
@@ -16,8 +16,8 @@
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
    USA.  */
 
-#ifndef LIBGETTEXT_H_74E363E9F6924C7DBC4D0ED9C2FA33DF
-#define LIBGETTEXT_H_74E363E9F6924C7DBC4D0ED9C2FA33DF 1
+#ifndef _LIBGETTEXT_H
+#define _LIBGETTEXT_H
 
 /* NLS can be disabled through the configure --disable-nls option.  */
 #if ENABLE_NLS
