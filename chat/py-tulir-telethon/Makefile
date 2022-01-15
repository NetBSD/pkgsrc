# $NetBSD: Makefile,v 1.1 2022/01/15 21:11:24 js Exp $

DISTNAME=	tulir-telethon-1.25.0a3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tulir-telethon/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tulir/Telethon
COMMENT=	Full-featured Telegram client library for Python 3
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-aes-[0-9]*:../../security/py-aes
DEPENDS+=	${PYPKGPREFIX}-rsa-[0-9]*:../../security/py-rsa

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
