# $NetBSD: Makefile,v 1.7 2022/02/07 21:14:41 adam Exp $

DISTNAME=	frozendict-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/frozendict/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/slezica/python-frozendict
COMMENT=	Immutable wrapper around dictionaries
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	c

PYTHON_VERSIONS_INCOMPATIBLE=	27

DISTUTILS_BUILDDIR_IN_TEST_ENV=	yes
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
