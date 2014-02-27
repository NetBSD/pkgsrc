# $NetBSD: Makefile,v 1.1 2014/02/27 14:46:17 wiz Exp $

DISTNAME=	pixels-sagas-startrek-201312
CATEGORIES=	fonts
MASTER_SITES=	http://www.pixelsagas.com/files/
DISTFILES+=	PS_Font_Fontana.zip
DISTFILES+=	PS_Font_Jefferies.zip
DISTFILES+=	PS_Font_Montalban.zip
DISTFILES+=	PS_Font_Okuda.zip
DISTFILES+=	PS_Font_Probert.zip
DISTFILES+=	PS_Font_Roddenberry.zip
DISTFILES+=	PS_Font_Sternbach.zip
DISTFILES+=	PS_Font_Tellarite.zip
DISTFILES+=	PS_Font_Trek_Arrowcaps.zip
DISTFILES+=	PS_Font_Trek_Arrowheads.zip

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://www.pixelsagas.com/fonts.php
COMMENT=	Star Trek fonts from Pixel Sagas (Neale Davidson)
LICENSE=	pixel-sagas-shareware-license

RESTRICTED=	License prohibits 3rd parties hosting the files.
NO_BIN_ON_FTP=	${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}

WRKSRC=		${WRKDIR}
TTFPATH=	lib/X11/fonts/TTF
FONTS_DIRS.ttf+=	${PREFIX}/${TTFPATH:Q}
INSTALLATION_DIRS=	${TTFPATH:Q}
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTS_DIRS.ttf:Q}
	${INSTALL_DATA} ${WRKSRC}/*.[OoTt][Tt][Ff] ${DESTDIR}${FONTS_DIRS.ttf:Q}

.include "../../mk/bsd.pkg.mk"
