# $NetBSD: Makefile,v 1.1 2026/03/01 00:52:25 js Exp $

DISTNAME=	slip10-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/slip10/}

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://github.com/trezor/python-slip10
COMMENT=	Reference implementation of SLIP-0010
LICENSE=	mit AND modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
