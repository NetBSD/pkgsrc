# $NetBSD: Makefile,v 1.10 2004/05/16 17:04:42 minskim Exp $
#

DISTNAME=		sdbm
# this is the Dec. 1990 release with some race condition fixes from an
# unknown outside source:
PKGNAME=		sdbm-90.12.1
CATEGORIES=		databases
MASTER_SITES=		ftp://tsx-11.mit.edu/pub/linux/sources/libs/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Substitute DBM, an implementation of the `real' ndbm library

WRKSRC=			${WRKDIR}
MAKE_ENV+=		LIBDIR=${PREFIX}/lib NOLINT=1 \
			LIBOWN=${LIBOWN} LIBGRP=${LIBGRP}

post-extract:
	@cd ${WRKDIR} && ${SH} sdbm.shar >/dev/null

post-install:
	${INSTALL_DATA} ${WRKSRC}/sdbm.h ${PREFIX}/include/
	${INSTALL_MAN} ${WRKSRC}/sdbm.3 ${PREFIX}/man/man3/

.include "../../mk/bsd.pkg.mk"
