# $NetBSD: Makefile,v 1.26 2011/11/11 22:41:35 joerg Exp $
#

DISTNAME=	dt-1.1.7
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Virtual consoles for NetBSD/mac68k (and macppc?)

PKG_DESTDIR_SUPPORT=	destdir

ONLY_FOR_PLATFORM=	NetBSD-*-m68k

WRKSRC=		${WRKDIR}/dt
BUILD_TARGET=	depend all
CPPFLAGS+=	-D${DT_LAYOUT}_LAYOUT

DTDOCSDIR=	${PREFIX}/share/doc/dt

INSTALLATION_DIRS=	bin ${DTDOCSDIR}

post-install:
	cd ${WRKSRC}; ${INSTALL_DATA} README dt.html example.dtrc ${DESTDIR}${DTDOCSDIR}

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
