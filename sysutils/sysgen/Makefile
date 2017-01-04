# $NetBSD: Makefile,v 1.14 2017/01/04 20:44:25 abs Exp $

DISTNAME=	sysgen
PKGNAME=	sysgen-20151230
CATEGORIES=	sysutils
MASTER_SITES=	http://minnie.tuhs.org/Archive/tools/Misc/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	abs@NetBSD.org
COMMENT=	Assign DEC Qbus or UNIBUS standard CSR and vector addresses
LICENSE=	public-domain

WRKSRC=		${WRKDIR}
BUILD_TARGET=	sysgen
DIST_SUBDIR=	sysgen

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sysgen ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sysgen.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
