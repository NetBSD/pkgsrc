# $NetBSD: Makefile,v 1.13 2005/12/05 20:50:38 rillig Exp $

PKGNAME=	${DISTNAME:S/-/-gnome-/}
PKGREVISION=	2

COMMENT=	GNOME frontend for free real-time 3D space simulator

DEPENDS+=	celestia-${CELESTIA_VERS}*:../../misc/celestia

CELESTIA_PROGPREFIX=	g

CONFIGURE_ARGS+=	--with-gnome

BUILD_DIRS=	${WRKSRC}/src
INSTALL_DIRS=	${BUILD_DIRS}

INSTALLATION_DIRS=	bin share/applications share/pixmaps

GCONF2_SCHEMAS=	celestia.schemas

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../misc/celestia/Makefile.common"

.include "../../devel/GConf2/schemas.mk"

.include "../../mk/bsd.pkg.mk"
