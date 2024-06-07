# $NetBSD: Makefile,v 1.14 2024/06/07 20:54:53 adam Exp $

DISTNAME=	authlib-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=A/Authlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://authlib.org/
COMMENT=	Ultimate Python library in building OAuth and OpenID Connect servers
LICENSE=	modified-bsd

WHEEL_NAME=	Authlib-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-cryptography>=3.2:../../security/py-cryptography

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
