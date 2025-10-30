# $NetBSD: Makefile,v 1.9 2025/10/30 15:24:40 adam Exp $

DISTNAME=	requests_gssapi-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-gssapi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pythongssapi/requests-gssapi
COMMENT=	Python requests GSSAPI authentication library
LICENSE=	isc

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-gssapi-[0-9]*:../../security/py-gssapi
DEPENDS+=	${PYPKGPREFIX}-requests>=1.1.0:../../devel/py-requests

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
