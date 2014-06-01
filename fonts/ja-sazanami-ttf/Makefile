# $NetBSD: Makefile,v 1.8 2014/06/01 16:35:34 wiz Exp $

DISTNAME=		sazanami-${SAZANAMI_VERS}
PKGNAME=		ja-sazanami-ttf-${SAZANAMI_VERS}
PKGREVISION=		2
CATEGORIES=		fonts japanese
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE_JP:=efont/10087/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		yamajun@ofug.net
HOMEPAGE=		http://wiki.fdiary.net/font/?sazanami
COMMENT=		Truly free Japanese TrueType font

SAZANAMI_VERS=		20040629
FONTS_DIRS.ttf=		${PREFIX}/share/fonts/X11/TTF

NO_BUILD=		YES
NO_CONFIGURE=		YES

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA}	${WRKSRC}/sazanami-gothic.ttf \
		${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA}	${WRKSRC}/sazanami-mincho.ttf \
		${DESTDIR}${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
