# $NetBSD: Makefile,v 1.34.2.1 2012/10/03 12:07:38 spz Exp $
#

DISTNAME=	gpsim-0.21.11
PKGREVISION=	14
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gpsim/}

MAINTAINER=	snoonan@tbearsiberians.com
HOMEPAGE=	http://gpsim.sourceforge.net/
COMMENT=	PIC emulator with X interface

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	YES
USE_GNU_READLINE=	YES

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
