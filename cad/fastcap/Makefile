# $NetBSD: Makefile,v 1.3 1998/09/14 17:15:05 agc Exp $
#

DISTNAME=	fastcap-2.0-15Jul92
PKGNAME=	fastcap-2.0.19920715
WRKSRC=		${WRKDIR}/fastcap
CATEGORIES=	cad
MASTER_SITES=	ftp://rle-vlsi.mit.edu/pub/fastcap/
DISTFILES=	fastcap-2.0-15Jul92.tar.Z \
		postscript/ug.ps.Z \
		postscript/mtt.ps.Z \
		postscript/tcad.ps.Z

MAINTAINER=	mcmahill@alum.mit.edu
HOMEPAGE=	http://kontiki.mit.edu/rle/research/info_research_proj.html

DIST_SUBDIR=	fastcap
EXTRACT_ONLY=	fastcap-2.0-15Jul92.tar.Z
IGNOREFILES=	postscript/ug.ps.Z \
		postscript/mtt.ps.Z \
		postscript/tcad.ps.Z

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	config
CONFIGURE_ARGS=		4

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/fastcap ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/cubegen ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/capgen ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/busgen ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pipedgen ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pyragen ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/1x1bus.lst ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/1x1coarse.neu ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/1x1fine.neu ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/1x1nonuni.neu ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/README ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/big_sphere1.neu ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/coated_sph.lst ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/cond_air_1x1.qui ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/cond_dielec_1x1.qui ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/connector2.sh ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/connector3.sh ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/connector4.sh ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/cubeeg.fig ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/dielec_face.neu ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/dielec_sides.neu ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/dielec_sides_2x2.neu ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/dielec_topbot.neu ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/pin ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/pipeeg.fig ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/ramcell.lst ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/ramcell.out ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/ramcell_bitl.neu ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/ramcell_botd.neu ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/ramcell_cond.neu ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/ramcell_gnd.neu ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/ramcell_test.neu ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/ramcell_topd.neu ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/ramgen.sh ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/sphere1.neu ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/sphere2.neu ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/sphere3.neu ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/testgen.sh ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/testrun.sh ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/via.neu ${PREFIX}/share/examples/fastcap
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fastcap
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/mtt.ps.Z ${PREFIX}/share/doc/fastcap
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/tcad.ps.Z ${PREFIX}/share/doc/fastcap
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/ug.ps.Z ${PREFIX}/share/doc/fastcap
.for file in mtt.ps.Z tcad.ps.Z ug.ps.Z
	uncompress -f ${PREFIX}/share/doc/fastcap/${file}
.endfor
	${INSTALL_DATA} ${WRKSRC}/README.docs ${PREFIX}/share/doc/fastcap

.include "../../mk/bsd.pkg.mk"
