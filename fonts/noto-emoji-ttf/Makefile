# $NetBSD: Makefile,v 1.10 2025/08/03 09:39:08 wiz Exp $

DISTNAME=		noto-emoji-2.048
PKGNAME=		${DISTNAME:S/emoji/emoji-ttf/}
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_GITHUB:=googlefonts/}
GITHUB_PROJECT=		noto-emoji
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		https://www.google.com/get/noto/
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
