# $NetBSD: Makefile,v 1.12 2009/02/13 22:24:14 abs Exp $
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

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
PKG_DESTDIR_SUPPORT=	user-destdir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sysgen ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sysgen.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
