$NetBSD: patch-config_perl.m4,v 1.1 2019/10/07 19:21:48 adam Exp $

--- config/perl.m4.orig	2018-02-05 21:01:02.000000000 +0000
+++ config/perl.m4
@@ -97,9 +97,7 @@ if test "$PORTNAME" = "win32" ; then
 		fi
 	fi
 else
-	pgac_tmp1=`$PERL -MExtUtils::Embed -e ldopts`
-	pgac_tmp2=`$PERL -MConfig -e 'print $Config{ccdlflags}'`
-	perl_embed_ldflags=`echo X"$pgac_tmp1" | sed -e "s/^X//" -e "s%$pgac_tmp2%%" -e ["s/ -arch [-a-zA-Z0-9_]*//g"]`
+	perl_embed_ldflags=`$PERL -MExtUtils::Embed -e ldopts`
 fi
 AC_SUBST(perl_embed_ldflags)dnl
 if test -z "$perl_embed_ldflags" ; then
