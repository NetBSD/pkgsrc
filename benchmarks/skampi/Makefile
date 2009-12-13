# $NetBSD: Makefile,v 1.22 2009/12/13 01:34:45 asau Exp $
#

DISTNAME=	skampi
PKGNAME=	skampi-5.0.4.355
CATEGORIES=	benchmarks parallel
MASTER_SITES=	http://liinwww.ira.uka.de/~skampi/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://liinwww.ira.uka.de/~skampi/
COMMENT=	MPI (Message Passing Interface) benchmarks
LICENSE=	gnu-gpl-v2

#DEPENDS+=	gnuplot>=3.7.1:../../graphics/gnuplot	# optional

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/skampi-5.0.4-r0355

USE_TOOLS+=	gmake pax
BUILD_TARGET=	skampi
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/skampi ${DESTDIR}${PREFIX}/bin/skampi
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/skampi
	(cd ${WRKSRC} && pax -rw ski ${DESTDIR}${PREFIX}/share/skampi)
	(cd ${WRKSRC} && pax -rw doc ${DESTDIR}${PREFIX}/share/skampi)

.include "../../parallel/mpi-ch/buildlink3.mk"
#.include "../../parallel/openmpi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
