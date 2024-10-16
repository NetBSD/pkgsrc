# $NetBSD: Makefile,v 1.22 2024/10/16 16:40:54 jperkin Exp $

DISTNAME=	telegram-0.11.3
PKGNAME=	mautrix-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_GITHUB:=mautrix/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
WRKSRC=		${WRKDIR}/${DISTNAME}

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://github.com/mautrix/telegram
COMMENT=	Matrix-Telegram hybrid puppeting/relaybot bridge
LICENSE=	gnu-agpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.15.35:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-magic>=0.4<0.5:../../sysutils/py-magic
DEPENDS+=	${PYPKGPREFIX}-commonmark>=0.8<0.10:../../textproc/py-commonmark
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3<4:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-yarl>=1<2:../../www/py-yarl
DEPENDS+=	${PYPKGPREFIX}-mautrix>=0.20:../../chat/py-mautrix
DEPENDS+=	${PYPKGPREFIX}-tulir-telethon>=1.25.0a7:../../chat/py-tulir-telethon
DEPENDS+=	${PYPKGPREFIX}-asyncpg>=0.20:../../databases/py-asyncpg
DEPENDS+=	${PYPKGPREFIX}-mako>=1<2:../../devel/py-mako
# webp_convert and qr_login
DEPENDS+=	${PYPKGPREFIX}-Pillow>=4:../../graphics/py-Pillow
# qr_login
DEPENDS+=	${PYPKGPREFIX}-qrcode>=6<9:../../graphics/py-qrcode

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	share/mautrix-telegram

post-install:
	mv ${DESTDIR}${PREFIX}/example-config.yaml \
		${DESTDIR}${PREFIX}/share/mautrix-telegram/

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
