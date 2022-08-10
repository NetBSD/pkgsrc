# $NetBSD: Makefile,v 1.40 2022/08/10 18:01:41 he Exp $

DISTNAME=	estic-1.61
PKGREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.gwdg.de/pub/misc/isdn/linux/isdn4linux/oldstuff/estic/
EXTRACT_SUFX=	.zip
DISTFILES=	${EXTRACT_ONLY} ${ESTICPATCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.von-bassewitz.de/uz/estic/estic.html
COMMENT=	German language configuration tool for ISTEC 1003/1008 ISDN systems
LICENSE=	estic-license

EXTRACT_ONLY=	estic-1.60-sources${EXTRACT_SUFX}

WRKSRC=		${WRKDIR}

USE_LANGUAGES=	c gnu++03
USE_TOOLS+=	patch unzip

BUILD_TARGET=	depend all
ESTICPATCH=	${DISTNAME}-patch-from-1.60${EXTRACT_SUFX}
MAKE_FILE=	make/freebsd-x.mak

BUILD_DIRS=	${WRKDIR}/${PKGNAME_NOREV:C/-.*//}

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
CPPFLAGS+=	-DSOLARIS
.else
CPPFLAGS+=	-DFREEBSD
.endif

# str.cc: In function 'String ShowControls(const String&, unsigned int)':
# str.cc:1145:57: error: array subscript has type 'char' [-Werror=char-subscripts]
#                      T += (Style & ccOct)? OctCodes [*Str] : HexCodes [*Str];
#                                                         ^
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

INSTALLATION_DIRS=	bin

post-extract:
	cd ${BUILD_DIRS} && \
	unzip -p ${DISTDIR}/${ESTICPATCH} \
	| ${PATCH} -p0 ${PATCH_DIST_ARGS}

pre-build:
	cd ${WRKDIR}/spunk && ${BUILD_MAKE_CMD} depend lib

do-install:
	${INSTALL_PROGRAM} ${BUILD_DIRS}/xestic ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${BUILD_DIRS}/estic.res ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/estic
	${INSTALL_DATA} ${BUILD_DIRS}/estic.doc ${DESTDIR}${PREFIX}/share/doc/estic
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/estic
	cd ${BUILD_DIRS}/samples && \
	${INSTALL_DATA} * ${DESTDIR}${PREFIX}/share/examples/estic

.include "../../mk/termcap.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
