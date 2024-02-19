# $NetBSD: Makefile,v 1.43 2024/02/19 06:02:37 adam Exp $

DISTNAME=	dnspython-2.6.1
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

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
