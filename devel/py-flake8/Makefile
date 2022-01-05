# $NetBSD: Makefile,v 1.40 2022/01/05 15:41:04 wiz Exp $

DISTNAME=	flake8-3.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flake8/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/pycqa/flake8
COMMENT=	Modular source code checker for Python programs
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-codestyle>=2.7.0:../../devel/py-codestyle
DEPENDS+=	${PYPKGPREFIX}-flakes>=2.3.0:../../devel/py-flakes
DEPENDS+=	${PYPKGPREFIX}-mccabe>=0.6.0:../../devel/py-mccabe
.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-configparser-[0-9]*:../../devel/py-configparser
DEPENDS+=	${PYPKGPREFIX}-enum34-[0-9]*:../../devel/py-enum34
DEPENDS+=	${PYPKGPREFIX}-functools32-[0-9]*:../../devel/py-functools32
DEPENDS+=	${PYPKGPREFIX}-typing-[0-9]*:../../devel/py-typing
.endif
.if ${_PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata-[0-9]*:../../devel/py-importlib-metadata
.endif
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=2.0.0:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-pylint-[0-9]*:../../devel/py-pylint

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} flake8 flake8-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
