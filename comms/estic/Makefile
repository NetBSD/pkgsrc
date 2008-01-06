# $NetBSD: Makefile,v 1.26 2008/01/06 18:39:38 rillig Exp $

DISTNAME=	estic-1.61
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.gwdg.de/pub/misc/isdn/linux/estic/
EXTRACT_SUFX=	.zip
DISTFILES=	${EXTRACT_ONLY} ${ESTICPATCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.von-bassewitz.de/uz/estic/estic.html
COMMENT=	German language configuration tool for ISTEC 1003/1008 ISDN systems

EXTRACT_ONLY=	estic-1.60-sources${EXTRACT_SUFX}

# No permissions are apparent from inspecting the sources.
LICENSE=		generic-nonlicense
RESTRICTED=		No permission to copy
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV:C/-.*//}

USE_LANGUAGES=	c c++
USE_TOOLS+=	patch unzip

BUILD_TARGET=	depend all
ESTICPATCH=	${DISTNAME}-patch-from-1.60${EXTRACT_SUFX}
MAKE_FILE=	make/freebsd-x.mak

INSTALLATION_DIRS=	bin

post-extract:
	cd ${WRKSRC} && \
	unzip -p ${DISTDIR}/${ESTICPATCH} \
	| ${PATCH} -p0 ${PATCH_DIST_ARGS}

pre-build:
	cd ${WRKDIR}/spunk && ${BUILD_MAKE_CMD} depend lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xestic ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/estic.res ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/estic
	${INSTALL_DATA} ${WRKSRC}/estic.doc ${PREFIX}/share/doc/estic
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/estic
	cd ${WRKSRC}/samples && \
	${INSTALL_DATA} * ${PREFIX}/share/examples/estic

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
