# $NetBSD: Makefile,v 1.2 2022/01/27 08:17:13 wiz Exp $

DISTNAME=	typeguard-2.13.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/typeguard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/agronholm/typeguard
COMMENT=	Python run-time type checking library
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-mypy>0:../../lang/py-mypy
TEST_DEPENDS+=	${PYPKGPREFIX}-test>0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-typing-extensions>0:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
