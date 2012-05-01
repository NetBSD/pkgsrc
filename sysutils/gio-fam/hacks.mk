# $NetBSD: hacks.mk,v 1.1 2012/05/01 18:45:53 adam Exp $

.if !defined(GIOFAM_HACKS_MK)
GIOFAM_HACKS_MK=	# defined

.if ${OPSYS} == "Darwin"
PKG_HACKS+=		darwin-iconv
SUBST_CLASSES+=		iconv
SUBST_STAGE.iconv=	pre-configure
SUBST_MESSAGE.iconv=	Changing libiconv_open to iconv_open.
SUBST_FILES.iconv=	configure
SUBST_SED.iconv=	-e 's,libiconv_open,iconv_open,g'
.endif

.endif
