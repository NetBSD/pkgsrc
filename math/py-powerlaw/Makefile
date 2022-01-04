# $NetBSD: Makefile,v 1.7 2022/01/04 20:54:15 wiz Exp $

DISTNAME=	powerlaw-1.4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/powerlaw/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/jeffalstott/powerlaw
COMMENT=	Toolbox for analysis of heavy-tailed distributions
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-mpmath-[0-9]*:../../math/py-mpmath
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-matplotlib, py-scipy

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
