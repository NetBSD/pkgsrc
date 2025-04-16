# $NetBSD: Makefile,v 1.91 2025/04/16 16:59:58 wiz Exp $

DISTNAME=	pillow-11.2.1
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^p/P/}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pillow/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://python-pillow.org/
COMMENT=	Python Imaging Library (Fork)
LICENSE=	hpnd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	netpbm-[0-9]*:../../graphics/netpbm
TEST_DEPENDS+=	${PYPKGPREFIX}-olefile-[0-9]*:../../devel/py-olefile
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout

USE_TOOLS+=	pkg-config

CONFLICTS+=	py[0-9]*-imaging-[0-9]*

DISTUTILS_BUILDDIR_IN_TEST_ENV=	yes

# as of 11.2.1
# 2 failed, 4738 passed, 211 skipped, 3 xfailed

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
