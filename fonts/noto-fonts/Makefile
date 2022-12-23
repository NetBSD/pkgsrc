# $NetBSD: Makefile,v 1.2 2022/12/23 13:17:38 nikita Exp $

DISTNAME=	noto-fonts
PKGNAME=	noto-fonts-20221206
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=notofonts/}
GITHUB_PROJECT=	noto-fonts
GITHUB_TAG=	20bc5918912503bc1537a407a694738c33c048aa

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
	${INSTALL_DATA} ${WRKSRC}/hinted/ttf/Arimo/*.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/hinted/ttf/Cousine/*.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/hinted/ttf/NotoK*/*.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/hinted/ttf/NotoM*/*.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/hinted/ttf/NotoN*/*.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/hinted/ttf/NotoR*/*.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/hinted/ttf/NotoSans*/*.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/hinted/ttf/NotoSerif*/*.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/hinted/ttf/NotoT*/*.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/hinted/ttf/Tinos/*.ttf ${DESTDIR}${FONTDIR}

# Do not install all ttf/otf font files.
#.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
