# $NetBSD: Makefile,v 1.27.2.1 2012/10/03 12:09:35 spz Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	1.0.1

DISTNAME=	Thunar-${XFCE4_VERSION}
PKGNAME=	xfce4-thunar-${XFCE4_VERSION}
PKGREVISION=	14
CATEGORIES=	sysutils
COMMENT=	Xfce file manager

PKGCONFIG_OVERRIDE+=	thunar-vfs/thunar-vfs-1.pc.in
PKGCONFIG_OVERRIDE+=	thunarx/thunarx-1.pc.in

PKG_SYSCONFSUBDIR=	xdg/Thunar
EGDIR=			${XFCE4_EGBASE}/Thunar

MAKE_DIRS+=	${XFCE4_EGBASE} ${PREFIX}/share/xfce4
CONF_FILES=	${EGDIR}/uca.xml ${PKG_SYSCONFDIR}/uca.xml

.include "options.mk"

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/fam.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
