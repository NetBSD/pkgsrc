# $NetBSD: Makefile,v 1.171 2019/10/16 07:21:46 adam Exp $

DISTNAME=	setuptools-41.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/setuptools/}
EXTRACT_SUFX=	.zip

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://github.com/pypa/setuptools
COMMENT=	New Python packaging system
LICENSE=	python-software-foundation OR zpl-2.0

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-fixture-config-[0-9]*:../../devel/py-test-fixture-config
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-test-virtualenv-[0-9]*:../../devel/py-test-virtualenv
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

.include "../../lang/python/distutils.mk"
.if ${_PYTHON_VERSION:M3[6-9]}
TEST_DEPENDS+=	${PYPKGPREFIX}-paver-[0-9]*:../../lang/py-paver
.else
TEST_DEPENDS+=	${PYPKGPREFIX}-pathlib2-[0-9]*:../../devel/py-pathlib2
.endif

REPLACE_PYTHON+=	setuptools/command/easy_install.py

PYSETUPTESTTARGET=	pytest

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
