# $NetBSD: Makefile,v 1.104 2026/09/02 19:02:51 wiz Exp $

DISTNAME=	pillow-12.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^p/P/}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pillow/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://python-pillow.github.io/
COMMENT=	Python Imaging Library (Fork)
LICENSE=	hpnd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	netpbm-[0-9]*:../../graphics/netpbm
TEST_DEPENDS+=	ghostscript-[0-9]*:../../print/ghostscript
TEST_DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
TEST_DEPENDS+=	${PYPKGPREFIX}-olefile-[0-9]*:../../devel/py-olefile
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout

USE_TOOLS+=	pkg-config

CONFLICTS+=	py[0-9]*-imaging-[0-9]*

DISTUTILS_BUILDDIR_IN_TEST_ENV=	yes

# as of 12.1.1
# 2 failed, 4959 passed, 102 skipped, 3 xfailed

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/libavif/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libimagequant/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/raqm/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
