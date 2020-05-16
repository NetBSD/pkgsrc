# $NetBSD: Makefile,v 1.5 2020/05/16 13:56:47 adam Exp $

DISTNAME=	dogpile.cache-0.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/./-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dogpile.cache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/zzzeek/dogpile.cache
COMMENT=	Caching front-end based on the Dogpile lock
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
TEST_DEPENDS+=	${PYPKGPREFIX}-mako-[0-9]*:../../devel/py-mako
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
