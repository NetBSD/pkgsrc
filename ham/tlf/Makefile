# $NetBSD: Makefile,v 1.1.1.1 2004/09/24 23:39:03 wulf Exp $
#

DISTNAME=	tlf-0.9.20
CATEGORIES=	ham
MASTER_SITES=	http://sharon.pi8zaa.ampr.org/pub/linux/ham/tlf/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://home.iae.nl/users/reinc/TLF-0.2.html
COMMENT=	Advanced hamradio logging and contest program

USE_NCURSES=	yes
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	yes
BUILD_USES_MSGFMT=yes

CONFIGURE_ARGS=	--enable-hamlib

post-patch:
	${ECHO} SC_DEVICE=/dev/tty00 >> ${WRKSRC}/share/logcfg.dat

.include "../../mk/bsd.prefs.mk"

LIBS+= ${LIBOSSAUDIO} 

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../ham/hamlib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
