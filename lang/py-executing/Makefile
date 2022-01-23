# $NetBSD: Makefile,v 1.1 2022/01/23 19:25:43 adam Exp $

DISTNAME=	executing-0.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/executing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alexmojaki/executing
COMMENT=	Get the currently executing AST node of a frame, and other information
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>0:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-asttokens>0:../../lang/py-asttokens
TEST_DEPENDS+=	${PYPKGPREFIX}-test>0:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
