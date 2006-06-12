# $NetBSD: Makefile,v 1.18 2006/06/12 16:28:09 wiz Exp $
#

DISTNAME=		Magnetic22Src
#			core version: 2.2, gui version: 1.6
PKGNAME=		gtkmagnetic-2.2.1.6
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://www.ifarchive.org/if-archive/magnetic-scrolls/interpreters/magnetic/
EXTRACT_SUFX=		.zip
DIST_SUBDIR=		${PKGNAME_NOREV}

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://www.if-legends.org/~msmemorial/magnetic.htm
COMMENT=		Interpreter for text adventures from Magnetic Scrolls

USE_TOOLS+=		gmake pkg-config
BUILD_TARGET=		gtkmagnetic
WRKSRC=			${WRKDIR}/Gtk

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:MSun)
LIBS.SunOS+=		-lCrun
.endif

INSTALLATION_DIRS=	bin

.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtkmagnetic ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gtkmagnetic
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gtkmagnetic

.include "../../mk/bsd.pkg.mk"
