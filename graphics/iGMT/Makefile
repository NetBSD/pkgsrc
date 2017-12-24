# $NetBSD: Makefile,v 1.36 2017/12/24 09:52:51 wiz Exp $

DISTNAME=		igmt_v1.2
PKGNAME=		iGMT-1.2
PKGREVISION=		6
CATEGORIES=		graphics
MASTER_SITES=		https://www.gfz-potsdam.de/pb1/op/igmt/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gfz-potsdam.de/pb1/op/igmt/
COMMENT=		Interactive Mapping of Geoscientific Datasets

DEPENDS+=		GMT>=3.3.6:../../graphics/GMT
DEPENDS+=		tcl>=8.0:../../lang/tcl
DEPENDS+=		tk>=8.0:../../x11/tk
DEPENDS+=		gv-[0-9]*:../../print/gv
DEPENDS+=		ImageMagick>=5.3.9nb1:../../graphics/ImageMagick

WRKSRC=			${WRKDIR}/igmt_1.2
NO_BUILD=		yes

USE_TOOLS+=		gs:run ksh:run

REPLACE_KSH=		igmt igmt_helper* img2latlongrd.batch

INSTALLATION_DIRS=	bin

do-configure:
	for i in ${WRKSRC}/igmt ${WRKSRC}/igmt_configure.tcl; do	\
		${SED} -e 's:@PREFIX@:'${PREFIX}':g'			\
		       -e 's:@GMT_PREFIX@:'${LOCALBASE}':g'		\
		       -e 's:@TK_PREFIX@:'${LOCALBASE}':g'		\
		$$i > $$i.tmp && ${MV} -f $$i.tmp $$i;			\
	done

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/igmt ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/igmt
	cd ${WRKSRC} && ${INSTALL_DATA} manual.ps README.TXT NOTES.TXT 	\
		COPYING COPYRIGHT ${DESTDIR}${PREFIX}/share/igmt/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/igmt/colormaps
	${INSTALL_DATA} ${WRKSRC}/colormaps/*				\
		${DESTDIR}${PREFIX}/share/igmt/colormaps/
	cd ${WRKSRC} && ${INSTALL_SCRIPT} igmt*.tcl *.awk 		\
		igmt_helper* *.batch ${DESTDIR}${PREFIX}/share/igmt/
	cd ${WRKSRC} && ${INSTALL_DATA} 01_02-98.cmt			\
		gps.vel hotspots.dat nuvel.yx igmt_def.gif		\
		allslabs_rum.gmt volcanoes.dat wcity.dat		\
		wcity_major.dat	igmt_gmtdefaults_3.0			\
		igmt_gmtdefaults_3.1 igmt_gmtdefaults_3.2		\
		igmt_gmtdefaults_3.3 ${DESTDIR}${PREFIX}/share/igmt/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/igmt
	cd ${WRKSRC} && ${INSTALL_DATA} example*.ps.gz			\
		${WRKSRC}/example*.dat					\
		${DESTDIR}${PREFIX}/share/examples/igmt/

.include "../../mk/bsd.pkg.mk"
