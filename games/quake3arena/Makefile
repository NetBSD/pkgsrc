# $NetBSD: Makefile,v 1.1.1.1 2000/12/13 23:58:32 wiz Exp $
#

DISTNAME=	linuxq3apoint-1.17.x86
PKGNAME=	quake3arena-1.17
CATEGORIES=	games x11
MASTER_SITES=	ftp://mirrors.aol.com/pub/pc_games/doom/idstuff/quake3/linux/
EXTRACT_SUFX=	.run

MAINTAINER=	jmcneill@invisible.yi.org
HOMEPAGE=	http://www.quake3arena.com/

DEPENDS+=	suse_base>=6.3:../../emulators/suse_base
DEPENDS+=	suse_x11>=6.3:../../emulators/suse_x11
DEPENDS+=	suse_glx-6.4:../../emulators/suse_glx

CONFLICTS=	quake3arena-demo-*

NO_SRC_ON_FTP=	no
NO_BIN_ON_FTP=	no

NO_CONFIGURE=	yes
NO_WRKSUBDIR=	yes
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
	${INSTALL_DATA} ${WRKSRC}/README ${SHAREDIR}/${BINNAME}-README
	cd ${WRKSRC} ; ${PAX} -rw baseq3 ${LIBDIR}
	cd ${WRKSRC} ; ${PAX} -rw Help ${SHAREDIR}
	${MV} ${SHAREDIR}/Help ${SHAREDIR}/quake3arena-Help

.include "../../mk/bsd.pkg.mk"
