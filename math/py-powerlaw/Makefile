# $NetBSD: Makefile,v 1.17 2026/10/16 19:44:04 adam Exp $

DISTNAME=	powerlaw-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/powerlaw/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/jeffalstott/powerlaw
COMMENT=	Toolbox for analysis of heavy-tailed distributions
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8.0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-mpmath-[0-9]*:../../math/py-mpmath
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-tqdm-[0-9]*:../../misc/py-tqdm

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
