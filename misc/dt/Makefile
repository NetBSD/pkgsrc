# $NetBSD: Makefile,v 1.19 2003/04/28 15:01:55 fredb Exp $
#

DISTNAME=	dt-1.1.7
PKGREVISION=	2
WRKSRC=		${WRKDIR}/dt
CATEGORIES=	misc
MASTER_SITES=   ${MASTER_SITE_LOCAL}

MAINTAINER=	fredb@netbsd.org
COMMENT=	Virtual consoles for NetBSD/mac68k (and macppc?)

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
ONLY_FOR_PLATFORM=	NetBSD-*-m68k

ALL_TARGET=	depend all
CPPFLAGS+=	-D${DT_LAYOUT}_LAYOUT

DTDOCSDIR=	${PREFIX}/share/doc/dt

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
