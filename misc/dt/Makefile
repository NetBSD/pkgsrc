# $NetBSD: Makefile,v 1.11 2001/06/11 06:34:44 jlam Exp $
#

DISTNAME=	dt-1.1.7
CATEGORIES=	misc
MASTER_SITES=   ${MASTER_SITE_LOCAL}

MAINTAINER=	fb@enteract.com
COMMENT=	Virtual consoles for NetBSD/mac68k (and macppc?)

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

.if ${MACHINE} != "mac68k"
IGNORE=		"${PKGNAME} is only useful for mac68k!"
.endif

ALL_TARGET=	depend all
CPPFLAGS+=	-D${DT_LAYOUT}_LAYOUT

DTDOCSDIR=	${PREFIX}/share/doc/dt
WRKSRC=		${WRKDIR}/dt

post-install:
	${INSTALL_DATA_DIR} ${DTDOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} README dt.html example.dtrc ${DTDOCSDIR}

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
DT_LAYOUT?=	US

.include "../../mk/bsd.pkg.mk"
