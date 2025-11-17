# $NetBSD: Makefile,v 1.8 2025/11/17 11:00:46 wiz Exp $

DISTNAME=		monafont-ttf-2.90
PKGNAME=		${DISTNAME:S/font/fonts/}
PKGREVISION=		1
CATEGORIES=		fonts japanese
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=monafont/}
EXTRACT_SUFX=		.zip

MAINTAINER=		yamajun@ofug.net
HOMEPAGE=		https://monafont.sourceforge.net/index-e.html
COMMENT=		Japanese TrueType fonts for "Mona" seen at 2ch.net

NO_BUILD=		YES
NO_CONFIGURE=		YES

FONTDIR=		${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf+=	${FONTDIR}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKDIR}/mona.ttf ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
