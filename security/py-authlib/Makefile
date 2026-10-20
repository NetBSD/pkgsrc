# $NetBSD: Makefile,v 1.40 2026/10/20 04:50:37 adam Exp $

DISTNAME=	authlib-1.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/authlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/authlib/authlib
COMMENT=	Python library for JOSE RFCs, including JWS, JWE, JWK, JWA, JWT
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-joserfc>=1.6.8:../../security/py-joserfc
DEPENDS+=	${PYPKGPREFIX}-cryptography>=45.0.1:../../security/py-cryptography

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
