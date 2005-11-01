# $NetBSD: Makefile,v 1.1.1.1 2005/11/01 14:56:14 dillo Exp $

DISTNAME=		Level9_4.0_Source
PKGNAME=		gtklevel9-4.0
CATEGORIES=		games
MASTER_SITES=		http://www.ifarchive.org/if-archive/level9/interpreters/level9/
EXTRACT_SUFX=		.zip

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://www.ifarchive.org/if-archive/level9/interpreters/level9/
COMMENT=		GTK+ port of the Level 9 text adventure interpreter

WRKSRC=			${WRKDIR}/Gtk

INSTALLATION_DIRS=	bin
BUILD_TARGET=		gtklevel9

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/level9
	${INSTALL_DATA} ${WRKDIR}/level9.txt ${PREFIX}/share/doc/level9
	${INSTALL_PROGRAM} ${WRKSRC}/level9 ${PREFIX}/bin

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
