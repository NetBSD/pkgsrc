# $NetBSD: Makefile,v 1.14 2004/12/03 15:14:52 wiz Exp $

DISTNAME=	estic-1.61
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.gwdg.de/pub/misc/isdn/linux/estic/
EXTRACT_SUFX=	.zip
DISTFILES=	${EXTRACT_ONLY} ${ESTICPATCH}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.von-bassewitz.de/uz/estic/estic.html
COMMENT=	German language configuration tool for ISTEC 1003/1008 ISDN systems

EXTRACT_ONLY=	estic-1.60-sources${EXTRACT_SUFX}

RESTRICTED=	"Only free distribution permitted"
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV:C/-.*//}
USE_BUILDLINK3=	yes
USE_X11=	# defined

BUILD_TARGET=	depend all
ESTICPATCH=	${DISTNAME}-patch-from-1.60${EXTRACT_SUFX}
LIB_TARGET=	depend lib
LIBSRC=		${WRKDIR}/spunk
MAKEFILE=	make/freebsd-x.mak

post-extract:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC} && \
	${LOCALBASE}/bin/unzip -p ${DISTDIR}/${ESTICPATCH} | \
		${PATCH} -p0 ${PATCH_DIST_ARGS}

pre-build:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${LIBSRC} && \
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} \
	  ${LIB_TARGET}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xestic ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/estic.res ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/estic
	${INSTALL_DATA} ${WRKSRC}/estic.doc ${PREFIX}/share/doc/estic
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/estic
	cd ${WRKSRC}/samples && \
	${INSTALL_DATA} * ${PREFIX}/share/examples/estic

.include "../../mk/bsd.pkg.mk"
