# $NetBSD: Makefile,v 1.10 2005/04/11 21:47:25 tv Exp $
#

DISTNAME=		memtester-4.0.5
CATEGORIES=		sysutils
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://pyropus.ca/software/memtester/
COMMENT=		Utility for testing the memory subsystem for faults

PKG_INSTALLATION_TYPES=	overwrite pkgviews


INSTALLATION_DIRS=	bin man/man8 share/doc/memtester

do-configure:
	${ECHO} ${CC:Q} ${CFLAGS:Q} > ${WRKSRC}/conf-cc
	${ECHO} ${CC:Q} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/memtester ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/memtester.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/README.tests ${PREFIX}/share/doc/memtester

.include "../../mk/bsd.pkg.mk"
