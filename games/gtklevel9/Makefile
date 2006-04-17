# $NetBSD: Makefile,v 1.5 2006/04/17 13:46:28 wiz Exp $

DISTNAME=		Level9_4.0_Source
PKGNAME=		gtklevel9-4.0
PKGREVISION=		3
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
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gtklevel9
	${INSTALL_DATA} ${WRKDIR}/level9.txt ${PREFIX}/share/doc/gtklevel9
	${INSTALL_PROGRAM} ${WRKSRC}/gtklevel9 ${PREFIX}/bin

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
