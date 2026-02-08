# $NetBSD: Makefile,v 1.24 2026/02/08 22:20:58 wiz Exp $

DISTNAME=	wcwidth-0.6.0
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

# as of 0.6.0
# 1 failed, 753 passed, 10 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
