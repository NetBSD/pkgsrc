# $NetBSD: Makefile,v 1.18 2012/09/07 19:16:37 adam Exp $

DISTNAME=		Level9_4.0_Source
PKGNAME=		gtklevel9-4.0
PKGREVISION=		13
CATEGORIES=		games
MASTER_SITES=		http://www.ifarchive.org/if-archive/level9/interpreters/level9/
EXTRACT_SUFX=		.zip
DIST_SUBDIR=		${PKGNAME_NOREV}

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://www.ifarchive.org/if-archive/level9/interpreters/level9/
COMMENT=		GTK+ port of the Level 9 text adventure interpreter

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/Gtk

INSTALLATION_DIRS=	bin
BUILD_TARGET=		gtklevel9
USE_TOOLS+=		pkg-config

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/gtklevel9
	${INSTALL_DATA} ${WRKDIR}/level9.txt \
		${DESTDIR}${PREFIX}/share/doc/gtklevel9
	${INSTALL_PROGRAM} ${WRKSRC}/gtklevel9 ${DESTDIR}${PREFIX}/bin

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
