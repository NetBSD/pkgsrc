# $NetBSD: Makefile,v 1.13 2002/02/10 22:49:53 fredb Exp $
#

DISTNAME=	dt-1.1.7
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=   ${MASTER_SITE_LOCAL}

MAINTAINER=	fredb@netbsd.org
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
