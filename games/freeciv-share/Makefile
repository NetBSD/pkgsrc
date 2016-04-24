# $NetBSD: Makefile,v 1.26 2016/04/24 06:52:44 prlw1 Exp $

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
