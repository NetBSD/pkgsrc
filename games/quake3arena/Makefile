# $NetBSD: Makefile,v 1.9 2002/04/04 12:29:48 tron Exp $

DISTNAME=	linuxq3apoint-1.17.x86
PKGNAME=	quake3arena-1.17
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/quake3/linux/old/ \
		ftp://ftp.uni-klu.ac.at/pub/linux/games/quake3/ \
		ftp://ftp.mirrors.degnet.de/pub/misc/idsoftware/quake3/linux/old/
EXTRACT_SUFX=	.run

MAINTAINER=	jmcneill@invisible.yi.org
HOMEPAGE=	http://www.quake3arena.com/
COMMENT=	Quake 3 Arena -- first person shooter (binary only, no data files)

DEPENDS+=	suse_base>=6.3:../../emulators/${SUSE_DIR_PREFIX}_base
DEPENDS+=	suse_x11>=6.3:../../emulators/${SUSE_DIR_PREFIX}_x11
DEPENDS+=	suse_glx>=6.4:../../emulators/${SUSE_DIR_PREFIX}_glx

CONFLICTS=	quake3arena-demo-[0-9]*

NO_SRC_ON_FTP=	no
NO_BIN_ON_FTP=	no

NO_CONFIGURE=	yes
WRKSRC=		${WRKDIR}
EXTRACT_CMD=	${SED} '1,/^END_OF_STUB$$/d' ${DOWNLOADED_DISTFILE} | \
								${GTAR} xzf -

.if !make(fetch)
ONLY_FOR_PLATFORM=*-*-i386
.endif

DISTBINNAME=	quake3.x86
BINNAME=	quake3arena

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
	cd ${WRKSRC} ; ${PAX} -rw baseq3 ${LIBDIR}
	cd ${WRKSRC} ; ${PAX} -rw Help ${SHAREDIR}
	${MV} ${SHAREDIR}/Help ${SHAREDIR}/quake3arena-Help

.include "../../emulators/suse_linux/Makefile.application"

