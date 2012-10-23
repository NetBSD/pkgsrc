# $NetBSD: Makefile,v 1.23 2012/10/23 19:51:12 asau Exp $
#

DISTNAME=		memtester-4.3.0
CATEGORIES=		sysutils
MASTER_SITES=		${HOMEPAGE}old-versions/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://pyropus.ca/software/memtester/
COMMENT=		Utility for testing the memory subsystem for faults
LICENSE=		gnu-gpl-v2

NOT_FOR_PLATFORM=	Interix-*-* # no m[un]lock(2), so not useful anyway

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DJB_RESTRICTED=		NO
DJB_MAKE_TARGETS=	NO

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8 share/doc/memtester

do-install:
	cd ${WRKSRC} &&							\
	${INSTALL_PROGRAM} memtester ${DESTDIR}${PREFIX}/bin;		\
	${INSTALL_MAN} memtester.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8; \
	${INSTALL_DATA} README.tests ${DESTDIR}${PREFIX}/share/doc/memtester

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
