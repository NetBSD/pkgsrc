# $NetBSD: Makefile,v 1.20 2025/03/02 09:20:35 wiz Exp $

DISTNAME=	authlib-1.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=A/Authlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://authlib.org/
COMMENT=	Ultimate Python library in building OAuth and OpenID Connect servers
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:S/a/A/}

PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
