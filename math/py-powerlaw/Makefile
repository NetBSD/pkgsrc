# $NetBSD: Makefile,v 1.2 2018/08/30 11:14:05 adam Exp $

DISTNAME=	powerlaw-1.4.4
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
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

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
