# $NetBSD: Makefile,v 1.1.1.1 2004/01/02 03:14:49 wiz Exp $
#

DISTNAME=	kanjidic
PKGNAME=	kanjidic-20030901
WRKSRC=		${WRKDIR}
CATEGORIES=	japanese misc
MASTER_SITES=	ftp://ftp.cc.monash.edu.au/pub/nihongo/ \
		http://japanology.arts.kuleuven.ac.be/mirrors/monash/ \
		ftp://ftp.nrc.ca/pub/packages/nihongo/ \
		http://www.bcit-broadcast.com/monash/ \
		ftp://ftp.sedl.org/pub/mirrors/nihongo/ \
		ftp://ftp.net.usf.edu/pub/monash/ \
		ftp://ftp.u-aizu.ac.jp/pub/SciEng/nihongo/ftp.cc.monash.edu.au/ \
		ftp://ftp.funet.fi/pub/culture/japan/mirrors/monash/pub/nihongo/
EXTRACT_SUFX=	.gz
DISTFILES=	kanjidic.gz kanjidic.doc

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.csse.monash.edu.au/~jwb/edict.html
COMMENT=	Japanese Kanji information

DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_ONLY=	kanjidic.gz

NO_BUILD=	# nothing to do

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/kanjidic
	${INSTALL_DATA} ${WRKSRC}/kanjidic ${PREFIX}/share/kanjidic/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/kanjidic
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/kanjidic.doc \
		${PREFIX}/share/doc/kanjidic

.include "../../mk/bsd.pkg.mk"
