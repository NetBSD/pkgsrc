# $NetBSD: Makefile,v 1.7 2009/07/08 14:28:28 joerg Exp $
#

DISTNAME=	netperf-2.3pl1
PKGNAME=	netperf-2.3.1
PKGREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.cup.hp.com/dist/networking/benchmarks/netperf/archive/ \
		ftp://ftp.netperf.org/netperf/archive/ 

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.netperf.org/
COMMENT=	Rick Jones' network performance benchmarking package

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gzip
MAKE_FILE=	makefile

CFLAGS.IRIX+=	-DIRIX

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/doc/netperf

post-install:
	${INSTALL_MAN} ${WRKSRC}/netperf.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/netperf.1
	${INSTALL_MAN} ${WRKSRC}/netserver.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/netserver.1
	${INSTALL_MAN} ${WRKSRC}/netperf.ps ${DESTDIR}${PREFIX}/share/doc/netperf
	${GZIP_CMD} ${DESTDIR}${PREFIX}/share/doc/netperf/netperf.ps

# The sources assume <malloc.h> exists.  Create a fake one for platforms
# that don't have it.
post-wrapper:
	if ${TEST} ! -f /usr/include/malloc.h; then		\
		${ECHO} "#include <stdlib.h>"			\
			> ${BUILDLINK_DIR}/include/malloc.h;	\
	fi

.include "../../mk/bsd.pkg.mk"
