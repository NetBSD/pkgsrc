# $NetBSD: Makefile,v 1.33 2009/02/25 17:03:03 minskim Exp $
#

DISTNAME=	fastcap-2.0-18Sep92
PKGNAME=	fastcap-2.0.19920918
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.rle.mit.edu/cpg/codes/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.rle.mit.edu/cpg/research_codes.htm
COMMENT=	Fast 3-D capacitance solver

BUILD_DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk

PKG_DESTDIR_SUPPORT=	user-destdir

EXTRACT_USING=		bsdtar

WRKSRC=			${WRKDIR}
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./config
CONFIGURE_ARGS+=	4
TEX_DEPMETHOD=	build
TEX_ACCEPTED=		teTeX3

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
	${INSTALL_PROGRAM} ${WRKSRC}/bin/fastcap ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/cubegen ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/capgen ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/busgen ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pipedgen ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pyragen ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/1x1bus.lst ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/1x1coarse.neu ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/1x1fine.neu ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/1x1nonuni.neu ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/README ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/big_sphere1.neu ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/coated_sph.lst ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/cond_air_1x1.qui ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/cond_dielec_1x1.qui ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/connector2.sh ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/connector3.sh ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/connector4.sh ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/cubeeg.fig ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/dielec_face.neu ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/dielec_sides.neu ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/dielec_sides_2x2.neu ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/dielec_topbot.neu ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/pin ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/pipeeg.fig ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/ramcell.lst ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/ramcell.out ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/ramcell_bitl.neu ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/ramcell_botd.neu ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/ramcell_cond.neu ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/ramcell_gnd.neu ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/ramcell_test.neu ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/ramcell_topd.neu ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/ramgen.sh ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/sphere1.neu ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/sphere2.neu ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/sphere3.neu ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/testgen.sh ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/testrun.sh ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA} ${WRKSRC}/examples/via.neu ${DESTDIR}${PREFIX}/share/examples/fastcap
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/fastcap
	${INSTALL_DATA} ${WRKSRC}/doc/mtt.ps  ${DESTDIR}${PREFIX}/share/doc/fastcap
	${INSTALL_DATA} ${WRKSRC}/doc/tcad.ps  ${DESTDIR}${PREFIX}/share/doc/fastcap
	${INSTALL_DATA} ${WRKSRC}/doc/ug.ps  ${DESTDIR}${PREFIX}/share/doc/fastcap
	${INSTALL_DATA} ${WRKSRC}/README.docs ${DESTDIR}${PREFIX}/share/doc/fastcap

.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
