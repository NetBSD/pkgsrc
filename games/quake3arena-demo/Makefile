# $NetBSD: Makefile,v 1.1.1.1 2000/12/09 18:25:05 wiz Exp $
#

DISTNAME=	linuxq3ademo-1_11-6_x86_gz
PKGNAME=	quake3arena-demo-1.11.6
CATEGORIES=	games x11
MASTER_SITES=	http://download1.activision.com/activision/quake3/demo/ \
		http://download2.activision.com/activision/quake3/demo/
EXTRACT_SUFX=	.sh

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.quake3arena.com/

DEPENDS+=	suse_linux>=6.3:../../emulators/suse_linux
DEPENDS+=	suse_glx-6.4:../../emulators/suse_glx

MIRROR_DISTFILE=no

NO_CONFIGURE=	yes
NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${SED} '1,/^END_OF_STUB$$/d' ${DOWNLOADED_DISTFILE} | \
								${GTAR} xzf -

.if !make(fetch)
ONLY_FOR_PLATFORM=*-*-i386
.endif

DISTBINNAME=	q3demo
BINNAME=	quake3arena-demo

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
	${INSTALL_PROGRAM} ${WRKSRC}/bin/x86/glibc-2.1/${DISTBINNAME} \
		${LIBDIR}/${BINNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/x86/glibc-2.1/q3ded ${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/bin/x86/glibc-2.1/libMesaVoodooGL.so.3.2 \
		${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${SHAREDIR}/${BINNAME}-README
	cd ${WRKSRC} ; ${PAX} -rw demoq3 icon.bmp icon.xpm ${LIBDIR}
	cd ${WRKSRC} ; ${PAX} -rw Help ${SHAREDIR}
	${MV} ${SHAREDIR}/Help ${SHAREDIR}/quake3arena-Help

.include "../../mk/bsd.pkg.mk"
