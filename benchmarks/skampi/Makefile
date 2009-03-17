# $NetBSD: Makefile,v 1.21 2009/03/17 21:40:44 darcy Exp $
#

DISTNAME=	skampi4
PKGNAME=	skampi-4.0.1
PKGREVISION=	3
CATEGORIES=	benchmarks parallel
MASTER_SITES=	http://liinwww.ira.uka.de/~skampi/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}_userman.ps.gz
DISTFILES+=	skampili.ps

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://liinwww.ira.uka.de/~skampi/
COMMENT=	MPI (Message Passing Interface) benchmarks

DEPENDS+=	gnuplot>=3.7.1:../../graphics/gnuplot
TEX_ACCEPTED=	teTeX3

PKG_DESTDIR_SUPPORT=	user-destdir

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_TOOLS+=	pax perl:run
REPLACE_PERL=	report_generator/dorep4.pl
DIST_SUBDIR=	${PKGNAME_NOREV}

INSTALLATION_DIRS=	bin

do-build:
	${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}_userman.ps.gz > \
		${WRKSRC}/${DISTNAME}_userman.ps
	(cd ${WRKSRC} &&					\
		${PREFIX}/bin/mpicc -o skosfile skosfile.c -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/skosfile ${DESTDIR}${PREFIX}/bin/skosfile
	${INSTALL_SCRIPT} ${WRKSRC}/report_generator/dorep4.pl 	\
		${DESTDIR}${PREFIX}/bin/dorep4.pl
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/skampi/dri
	(cd ${WRKSRC}/report_generator/dri && 			\
		pax -rw . ${DESTDIR}${PREFIX}/share/skampi/dri)
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/skampi
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}_userman.ps 	\
		${DESTDIR}${PREFIX}/share/doc/skampi/
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/skampili.ps 	\
		${DESTDIR}${PREFIX}/share/doc/skampi/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/skampi
	${INSTALL_DATA} ${WRKSRC}/.skampi 			\
		${DESTDIR}${PREFIX}/share/examples/skampi/dot.skampi
	${INSTALL_DATA} ${WRKSRC}/.skampi-all-collectives 	\
		${DESTDIR}${PREFIX}/share/examples/skampi/dot.skampi-all-collectives
	${INSTALL_DATA} ${WRKSRC}/.skampi-dt-long 		\
		${DESTDIR}${PREFIX}/share/examples/skampi/dot.skampi-dt-long
	${INSTALL_DATA} ${WRKSRC}/.skampi-dt-short 		\
		${DESTDIR}${PREFIX}/share/examples/skampi/dot.skampi-dt-short

.include "../../parallel/mpi-ch/buildlink3.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
