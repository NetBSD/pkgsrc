# $NetBSD: Makefile,v 1.14 2006/09/29 21:21:54 dmcmahill Exp $
#

DISTNAME=		RealPlayer10GOLD
# Exact version obtained from  the output of
#   file RealPlayer10GOLD.rpm
PKGNAME=		RealPlayerGold-${PKGVER}
CATEGORIES=		multimedia
MASTER_SITES=		http://forms.real.com/real/player/download.html?f=unix/
EXTRACT_SUFX=		.rpm

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.real.com/linux/
COMMENT=		Real Audio and Video Player

PKGVER=			10.0.8.805.20060718
RPMFILES=		${DISTNAME}${EXTRACT_SUFX}
RPM2PKGARGS=		-d ${PREFIX} -f ${PLIST_SRC} -p ${REALPLAYER_SUBDIR} -s3
RPM2PKGSTRIP=		3
EXTRACT_ONLY=		# empty
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC
DIST_SUBDIR=		${PKGNAME_NOREV}

# Verify that the version of the distfile (which changes often without the name changing)
# is still correct.  This helps sort out download errors vs out of date pkgsrc errors.
post-fetch:
	ver=`file ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} | ${SED} -e 's;.*Player-;;g'  -e 's;-;.;g'` ; \
		if [ "$$ver" != "${PKGVER}" ] ; then \
			${ECHO} "It appears that real.com has made a new version ($$ver) available so this" ; \
			${ECHO} "package will need updating to work correctly.  That likely the reason for" ; \
			${ECHO} "the checksum failure." ; \
		fi 


.include "../../emulators/suse_linux/Makefile.application"

.if !defined(USE_NATIVE_LINUX)
DEPENDS+=		suse_base>=9.1:../../emulators/${SUSE_DIR_PREFIX}_base
DEPENDS+=		suse_fontconfig>=9.1:../../emulators/${SUSE_DIR_PREFIX}_fontconfig
DEPENDS+=		suse_freetype2>=9.1:../../emulators/${SUSE_DIR_PREFIX}_freetype2
DEPENDS+=		suse_x11>=9.1:../../emulators/${SUSE_DIR_PREFIX}_x11
DEPENDS+=		suse_gtk2>=9.1:../../emulators/${SUSE_DIR_PREFIX}_gtk2
.endif

REALPLAYER_SUBDIR=	lib
REALPLAYER_HOME=	${PREFIX}/${REALPLAYER_SUBDIR}/RealPlayer

RESTRICTED=		Redistribution not permitted
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

ONLY_FOR_PLATFORM=	*-*-i386

.include "../../mk/x11.buildlink3.mk"

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
