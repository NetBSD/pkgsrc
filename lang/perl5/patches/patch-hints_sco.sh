$NetBSD: patch-hints_sco.sh,v 1.1 2014/03/14 22:41:10 ryoon Exp $

* More hints

--- hints/sco.sh.orig	2013-11-04 15:15:38.000000000 +0000
+++ hints/sco.sh
@@ -120,6 +120,7 @@ else
         *gcc*)
             ccflags="$ccflags -melf"
             optimize='-O2'
+            ldflags="-shared"
         ;;
         *)
             ccflags="$ccflags -w0 -belf"
@@ -144,8 +145,8 @@ else
         case "$cc" in
             *gcc*)
                 ccdlflags='-Xlinker -Bexport -L/usr/local/lib'
-                cccdlflags='-fpic'
-                lddlflags='-G -L/usr/local/lib'
+                cccdlflags="-fpic $cccdlflags"
+                lddlflags=" -G -L/usr/local/lib $lddlflags"
             ;;
             *)
                 ccdlflags='-Wl,-Bexport -L/usr/local/lib'
@@ -168,6 +169,51 @@ else
     fi
 fi
 
+d_gethostbyname_r="define"
+d_gethostbyaddr_r="define"
+d_gethostent_r="define"
+d_getnetbyname_r="define"
+d_getnetbyaddr_r="define"
+d_getnetent_r="define"
+d_getprotobyname_r="define"
+d_getprotoent_r="define"
+d_getprotobynumber_r="define"
+d_getservbyname_r="define"
+d_getprotobynumber_r="define"
+d_getservent_r="define"
+d_getservbyname_r="define"
+d_getservbyport_r="define"
+d_setservent_r="define"
+d_sethostent_r="define"
+d_setnetent_r="define"
+d_setprotoent_r="define"
+d_endhostent_r="define"
+d_endnetent_r="define"
+d_endprotoent_r="define"
+d_endservent_r="define"
+
+d_gethostbyname_r_proto="define"
+d_gethostbyaddr_r_proto="define"
+d_gethostent_r_proto="define"
+d_getnetbyname_r_proto="define"
+d_getnetbyaddr_r_proto="define"
+d_getnetent_r_proto="define"
+d_getprotobyname_r_proto="define"
+d_getprotoent_r_proto="define"
+d_getprotobynumber_r_proto="define"
+d_getservbyname_r_proto="define"
+d_getprotobynumber_r_proto="define"
+d_getservent_r_proto="define"
+d_getservbyname_r_proto="define"
+d_getservbyport_r_proto="define"
+d_setservent_r_proto="define"
+d_sethostent_r_proto="define"
+d_setnetent_r_proto="define"
+d_setprotoent_r_proto="define"
+d_endhostent_r_proto="define"
+d_endnetent_r_proto="define"
+d_endprotoent_r_proto="define"
+d_endservent_r_proto="define"
 
 ###############################################################
 # Various hints, common to all releases, to have it work better:
