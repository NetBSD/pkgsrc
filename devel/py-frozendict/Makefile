# $NetBSD: Makefile,v 1.16 2023/04/16 14:40:46 wiz Exp $

DISTNAME=	frozendict-2.3.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/frozendict/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/Marco-Sulla/python-frozendict
COMMENT=	Immutable wrapper around dictionaries
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
