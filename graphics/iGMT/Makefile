# $NetBSD: Makefile,v 1.1.1.1 2001/01/29 04:32:11 jtb Exp $

DISTNAME=		igmt_v1.2
PKGNAME=		iGMT-1.2
CATEGORIES=		graphics
MASTER_SITES=		http://op.gfz-potsdam.de/igmt/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://op.gfz-potsdam.de/igmt/

DEPENDS+=		GMT-3.3.6:../../graphics/GMT
DEPENDS+=		tcl-[0-9]*:../../lang/tcl
DEPENDS+=		tk-[0-9]*:../../lang/tk
DEPENDS+=		ghostscript-[0-9]*:../../print/ghostscript
DEPENDS+=		gv-[0-9]*:../../print/gv
DEPENDS+=		ImageMagick-[0-9]*:../../graphics/ImageMagick

WRKSRC=			${WRKDIR}/igmt_1.2
NO_BUILD=		YES
EVAL_PREFIX+=		GMT_PREFIX=GMT TK_PREFIX=tk

post-patch:
	${RM} ${WRKSRC}/*.orig ${WRKSRC}/configure_script

do-configure:
	for i in ${WRKSRC}/igmt ${WRKSRC}/igmt_configure.tcl; do	\
		${SED} -e 's:@PREFIX@:'${PREFIX}':g'			\
		       -e 's:@GMT_PREFIX@:'${GMT_PREFIX}':g'		\
		       -e 's:@TK_PREFIX@:'${TK_PREFIX}':g'		\
		< $$i > $$i.tmp && ${MV} -f $$i.tmp $$i;		\
	done

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/igmt ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/igmt
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/igmt
	@for f in manual.ps README.TXT NOTES.TXT COPYING COPYRIGHT; do		\
		i="${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/doc/igmt/"; \
		${ECHO} $$i; $$i; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/igmt/colormaps
	@for f in ${WRKSRC}/colormaps/*; do				 \
		i="${INSTALL_DATA} $$f ${PREFIX}/share/igmt/colormaps/"; \
		${ECHO} $$i; $$i;					 \
	done
	@for f in ${WRKSRC}/igmt*.tcl ${WRKSRC}/*.awk; do \
		i="${INSTALL_DATA} $$f ${PREFIX}/share/igmt/"; \
		${ECHO} $$i; $$i; \
	done
	@for f in 01_02-98.cmt gps.vel hotspots.dat nuvel.yx		 \
	igmt_def.gif allslabs_rum.gmt volcanoes.dat wcity.dat		 \
	wcity_major.dat	igmt_gmtdefaults_3.0 igmt_gmtdefaults_3.1	 \
	igmt_gmtdefaults_3.2 igmt_gmtdefaults_3.3; do			 \
		i="${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/igmt/"; \
		${ECHO} $$i; $$i;					 \
	done
	@for f in ${WRKSRC}/igmt_helper* ${WRKSRC}/*.batch; do		\
		i="${INSTALL_SCRIPT} $$f ${PREFIX}/share/igmt/";	\
		${ECHO} $$i; $$i;					\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/igmt
	@for f in ${WRKSRC}/example*.ps.gz ${WRKSRC}/example*.dat; do \
		i="${INSTALL_DATA} $$f ${PREFIX}/share/examples/igmt/"; \
		${ECHO} $$i; $$i; \
	done

.include "../../mk/bsd.pkg.mk"
