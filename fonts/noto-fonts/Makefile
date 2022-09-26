# $NetBSD: Makefile,v 1.1 2022/09/26 16:04:49 ryoon Exp $

DISTNAME=	noto-fonts
PKGNAME=	noto-fonts-20220810
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=notofonts/}
GITHUB_PROJECT=	noto-fonts
GITHUB_TAG=	2725c70baa8b0176c7577093ba1fc6179aa79478

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/notofonts/noto-fonts/
COMMENT=	Google Noto fonts, except CJK and Emoji
LICENSE=	ofl-v1.1

CONFLICTS+=	noto-ttf-[0-9]*

USE_LANGUAGES=	# none
NO_CONFIGURE=	yes
NO_BUILD=	yes

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	share/fonts/X11/TTF

do-install:
	# `${WRKSRC}/hinted/ttf/Noto*/*.ttf` causes too long argument error.
	${INSTALL_DATA} ${WRKSRC}/hinted/ttf/NotoK*/*.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/hinted/ttf/NotoL*/*.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/hinted/ttf/NotoM*/*.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/hinted/ttf/NotoN*/*.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/hinted/ttf/NotoR*/*.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/hinted/ttf/NotoSans*/*.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/hinted/ttf/NotoSerif*/*.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/hinted/ttf/NotoT*/*.ttf ${DESTDIR}${FONTDIR}

# Do not install all ttf/otf font files.
#.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
