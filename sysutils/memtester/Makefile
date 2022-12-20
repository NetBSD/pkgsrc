# $NetBSD: Makefile,v 1.31 2022/12/20 20:56:11 schmonz Exp $
#

DISTNAME=		memtester-4.6.0
CATEGORIES=		sysutils
MASTER_SITES=		${HOMEPAGE}old-versions/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://pyropus.ca/software/memtester/
COMMENT=		Utility for testing the memory subsystem for faults
LICENSE=		gnu-gpl-v2

DJB_MAKE_TARGETS=	NO

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8 share/doc/memtester

do-install:
	cd ${WRKSRC} &&							\
	${INSTALL_PROGRAM} memtester ${DESTDIR}${PREFIX}/bin;		\
	${INSTALL_MAN} memtester.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8; \
	${INSTALL_DATA} README.tests ${DESTDIR}${PREFIX}/share/doc/memtester

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
