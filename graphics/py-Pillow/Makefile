# $NetBSD: Makefile,v 1.39 2018/04/03 09:24:19 adam Exp $

DISTNAME=	Pillow-5.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Pillow/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://python-pillow.org/
COMMENT=	Python Imaging Library (Fork)
LICENSE=	hpnd

USE_TOOLS+=	pkg-config

CONFLICTS+=	${PYPKGPREFIX}-imaging-[0-9]*

DEPENDS+=	${PYPKGPREFIX}-olefile-[0-9]*:../../devel/py-olefile
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

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
