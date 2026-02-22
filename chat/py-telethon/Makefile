# $NetBSD: Makefile,v 1.9 2026/02/22 09:28:09 wiz Exp $

DISTNAME=	telethon-1.39.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_PYPI:=T/Telethon/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codeberg.org/Lonami/Telethon
COMMENT=	Full-featured Telegram client library for Python 3
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-aes-[0-9]*:../../security/py-aes
DEPENDS+=	${PYPKGPREFIX}-rsa-[0-9]*:../../security/py-rsa

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
