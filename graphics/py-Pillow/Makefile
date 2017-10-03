# $NetBSD: Makefile,v 1.37 2017/10/03 19:48:28 adam Exp $

DISTNAME=	Pillow-4.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Pillow/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://python-pillow.org/
COMMENT=	Python Imaging Library (Fork)
LICENSE=	hpnd

USE_TOOLS+=	pkg-config

CONFLICTS+=	${PYPKGPREFIX}-imaging-[0-9]*

DEPENDS+=	${PYPKGPREFIX}-olefile-*:../../devel/py-olefile

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libimagequant/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
