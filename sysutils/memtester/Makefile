# $NetBSD: Makefile,v 1.4 2004/08/10 05:20:54 schmonz Exp $
#

DISTNAME=		memtester-4.0.2
CATEGORIES=		sysutils
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.qcc.ca/~charlesc/software/memtester/
COMMENT=		Utility for testing the memory subsystem for faults

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes

INSTALLATION_DIRS=	bin man/man8 share/doc/memtester

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/memtester ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/memtester.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/README.tests ${PREFIX}/share/doc/memtester

.include "../../mk/bsd.pkg.mk"
