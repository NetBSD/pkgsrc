# $NetBSD: Makefile,v 1.1.1.1 2003/03/19 17:24:20 jschauma Exp $
#

DISTNAME=	skampi4
PKGNAME=	skampi-4.0
CATEGORIES=	benchmarks parallel
MASTER_SITES=	http://liinwww.ira.uka.de/~skampi/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}_userman.ps.gz
DISTFILES+=	skampili.ps

MAINTAINER=	jschauma@netbsd.org
HOMEPAGE=	http://liinwww.ira.uka.de/~skampi/
COMMENT=	SHORT_DESCRIPTION_OF_THE_PACKAGE

DEPENDS=	mpich>=1.2.1:../../parallel/mpi-ch
DEPENDS+=	gnuplot>=3.7.1:../../graphics/gnuplot
DEPENDS+=	teTeX>=1.0.7:../../print/teTeX

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_PERL5=	run
REPLACE_PERL=	${WRKSRC}/report_generator/dorep4.pl

do-build:
	${GUNZIP_CMD} ${DISTDIR}/${DISTNAME}_userman.ps.gz -c > \
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
	${INSTALL_DATA} ${DISTDIR}/skampili.ps ${PREFIX}/share/doc/skampi/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/skampi
	${INSTALL_DATA} ${WRKSRC}/.skampi 			\
		${PREFIX}/share/examples/skampi/dot.skampi
	${INSTALL_DATA} ${WRKSRC}/.skampi-all-collectives 	\
		${PREFIX}/share/examples/skampi/dot.skampi-all-collectives
	${INSTALL_DATA} ${WRKSRC}/.skampi-dt-long 		\
		${PREFIX}/share/examples/skampi/dot.skampi-dt-long
	${INSTALL_DATA} ${WRKSRC}/.skampi-dt-short 		\
		${PREFIX}/share/examples/skampi/dot.skampi-dt-short

.include "../../mk/bsd.pkg.mk"
