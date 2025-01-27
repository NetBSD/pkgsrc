# $NetBSD: Makefile,v 1.30 2025/01/27 20:47:19 rillig Exp $
#

DISTNAME=	skampi
PKGNAME=	skampi-5.0.4.355
CATEGORIES=	benchmarks parallel
#MASTER_SITES=	http://liinwww.ira.uka.de/~skampi/download/
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://liinwww.ira.uka.de/~skampi/
COMMENT=	MPI (Message Passing Interface) benchmarks
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/skampi-5.0.4-r0355

USE_TOOLS+=		gmake pax
BUILD_TARGET=		skampi
INSTALLATION_DIRS=	bin

# Force file regeneration:
post-extract:
	rm ${WRKSRC}/Makefile.dep

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/skampi ${DESTDIR}${PREFIX}/bin/skampi
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/skampi
	(cd ${WRKSRC} && pax -rw ski ${DESTDIR}${PREFIX}/share/skampi)
	(cd ${WRKSRC} && pax -rw doc ${DESTDIR}${PREFIX}/share/skampi)

.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
