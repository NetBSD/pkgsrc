# $NetBSD: Makefile,v 1.59 2020/06/18 12:24:55 adam Exp $

DISTNAME=	matplotlib-3.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/matplotlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://matplotlib.org/
COMMENT=	Matlab-style plotting package for Python
# LICENSE=	see ${WRKSRC}/LICENSE/LICENSE

DEPENDS+=	${PYPKGPREFIX}-Pillow>=3.4:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo
DEPENDS+=	${PYPKGPREFIX}-cycler>=0.10:../../graphics/py-cycler
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.1:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-kiwisolver>=1.0.1:../../math/py-kiwisolver
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.2.0:../../devel/py-pyparsing
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

PYSETUPTESTTARGET=	pytest

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
