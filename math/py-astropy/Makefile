# $NetBSD: Makefile,v 1.10 2023/09/16 04:24:31 adam Exp $

DISTNAME=	astropy-5.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/astropy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.astropy.org/
COMMENT=	Python module for astronomical calculations and data analysis
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-extension-helpers-[0-9]*:../../devel/py-extension-helpers
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.13:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-pyerfa>=2.0.0.1:../../math/py-pyerfa
DEPENDS+=	${PYPKGPREFIX}-packaging>=19.0:../../devel/py-packaging
# recommended
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.5:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.5.3:../../graphics/py-matplotlib

USE_LANGUAGES=	c c++

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
