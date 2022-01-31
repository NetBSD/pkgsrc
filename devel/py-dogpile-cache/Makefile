# $NetBSD: Makefile,v 1.9 2022/01/31 13:56:06 adam Exp $

DISTNAME=	dogpile.cache-1.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/./-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dogpile.cache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/zzzeek/dogpile.cache
COMMENT=	Caching front-end based on the Dogpile lock
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-decorator>=4.0.0:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-stevedore>=3.0.0:../../devel/py-stevedore
TEST_DEPENDS+=	${PYPKGPREFIX}-mako-[0-9]*:../../devel/py-mako
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
