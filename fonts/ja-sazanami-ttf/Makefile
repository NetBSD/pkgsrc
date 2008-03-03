# $NetBSD: Makefile,v 1.6 2008/03/03 20:17:12 jlam Exp $

DISTNAME=		sazanami-${SAZANAMI_VERS}
PKGNAME=		ja-sazanami-ttf-${SAZANAMI_VERS}
PKGREVISION=		1
CATEGORIES=		fonts japanese
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE_JP:=efont/10087/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		yamajun@ofug.net
HOMEPAGE=		http://wiki.fdiary.net/font/?sazanami
COMMENT=		Truly free Japanese TrueType font

PKG_DESTDIR_SUPPORT=	user-destdir

SAZANAMI_VERS=		20040629
FONTS_DIRS.ttf=		${PREFIX}/lib/X11/fonts/TTF

NO_BUILD=		YES
NO_CONFIGURE=		YES

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA}	${WRKSRC}/sazanami-gothic.ttf \
		${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA}	${WRKSRC}/sazanami-mincho.ttf \
		${DESTDIR}${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
