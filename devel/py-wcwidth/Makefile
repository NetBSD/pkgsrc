# $NetBSD: Makefile,v 1.31 2026/09/24 10:39:31 adam Exp $

DISTNAME=	wcwidth-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wcwidth/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/jquast/wcwidth
COMMENT=	Measures number of Terminal column cells of wide-character codes
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

# as of 0.8.3
# 1 failed, 1363 passed, 10 skipped
# after installation, no errors

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
