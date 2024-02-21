# $NetBSD: Makefile,v 1.12 2024/02/21 22:41:47 wiz Exp $

DISTNAME=	quadprog-0.1.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=q/quadprog/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rmcgibbo/quadprog
COMMENT=	Solver for a strictly convex quadratic program
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
TEST_DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
