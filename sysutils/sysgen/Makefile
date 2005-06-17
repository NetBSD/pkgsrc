# $NetBSD: Makefile,v 1.10 2005/06/17 03:50:35 jlam Exp $
#

DISTNAME=	sysgen
PKGNAME=	sysgen-1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://ox.compsoc.net/~dankolb/sysgen/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	abs@NetBSD.org
COMMENT=	Assign DEC Qbus or UNIBUS standard CSR and vector addresses

WRKSRC=		${WRKDIR}
BUILD_TARGET=	sysgen

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sysgen ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sysgen.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
