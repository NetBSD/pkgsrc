# $NetBSD: Makefile,v 1.5 2026/08/24 13:12:53 adam Exp $

DISTNAME=	joserfc-1.7.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/joserfc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/authlib/joserfc
COMMENT=	Python library for JOSE RFCs, including JWS, JWE, JWK, JWA, JWT
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cryptography>=45.0.1:../../security/py-cryptography

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
