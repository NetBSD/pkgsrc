# $NetBSD: Makefile,v 1.4 2017/02/12 06:26:01 ryoon Exp $

PKGREVISION= 3
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-system-monitor-${MATE_VERSION}
CATEGORIES=	sysutils

COMMENT=	MATE system monitor

TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

USE_LANGUAGES=	c c++
CXXFLAGS+=	-std=c++11

.include "../../devel/glib2/schemas.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/libwnck3/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/gtkmm3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
