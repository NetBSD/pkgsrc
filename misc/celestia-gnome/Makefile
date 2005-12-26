# $NetBSD: Makefile,v 1.14 2005/12/26 23:39:32 schmonz Exp $

PKGNAME=	${DISTNAME:S/-/-gnome-/}
PKGREVISION=	2

COMMENT=	GNOME frontend for free real-time 3D space simulator

PKG_FAIL_REASON+=	"Broken on NetBSD/i386 3.0 in pkgsrc-2005Q4"
PKG_FAIL_REASON+=	"Will be removed in pkgsrc-2006Q1 unless fixed"

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
