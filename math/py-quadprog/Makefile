# $NetBSD: Makefile,v 1.10 2023/07/01 08:37:40 wiz Exp $

DISTNAME=	quadprog-0.1.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
# pypi distfile does not contain cython input files
#MASTER_SITES=	${MASTER_SITE_PYPI:=q/quadprog/}
MASTER_SITES=	${MASTER_SITE_GITHUB:=quadprog/}
# switched during 0.1.11, remove during next update
DIST_SUBDIR=	${DISTNAME}
GITHUB_PROJECT=	quadprog
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rmcgibbo/quadprog
COMMENT=	Solver for a strictly convex quadratic program
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 38

# 0.1.11 distfile does not support python 3.11
# https://github.com/quadprog/quadprog/issues/41
post-extract:
	cd ${WRKSRC} && cythonize-${PYVERSSUFFIX} quadprog

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
