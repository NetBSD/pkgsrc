# $NetBSD: Makefile,v 1.4 2002/03/15 04:57:31 hubertf Exp $
#

DISTNAME=	sysgen
PKGNAME=	sysgen-1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://ox.compsoc.net/~dankolb/sysgen/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	abs@netbsd.org
COMMENT=	assign DEC Qbus or UNIBUS standard CSR and vector addresses

WRKSRC=		${WRKDIR}
ALL_TARGET=	sysgen

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sysgen ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sysgen.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
