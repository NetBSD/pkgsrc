# $NetBSD: Makefile,v 1.12 2024/05/11 15:38:30 wiz Exp $

DISTNAME=	astropy-5.3.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/astropy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.astropy.org/
COMMENT=	Python module for astronomical calculations and data analysis
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TOOL_DEPENDS+=	${PYPKGPREFIX}-extension-helpers-[0-9]*:../../devel/py-extension-helpers
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.13:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-pyerfa>=2.0.0.1:../../math/py-pyerfa
DEPENDS+=	${PYPKGPREFIX}-packaging>=19.0:../../devel/py-packaging
# recommended
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.5:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.5.3:../../graphics/py-matplotlib

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
