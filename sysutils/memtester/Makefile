# $NetBSD: Makefile,v 1.17 2007/11/21 18:41:19 xtraeme Exp $
#

DISTNAME=		memtester-4.0.8
CATEGORIES=		sysutils
MASTER_SITES=		${HOMEPAGE}old-versions/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://pyropus.ca/software/memtester/
COMMENT=		Utility for testing the memory subsystem for faults

NOT_FOR_PLATFORM=	Interix-*-* # no m[un]lock(2), so not useful anyway

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DJB_RESTRICTED=		NO
DJB_MAKE_TARGETS=	NO

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8 share/doc/memtester

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/memtester ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/memtester.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/README.tests ${PREFIX}/share/doc/memtester

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
