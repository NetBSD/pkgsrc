# $NetBSD: Makefile,v 1.11 2023/10/28 19:56:59 wiz Exp $

DISTNAME=	exceptiongroup-1.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/exceptiongroup/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/agronholm/exceptiongroup
COMMENT=	Backport of PEP 654 (exception groups)
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-flit_scm-[0-9]*:../../devel/py-flit_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
