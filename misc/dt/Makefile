# $NetBSD: Makefile,v 1.5 1999/09/07 14:53:55 jlam Exp $
#

DISTNAME=	dt-1.1.7
WRKSRC=		${WRKDIR}/dt
CATEGORIES=	misc
MASTER_SITES=   ${MASTER_SITE_LOCAL}

MAINTAINER=	fb@enteract.com

.BEGIN:
.if (${MACHINE} != "mac68k") && (${MACHINE} != "macppc")
IGNORE=		"is only useful for ports that have the adb and grf devices"
.endif

MIRROR_DISTFILE=no

ALL_TARGET=	depend all
DTDOCSDIR=	${PREFIX}/share/doc/dt

.include "../../mk/bsd.prefs.mk"

# DT_LAYOUT specifies which keyboard layout to use.
# Currently supported keyboard layouts:
#
#	US	US
#	FI	Finnish
#	FR	French
#	GER	German
#	DV	Dvorak
#
DT_LAYOUT?=	FI

CPPFLAGS+=	-D${DT_LAYOUT}_LAYOUT
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}"

post-install:
	${INSTALL_DATA_DIR} ${DTDOCSDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} README dt.html example.dtrc ${DTDOCSDIR})

.include "../../mk/bsd.pkg.mk"
