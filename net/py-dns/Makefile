# $NetBSD: Makefile,v 1.44 2024/10/12 09:35:07 wiz Exp $

DISTNAME=	dnspython-2.7.0
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

# as of 2.7.0
# 15 failed, 1194 passed, 117 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
