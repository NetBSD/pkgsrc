# $NetBSD: Makefile,v 1.2 1999/04/13 15:31:06 agc Exp $
#

DISTNAME=	dt-1.1.6
WRKSRC=		${WRKDIR}/dt
CATEGORIES=	misc
MASTER_SITES=   ${MASTER_SITES_LOCAL}

MAINTAINER=	fb@enteract.com

.BEGIN:
.if (${MACHINE} != "mac68k") && (${MACHINE} != "macppc")
IGNORE=		"is only useful for ports that have the adb and grf devices"
.endif

MIRROR_DISTFILE=no

ALL_TARGET=	depend all
DTDOCSDIR=	${PREFIX}/share/doc/dt

post-install:
	${INSTALL_DATA_DIR} ${DTDOCSDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} README dt.html example.dtrc ${DTDOCSDIR})

.include "../../mk/bsd.pkg.mk"
