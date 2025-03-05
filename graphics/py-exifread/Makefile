# $NetBSD: Makefile,v 1.6 2025/03/05 10:04:37 wiz Exp $

DISTNAME=	ExifRead-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=E/ExifRead/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ianare/exif-py
COMMENT=	Read Exif metadata from TIFF and JPEG files
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:tl}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} EXIF.py exifread-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
