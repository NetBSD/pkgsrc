# $NetBSD: Makefile,v 1.6 2022/01/04 20:54:13 wiz Exp $

PKGREVISION= 1
.include "../../devel/py-angr/version.mk"

DISTNAME=	claripy-${ANGR_VERSION}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=angr/}
GITHUB_PROJECT=	claripy
GITHUB_TAG=	v${ANGR_VERSION}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/angr/claripy/
COMMENT=	Abstraction layer for constraint solvers
LICENSE=	2-clause-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-cachetools>=0:../../devel/py-cachetools
DEPENDS+=	${PYPKGPREFIX}-decorator>=0:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-future>=0:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-smt>=0:../../math/py-smt
DEPENDS+=	${PYPKGPREFIX}-z3solver>=0:../../math/py-z3solver

do-test:
	${RUN} cd ${WRKSRC}/tests && \
	${SETENV} ${TEST_ENV} \
	${PYTHONBIN} -m unittest discover

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
