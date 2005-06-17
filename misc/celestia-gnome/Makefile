# $NetBSD: Makefile,v 1.10 2005/06/17 03:50:21 jlam Exp $

PKGNAME=	${DISTNAME:S/-/-gnome-/}

COMMENT=	GNOME frontend for free real-time 3D space simulator

DEPENDS=	celestia-${CELESTIA_VERS}*:../../misc/celestia

CONFIGURE_ARGS+=	--with-gnome

BUILD_DIRS=	${WRKSRC}/src

INSTALLATION_DIRS=	bin share/applications share/pixmaps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/celestia/celestia \
		${PREFIX}/bin/gcelestia
	${INSTALL_DATA_DIR} ${PREFIX}/etc/gconf/schemas
	${INSTALL_DATA} ${WRKSRC}/src/celestia/gtk/data/celestia.schemas \
		${PREFIX}/etc/gconf/schemas
	${INSTALL_DATA} ${WRKSRC}/src/celestia/gtk/data/celestia.desktop \
		${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/src/celestia/gtk/data/celestia.png \
		${PREFIX}/share/pixmaps

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../misc/celestia/Makefile.common"

.include "../../mk/bsd.pkg.mk"
