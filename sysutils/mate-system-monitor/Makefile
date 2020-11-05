# $NetBSD: Makefile,v 1.25 2020/11/05 09:09:09 ryoon Exp $

PKGREVISION= 7
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-system-monitor-1.22.2
CATEGORIES=	sysutils

COMMENT=	MATE system monitor

USE_TOOLS+=	intltool
TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

USE_LANGUAGES=	c c++11

.include "../../devel/glib2/schemas.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/libwnck3/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtkmm3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
