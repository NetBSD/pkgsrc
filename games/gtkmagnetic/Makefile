# $NetBSD: Makefile,v 1.50 2018/11/14 22:21:30 kleink Exp $
#

DISTNAME=		Magnetic22Src
#			core version: 2.2, gui version: 1.6
PKGNAME=		gtkmagnetic-2.2.1.6
PKGREVISION=		29
CATEGORIES=		games
MASTER_SITES=		http://www.ifarchive.org/if-archive/magnetic-scrolls/interpreters/magnetic/
EXTRACT_SUFX=		.zip
DIST_SUBDIR=		${PKGNAME_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.if-legends.org/~msmemorial/magnetic.htm
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
	${INSTALL_PROGRAM} ${WRKSRC}/gtkmagnetic ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/gtkmagnetic
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/gtkmagnetic

.include "../../mk/bsd.pkg.mk"
