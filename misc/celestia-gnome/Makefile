# $NetBSD: Makefile,v 1.4 2004/04/19 13:31:41 markd Exp $
#

.include "../../misc/celestia/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gnome-/}
PKGREVISION=	2

COMMENT=	GNOME frontend for free real-time 3D space simulator

DEPENDS=	celestia-${CELESTIA_VERS}*:../../misc/celestia

CONFIGURE_ARGS+=	--with-gnome
CONFIGURE_ARGS+=	--without-kde

BUILD_DIRS=	${WRKSRC}/src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/celestia/celestia ${PREFIX}/bin/gcelestia

.include "../../graphics/glut/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../x11/gtkglarea/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
