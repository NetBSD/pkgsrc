# $NetBSD: Makefile,v 1.6 2024/11/11 07:28:44 wiz Exp $

DISTNAME=	shellingham-1.5.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/post//}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/shellingham/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sarugaku/shellingham
COMMENT=	Tool to detect surrounding shell
LICENSE=	isc

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=40.0:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# needs 'make install'
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
