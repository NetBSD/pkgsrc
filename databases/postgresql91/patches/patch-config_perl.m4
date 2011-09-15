$NetBSD: patch-config_perl.m4,v 1.1.1.1 2011/09/15 08:27:39 adam Exp $

--- config/perl.m4.orig	2010-02-23 18:35:06.000000000 +0000
+++ config/perl.m4
@@ -57,9 +57,7 @@ AC_DEFUN([PGAC_CHECK_PERL_CONFIGS],
 AC_DEFUN([PGAC_CHECK_PERL_EMBED_LDFLAGS],
 [AC_REQUIRE([PGAC_PATH_PERL])
 AC_MSG_CHECKING(for flags to link embedded Perl)
-pgac_tmp1=`$PERL -MExtUtils::Embed -e ldopts`
-pgac_tmp2=`$PERL -MConfig -e 'print $Config{ccdlflags}'`
-perl_embed_ldflags=`echo X"$pgac_tmp1" | sed -e "s/^X//" -e "s%$pgac_tmp2%%" -e ["s/ -arch [-a-zA-Z0-9_]*//g"]`
+perl_embed_ldflags=`$PERL -MExtUtils::Embed -e ldopts`
 AC_SUBST(perl_embed_ldflags)dnl
 if test -z "$perl_embed_ldflags" ; then
 	AC_MSG_RESULT(no)
