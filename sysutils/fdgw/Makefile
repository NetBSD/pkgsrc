# $NetBSD: Makefile,v 1.9 2004/12/03 15:15:10 wiz Exp $
#

DISTNAME=	fdgw-20020130
CATEGORIES=	sysutils net
MASTER_SITES=	ftp://ftp.fml.org/pub/fdgw/source/

MAINTAINER= 	fukachan@fml.org
HOMEPAGE=	http://www.fml.org/software/fdgw/
COMMENT= 	Toolkit to build a one-floppy NetBSD system

_IMG_SRC_DIR =	${WRKSRC}/image.${MACHINE_ARCH}
_IMG_DST_DIR =	${PREFIX}/fdgw/${MACHINE_ARCH}

ONLY_FOR_PLATFORM=	NetBSD-1.5.*-i386

BUILD_TARGET=	dist-build
MAKE_ENV+=	BSDSRCDIR="${BSDSRCDIR}"

pre-fetch:
	@ ${ECHO} "";
	@ ${ECHO} "********************************************************";
	@ ${ECHO} "Please note: The install stage of fdgw requires a kernel"
	@ ${ECHO} "             with 'pseudo-device vnd 4' enabled.";
	@ ${ECHO} "********************************************************";
	@ ${ECHO} "";

pre-install:
	(cd ${WRKSRC} && ${MAKE} dist-image)

do-install:
	${TEST} -d ${_IMG_DST_DIR} || ${MKDIR} ${_IMG_DST_DIR}
	${INSTALL_DATA} ${_IMG_SRC_DIR}/natbox.img ${_IMG_DST_DIR}/natbox.img
	${INSTALL_DATA} ${_IMG_SRC_DIR}/adslrouter.img ${_IMG_DST_DIR}/adslrouter.img

post-install:
	@ ${ECHO} "";
	@ ${ECHO} "*****************************************************";
	@ ${ECHO} "";
	@ ${ECHO} "The floppy images are installed into ${_IMG_DST_DIR}."
	@ ${ECHO} ""
	@ ${ECHO} "To write adslrouter.img onto a floppy:"
	@ ${ECHO} "     # dd if=adslrouter.img of=/dev/rfd0a bs=18k"
	@ ${ECHO} "";
	@ ${ECHO} "See ${HOMEPAGE} for more details, e.g. customization";
	@ ${ECHO} "";
	@ ${ECHO} "*****************************************************";
	@ ${ECHO} "";

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/bin/lndir)
PKG_FAIL_REASON= "${PKGNAME} requires the 'lndir' command, and hence X11"
.endif

# we need the NetBSD source tree.
BSDSRCDIR?=	/usr/src
.if !exists(${BSDSRCDIR})
PKG_FAIL_REASON+= "${PKGNAME} requires the NetBSD source tree in BSDSRCDIR (${BSDSRCDIR})"
.endif

.include "../../mk/bsd.pkg.mk"
