# $NetBSD: Makefile,v 1.1.1.1 1998/12/10 15:35:15 tv Exp $
#

DISTNAME=		sdbm
# this is the Dec. 1990 release with some race condition fixes from an
# unknown outside source:
PKGNAME=		sdbm-90.12.1
NO_WRKSUBDIR=		yes
CATEGORIES=		databases
MASTER_SITES=		ftp://tsx-11.mit.edu/pub/linux/sources/libs/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		packages@netbsd.org

MAKEFILE=		makefile
ALL_TARGET=		sdbm
MAKE_FLAGS=		CFLAGS="${CFLAGS} -DSDBM -DDUFF"

post-extract:
	@cd ${WRKDIR} && ${SH} sdbm.shar >/dev/null

do-install:
	${INSTALL_DATA} ${WRKSRC}/libsdbm.a ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/sdbm.h ${PREFIX}/include/
	${INSTALL_MAN} ${WRKSRC}/sdbm.3 ${PREFIX}/man/man3/

.include "../../mk/bsd.pkg.mk"
