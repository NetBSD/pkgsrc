# $NetBSD: Makefile,v 1.67 2023/11/12 13:21:21 wiz Exp $
#

DISTNAME=	gpsim-0.26.1
PKGREVISION=	20
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gpsim/}

MAINTAINER=	snoonan@tbearsiberians.com
HOMEPAGE=	http://gpsim.sourceforge.net/
COMMENT=	PIC emulator with X interface

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	YES

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

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
