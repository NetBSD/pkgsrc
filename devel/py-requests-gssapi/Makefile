# $NetBSD: Makefile,v 1.1 2025/09/06 18:26:56 riastradh Exp $

DISTNAME=	requests-gssapi-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-gssapi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pythongssapi/requests-gssapi
COMMENT=	GSSAPI authentication support for Python requests module
LICENSE=	isc

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.0.0:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-requests>=1.1.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-gssapi>=0:../../security/py-gssapi

TEST_ENV+=	PYTHONPATH=${WRKSRC:Q}/build/lib

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
