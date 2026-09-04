# $NetBSD: Makefile,v 1.1 2026/09/04 08:46:01 adam Exp $

DISTNAME=	formulaic-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/formulaic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/matthewwardrop/formulaic
COMMENT=	Implementation of Wilkinson formulas
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-interface-meta>=1.2.0:../../misc/py-interface-meta
DEPENDS+=	${PYPKGPREFIX}-narwhals>=1.17:../../misc/py-narwhals
DEPENDS+=	${PYPKGPREFIX}-pandas>=1.3:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.6:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-wrapt>=1.17.0:../../devel/py-wrapt
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.2.0:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-numpy

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
