# $NetBSD: Makefile,v 1.62 2024/11/01 12:52:34 wiz Exp $

PKGNAME=	${DISTNAME:S/-/-share-/}
PKGREVISION=	12
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
