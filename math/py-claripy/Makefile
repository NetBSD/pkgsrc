# $NetBSD: Makefile,v 1.3 2020/08/18 20:14:43 riastradh Exp $

DISTNAME=	claripy-8.20.1.7
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=angr/}
GITHUB_PROJECT=	claripy
GITHUB_TAG=	ea20bb80a84aab942f89cffbf035675dc0cf1af4

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/angr/claripy/
COMMENT=	Abstraction layer for constraint solvers
LICENSE=	2-clause-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-cachetools>=0:../../devel/py-cachetools
DEPENDS+=	${PYPKGPREFIX}-decorator>=0:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-future>=0:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-smt>=0:../../math/py-smt
DEPENDS+=	${PYPKGPREFIX}-z3>=0:../../math/py-z3

do-test:
	${RUN} cd ${WRKSRC}/tests && \
	${SETENV} ${TEST_ENV} \
	${PYTHONBIN} -m unittest discover

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
