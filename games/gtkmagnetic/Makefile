# $NetBSD: Makefile,v 1.10 2005/06/16 06:57:54 jlam Exp $
#

DISTNAME=		Magnetic22Src
PKGNAME=		gtkmagnetic-2.2
PKGREVISION=	2
CATEGORIES=		games
MASTER_SITES=		http://www.ifarchive.org/if-archive/magnetic-scrolls/interpreters/magnetic/
EXTRACT_SUFX=		.zip

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://www.if-legends.org/~msmemorial/magnetic.htm
COMMENT=		Interpreter for text adventures from Magnetic Scrolls

USE_TOOLS+=		gmake
BUILD_TARGET=		gtkmagnetic
WRKSRC=			${WRKDIR}/Gtk

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:MSun)
LIBS.SunOS+=		-lCrun
.endif

INSTALLATION_DIRS=	bin

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtkmagnetic ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gtkmagnetic
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gtkmagnetic

.include "../../mk/bsd.pkg.mk"
