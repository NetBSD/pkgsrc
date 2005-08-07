# $NetBSD: Makefile,v 1.11 2005/08/07 11:56:01 schmonz Exp $
#

DISTNAME=		memtester-4.0.5
CATEGORIES=		sysutils
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://pyropus.ca/software/memtester/
COMMENT=		Utility for testing the memory subsystem for faults

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_TARGET=		all

DJB_RESTRICTED=		NO

INSTALLATION_DIRS=	bin man/man8 share/doc/memtester

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/memtester ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/memtester.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/README.tests ${PREFIX}/share/doc/memtester

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
