# $NetBSD: Makefile,v 1.37 2026/04/27 05:45:44 wiz Exp $

DISTNAME=	authlib-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/authlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/authlib/joserfc
COMMENT=	Python library for JOSE RFCs, including JWS, JWE, JWK, JWA, JWT
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-joserfc>=1.6.0:../../security/py-joserfc

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
