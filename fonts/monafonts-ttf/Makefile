# $NetBSD: Makefile,v 1.1.1.1 2007/12/11 13:16:29 obache Exp $
# $FreeBSD: ports/japanese/monafonts-ttf/Makefile,v 1.1 2003/10/14 13:35:38 nobutaka Exp $

DISTNAME=		monafont-ttf-2.90
PKGNAME=		${DISTNAME:S/font/fonts/}
CATEGORIES=		fonts japanese
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=monafont/}
EXTRACT_SUFX=		.zip

MAINTAINER=		yamajun@ofug.net
HOMEPAGE=		http://monafont.sourceforge.net/index-e.html
COMMENT=		Japanese TrueType fonts for "Mona" seen at 2ch.net

USE_X11BASE=		YES
NO_BUILD=		YES
NO_CONFIGURE=		YES

FONTDIR=		${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf+=	${FONTDIR}

PKG_DESTDIR_SUPPORT=	user-destdir

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKDIR}/mona.ttf ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
