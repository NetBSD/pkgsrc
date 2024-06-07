# $NetBSD: Makefile,v 1.3 2024/06/07 19:57:36 ryoon Exp $

DISTNAME=	notofonts.github.io-noto-monthly-release-24.6.1
PKGNAME=	noto-fonts-20240601
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=notofonts/}
GITHUB_PROJECT=	notofonts.github.io
GITHUB_TAG=	noto-monthly-release-24.6.1

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://notofonts.github.io/
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
	${INSTALL_DATA} ${WRKSRC}/fonts/NotoF*/hinted/ttf/*.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/NotoK*/hinted/ttf/*.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/NotoN*/hinted/ttf/*.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/NotoR*/hinted/ttf/*.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/NotoSans*/hinted/ttf/*.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/NotoSerif*/hinted/ttf/*.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/NotoT*/hinted/ttf/*.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/NotoZ*/hinted/ttf/*.ttf ${DESTDIR}${FONTDIR}

# Do not install all ttf/otf font files.
#.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
