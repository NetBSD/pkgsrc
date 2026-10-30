# $NetBSD: Makefile,v 1.47 2026/10/30 05:46:41 adam Exp $

DISTNAME=	dnspython-2.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-/-/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dnspython/}

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	https://www.dnspython.org/
COMMENT=	Python DNS toolkit
LICENSE=	isc

TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-build>=0.9.21:../../devel/py-uv-build
# idna
DEPENDS+=	${PYPKGPREFIX}-idna>=3.20:../../www/py-idna
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0.0:../../devel/py-test-cov

USE_LANGUAGES=	# none

# as of 2.8.0
# 15 failed, 1249 passed, 118 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
