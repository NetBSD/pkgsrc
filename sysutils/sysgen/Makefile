# $NetBSD: Makefile,v 1.2 2001/02/17 17:42:18 wiz Exp $
#

DISTNAME=	sysgen
PKGNAME=	sysgen-1.0
CATEGORIES=	systools
MASTER_SITES=	http://ox.compsoc.net/~dankolb/sysgen/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	abs@netbsd.org
COMMENT=	assign DEC Qbus or UNIBUS standard CSR and vector addresses

NO_WRKSUBDIR=	yes
ALL_TARGET=	sysgen

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sysgen ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sysgen.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
