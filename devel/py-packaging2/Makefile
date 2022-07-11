# $NetBSD: Makefile,v 1.3 2022/07/11 08:51:08 wiz Exp $

DISTNAME=	packaging-20.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/packaging/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/packaging
COMMENT=	Core utilities for Python packages (Python 2.x version)
LICENSE=	modified-bsd OR apache-2.0

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-pyparsing-[0-9]*:../../devel/py-pyparsing2
TEST_DEPENDS+=	${PYPKGPREFIX}-pretend-[0-9]*:../../devel/py-pretend
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test4

PYTHON_VERSIONS_ACCEPTED=	27

USE_LANGUAGES=	# none

# needs 'make install' before
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
