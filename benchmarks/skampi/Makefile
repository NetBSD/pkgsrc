# $NetBSD: Makefile,v 1.25 2012/09/11 22:37:14 asau Exp $
#

DISTNAME=	skampi
PKGNAME=	skampi-5.0.4.355
CATEGORIES=	benchmarks parallel
MASTER_SITES=	http://liinwww.ira.uka.de/~skampi/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://liinwww.ira.uka.de/~skampi/
COMMENT=	MPI (Message Passing Interface) benchmarks
LICENSE=	gnu-gpl-v2

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}/skampi-5.0.4-r0355

USE_TOOLS+=	gmake pax
BUILD_TARGET=	skampi
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/skampi ${DESTDIR}${PREFIX}/bin/skampi
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/skampi
	(cd ${WRKSRC} && pax -rw ski ${DESTDIR}${PREFIX}/share/skampi)
	(cd ${WRKSRC} && pax -rw doc ${DESTDIR}${PREFIX}/share/skampi)

.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
