# $NetBSD: Makefile,v 1.1.1.1 2005/03/06 05:16:23 uebayasi Exp $

DISTNAME=		sazanami-${SAZANAMI_VERS}
PKGNAME=		ja-sazanami-ttf-${SAZANAMI_VERS}
CATEGORIES=		fonts japanese
MASTER_SITES=		http://downloads.sourceforge.jp/efont/10087/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		yamajun@ofug.net
HOMEPAGE=		http://wiki.fdiary.net/font/?sazanami
COMMENT=		Truely free Japanese TrueType font

SAZANAMI_VERS=		20040629
FONTS_TTF_DIRS=		${PREFIX}/lib/X11/fonts/TTF

NO_BUILD=		YES
NO_CONFIGURE=		YES

do-install:
	${INSTALL_DATA_DIR} ${FONTS_TTF_DIRS}
	${INSTALL_DATA}	${WRKSRC}/sazanami-gothic.ttf ${FONTS_TTF_DIRS}
	${INSTALL_DATA}	${WRKSRC}/sazanami-mincho.ttf ${FONTS_TTF_DIRS}

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
