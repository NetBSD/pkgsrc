# $NetBSD: Makefile,v 1.5 2003/08/05 13:38:35 drochner Exp $
#

.include "../../misc/celestia/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-kde-/}
PKGREVISION=	2

COMMENT=	KDE frontend for free real-time 3D space simulator

DEPENDS=	celestia-${CELESTIA_VERS}:../../misc/celestia

CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--with-kde

BUILD_DIRS=	${WRKSRC}/src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/celestia/celestia ${PREFIX}/bin/kcelestia

.include "../../x11/kdelibs3/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
