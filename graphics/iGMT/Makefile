# $NetBSD: Makefile,v 1.23 2005/06/16 06:57:58 jlam Exp $

DISTNAME=		igmt_v1.2
PKGNAME=		iGMT-1.2
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		http://op.gfz-potsdam.de/igmt/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://op.gfz-potsdam.de/igmt/
COMMENT=		Interactive Mapping of Geoscientific Datasets

DEPENDS+=		GMT>=3.3.6:../../graphics/GMT
DEPENDS+=		tcl>=8.0:../../lang/tcl
DEPENDS+=		tk>=8.0:../../x11/tk
DEPENDS+=		gv-[0-9]*:../../print/gv
DEPENDS+=		ImageMagick>=5.3.9nb1:../../graphics/ImageMagick

WRKSRC=			${WRKDIR}/igmt_1.2
NO_BUILD=		yes

GMT_PREFIX_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=		GMT_PREFIX=GMT
EVAL_PREFIX+=		TK_PREFIX=tk
INSTALLATION_DIRS=	bin

.include "../../mk/x11.buildlink3.mk"

do-configure:
	for i in ${WRKSRC}/igmt ${WRKSRC}/igmt_configure.tcl; do	\
		${SED} -e 's:@PREFIX@:'${PREFIX}':g'			\
		       -e 's:@GMT_PREFIX@:'${GMT_PREFIX}':g'		\
		       -e 's:@TK_PREFIX@:'${TK_PREFIX}':g'		\
		$$i > $$i.tmp && ${MV} -f $$i.tmp $$i;			\
	done

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/igmt ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/igmt
	cd ${WRKSRC} && ${INSTALL_DATA} manual.ps README.TXT NOTES.TXT 	\
		COPYING COPYRIGHT ${PREFIX}/share/igmt/
	${INSTALL_DATA_DIR} ${PREFIX}/share/igmt/colormaps
	${INSTALL_DATA} ${WRKSRC}/colormaps/* ${PREFIX}/share/igmt/colormaps/
	cd ${WRKSRC} && ${INSTALL_SCRIPT} igmt*.tcl *.awk 		\
		igmt_helper* *.batch ${PREFIX}/share/igmt/
	cd ${WRKSRC} && ${INSTALL_DATA} 01_02-98.cmt			\
		gps.vel hotspots.dat nuvel.yx igmt_def.gif		\
		allslabs_rum.gmt volcanoes.dat wcity.dat		\
		wcity_major.dat	igmt_gmtdefaults_3.0			\
		igmt_gmtdefaults_3.1 igmt_gmtdefaults_3.2		\
		igmt_gmtdefaults_3.3 ${PREFIX}/share/igmt/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/igmt
	cd ${WRKSRC} && ${INSTALL_DATA} example*.ps.gz			\
		${WRKSRC}/example*.dat ${PREFIX}/share/examples/igmt/

.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
