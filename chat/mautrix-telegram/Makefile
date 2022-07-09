# $NetBSD: Makefile,v 1.14 2022/07/09 09:23:48 wiz Exp $

DISTNAME=	telegram-0.11.3
PKGNAME=	mautrix-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_GITHUB:=mautrix/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
WRKSRC=		${WRKDIR}/${DISTNAME}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/mautrix/telegram
COMMENT=	Matrix-Telegram hybrid puppeting/relaybot bridge
LICENSE=	gnu-agpl-v3

# pytest-runner
TOOL_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.15.35:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-magic>=0.4<0.5:../../sysutils/py-magic
DEPENDS+=	${PYPKGPREFIX}-commonmark>=0.8<0.10:../../textproc/py-commonmark
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3<4:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-yarl>=1<2:../../www/py-yarl
DEPENDS+=	${PYPKGPREFIX}-mautrix>=0.16<0.17:../../chat/py-mautrix
DEPENDS+=	${PYPKGPREFIX}-tulir-telethon>=1.25.0a7:../../chat/py-tulir-telethon
DEPENDS+=	${PYPKGPREFIX}-asyncpg>=0.20:../../databases/py-asyncpg
DEPENDS+=	${PYPKGPREFIX}-mako>=1<2:../../devel/py-mako
# webp_convert and qr_login
DEPENDS+=	${PYPKGPREFIX}-Pillow>=4<10:../../graphics/py-Pillow
# qr_login
DEPENDS+=	${PYPKGPREFIX}-qrcode>=6<8:../../graphics/py-qrcode

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

EGG_NAME=	mautrix_telegram-${PKGVERSION_NOREV}+dev.unknown

INSTALLATION_DIRS+=	share/mautrix-telegram

post-install:
	mv ${DESTDIR}${PREFIX}/example-config.yaml \
		${DESTDIR}${PREFIX}/share/mautrix-telegram/

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
