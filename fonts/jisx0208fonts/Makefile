# $NetBSD: Makefile,v 1.1.1.1 2000/04/09 15:20:48 itojun Exp $
#

DISTNAME=	jisx0208fonts-0.0
CATEGORIES=	x11 japanese
MASTER_SITES=   ftp://ftp.iij.ad.jp/pub/X/X11R6.4/xc/fonts/bdf/misc/ \
		ftp://ftp.eu.net/X11/R6.4/xc/fonts/bdf/misc/
DISTFILES=	${ELISA10X8} ${ELISA8X8} ${KANAME12} ${KAPPA20} ${NAGA10}

MAINTAINER=	itojun@itojun.org

USE_X11BASE=	yes
EXTRACT_ONLY=	# empty

MAKE_ENV+=	FONTDIR=${FONTDIR} GZIP_CMD="${GZIP_CMD}"

# fonts
MASTER_SITES+=	http://hp.vector.co.jp/authors/VA004814/freesoft/ \
		ftp://ftp.jp.netbsd.org/pub/NetBSD-jp/tut-jp/fonts/
ELISA10X8=	elisau10.tgz clR5x8.bdf
EXTRACT_ONLY+=	elisau10.tgz

MASTER_SITES+=	http://www.tea.forus.or.jp/toshi/exhibition/
ELISA8X8=	elisat10.tar.gz
EXTRACT_ONLY+=	elisat10.tar.gz

MASTER_SITES+=	http://www.din.or.jp/~storm/fonts/
KANAME12=	kaname_k12_bdf.tar.gz
EXTRACT_ONLY+=	kaname_k12_bdf.tar.gz

MASTER_SITES+=	ftp://ftp.jaist.ac.jp/pub/misc/character/fonts/kappa/
KAPPA20=	Kappa20-0.3.tar.gz
EXTRACT_ONLY+=	Kappa20-0.3.tar.gz

MASTER_SITES+=	http://hp.vector.co.jp/authors/VA013391/fonts/
NAGA10=		knj10-1.1.tar.gz 6x12.tar.gz
EXTRACT_ONLY+=	knj10-1.1.tar.gz 6x12.tar.gz

FONTDIR=${PREFIX}/lib/X11/fonts/local

post-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/clR5x8.bdf ${WRKDIR}
	${CP} ${FILESDIR}/Makefile ${WRKSRC}
	(cd ${WRKSRC}; ${MAKE} prepare)

post-install:
	${MKDIR} ${PREFIX}/share/doc/jisx0208fonts
	${INSTALL_DATA} ${WRKDIR}/knj10-1.1/README \
		${PREFIX}/share/doc/jisx0208fonts/README.naga10-1.1
	${INSTALL_DATA} ${FILESDIR}/README.kappa20 \
		${PREFIX}/share/doc/jisx0208fonts
	(cd ${FONTDIR}; mkfontdir)

.include "../../mk/bsd.pkg.mk"
