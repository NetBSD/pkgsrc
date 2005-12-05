# $NetBSD: Makefile,v 1.5 2005/12/05 20:50:39 rillig Exp $
#

DISTNAME=	kanjidic2
PKGNAME=	kanjidic2-2004.2.1
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
DISTFILES=	kanjidic2.xml.gz kanjidic_doc.html kanjidic2_ov.html kanjidic2_dtd.gz kanjidic2_xsd.gz

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.csse.monash.edu.au/~jwb/kanjidic.html
COMMENT=	Japanese Kanji information

DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_ONLY=	kanjidic2.xml.gz kanjidic2_dtd.gz kanjidic2_xsd.gz
WRKSRC=		${WRKDIR}

NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/kanjidic2
	${INSTALL_DATA} ${WRKSRC}/kanjidic2.xml ${PREFIX}/share/kanjidic2/
	${INSTALL_DATA} ${WRKSRC}/kanjidic2_dtd \
		${PREFIX}/share/kanjidic2/kanjidic2.dtd
	${INSTALL_DATA} ${WRKSRC}/kanjidic2_xsd \
		${PREFIX}/share/kanjidic2/kanjidic2.xsd
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/kanjidic2
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/kanjidic_doc.html \
		${PREFIX}/share/doc/kanjidic2
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/kanjidic2_ov.html \
		${PREFIX}/share/doc/kanjidic2

.include "../../mk/bsd.pkg.mk"
