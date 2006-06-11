# $NetBSD: Makefile,v 1.19 2006/06/11 14:08:28 joerg Exp $
#

DISTNAME=	gpsim-0.21.11
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gpsim/}

MAINTAINER=	snoonan@tbearsiberians.com
HOMEPAGE=	http://www.dattalo.com/gnupic/gpsim.html
COMMENT=	PIC emulator with X interface

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	YES
USE_GNU_READLINE=	YES

post-install:
	${INSTALL_DATA_DIR}  ${PREFIX}/share/doc/gpsim
	${INSTALL_DATA} ${WRKSRC}/doc/gpsim.pdf ${PREFIX}/share/doc/gpsim
	${INSTALL_DATA} ${WRKSRC}/doc/gpsim.ps ${PREFIX}/share/doc/gpsim

.include "../../devel/popt/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk2+extra/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
