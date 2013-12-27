# $NetBSD: Makefile,v 1.3 2013/12/27 11:08:04 dholland Exp $
#

DISTNAME=	Pillow-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	https://pypi.python.org/packages/source/P/Pillow/
EXTRACT_SUFX=	.zip

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://python-imaging.github.io/
COMMENT=	Python Imaging Library (Fork)

CONFLICTS+=	${PYPKGPREFIX}-imaging-[0-9]*

PYTHON_SELF_CONFLICT=		yes
PYTHON_VERSIONS_INCLUDE_3X=	yes

ALL_ENV+=	C_INCLUDE_PATH=${BUILDLINK_PREFIX.freetype2}/include
ALL_ENV+=	LIBRARY_PATH=${BUILDLINK_PREFIX.freetype2}/lib

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
