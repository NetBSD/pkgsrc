# $NetBSD: Makefile,v 1.8 2022/05/01 09:13:41 wiz Exp $

DISTNAME=	plumbum-1.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/plumbum/}

MAINTAINER=	gde@llew.me
HOMEPAGE=	https://plumbum.readthedocs.io/
COMMENT=	Plumbum: shell combinators library
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
