# $NetBSD: Makefile,v 1.18 2024/05/06 04:36:19 adam Exp $

DISTNAME=	dogpile.cache-1.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/./-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dogpile.cache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/zzzeek/dogpile.cache
COMMENT=	Caching front-end based on the Dogpile lock
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.2:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-decorator>=4.0.0:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-stevedore>=3.0.0:../../devel/py-stevedore
TEST_DEPENDS+=	${PYPKGPREFIX}-mako-[0-9]*:../../devel/py-mako
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.0.1:../../devel/py-typing-extensions
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
