# $NetBSD: Makefile,v 1.11 2025/09/17 08:08:42 wiz Exp $

DISTNAME=		noto-emoji-2.051
PKGNAME=		${DISTNAME:S/emoji/emoji-ttf/}
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_GITHUB:=googlefonts/}
GITHUB_PROJECT=		noto-emoji
GITHUB_TAG=		v${PKGVERSION_NOREV}

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
	${INSTALL_DATA} ${WRKSRC}/fonts/NotoColorEmoji.ttf ${DESTDIR}/${PREFIX}/${FONTSDIR}

.include "../../mk/bsd.pkg.mk"
