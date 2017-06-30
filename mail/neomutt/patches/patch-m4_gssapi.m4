$NetBSD: patch-m4_gssapi.m4,v 1.2 2017/06/30 10:58:18 wiz Exp $

Handle native Solaris GSSAPI.
https://github.com/neomutt/neomutt/pull/660

--- m4/gssapi.m4.orig	2017-06-09 10:52:07.000000000 +0000
+++ m4/gssapi.m4
@@ -28,6 +28,7 @@ AC_DEFUN([MUTT_AM_PATH_GSSAPI],
     case "`$KRB5CFGPATH --version`" in
       "Kerberos 5 "*)	GSSAPI_IMPL="MIT";;
       ?eimdal*)		GSSAPI_IMPL="Heimdal";;
+      Solaris*)		GSSAPI_IMPL="Solaris";;
       *)		GSSAPI_IMPL="Unknown";;
    esac
   else
