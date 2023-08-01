# $NetBSD: Makefile,v 1.2 2023/08/01 23:20:41 wiz Exp $

DISTNAME=	pykka-3.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pykka/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jodal/pykka
COMMENT=	Python implementation of the actor model
LICENSE=	apache-2.0

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

TEST_ENV=	PYTHONPATH=${WRKSRC}/build/lib

# as of 3.1.1
# 137 passed, 1 warning, 8 errors
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
