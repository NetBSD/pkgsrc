# $NetBSD: Makefile,v 1.29 2026/01/06 11:18:42 wiz Exp $

DISTNAME=	dogpile_cache-1.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dogpile.cache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/zzzeek/dogpile.cache
COMMENT=	Caching front-end based on the Dogpile lock
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-decorator>=4.0.0:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-stevedore>=3.0.0:../../devel/py-stevedore
TEST_DEPENDS+=	${PYPKGPREFIX}-mako-[0-9]*:../../devel/py-mako
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx via py-stevedore

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
