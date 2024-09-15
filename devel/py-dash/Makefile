# $NetBSD: Makefile,v 1.14 2024/09/15 15:36:51 adam Exp $

DISTNAME=	pydash-8.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydash/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dgilland/pydash
COMMENT=	Python utility libraries for doing stuff in a functional way
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.0.:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.6.1:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-invoke-[0-9]*:../../sysutils/py-invoke
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
