# $NetBSD: Makefile,v 1.6 2014/01/25 10:30:09 wiz Exp $

DISTNAME=	Pillow-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	https://pypi.python.org/packages/source/P/Pillow/
EXTRACT_SUFX=	.zip

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://python-imaging.github.io/
COMMENT=	Python Imaging Library (Fork)

CONFLICTS+=	${PYPKGPREFIX}-imaging-[0-9]*

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
