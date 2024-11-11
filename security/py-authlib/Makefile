# $NetBSD: Makefile,v 1.16 2024/11/11 07:28:54 wiz Exp $

DISTNAME=	authlib-1.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=A/Authlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://authlib.org/
COMMENT=	Ultimate Python library in building OAuth and OpenID Connect servers
LICENSE=	modified-bsd

WHEEL_NAME=	Authlib-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cryptography>=3.2:../../security/py-cryptography

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
