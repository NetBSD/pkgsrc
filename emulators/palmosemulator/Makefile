# $NetBSD: Makefile,v 1.36 2012/10/03 12:55:16 asau Exp $
#

DISTNAME=	emulator_src_${POSE_VERSION}
PKGNAME=	palmosemulator-${POSE_VERSION}
PKGREVISION=	12
CATEGORIES=	emulators x11
MASTER_SITES=	http://www.palmos.com/dev/tools/emulator/sources/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		emulator-skins-19.tar.gz

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://www.palmos.com/dev/tools/emulator/
COMMENT=	Palm OS Emulator
#LICENSE=       GPL

NOT_FOR_PLATFORM=	${LP64PLATFORMS}

POSE_VERSION=	3.5

DIST_SUBDIR=	${PKGBASE}

# Source is under sources/ directory, skins are not...
SITES.emulator-skins-19.tar.gz=	http://www.palmos.com/dev/tools/emulator/

WRKSRC=		${WRKDIR}/Emulator_Src_${POSE_VERSION}
POSE_BUILD_DIR=	${WRKSRC}/BuildUnix
POSE_SHARE_DIR=	${PREFIX}/share/palmosemulator
POSE_SKINS_DIR=	${POSE_SHARE_DIR}/skins
WRKSRC_SKINS=	${WRKDIR}/Skins_v1.9
CPPFLAGS+=	-DFLTK_1_0_COMPAT

CONFIGURE_DIRS=	${POSE_BUILD_DIR}
BUILD_DIRS=	${POSE_BUILD_DIR}

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake perl:run

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-fltk=${BUILDLINK_PREFIX.fltk}
CONFIGURE_ENV+=		PACKAGE_SKINS_DIR=${POSE_SKINS_DIR:Q}

REPLACE_PERL=	Scripting/Perl/*.pl

INSTALLATION_DIRS=	bin ${POSE_SHARE_DIR}/docs ${POSE_SHARE_DIR}/scripting
INSTALLATION_DIRS+=	${POSE_SHARE_DIR}/prc ${POSE_SKINS_DIR}

do-install:
	${INSTALL_PROGRAM} ${POSE_BUILD_DIR}/pose ${DESTDIR}${PREFIX}/bin/pose
	${FIND} ${WRKSRC}/Docs -type f -print | \
		while read i; do \
			${INSTALL_DATA} "$$i" ${DESTDIR}${POSE_SHARE_DIR}/docs; \
		done
	for lang in Python Perl; do \
		ddir=${DESTDIR}${POSE_SHARE_DIR}/scripting/$$lang; \
		${INSTALL_SCRIPT_DIR} "$$ddir"; \
		${FIND} "${WRKSRC}/Scripting/$$lang" -type f -print | \
		while read i; do \
			case "$$i" in \
				*.pl) ${INSTALL_SCRIPT} "$$i" "$$ddir";; \
				*) ${INSTALL_DATA} "$$i" "$$ddir";; \
			esac; \
		done; \
	done
	${INSTALL_DATA} ${WRKSRC_SKINS}/ReadMe.txt ${DESTDIR}${POSE_SHARE_DIR}/docs/ReadMe_skins.txt
	${INSTALL_DATA} ${WRKSRC}/ROMTransfer/Source/ROM_Transfer.prc ${DESTDIR}${POSE_SHARE_DIR}/prc
	${FIND} ${WRKSRC_SKINS} \( -name "*.skin" -o -name "*.jpg" \) -print |\
		while read i; do \
			${INSTALL_DATA} "$$i" ${DESTDIR}${POSE_SKINS_DIR}; \
		done

.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
