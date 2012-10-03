# $NetBSD: Makefile,v 1.8 2012/10/03 18:28:28 asau Exp $

DISTNAME=	mplayer-fonts-20030714
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	ftp://ftp2.mplayerhq.hu/MPlayer/releases/fonts/ \
		ftp://ftp1.mplayerhq.hu/MPlayer/releases/fonts/ \
		ftp://ftp5.mplayerhq.hu/MPlayer/releases/fonts/ \
		http://www1.mplayerhq.hu/MPlayer/releases/fonts/ \
		http://www2.mplayerhq.hu/MPlayer/releases/fonts/
DISTFILES=	font-arial-iso-8859-1.tar.bz2 \
		font-arial-iso-8859-2.tar.bz2 \
		font-arial-iso-8859-7.tar.bz2 \
		font-arial-cp1250.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mplayerhq.hu/
COMMENT=	Fonts for mplayer and gmplayer

CONFLICTS=	mplayer-share<1.0rc7nb2

DIST_SUBDIR=	${DISTNAME}

NO_BUILD=	YES
NO_CONFIGURE=	YES

USE_TOOLS+=	pax

INSTALLATION_DIRS= share/mplayer/fonts

do-install:
	for D in font-arial-cp1250 font-arial-iso-8859-1 \
		font-arial-iso-8859-2 font-arial-iso-8859-7; do \
		(cd ${WRKDIR}/$$D && \
			pax -rwpppm * ${DESTDIR}${PREFIX}/share/mplayer/fonts); \
	done
	${LN} -s ${PREFIX}/share/mplayer/fonts/font-arial-18-iso-8859-1 \
		${DESTDIR}${PREFIX}/share/mplayer/font

.include "../../mk/bsd.pkg.mk"
