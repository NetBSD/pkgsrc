# $NetBSD: Makefile,v 1.3 1999/09/19 00:51:36 hubertf Exp $
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

MAKE_ENV+=		LIBDIR=${PREFIX}/lib NOLINT=1

post-extract:
	@cd ${WRKDIR} && ${SH} sdbm.shar >/dev/null

post-install:
	${INSTALL_DATA} ${WRKSRC}/sdbm.h ${PREFIX}/include/
	${INSTALL_MAN} ${WRKSRC}/sdbm.3 ${PREFIX}/man/man3/

.include "../../mk/bsd.pkg.mk"
