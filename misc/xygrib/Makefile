# $NetBSD: Makefile,v 1.26 2024/05/23 14:18:02 gdt Exp $

GITHUB_PROJECT=	XyGrib
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	XyGrib-1.2.6.1
PKGREVISION=	24
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=opengribs/}
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://opengribs.org/
COMMENT=	GRIB file viewer for weather data
LICENSE=	gnu-gpl-v3

.include "data.mk"

USE_LANGUAGES+=	c c++
USE_CMAKE=	yes

.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../geography/libnova/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
