# $NetBSD: Makefile,v 1.3 2005/01/03 15:46:40 wiz Exp $
#

DISTNAME=	JMdict
PKGNAME=	JMdict-2004.03
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
DISTFILES=	jmdict_proj_desc.html JMdict.gz JMdict.dtd

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.csse.monash.edu.au/~jwb/edict.html
COMMENT=	Japanese-Multilingual electronic dictionary

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_ONLY=	JMdict.gz

NO_BUILD=	# nothing to do

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/JMdict
	${INSTALL_DATA} ${WRKSRC}/JMdict ${PREFIX}/share/JMdict
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/JMdict.dtd \
		${PREFIX}/share/JMdict
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/JMdict
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/jmdict_proj_desc.html \
		${PREFIX}/share/doc/JMdict

.include "../../mk/bsd.pkg.mk"
