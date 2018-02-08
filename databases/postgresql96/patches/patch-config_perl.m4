$NetBSD: patch-config_perl.m4,v 1.2 2018/02/08 20:53:58 adam Exp $

--- config/perl.m4.orig	2018-02-05 21:07:03.000000000 +0000
+++ config/perl.m4
@@ -100,9 +100,7 @@ if test "$PORTNAME" = "win32" ; then
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
