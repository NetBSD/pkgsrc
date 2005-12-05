# $NetBSD: Makefile,v 1.5 2005/12/05 20:50:39 rillig Exp $
#

DISTNAME=	edict
PKGNAME=	edict-2004.003
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
DISTFILES=	edict.gz edict_doc.txt

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.csse.monash.edu.au/~jwb/edict.html
COMMENT=	Japanese-English dictionary file

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_ONLY=	edict.gz

NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/edict
	${INSTALL_DATA} ${WRKSRC}/edict ${PREFIX}/share/edict/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/edict
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/edict_doc.txt \
		${PREFIX}/share/doc/edict

.include "../../mk/bsd.pkg.mk"
