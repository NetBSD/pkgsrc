# $NetBSD: Makefile,v 1.17 2024/10/03 12:03:43 adam Exp $

DISTNAME=	astropy-6.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/astropy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.astropy.org/
COMMENT=	Python module for astronomical calculations and data analysis
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-extension-helpers-[0-9]*:../../devel/py-extension-helpers
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-astropy-iers-data>=0.2024.8.27.10.28.29:../../math/py-astropy-iers-data
DEPENDS+=	${PYPKGPREFIX}-pyerfa>=2.0.0.1:../../math/py-pyerfa
DEPENDS+=	${PYPKGPREFIX}-packaging>=19.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.13:../../textproc/py-yaml
# recommended
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.5.3:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.8:../../math/py-scipy

USE_LANGUAGES=	c c++

PYTHON_SELF_CONFLICT=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	38 39

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
