# $NetBSD: Makefile,v 1.20 2005/05/16 01:15:31 jlam Exp $

DISTNAME=	linuxq3apoint-1.32b.x86
PKGREVISION=	1
PKGNAME=	quake3arena-1.32b
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/quake3/linux/ \
		ftp://mirrors.xmission.com/idsoftware/quake3/linux/
EXTRACT_SUFX=	.run

MAINTAINER=	jmcneill@NetBSD.org
HOMEPAGE=	http://www.quake3arena.com/
COMMENT=	Quake 3 Arena -- first person shooter (binary only, no data files)

CONFLICTS=	quake3arena-demo-[0-9]*

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != Linux
DEPENDS+=	suse_base>=6.3:../../emulators/${SUSE_DIR_PREFIX}_base
DEPENDS+=	suse_x11>=6.3:../../emulators/${SUSE_DIR_PREFIX}_x11
DEPENDS+=	suse_glx>=6.4:../../emulators/${SUSE_DIR_PREFIX}_glx
.include "../../emulators/suse_linux/Makefile.application"
.else
USE_X11=	yes
.endif

NO_SRC_ON_FTP=	no
NO_BIN_ON_FTP=	no
NO_CONFIGURE=	yes
CHECK_SHLIBS=	NO

PKGSRC_USE_TOOLS+=	gtar

EXTRACT_CMD=	${SED} '1,265d' ${DOWNLOADED_DISTFILE} | ${GTAR} xzf -

.if !make(fetch)
ONLY_FOR_PLATFORM=*-*-i386
.endif

DISTBINNAME=	quake3.x86
BINNAME=	quake3arena

WRKSRC=		${WRKDIR}
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
	${INSTALL_PROGRAM} ${WRKSRC}/bin/x86/${DISTBINNAME} \
		${LIBDIR}/${BINNAME}
	${INSTALL_DATA} ${WRKSRC}/README-linux.txt ${SHAREDIR}/${BINNAME}-README

	cd ${WRKSRC} && ${PAX} -rw baseq3 ${LIBDIR}

.if ${OPSYS} == "FreeBSD"
post-install:
	${BRANDELF} -t Linux ${LIBDIR}/${BINNAME}
.endif

.include "../../mk/bsd.pkg.mk"
