# $NetBSD: Makefile,v 1.24 2015/04/26 19:19:42 spz Exp $

PKGNAME=	${DISTNAME:S/-/-share-/}
#PKGREVISION=	0
COMMENT=	Machine independent files for Freeciv

.include "../../games/freeciv-share/Makefile.common"

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--disable-fcmp
CONFIGURE_ARGS+=	--disable-client
CONFIGURE_ARGS+=	--enable-make-data

SUBST_CLASSES+=			suppressguidata
SUBST_STAGE.suppressguidata=	pre-configure
SUBST_FILES.suppressguidata=	data/Makefile.in
SUBST_SED.suppressguidata=	-e 's|themes wonders|wonders|g'
SUBST_MESSAGE.suppressguidata=	Suppressing installation of gui themes

.include "../../mk/bsd.pkg.mk"
