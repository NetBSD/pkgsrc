# $NetBSD: Makefile,v 1.32 2023/11/14 01:03:47 gutteridge Exp $

DISTNAME=	lximage-qt-1.4.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lximage-qt/
COMMENT=	Image viewer and screenshot tool for the LXQt desktop
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	lxqt-build-tools>=0.13.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/libfm-qt/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
