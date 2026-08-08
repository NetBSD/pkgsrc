# $NetBSD: Makefile,v 1.17 2026/08/08 21:37:02 wiz Exp $

DISTNAME=	digikam-gmic-qt-4.0.3.20260806
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=cgilles/}
GITHUB_TAG=	e1ab9ace80d6bd0fd38ba6bd333ea85f282ba28b

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cgilles/digikam-gmic-qt
COMMENT=	G'MIC plugin for digiKam
LICENSE=	modified-bsd AND gnu-gpl-v2 AND gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake bash:build

CMAKE_CONFIGURE_ARGS+=	-DENABLE_SYSTEM_GMIC=OFF
CMAKE_CONFIGURE_ARGS+=	-DGMIC_QT_HOST=digikam
CMAKE_CONFIGURE_ARGS+=	-DBUILD_WITH_QT6=ON

REPLACE_BASH+=	translations/lrelease.sh

# make binaries available in default search path
BUILDLINK_FNAME_TRANSFORM.qt6-qttools+=	-e s,qt6/bin,bin,

CONFLICTS+=	gmic-qt-digikam-[0-9]*
SUPERSEDES+=	gmic-qt-digikam-[0-9]*

.include "../../devel/cmake/build.mk"
BUILDLINK_API_DEPENDS.digikam+=	digikam>=8.8.0
.include "../../graphics/digikam/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
