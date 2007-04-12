# $NetBSD: Makefile,v 1.1.1.1 2007/04/12 09:46:28 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.8.0

DISTNAME=	Thunar-${XFCE4_VERSION}
PKGNAME=	xfce4-thunar-${XFCE4_VERSION}
CATEGORIES=	sysutils
COMMENT=	Xfce file manager

#DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

USE_DIRS+=	xdg-1.2
USE_TOOLS+=	intltool pkg-config

PKGCONFIG_OVERRIDE+=	thunar-vfs/thunar-vfs-1.pc.in
PKGCONFIG_OVERRIDE+=	thunarx/thunarx-1.pc.in

.include "../../devel/GConf2/buildlink3.mk"
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
