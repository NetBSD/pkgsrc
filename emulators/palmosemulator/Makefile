# $NetBSD: Makefile,v 1.1.1.1 2002/12/31 06:59:52 dsainty Exp $
#

DISTNAME=	emulator_src_${PKGVERSION}
PKGNAME=	palmosemulator-3.5
CATEGORIES=	emulators x11
MASTER_SITES=	http://www.palmos.com/dev/tools/emulator/sources/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		emulator-skins-19.tar.gz

MAINTAINER=	dsainty@netbsd.org
HOMEPAGE=	http://www.palmos.com/dev/tools/emulator/
COMMENT=	Palm OS Emulator

DIST_SUBDIR=	${PKGBASE}

# Source is under sources/ directory, skins are not...
SITES_emulator-skins-19.tar.gz=	http://www.palmos.com/dev/tools/emulator/

#LICENSE=       GPL

WRKSRC=         ${WRKDIR}/Emulator_Src_3.5
POSE_BUILD_DIR=	${WRKSRC}/BuildUnix
POSE_SHARE_DIR=	${PREFIX}/share/palmosemulator
POSE_SKINS_DIR=	${POSE_SHARE_DIR}/skins
WRKSRC_SKINS=	${WRKDIR}/Skins_v1.9

CONFIGURE_DIRS=	${POSE_BUILD_DIR}
BUILD_DIRS=	${POSE_BUILD_DIR}

USE_BUILDLINK2=	YES
USE_X11=	YES
USE_GMAKE=	YES

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-fltk=${BUILDLINK_PREFIX.fltk}
CONFIGURE_ARGS+=	--enable-debug
CONFIGURE_ENV+=		PACKAGE_SKINS_DIR=${POSE_SKINS_DIR}

do-install:
	${INSTALL_PROGRAM} ${POSE_BUILD_DIR}/pose ${PREFIX}/bin/pose
	${INSTALL_DATA_DIR} ${POSE_SHARE_DIR}
	${INSTALL_DATA_DIR} ${POSE_SHARE_DIR}/docs
	${FIND} ${WRKSRC}/Docs -type f -print | \
		while read i; do \
			${INSTALL_DATA} "$$i" ${POSE_SHARE_DIR}/docs; \
		done
	${INSTALL_DATA} ${WRKSRC_SKINS}/ReadMe.txt ${POSE_SHARE_DIR}/docs/ReadMe_skins.txt
	${INSTALL_DATA_DIR} ${POSE_SHARE_DIR}/prc
	${INSTALL_DATA} ${WRKSRC}/ROMTransfer/Source/ROM_Transfer.prc ${POSE_SHARE_DIR}/prc
	${INSTALL_DATA_DIR} ${POSE_SKINS_DIR}
	${FIND} ${WRKSRC_SKINS} \( -name "*.skin" -o -name "*.jpg" \) -print |\
		while read i; do \
			${INSTALL_DATA} "$$i" ${POSE_SKINS_DIR}; \
		done

.include "../../x11/fltk/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
