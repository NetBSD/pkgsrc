# $NetBSD: Makefile,v 1.13 2005/11/01 19:01:17 tv Exp $
#

DISTNAME=		memtester-4.0.5
CATEGORIES=		sysutils
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://pyropus.ca/software/memtester/
COMMENT=		Utility for testing the memory subsystem for faults

NOT_FOR_PLATFORM=	Interix-*-* # no m[un]lock(2), so not useful anyway

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DJB_RESTRICTED=		NO
DJB_MAKE_TARGETS=	NO

INSTALLATION_DIRS=	bin man/man8 share/doc/memtester

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/memtester ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/memtester.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/README.tests ${PREFIX}/share/doc/memtester

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
