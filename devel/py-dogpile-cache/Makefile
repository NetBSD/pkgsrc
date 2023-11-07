# $NetBSD: Makefile,v 1.14 2023/11/07 22:37:59 wiz Exp $

DISTNAME=	dogpile.cache-1.2.2
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
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

#PYSETUPTESTTARGET=	pytest

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.0.1:../../devel/py-typing-extensions
.endif

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
