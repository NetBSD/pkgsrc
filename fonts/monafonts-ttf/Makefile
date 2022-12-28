# $NetBSD: Makefile,v 1.7 2022/12/28 13:57:22 wiz Exp $

DISTNAME=		monafont-ttf-2.90
PKGNAME=		${DISTNAME:S/font/fonts/}
PKGREVISION=		1
CATEGORIES=		fonts japanese
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=monafont/}
EXTRACT_SUFX=		.zip

MAINTAINER=		yamajun@ofug.net
HOMEPAGE=		http://monafont.sourceforge.net/index-e.html
COMMENT=		Japanese TrueType fonts for "Mona" seen at 2ch.net

NO_BUILD=		YES
NO_CONFIGURE=		YES

FONTDIR=		${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf+=	${FONTDIR}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKDIR}/mona.ttf ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
