# $NetBSD: Makefile,v 1.1.1.1 2004/01/26 14:46:49 jmmv Exp $
#

DISTNAME=	install_flash_player_6_linux
PKGNAME=	moz-bin-flash-${VERSION}
CATEGORIES=	multimedia www
MASTER_SITES=	http://download.macromedia.com/pub/shockwave/flash/english/linux/6.0r69/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.macromedia.com/
COMMENT=	Flash player for the linux version of mozilla (binary pkg)

DEPENDS+=	mozilla-bin-[0-9]*:../../www/mozilla-bin

CONFLICTS+=	mozilla-flash-bin-[0-9]*

VERSION=	6.0.69

NO_CONFIGURE=	YES
NO_BUILD=	YES

WRKSRC=		${WRKDIR}/install_flash_player_6_linux

DOCDIR=		share/doc/moz-bin-flash
PLIST_SUBST+=	DOCDIR="${DOCDIR}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libflashplayer.so ${PREFIX}/lib/mozilla-linux/plugins
	${INSTALL_DATA} ${WRKSRC}/flashplayer.xpt ${PREFIX}/lib/mozilla-linux/components

	${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}
	${INSTALL_DATA}	${WRKSRC}/readme.txt ${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/ReadMe.htm ${PREFIX}/${DOCDIR}

.include "../../mk/bsd.pkg.mk"
