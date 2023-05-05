# $NetBSD: Makefile,v 1.16 2023/05/05 11:39:41 wiz Exp $

DISTNAME=	watchdog-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/watchdog/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/gorakhargosh/watchdog
COMMENT=	Filesystem events monitoring
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-mypy-[0-9]*:../../lang/py-mypy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=0.3:../../devel/py-test-timeout

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
# as of 3.0.0
# 3 failed, 141 passed, 13 skipped, 20 warnings, 1 error
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} watchmedo watchmedo-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
