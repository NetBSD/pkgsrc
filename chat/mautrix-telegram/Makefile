# $NetBSD: Makefile,v 1.2 2020/11/19 01:24:23 js Exp $

DISTNAME=	mautrix-telegram-0.9.0
PKGREVISION=	1
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_GITHUB:=tulir/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/tulir/mautrix-telegram
COMMENT=	Matrix-Telegram hybrid puppeting/relaybot bridge
LICENSE=	gnu-agpl-v3

DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.2<2:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-alembic>=1<2:../../databases/py-alembic
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.15.35<0.17:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-magic>=0.4<0.5:../../sysutils/py-magic
DEPENDS+=	${PYPKGPREFIX}-commonmark>=0.8<0.10:../../textproc/py-commonmark
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3<4:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-yarl>=1<2:../../www/py-yarl
DEPENDS+=	${PYPKGPREFIX}-mautrix>=0.8.2<0.9:../../chat/py-mautrix
DEPENDS+=	${PYPKGPREFIX}-telethon>=1.17<18:../../chat/py-telethon
DEPENDS+=	${PYPKGPREFIX}-telethon-session-sqlalchemy>=0.2.14<0.3:../../chat/py-telethon-session-sqlalchemy
# webp_convert and qr_login
DEPENDS+=	${PYPKGPREFIX}-Pillow>=4<8:../../graphics/py-Pillow
# qr_login
DEPENDS+=	${PYPKGPREFIX}-qrcode>=6<7:../../graphics/py-qrcode

USE_TOOLS+=	pax
USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 36

EGG_NAME=	mautrix_telegram-${PKGVERSION_NOREV}+dev.unknown

INSTALLATION_DIRS+=	share/mautrix-telegram

post-install:
	mv ${DESTDIR}${PREFIX}/alembic ${DESTDIR}${PREFIX}/alembic.ini \
		${DESTDIR}${PREFIX}/example-config.yaml \
		${DESTDIR}${PREFIX}/share/mautrix-telegram/
	cd ${DESTDIR}${PREFIX}/${PYSITELIB}/mautrix_telegram && \
		${PAX} -wr example-config.yaml \
		${DESTDIR}${PREFIX}/share/mautrix-telegram/

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
