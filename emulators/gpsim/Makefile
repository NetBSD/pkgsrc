# $NetBSD: Makefile,v 1.58 2020/03/08 16:49:27 wiz Exp $
#

DISTNAME=	gpsim-0.26.1
PKGREVISION=	13
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gpsim/}

MAINTAINER=	snoonan@tbearsiberians.com
HOMEPAGE=	https://gpsim.sourceforge.net/
COMMENT=	PIC emulator with X interface

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++03

USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	YES

INSTALLATION_DIRS=	share/doc/gpsim

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/gpsim.pdf ${DESTDIR}${PREFIX}/share/doc/gpsim
	${INSTALL_DATA} ${WRKSRC}/doc/gpsim.ps ${DESTDIR}${PREFIX}/share/doc/gpsim

.include "../../devel/popt/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk2+extra/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
