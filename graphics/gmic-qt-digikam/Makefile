# $NetBSD: Makefile,v 1.9 2024/05/16 06:15:02 wiz Exp $

DISTNAME=	gmic-qt-digikam-3.2.2.20230417
PKGREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=cgilles/}
GITHUB_TAG=	925ba362081e875a2ece1bcfffbe0f408a908017
GITHUB_PROJECT=	gmic-qt

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cgilles/gmic-qt/
COMMENT=	G'MIC plugin for digiKam
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake bash:build

CMAKE_ARGS+=	-DENABLE_SYSTEM_GMIC=OFF
CMAKE_ARGS+=	-DGMIC_QT_HOST=digikam

REPLACE_BASH+=	translations/lrelease.sh

# make binaries available in default search path
BUILDLINK_FNAME_TRANSFORM.qt5-qttools+=	-e s,qt5/bin,bin,

.include "../../devel/cmake/build.mk"
.include "../../graphics/digikam/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools?=	build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
