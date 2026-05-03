# $NetBSD: Makefile,v 1.25 2026/05/03 14:58:57 wiz Exp $

DISTNAME=	wcwidth-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wcwidth/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/jquast/wcwidth
COMMENT=	Measures number of Terminal column cells of wide-character codes
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

USE_LANGUAGES=	# none

# as of 0.7.0
# 1 failed, 1133 passed, 10 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
