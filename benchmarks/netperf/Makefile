# $NetBSD: Makefile,v 1.4 2007/12/29 10:14:50 wiz Exp $
#

DISTNAME=	netperf-2.3pl1
PKGNAME=	netperf-2.3.1
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.cup.hp.com/dist/networking/benchmarks/netperf/archive/ \
		ftp://ftp.netperf.org/netperf/archive/ \
		ftp://ftp.cup.hp.com/dist/networking/benchmarks/netperf/ \
		ftp://ftp.netperf.org/netperf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.netperf.org/
COMMENT=	Rick Jones' network performance benchmarking package

USE_TOOLS+=	gzip
MAKE_FILE=	makefile

CFLAGS.IRIX+=	-DIRIX

post-install:
	strip ${PREFIX}/netperf/netperf
	strip ${PREFIX}/netperf/netserver
	${INSTALL_MAN} ${WRKSRC}/netperf.man ${PREFIX}/${PKGMANDIR}/man1/netperf.1
	${INSTALL_MAN} ${WRKSRC}/netserver.man ${PREFIX}/${PKGMANDIR}/man1/netserver.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/netperf
	${INSTALL_MAN} ${WRKSRC}/netperf.ps ${PREFIX}/share/doc/netperf
	${GZIP_CMD} ${PREFIX}/share/doc/netperf/netperf.ps

# The sources assume <malloc.h> exists.  Create a fake one for platforms
# that don't have it.
post-wrapper:
	if ${TEST} ! -f /usr/include/malloc.h; then		\
		${ECHO} "#include <stdlib.h>"			\
			> ${BUILDLINK_DIR}/include/malloc.h;	\
	fi

.include "../../mk/bsd.pkg.mk"
