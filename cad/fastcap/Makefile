# $NetBSD: Makefile,v 1.24 2005/06/16 06:57:41 jlam Exp $
#

DISTNAME=	fastcap-2.0-18Sep92
PKGNAME=	fastcap-2.0.19920918
CATEGORIES=	cad
MASTER_SITES=	http://www.rle.mit.edu/cpg/codes/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.rle.mit.edu/cpg/research_codes.htm
COMMENT=	Fast 3-D capacitance solver

BUILD_DEPENDS+=	teTeX>=1.0.7:../../print/teTeX
EXTRACT_USING=	gtar	# cannot be extracted with pax as tar

WRKSRC=			${WRKDIR}
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./config
CONFIGURE_ARGS=		4

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=		2.95.3
.endif

INSTALLATION_DIRS=	bin

post-patch:
	${CHMOD} 755 ${WRKSRC}/config

post-build:
	cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} manual
.for file in mtt tcad ug
	cd ${WRKSRC}/doc && dvips -o ${file}.ps ${file}.dvi
.endfor

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
	${INSTALL_DATA} ${WRKSRC}/doc/mtt.ps  ${PREFIX}/share/doc/fastcap
	${INSTALL_DATA} ${WRKSRC}/doc/tcad.ps  ${PREFIX}/share/doc/fastcap
	${INSTALL_DATA} ${WRKSRC}/doc/ug.ps  ${PREFIX}/share/doc/fastcap
	${INSTALL_DATA} ${WRKSRC}/README.docs ${PREFIX}/share/doc/fastcap

.include "../../mk/bsd.pkg.mk"
