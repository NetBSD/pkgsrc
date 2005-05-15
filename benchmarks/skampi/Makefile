# $NetBSD: Makefile,v 1.10 2005/05/15 04:29:48 jlam Exp $
#

DISTNAME=	skampi4
PKGNAME=	skampi-4.0.1
PKGREVISION=	2
CATEGORIES=	benchmarks parallel
MASTER_SITES=	http://liinwww.ira.uka.de/~skampi/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}_userman.ps.gz
DISTFILES+=	skampili.ps

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://liinwww.ira.uka.de/~skampi/
COMMENT=	MPI (Message Passing Interface) benchmarks

DEPENDS+=	gnuplot>=3.7.1:../../graphics/gnuplot
DEPENDS+=	teTeX>=1.0.7:../../print/teTeX

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_PERL5=	run
REPLACE_PERL=	report_generator/dorep4.pl
DIST_SUBDIR=	${PKGNAME_NOREV}

do-build:
	${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}_userman.ps.gz > \
		${WRKSRC}/${DISTNAME}_userman.ps
	(cd ${WRKSRC} &&					\
		${PREFIX}/bin/mpicc -o skosfile skosfile.c -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/skosfile ${PREFIX}/bin/skosfile
	${INSTALL_SCRIPT} ${WRKSRC}/report_generator/dorep4.pl 	\
		${PREFIX}/bin/dorep4.pl
	${INSTALL_DATA_DIR} ${PREFIX}/share/skampi/dri
	(cd ${WRKSRC}/report_generator/dri && 			\
		${PAX} -rw . ${PREFIX}/share/skampi/dri)
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/skampi
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}_userman.ps 	\
		${PREFIX}/share/doc/skampi/
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/skampili.ps 	\
		${PREFIX}/share/doc/skampi/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/skampi
	${INSTALL_DATA} ${WRKSRC}/.skampi 			\
		${PREFIX}/share/examples/skampi/dot.skampi
	${INSTALL_DATA} ${WRKSRC}/.skampi-all-collectives 	\
		${PREFIX}/share/examples/skampi/dot.skampi-all-collectives
	${INSTALL_DATA} ${WRKSRC}/.skampi-dt-long 		\
		${PREFIX}/share/examples/skampi/dot.skampi-dt-long
	${INSTALL_DATA} ${WRKSRC}/.skampi-dt-short 		\
		${PREFIX}/share/examples/skampi/dot.skampi-dt-short

.include "../../parallel/mpi-ch/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
