# $NetBSD: Makefile,v 1.1.1.1 2001/02/10 18:34:23 tron Exp $

DISTNAME=	estic-1.61
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.gwdg.de/pub/misc/isdn/linux/estic/
EXTRACT_SUFX=	.zip
DISTFILES=	${EXTRACT_ONLY} ${ESTICPATCH}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.von-bassewitz.de/uz/estic/estic.html

EXTRACT_ONLY=	estic-1.60-sources${EXTRACT_SUFX}
USE_X11=	YES

RESTRICTED=	"Only free distribution permitted"
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

ALL_TARGET=	depend all
ESTICPATCH=	${DISTNAME}-patch-from-1.60${EXTRACT_SUFX}
LIB_TARGET=	depend lib
LIBSRC=		${WRKDIR}/spunk
MAKEFILE=	make/freebsd-x.mak
WRKSRC=		${WRKDIR}/${PKGNAME:C/-.*//}

post-extract:
	${_PKG_SILENT}${_PKG_DEBUG}${GZCAT} ${DISTDIR}/${ESTICPATCH} | \
	${PATCH} ${PATCH_DIST_ARGS}

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
