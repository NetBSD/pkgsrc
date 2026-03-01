# $NetBSD: Makefile,v 1.2 2026/03/01 07:13:14 wiz Exp $

DISTNAME=	slip10-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/slip10/}

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://github.com/trezor/python-slip10
COMMENT=	Reference implementation of SLIP-0010
LICENSE=	mit AND modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core-[0-9]*:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
