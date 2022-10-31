# $NetBSD: Makefile,v 1.3 2022/10/31 17:12:39 adam Exp $

DISTNAME=	executing-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/executing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alexmojaki/executing
COMMENT=	Get the currently executing AST node of a frame, and other information
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-asttokens-[0-9]*:../../lang/py-asttokens
TEST_DEPENDS+=	${PYPKGPREFIX}-littleutils-[0-9]*:../../devel/py-littleutils
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 311
TEST_DEPENDS+=	${PYPKGPREFIX}-rich-[0-9]*:../../comms/py-rich
.endif

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
