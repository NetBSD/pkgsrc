# $NetBSD: Makefile,v 1.1.1.1 2004/11/20 12:45:40 rh Exp $
#

DISTNAME=		RealPlayer10GOLD
PKGNAME=		RealPlayerGold-10.0.1
CATEGORIES=		multimedia
MASTER_SITES=		https://helixcommunity.org/download.php/643/
EXTRACT_SUFX=		.rpm

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.real.com/linux/
COMMENT=		Real Audio and Video Player

BUILD_DEPENDS+=		wget-[0-9]*:../../net/wget

FETCH_CMD=		${PREFIX}/bin/wget
RPMFILES=		${DISTNAME}${EXTRACT_SUFX}
RPM2PKGARGS=		-d ${PREFIX} -f ${PLIST_SRC} -p ${REALPLAYER_SUBDIR} -s3
EXTRACT_ONLY=		# empty
NO_BUILDLINK=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC
DIST_SUBDIR=		${PKGNAME_NOREV}

.include "../../emulators/suse_linux/Makefile.application"

.if ${OPSYS} != "Linux"
DEPENDS+=		suse_base>=9.1:../../emulators/suse91_base
DEPENDS+=		suse_fontconfig>=9.1:../../emulators/suse91_fontconfig
DEPENDS+=		suse_freetype2>=9.1:../../emulators/suse91_freetype2
DEPENDS+=		suse_x11>=9.1:../../emulators/suse91_x11
DEPENDS+=		suse_gtk2>=9.1:../../emulators/suse91_gtk2
.else
USE_X11=		yes
.endif

REALPLAYER_SUBDIR=	lib
REALPLAYER_HOME=	${PREFIX}/${REALPLAYER_SUBDIR}/RealPlayer

RESTRICTED=		"Redistribution not permitted"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

ONLY_FOR_PLATFORM=	*-*-i386

do-build:
	${SED} -e 's|@REALPLAYER_HOME@|${REALPLAYER_HOME}|g'		\
		${FILESDIR}/realplay.sh > ${WRKDIR}/realplayergold

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/realplayergold ${PREFIX}/bin
	${ECHO} bin/realplayergold >> ${PLIST_SRC}
	${SED} -e 's|/bin/true|${TRUE}|g' < ${REALPLAYER_HOME}/realplay	\
		> ${WRKDIR}/realplay
	${INSTALL_SCRIPT} ${WRKDIR}/realplay ${REALPLAYER_HOME}

.include "../../mk/bsd.pkg.mk"
