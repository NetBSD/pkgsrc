# $NetBSD: Makefile,v 1.9 2019/11/03 17:12:04 rillig Exp $
#

DISTNAME=	tstools-1_11
PKGREVISION=	1
PKGNAME=	${DISTNAME:S/_/./}
CATEGORIES=	multimedia
MASTER_SITES=	https://tstools.googlecode.com/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-multimedia@NetBSD.org
HOMEPAGE=	https://github.com/kynesim/tstools
COMMENT=	Cross-platform command line tools for working with MPEG data
LICENSE=	mpl-1.1

MAKE_JOBS_SAFE=		no

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/./}
USE_TOOLS+=	gmake

LDFLAGS.SunOS+=	-lsocket -lnsl -lresolv

TSPROGS=	es2ts \
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
