# $NetBSD: Makefile,v 1.5 2022/04/07 19:59:55 wiz Exp $

DISTNAME=		noto-emoji-2.034
PKGNAME=		${DISTNAME:S/emoji/emoji-ttf/}
PKGREVISION=		1
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_GITHUB:=googlei18n/}
GITHUB_PROJECT=		noto-emoji
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		https://www.google.com/get/noto/
COMMENT=		Noto Emoji Font from Google
LICENSE=		ofl-v1.1

NO_BUILD=		yes
USE_LANGUAGES=		# none

FONTSDIR=		share/fonts/X11/TTF

INSTALLATION_DIRS=	${FONTSDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/fonts/NotoColorEmoji.ttf ${DESTDIR}/${PREFIX}/${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/NotoEmoji-Regular.ttf ${DESTDIR}/${PREFIX}/${FONTSDIR}

.include "../../mk/bsd.pkg.mk"
