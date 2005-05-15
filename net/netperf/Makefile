# $NetBSD: Makefile,v 1.14 2005/05/15 21:52:10 jlam Exp $
# KAME Id: Makefile,v 1.3 2000/01/21 12:34:29 itojun Exp
#

DISTNAME=	netperf-2.3pl1
PKGNAME=	netperf-2.3.1
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.cup.hp.com/dist/networking/benchmarks/netperf/

MAINTAINER=	itojun@kame.net
HOMEPAGE=	http://www.netperf.org/
COMMENT=	Rick Jones' network performance benchmarking package

PKGSRC_USE_TOOLS+=	gzip
MAKEFILE=		makefile

CFLAGS.IRIX+=	-DIRIX

post-install:
	strip ${PREFIX}/netperf/netperf
	strip ${PREFIX}/netperf/netserver
	${INSTALL_MAN} ${WRKSRC}/netperf.man ${PREFIX}/man/man1/netperf.1
	${INSTALL_MAN} ${WRKSRC}/netserver.man ${PREFIX}/man/man1/netserver.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/netperf
	${INSTALL_MAN} ${WRKSRC}/netperf.ps ${PREFIX}/share/doc/netperf
	${GZIP_CMD} ${PREFIX}/share/doc/netperf/netperf.ps

.include "../../mk/bsd.pkg.mk"
