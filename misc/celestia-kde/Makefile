# $NetBSD: Makefile,v 1.2 2003/05/20 00:49:33 jmc Exp $
#

.include "../../misc/celestia/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-kde-/}

COMMENT=	KDE frontend for free real-time 3D space simulator

DEPENDS=	celestia-${CELESTIA_VERS}:../../misc/celestia

CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--with-kde
USE_GMAKE=		yes

BUILD_DIRS=	${WRKSRC}/src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/celestia/celestia ${PREFIX}/bin/kcelestia

.include "../../x11/kdelibs3/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
