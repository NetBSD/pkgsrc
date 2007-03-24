# $NetBSD: Makefile,v 1.14 2007/03/24 19:21:20 joerg Exp $
#

DISTNAME=		sdbm
# this is the Dec. 1990 release with some race condition fixes from an
# unknown outside source:
PKGNAME=		sdbm-90.12.1
CATEGORIES=		databases
MASTER_SITES=		ftp://tsx-11.mit.edu/pub/linux/sources/libs/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Substitute DBM, an implementation of the `real' ndbm library

WRKSRC=			${WRKDIR}
MAKE_ENV+=		LIBDIR=${PREFIX}/lib NOLINT=1 \
			LIBOWN=${LIBOWN:Q} LIBGRP=${LIBGRP:Q}
INSTALLATION_DIRS=	include lib ${PKGMANDIR}/man3

post-extract:
	@cd ${WRKDIR} && ${SH} sdbm.shar >/dev/null

post-install:
	${INSTALL_DATA} ${WRKSRC}/sdbm.h ${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/sdbm.3 ${PREFIX}/${PKGMANDIR}/man3

.include "../../mk/bsd.pkg.mk"
