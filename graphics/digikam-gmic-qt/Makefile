# $NetBSD: Makefile,v 1.9 2025/10/05 19:26:01 js Exp $

DISTNAME=	digikam-gmic-qt-3.6.0.20250805
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=cgilles/}
GITHUB_TAG=	8c1d72dc9b21e46f2641d22b835a355006491ea1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cgilles/digikam-gmic-qt
COMMENT=	G'MIC plugin for digiKam
LICENSE=	modified-bsd AND gnu-gpl-v2 AND gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake bash:build

CMAKE_CONFIGURE_ARGS+=	-DENABLE_SYSTEM_GMIC=OFF
CMAKE_CONFIGURE_ARGS+=	-DGMIC_QT_HOST=digikam
CMAKE_CONFIGURE_ARGS+=	-DBUILD_WITH_QT6=OFF

REPLACE_BASH+=	translations/lrelease.sh

# make binaries available in default search path
BUILDLINK_FNAME_TRANSFORM.qt5-qttools+=	-e s,qt5/bin,bin,

CONFLICTS+=	gmic-qt-digikam-[0-9]*
SUPERSEDES+=	gmic-qt-digikam-[0-9]*

.include "../../devel/cmake/build.mk"
BUILDLINK_API_DEPENDS.digikam+=	digikam>=8.7.0
.include "../../graphics/digikam/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
