$NetBSD: patch-tnm_generic_tnm.h,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.

--- tnm/generic/tnm.h~	1998-11-03 16:17:48.000000000 +0100
+++ tnm/generic/tnm.h	2014-03-04 14:12:35.000000000 +0100
@@ -81,39 +81,39 @@
 
 EXTERN int
 Tnm_EventCmd	_ANSI_ARGS_((ClientData clientData, Tcl_Interp *interp, 
-			     int argc, char **argv));
+			     int argc, const char **argv));
 EXTERN int
 Tnm_JobCmd	_ANSI_ARGS_((ClientData clientData, Tcl_Interp *interp, 
-			     int argc, char **argv));
+			     int argc, const char **argv));
 EXTERN int
 Tnm_SyslogCmd	_ANSI_ARGS_((ClientData clientData, Tcl_Interp *interp, 
-			     int argc, char **argv));
+			     int argc, const char **argv));
 EXTERN int
 Tnm_UdpCmd	_ANSI_ARGS_((ClientData clientData, Tcl_Interp *interp, 
-			     int argc, char **argv));
+			     int argc, const char **argv));
 EXTERN int
 Tnm_RpcCmd	_ANSI_ARGS_((ClientData clientData, Tcl_Interp *interp, 
-			     int argc, char **argv));
+			     int argc, const char **argv));
 EXTERN int
 Tnm_HttpCmd	_ANSI_ARGS_((ClientData clientData, Tcl_Interp *interp, 
-			     int argc, char **argv));
+			     int argc, const char **argv));
 EXTERN int
 Tnm_DnsCmd	_ANSI_ARGS_((ClientData clientData, Tcl_Interp *interp, 
-			     int argc, char **argv));
+			     int argc, const char **argv));
 EXTERN int
 Tnm_NtpCmd	_ANSI_ARGS_((ClientData clientData, Tcl_Interp *interp, 
-			     int argc, char **argv));
+			     int argc, const char **argv));
 EXTERN int
 Tnm_SunrpcCmd	_ANSI_ARGS_((ClientData clientData, Tcl_Interp *interp, 
-			     int argc, char **argv));
+			     int argc, const char **argv));
 EXTERN int
 Tnm_IcmpCmd	_ANSI_ARGS_((ClientData clientData, Tcl_Interp *interp,
-			     int argc, char **argv));
+			     int argc, const char **argv));
 EXTERN int
 Tnm_InedCmd	_ANSI_ARGS_((ClientData clientData, Tcl_Interp *interp, 
-			     int argc, char **argv));
+			     int argc, const char **argv));
 EXTERN int
 Tnm_NetdbCmd	_ANSI_ARGS_((ClientData clientData, Tcl_Interp *interp, 
-			     int argc, char **argv));
+			     int argc, const char **argv));
 
 #endif /* _TNM */
