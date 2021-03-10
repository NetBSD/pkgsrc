# $NetBSD: Makefile,v 1.2 2021/03/10 19:03:34 adam Exp $

DISTNAME=	ExifRead-2.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=E/ExifRead/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ianare/exif-py
COMMENT=	Read Exif metadata from TIFF and JPEG files
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} EXIF.py exifread-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
