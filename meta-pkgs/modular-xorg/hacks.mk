# $NetBSD: hacks.mk,v 1.1 2012/06/06 22:19:14 wiz Exp $

# hack for wrong autoconf snippet that was propagated to too many xorg packages

SUBST_CLASSES+=				xorg-autoconf-err
SUBST_SED.xorg-autoconf-err=		-e 's/as_echo \(xorg_cv_cc_flag_-errwarn=E_NO_EXPLICIT_TYPE_GIVEN -errwarn=E_NO_IMPLICIT_DECL_ALLOWED\)/as_echo "\1"/'
SUBST_FILES.xorg-autoconf-err=		configure
SUBST_STAGE.xorg-autoconf-err=		pre-configure
SUBST_MESSAGE.xorg-autoconf-err=	Fix error in configure script propagated from xorg autoconf macros.
