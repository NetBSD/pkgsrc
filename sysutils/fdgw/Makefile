# $NetBSD: Makefile,v 1.5 2002/04/12 20:51:26 agc Exp $
#

DISTNAME=	fdgw-20020130
CATEGORIES=	sysutils net
MASTER_SITES=	ftp://ftp.fml.org/pub/fdgw/source/

MAINTAINER= 	fukachan@fml.org
HOMEPAGE=	http://www.fml.org/software/fdgw/
COMMENT= 	toolkit to build a one-floppy NetBSD system

BSDSRCDIR?=	/usr/src
_IMG_SRC_DIR =	${WRKSRC}/image.${MACHINE_ARCH}
_IMG_DST_DIR =	${PREFIX}/fdgw/${MACHINE_ARCH}

ONLY_FOR_PLATFORM=	NetBSD-1.5.*-i386

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/bin/lndir)
IGNORE=                 "${PKGNAME} requires the 'lndir' command, and hence X11"
.endif

# we need the NetBSD source tree.
.if !exists(${BSDSRCDIR})
IGNORE= "${PKGNAME} requires the NetBSD source tree in BSDSRCDIR (${BSDSRCDIR})"
.endif

ALL_TARGET=	dist-build

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

.include "../../mk/bsd.pkg.mk"
