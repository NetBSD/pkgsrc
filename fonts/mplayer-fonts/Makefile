# $NetBSD: Makefile,v 1.1.1.1 2006/02/03 00:37:59 wiz Exp $

DISTNAME=	mplayer-fonts-20030714
CATEGORIES=	fonts
MASTER_SITES=	http://ftp5.mplayerhq.hu/mplayer/releases/fonts/ \
		http://www4.mplayerhq.hu/MPlayer/releases/fonts/ \
		ftp://ftp2.mplayerhq.hu/MPlayer/releases/fonts/ \
		ftp://ftp1.mplayerhq.hu/MPlayer/releases/fonts \
		ftp://ftp5.mplayerhq.hu/mplayer/releases/fonts/ \
		http://www1.mplayerhq.hu/MPlayer/releases/fonts/ \
		http://www2.mplayerhq.hu/MPlayer/releases/fonts/
DISTFILES=	font-arial-iso-8859-1.tar.bz2 \
		font-arial-iso-8859-2.tar.bz2 \
		font-arial-cp1250.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mplayerhq.hu/
COMMENT=	Fonts for mplayer and gmplayer

CONFLICTS=	mplayer-share<1.0rc7nb2

DIST_SUBDIR=	${DISTNAME}

NO_BUILD=	YES
NO_CONFIGURE=	YES

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/mplayer
	${INSTALL_DATA_DIR} ${PREFIX}/share/mplayer/fonts
	for D in font-arial-cp1250 font-arial-iso-8859-1 font-arial-iso-8859-2; do \
		(cd ${WRKDIR}/$$D && \
			${PAX} -rwpppm * ${PREFIX}/share/mplayer/fonts); \
	done
	${LN} -s ${PREFIX}/share/mplayer/fonts/font-arial-18-iso-8859-1 \
		${PREFIX}/share/mplayer/font

.include "../../mk/bsd.pkg.mk"
