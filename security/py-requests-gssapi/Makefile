# $NetBSD: Makefile,v 1.7 2025/07/05 11:44:11 wiz Exp $

DISTNAME=	requests-gssapi-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
