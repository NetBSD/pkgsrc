# $NetBSD: Makefile,v 1.7 2023/05/11 07:20:30 adam Exp $

.include "../../devel/py-angr/version.mk"

DISTNAME=	claripy-${ANGR_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/claripy/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/angr/claripy
COMMENT=	Abstraction layer for constraint solvers
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-cachetools-[0-9]*:../../devel/py-cachetools
DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-smt>=0.9.5:../../math/py-smt
DEPENDS+=	${PYPKGPREFIX}-z3>=4.10.2.0:../../math/py-z3

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest discover

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
