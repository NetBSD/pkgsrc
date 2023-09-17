$NetBSD: patch-config_perl.m4,v 1.1 2023/09/17 08:53:21 adam Exp $

--- config/perl.m4.orig	2023-09-11 20:25:06.000000000 +0000
+++ config/perl.m4
@@ -98,9 +98,7 @@ if test "$PORTNAME" = "win32" ; then
 		fi
 	fi
 else
-	pgac_tmp1=`$PERL -MExtUtils::Embed -e ldopts`
-	pgac_tmp2=`$PERL -MConfig -e 'print "$Config{ccdlflags} $Config{ldflags}"'`
-	perl_embed_ldflags=`echo X"$pgac_tmp1" | sed -e "s/^X//" -e "s%$pgac_tmp2%%"`
+	perl_embed_ldflags=`$PERL -MExtUtils::Embed -e ldopts`
 fi
 AC_SUBST(perl_embed_ldflags)dnl
 if test -z "$perl_embed_ldflags" ; then
