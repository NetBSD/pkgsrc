# $NetBSD: Makefile,v 1.6 2023/10/01 16:23:54 adam Exp $

DISTNAME=	executing-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/executing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alexmojaki/executing
COMMENT=	Get the currently executing AST node of a frame, and other information
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-asttokens>=2.1.0:../../lang/py-asttokens
TEST_DEPENDS+=	${PYPKGPREFIX}-ipython-[0-9]*:../../devel/py-ipython
TEST_DEPENDS+=	${PYPKGPREFIX}-littleutils-[0-9]*:../../devel/py-littleutils
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} >= 311
TEST_DEPENDS+=	${PYPKGPREFIX}-rich-[0-9]*:../../comms/py-rich
.endif

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
