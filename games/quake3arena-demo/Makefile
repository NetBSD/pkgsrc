# $NetBSD: Makefile,v 1.15 2003/09/16 14:21:00 xtraeme Exp $

DISTNAME=	linuxq3ademo-1_11-6_x86_gz
PKGNAME=	quake3arena-demo-1.11.6
WRKSRC=		${WRKDIR}
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/quake3/linux/ \
		ftp://mirrors.xmission.com/idsoftware/quake3/linux/
EXTRACT_SUFX=	.sh

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.quake3arena.com/
COMMENT=	Quake 3 Arena -- first person shooter (linux demo)

CONFLICTS=	quake3arena-[0-9]*

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != Linux
DEPENDS+=	suse_linux>=6.3:../../emulators/${SUSE_DIR_PREFIX}_linux
DEPENDS+=	suse_glx>=6.4:../../emulators/${SUSE_DIR_PREFIX}_glx
.include "../../emulators/suse_linux/Makefile.application"
.else
USE_X11=	yes
.include "../../graphics/MesaLib/buildlink2.mk"
.endif

NO_CONFIGURE=	yes
EXTRACT_CMD=	${SED} '1,/^END_OF_STUB$$/d' ${DOWNLOADED_DISTFILE} | \
								${GTAR} xzf -

ONLY_FOR_PLATFORM=*-*-i386

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
	${LN} -s ${LIBDIR}/libMesaVoodooGL.so.3.2 \
		${LIBDIR}/libMesaVoodooGL.so.3
	${LN} -s ${LIBDIR}/libMesaVoodooGL.so.3.2 \
		${LIBDIR}/libMesaVoodooGL.so
	${INSTALL_DATA} ${WRKSRC}/README ${SHAREDIR}/${BINNAME}-README
	cd ${WRKSRC} && ${PAX} -rw demoq3 icon.bmp icon.xpm ${LIBDIR}
	cd ${WRKSRC} && ${PAX} -rw Help ${SHAREDIR}
	${MV} ${SHAREDIR}/Help ${SHAREDIR}/quake3arena-Help

.include "../../mk/bsd.pkg.mk"
