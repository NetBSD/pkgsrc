# $NetBSD: Makefile,v 1.7 2002/02/07 11:39:52 wiz Exp $
#

DISTNAME=	heretic2-demo-x86
PKGNAME=	heretic2-demo-2.0
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.linuxgames.com/loki/demos/heretic2/ \
		ftp://download.linuxlords.com/pub/demos/heretic2/ \
		ftp://ftp.linux.tucows.com/pub/Loki/demos/heretic2/
EXTRACT_SUFX=	.run

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://www.lokigames.com/products/heretic2/demo.php3
COMMENT=	Heretic2 - first person Quake 3D engine based (linux demo)

NO_CONFIGURE=	yes
WRKSRC=		${WRKDIR}
EXTRACT_CMD=	${SED} '1,/^END_OF_STUB$$/d' ${DOWNLOADED_DISTFILE} | \
								${GTAR} xzf -

ONLY_FOR_PLATFORM=*-*-i386

DISTBINNAME=	heretic2_demo.x86
BINNAME=	heretic2-demo

DIST_SUBDIR=	lokigames
LIBDIR=		${PREFIX}/lib/lokigames/${BINNAME}
SHAREDIR=	${PREFIX}/share/doc/lokigames

do-build:
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' \
	       -e 's#@@LIBDIR@@#${LIBDIR}#g' \
	       -e 's#@@BINNAME@@#${BINNAME}#g' \
	    <${FILESDIR}/wrapper.sh >${WRKDIR}/${BINNAME}.sh

# The executable must be in the same directory as the data.
do-install:
	${INSTALL_PROGRAM_DIR} ${LIBDIR}
	${INSTALL_DATA_DIR} ${SHAREDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${BINNAME}.sh ${PREFIX}/bin/${BINNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTBINNAME} ${LIBDIR}/${BINNAME}
	${INSTALL_DATA} ${WRKSRC}/README ${SHAREDIR}/${BINNAME}-QuickStart.txt
	${INSTALL_DATA} ${WRKSRC}/README ${SHAREDIR}/${BINNAME}-README
	cd ${WRKSRC} ; ${PAX} -rw base gl_drivers icon.xpm ref_glx.so ${LIBDIR}

.include "../../mk/bsd.pkg.mk"
