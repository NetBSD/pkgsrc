# $NetBSD: Makefile,v 1.6 2003/07/17 22:53:53 grant Exp $
#

DISTNAME=	sysgen
PKGNAME=	sysgen-1.0
WRKSRC=		${WRKDIR}
CATEGORIES=	sysutils
MASTER_SITES=	http://ox.compsoc.net/~dankolb/sysgen/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	abs@NetBSD.org
COMMENT=	assign DEC Qbus or UNIBUS standard CSR and vector addresses

ALL_TARGET=	sysgen

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sysgen ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sysgen.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
