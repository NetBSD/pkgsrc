# $NetBSD: Makefile,v 1.2 2004/07/28 16:03:47 schmonz Exp $
#

DISTNAME=	memtester-2.93.1
CATEGORIES=	sysutils
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.qcc.ca/~charlesc/software/memtester/
COMMENT=	Utility to test for faulty memory subsystem

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		yes

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/memtest ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/memtest.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
