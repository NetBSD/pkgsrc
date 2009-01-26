# $NetBSD: Makefile,v 1.1.1.1 2009/01/26 22:49:28 jmcneill Exp $
#

DISTNAME=	tstools-1_11
PKGNAME=	${DISTNAME:S/_/./}
CATEGORIES=	multimedia
MASTER_SITES=	http://download.berlios.de/tstools/	\
		http://download2.berlios.de/tstools/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-multimedia@NetBSD.org
HOMEPAGE=	http://tstools.berlios.de/
COMMENT=	Cross-platform command line tools for working with MPEG data

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/./}
USE_TOOLS+=	gmake

TSPROGS=es2ts \
	esdots \
	esfilter \
	esmerge \
	esreport \
	esreverse \
	m2ts2ts \
	pcapreport \
	ps2ts \
	psdots \
	psreport \
	stream_type \
	ts2es \
	ts_packet_insert \
	tsinfo \
	tsplay \
	tsreport \
	tsserve

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin
.for tsprog in ${TSPROGS}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${tsprog} \
	    ${DESTDIR}${PREFIX}/bin/${tsprog}
.endfor

.include "../../mk/bsd.pkg.mk"
