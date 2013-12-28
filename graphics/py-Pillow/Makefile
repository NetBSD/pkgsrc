# $NetBSD: Makefile,v 1.4 2013/12/28 02:53:46 obache Exp $
#

DISTNAME=	Pillow-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	https://pypi.python.org/packages/source/P/Pillow/
EXTRACT_SUFX=	.zip

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://python-imaging.github.io/
COMMENT=	Python Imaging Library (Fork)

CONFLICTS+=	${PYPKGPREFIX}-imaging-[0-9]*

PYTHON_VERSIONS_INCLUDE_3X=	yes

MAKE_ENV+=	C_INCLUDE_PATH=${BUILDLINK_PREFIX.freetype2}/include
MAKE_ENV+=	LIBRARY_PATH=${BUILDLINK_PREFIX.freetype2}/lib

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
