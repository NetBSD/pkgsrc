# $NetBSD: Makefile,v 1.4 2001/02/17 18:19:14 wiz Exp $
# KAME Id: Makefile,v 1.3 2000/01/21 12:34:29 itojun Exp
#

DISTNAME=	netperf-2.1pl3
PKGNAME=	netperf-2.1.3
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.cup.hp.com/dist/networking/benchmarks/netperf/

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	netperf-21pl3-20000721.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	itojun@kame.net
HOMEPAGE=	http://www.netperf.org/
COMMENT=	Rick Jones' network performance benchmarking package

MAKEFILE=	makefile
MAN1=		netperf.1 netserver.1
MINSTALL=	${INSTALL} ${COPY} -o ${MANOWN} -g ${MANGRP} -m ${MANMODE}

BUILD_DEFS+=	USE_INET6
.include "../../mk/bsd.prefs.mk"
.if defined(USE_INET6) && ${USE_INET6} == "YES"
CFLAGS+=	-DDO_IPV6
.endif

post-install:
	strip ${PREFIX}/netperf/netperf
	strip ${PREFIX}/netperf/netserver
	${MINSTALL} ${WRKSRC}/netperf.man ${PREFIX}/man/man1/netperf.1
	${MINSTALL} ${WRKSRC}/netserver.man ${PREFIX}/man/man1/netserver.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/netperf
	${MINSTALL} ${WRKSRC}/netperf.ps ${PREFIX}/share/doc/netperf
	${GZIP_CMD} -9nf ${PREFIX}/share/doc/netperf/netperf.ps
.endif

.include "../../mk/bsd.pkg.mk"
