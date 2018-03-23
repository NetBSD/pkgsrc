# $NetBSD: Makefile,v 1.13 2018/03/23 21:09:11 joerg Exp $

DISTNAME=	flake8-3.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flake8/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/flake8/
COMMENT=	Modular source code checker for Python programs
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-flakes>=1.5.0:../../devel/py-flakes
DEPENDS+=	${PYPKGPREFIX}-mccabe>=0.6.0:../../devel/py-mccabe
DEPENDS+=	${PYPKGPREFIX}-codestyle>=2.0.0:../../devel/py-codestyle
.include "../../lang/python/pyversion.mk"
.if "${PYPKGPREFIX}" == "py27"
DEPENDS+=	${PYPKGPREFIX}-configparser-[0-9]*:../../devel/py-configparser
DEPENDS+=	${PYPKGPREFIX}-enum34-[0-9]*:../../devel/py-enum34
.else
# Enforced by setuptools
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
.endif

# 8 test failures as of 3.0.4, see
# https://gitlab.com/pycqa/flake8/issues/232
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} flake8 flake8-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
