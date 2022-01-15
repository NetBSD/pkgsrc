# $NetBSD: Makefile,v 1.10 2022/01/15 20:22:06 js Exp $

DISTNAME=	mautrix-telegram-0.11.1
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_GITHUB:=tulir/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
WRKSRC=		${WRKDIR}/telegram-${PKGVERSION_NOREV}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/tulir/mautrix-telegram
COMMENT=	Matrix-Telegram hybrid puppeting/relaybot bridge
LICENSE=	gnu-agpl-v3

# pytest-runner
TOOL_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.15.35:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-magic>=0.4<0.5:../../sysutils/py-magic
DEPENDS+=	${PYPKGPREFIX}-commonmark>=0.8<0.10:../../textproc/py-commonmark
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3<4:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-yarl>=1<2:../../www/py-yarl
DEPENDS+=	${PYPKGPREFIX}-mautrix>=0.14.3<0.15:../../chat/py-mautrix
DEPENDS+=	${PYPKGPREFIX}-telethon>=1.24<1.25:../../chat/py-telethon
DEPENDS+=	${PYPKGPREFIX}-asyncpg>=0.20<0.26:../../databases/py-asyncpg
DEPENDS+=	${PYPKGPREFIX}-mako>=1<2:../../devel/py-mako
# webp_convert and qr_login
DEPENDS+=	${PYPKGPREFIX}-Pillow>=4<9:../../graphics/py-Pillow
# qr_login
DEPENDS+=	${PYPKGPREFIX}-qrcode>=6<7:../../graphics/py-qrcode

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

EGG_NAME=	mautrix_telegram-${PKGVERSION_NOREV}+dev.unknown

INSTALLATION_DIRS+=	share/mautrix-telegram

post-install:
	mv ${DESTDIR}${PREFIX}/example-config.yaml \
		${DESTDIR}${PREFIX}/share/mautrix-telegram/

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
