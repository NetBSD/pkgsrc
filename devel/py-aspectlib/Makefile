# $NetBSD: Makefile,v 1.1 2026/11/09 09:29:28 wiz Exp $

DISTNAME=	aspectlib-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aspectlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ionelmc/python-aspectlib
COMMENT=	Aspect-oriented programming, monkey-patch and decorators library
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-process-tests>=0:../../devel/py-process-tests
TEST_DEPENDS+=	${PYPKGPREFIX}-tornado>=0:../../www/py-tornado

USE_LANGUAGES=	# none

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
