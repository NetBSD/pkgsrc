# $NetBSD: Makefile,v 1.32 2011/11/01 06:00:42 sbd Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-mixer-${XFCE4_VERSION}
PKGREVISION=	6
CATEGORIES=	audio
COMMENT=	Xfce mixer plugin

MAKE_DIRS+=	${PREFIX}/libexec/xfce4 ${PREFIX}/libexec/xfce4/panel-plugins
MAKE_DIRS+=	${PREFIX}/share/xfce4 ${PREFIX}/share/xfce4/panel-plugins

BUILDLINK_API_DEPENDS.gst-plugins0.10-base+=	gst-plugins0.10-base>=0.10.14

.include "../../devel/xfconf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
