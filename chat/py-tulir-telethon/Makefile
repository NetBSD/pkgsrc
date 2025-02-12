# $NetBSD: Makefile,v 1.3 2025/02/12 16:40:34 adam Exp $

DISTNAME=	tulir-telethon-1.37.0a1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tulir-telethon/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tulir/Telethon
COMMENT=	Full-featured Telegram client library for Python 3
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-aes-[0-9]*:../../security/py-aes
DEPENDS+=	${PYPKGPREFIX}-rsa-[0-9]*:../../security/py-rsa

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
