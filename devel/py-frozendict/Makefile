# $NetBSD: Makefile,v 1.13 2023/03/02 12:40:45 adam Exp $

DISTNAME=	frozendict-2.3.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/frozendict/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/slezica/python-frozendict
COMMENT=	Immutable wrapper around dictionaries
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

PLIST_VARS=	c

.include "../../lang/python/pyversion.mk"

.if ${PYPKGPREFIX} == "py311"
# as of 2.3.4, python 3.11 is not supported
# do not build C extension for now
PYSETUPARGS=	py
.else
PLIST.c=	yes
.endif

DISTUTILS_BUILDDIR_IN_TEST_ENV=	yes
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
