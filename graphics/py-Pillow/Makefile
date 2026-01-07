# $NetBSD: Makefile,v 1.98 2026/01/07 14:26:55 ryoon Exp $

DISTNAME=	pillow-12.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^p/P/}
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

# as of 11.3.0
# 2 failed, 4934 passed, 88 skipped, 3 xfailed

.include "../../lang/python/wheel.mk"
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
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
