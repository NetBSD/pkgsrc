# $NetBSD: Makefile,v 1.15 2004/10/03 00:14:40 tv Exp $
#

DISTNAME=	emulator_src_${POSE_VERSION}
PKGNAME=	palmosemulator-${POSE_VERSION}
PKGREVISION=	5
CATEGORIES=	emulators x11
MASTER_SITES=	http://www.palmos.com/dev/tools/emulator/sources/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		emulator-skins-19.tar.gz

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://www.palmos.com/dev/tools/emulator/
COMMENT=	Palm OS Emulator

POSE_VERSION=	3.5

DIST_SUBDIR=	${PKGBASE}

# Source is under sources/ directory, skins are not...
SITES_emulator-skins-19.tar.gz=	http://www.palmos.com/dev/tools/emulator/

#LICENSE=       GPL

WRKSRC=         ${WRKDIR}/Emulator_Src_${POSE_VERSION}
POSE_BUILD_DIR=	${WRKSRC}/BuildUnix
POSE_SHARE_DIR=	${PREFIX}/share/palmosemulator
POSE_SKINS_DIR=	${POSE_SHARE_DIR}/skins
WRKSRC_SKINS=	${WRKDIR}/Skins_v1.9
CPPFLAGS+=	-DFLTK_1_0_COMPAT

CONFIGURE_DIRS=	${POSE_BUILD_DIR}
BUILD_DIRS=	${POSE_BUILD_DIR}

USE_BUILDLINK3=	YES
USE_PERL5=	build
USE_X11=	YES
USE_GNU_TOOLS+=	make

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-fltk=${BUILDLINK_PREFIX.fltk}
CONFIGURE_ENV+=		PACKAGE_SKINS_DIR=${POSE_SKINS_DIR}

# Assumes too much about how to build va_list's from scratch
NOT_FOR_PLATFORM=	*-*-powerpc

do-install:
	${INSTALL_PROGRAM} ${POSE_BUILD_DIR}/pose ${PREFIX}/bin/pose
	${INSTALL_DATA_DIR} ${POSE_SHARE_DIR}
	${INSTALL_DATA_DIR} ${POSE_SHARE_DIR}/docs
	${INSTALL_DATA_DIR} ${POSE_SHARE_DIR}/scripting
	${FIND} ${WRKSRC}/Docs -type f -print | \
		while read i; do \
			${INSTALL_DATA} "$$i" ${POSE_SHARE_DIR}/docs; \
		done
	for lang in Python Perl; do \
		ddir="${POSE_SHARE_DIR}/scripting/$$lang"; \
		${INSTALL_SCRIPT_DIR} "$$ddir"; \
		${FIND} "${WRKSRC}/Scripting/$$lang" -type f -print | \
		while read i; do \
			case "$$i" in \
				*.pl) ${INSTALL_SCRIPT} "$$i" "$$ddir";; \
				*) ${INSTALL_DATA} "$$i" "$$ddir";; \
			esac; \
		done; \
	done
	${INSTALL_DATA} ${WRKSRC_SKINS}/ReadMe.txt ${POSE_SHARE_DIR}/docs/ReadMe_skins.txt
	${INSTALL_DATA_DIR} ${POSE_SHARE_DIR}/prc
	${INSTALL_DATA} ${WRKSRC}/ROMTransfer/Source/ROM_Transfer.prc ${POSE_SHARE_DIR}/prc
	${INSTALL_DATA_DIR} ${POSE_SKINS_DIR}
	${FIND} ${WRKSRC_SKINS} \( -name "*.skin" -o -name "*.jpg" \) -print |\
		while read i; do \
			${INSTALL_DATA} "$$i" ${POSE_SKINS_DIR}; \
		done

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
