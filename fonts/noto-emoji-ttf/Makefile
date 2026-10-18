# $NetBSD: Makefile,v 1.14 2026/10/18 13:01:45 pin Exp $

DISTNAME=		noto-emoji-2.051.0.0.20260924
PKGNAME=		${DISTNAME:S/emoji/emoji-ttf/}
PKGREVISION=		1
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
VARIANTSDIR=		share/${PKGBASE}/variants

INSTALLATION_DIRS=	${FONTSDIR} ${VARIANTSDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/2D/fonts/NotoColorEmoji.ttf \
		${DESTDIR}${PREFIX}/${FONTSDIR}
.for f in Noto-COLRv1 Noto-COLRv1-emojicompat Noto-COLRv1-noflags \
	NotoColorEmoji-emojicompat NotoColorEmoji-flagsonly \
	NotoColorEmoji-noflags NotoColorEmoji_WindowsCompatible
	${INSTALL_DATA} ${WRKSRC}/2D/fonts/${f}.ttf \
		${DESTDIR}${PREFIX}/${VARIANTSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
