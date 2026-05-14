# $NetBSD: Makefile,v 1.52 2026/05/14 16:41:14 ryoon Exp $

PKGREVISION= 1
.include "../../meta-pkgs/lxqt/Makefile.common"

DISTNAME=	lximage-qt-2.4.0
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lximage-qt/
COMMENT=	Image viewer and screenshot tool for the LXQt desktop
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config perl

TOOL_DEPENDS+=	lxqt-build-tools>=2.4.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../x11/libfm-qt/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
