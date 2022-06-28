# $NetBSD: Makefile,v 1.15 2022/06/28 11:30:52 wiz Exp $

DISTNAME=	lxqt-archiver-0.6.0
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-archiver/
COMMENT=	Simple and lightweight Qt file archiver
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config perl bsdtar:run gzip:run 7za:run gtar:run bzip2:run unzip:run zip:run xz:run

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CMAKE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	lxqt-build-tools>=0.11.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/libfm-qt/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
