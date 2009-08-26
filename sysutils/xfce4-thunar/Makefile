# $NetBSD: Makefile,v 1.12 2009/08/26 19:57:03 sno Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.9.3

DISTNAME=	Thunar-${XFCE4_VERSION}
PKGNAME=	xfce4-thunar-${XFCE4_VERSION}
PKGREVISION=	3
CATEGORIES=	sysutils
COMMENT=	Xfce file manager

#DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser


PKGCONFIG_OVERRIDE+=	thunar-vfs/thunar-vfs-1.pc.in
PKGCONFIG_OVERRIDE+=	thunarx/thunarx-1.pc.in

PKG_SYSCONFSUBDIR=      xdg/Thunar
EGDIR=                  ${PREFIX}/share/examples/Thunar
CONF_FILES=             ${EGDIR:Q}/uca.xml ${PKG_SYSCONFDIR:Q}/uca.xml

.include "options.mk"

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/fam.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
