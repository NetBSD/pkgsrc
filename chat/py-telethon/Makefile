# $NetBSD: Makefile,v 1.7 2025/03/05 09:32:24 wiz Exp $

DISTNAME=	Telethon-1.36.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_PYPI:=T/Telethon/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/LonamiWebs/Telethon
COMMENT=	Full-featured Telegram client library for Python 3
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-aes-[0-9]*:../../security/py-aes
DEPENDS+=	${PYPKGPREFIX}-rsa-[0-9]*:../../security/py-rsa

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:tl}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
