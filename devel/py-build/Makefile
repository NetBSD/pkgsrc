# $NetBSD: Makefile,v 1.16 2023/10/25 22:33:40 wiz Exp $

DISTNAME=	build-1.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/build/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/build
COMMENT=	Simple, correct PEP517 package builder
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-packaging>=19.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pyproject_hooks-[0-9]*:../../devel/py-pyproject_hooks
TEST_DEPENDS+=	${PYPKGPREFIX}-filelock-[0-9]*:../../devel/py-filelock
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky-[0-9]*:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.0.0:../../textproc/py-tomli
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pyproject-build pyproject-build-${PYVERSSUFFIX} || ${TRUE}

# needs 'make install'
# as of 1.0.3:
# 5 failed, 113 passed, 33 skipped, 1 xfailed, 6 errors
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/bootstrap.mk"
.include "../../mk/bsd.pkg.mk"
