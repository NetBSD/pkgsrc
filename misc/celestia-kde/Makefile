# $NetBSD: Makefile,v 1.3 2003/05/22 09:39:08 salo Exp $
#

.include "../../misc/celestia/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-kde-/}

COMMENT=	KDE frontend for free real-time 3D space simulator

DEPENDS=	celestia-${CELESTIA_VERS}:../../misc/celestia

CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--with-kde

BUILD_DIRS=	${WRKSRC}/src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/celestia/celestia ${PREFIX}/bin/kcelestia

.include "../../x11/kdelibs3/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
