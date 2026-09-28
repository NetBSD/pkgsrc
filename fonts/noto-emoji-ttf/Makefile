# $NetBSD: Makefile,v 1.13 2026/09/28 14:29:29 wiz Exp $

DISTNAME=		noto-emoji-2.051.0.0.20260924
PKGNAME=		${DISTNAME:S/emoji/emoji-ttf/}
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_GITHUB:=googlefonts/}
GITHUB_PROJECT=		noto-emoji
GITHUB_TAG=		v2026-09-24-unicode18_0

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		https://fonts.google.com/noto/specimen/Noto+Color+Emoji
COMMENT=		Noto Emoji Font from Google
LICENSE=		ofl-v1.1

CONFLICTS+=		noto-ttf-[0-9]*

NO_BUILD=		yes
USE_LANGUAGES=		# none

FONTSDIR=		share/fonts/X11/TTF

INSTALLATION_DIRS=	${FONTSDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/2D/fonts/*.ttf ${DESTDIR}${PREFIX}/${FONTSDIR}

.include "../../mk/bsd.pkg.mk"
