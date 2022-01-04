# $NetBSD: Makefile,v 1.57 2022/01/04 20:54:03 wiz Exp $

DISTNAME=	Pillow-8.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Pillow/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://python-pillow.org/
COMMENT=	Python Imaging Library (Fork)
LICENSE=	hpnd

USE_TOOLS+=	pkg-config

CONFLICTS+=	${PYPKGPREFIX}-imaging-[0-9]*

DEPENDS+=	${PYPKGPREFIX}-olefile-[0-9]*:../../devel/py-olefile
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	netpbm-[0-9]*:../../graphics/netpbm

PYTHON_VERSIONS_INCOMPATIBLE=	27

PYSETUPBUILDTARGET=	build_ext
PYSETUPBUILDARGS+=	--disable-xcb

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
