# $NetBSD: Makefile,v 1.45 2025/09/21 15:45:29 wiz Exp $

DISTNAME=	dnspython-2.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-/-/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dnspython/}

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	https://www.dnspython.org/
COMMENT=	Python DNS toolkit
LICENSE=	isc

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.21.0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-idna>=2.1:../../www/py-idna
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0.0:../../devel/py-test-cov

USE_LANGUAGES=	# none

# as of 2.8.0
# 15 failed, 1249 passed, 118 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
