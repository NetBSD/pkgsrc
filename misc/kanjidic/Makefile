# $NetBSD: Makefile,v 1.5 2005/12/05 20:50:39 rillig Exp $
#

DISTNAME=	kanjidic
PKGNAME=	kanjidic-20040814
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
HOMEPAGE=	http://www.csse.monash.edu.au/~jwb/kanjidic.html
COMMENT=	Japanese Kanji information

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_ONLY=	kanjidic.gz

NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/kanjidic
	${INSTALL_DATA} ${WRKSRC}/kanjidic ${PREFIX}/share/kanjidic/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/kanjidic
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/kanjidic.doc \
		${PREFIX}/share/doc/kanjidic

.include "../../mk/bsd.pkg.mk"
