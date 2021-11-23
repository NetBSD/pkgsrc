# $NetBSD: Makefile,v 1.191 2021/11/23 10:32:17 wiz Exp $

DISTNAME=	setuptools-59.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/setuptools/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://github.com/pypa/setuptools
COMMENT=	New Python packaging system
LICENSE=	python-software-foundation OR zpl-2.0

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
TEST_DEPENDS+=	${PYPKGPREFIX}-jaraco.envs-[0-9]*:../../devel/py-jaraco.envs
TEST_DEPENDS+=	${PYPKGPREFIX}-jaraco.path-[0-9]*:../../devel/py-jaraco.path
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-paver-[0-9]*:../../lang/py-paver
TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-test-fixture-config-[0-9]*:../../devel/py-test-fixture-config
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-test-virtualenv-[0-9]*:../../devel/py-test-virtualenv
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

PYTHON_VERSIONS_INCOMPATIBLE=	27

PYSETUPTESTTARGET=	pytest

# This setting, which will soon be default-on again, breaks on NetBSD
# https://github.com/pypa/setuptools/issues/2364
# files/_distutils_system_mod should fix this, but I don't know how yet
# https://github.com/pypa/distutils/issues/16
#MAKE_ENV+=	SETUPTOOLS_USE_DISTUTILS=local

#post-extract:
#	${MKDIR} ${WRKSRC}/build/lib/setuptools/
#	cp ${FILESDIR}/_distutils_system_mod ${WRKSRC}/build/lib/setuptools/

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
