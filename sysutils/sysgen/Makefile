# $NetBSD: Makefile,v 1.1.1.1 2000/10/19 12:05:59 abs Exp $
#

DISTNAME=	sysgen
PKGNAME=	sysgen-1.0
CATEGORIES=	systools
MASTER_SITES=	http://ox.compsoc.net/~dankolb/sysgen/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	abs@netbsd.org

NO_WRKSUBDIR=	yes
ALL_TARGET=	sysgen

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sysgen ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sysgen.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
