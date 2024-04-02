# $NetBSD: Makefile,v 1.80 2024/04/02 05:55:48 adam Exp $

DISTNAME=	pillow-10.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^p/P/}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pillow/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://python-pillow.org/
COMMENT=	Python Imaging Library (Fork)
LICENSE=	hpnd

USE_TOOLS+=	pkg-config

CONFLICTS+=	${PYPKGPREFIX}-imaging-[0-9]*

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=67.8:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-olefile-[0-9]*:../../devel/py-olefile
TEST_DEPENDS+=	netpbm-[0-9]*:../../graphics/netpbm
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout

PYTHON_VERSIONS_INCOMPATIBLE=	27

DISTUTILS_BUILDDIR_IN_TEST_ENV=	yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libimagequant/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
