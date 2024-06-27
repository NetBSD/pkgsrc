# $NetBSD: Makefile,v 1.1 2024/06/27 12:31:32 bouyer Exp $

VERSION=	20240620
DISTNAME=	XyGrib-${VERSION}
PKGNAME=	XyGrib-devel-${VERSION}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=opengribs/}
GITHUB_PROJECT=	XyGrib
GITHUB_TAG=	88c425ca2d7f4ba5d7ab75bfa25e177bee02d310
EXTRACT_USING= bsdtar
DISTFILES=	${DISTNAME}-${GITHUB_TAG}${EXTRACT_SUFX}


MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://opengribs.org/
COMMENT=	GRIB file viewer for weather data (developement branch)
LICENSE=	gnu-gpl-v3

# This program is not maintained upstream.
# https://github.com/opengribs/XyGrib/issues/313

.include "data.mk"

USE_LANGUAGES+=	c c++
USE_CMAKE=	yes
CMAKE_ARGS+=	-DGNU_PACKAGE=ON -DGEN_TRANSLATIONS=OFF

.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../geography/libnova/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
