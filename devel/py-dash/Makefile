# $NetBSD: Makefile,v 1.17 2025/01/27 10:04:30 adam Exp $

DISTNAME=	pydash-8.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydash/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dgilland/pydash
COMMENT=	Python utility libraries for doing stuff in a functional way
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.0.:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.6.1:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-invoke-[0-9]*:../../sysutils/py-invoke
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mypy-testing-[0-9]*:../../devel/py-test-mypy-testing

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
