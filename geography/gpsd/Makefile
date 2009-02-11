# $NetBSD: Makefile,v 1.14 2009/02/11 01:05:25 gdt Exp $

DISTNAME=	gpsd-2.38
CATEGORIES=	geography
MASTER_SITES=	http://download.berlios.de/gpsd/

MAINTAINER=	tsarna@NetBSD.org
# MAINTAINER+=	gdt@NetBSD.org
HOMEPAGE=	http://gpsd.berlios.de/
COMMENT=	GPS information daemon

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--disable-python

USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_NCURSES=	yes

INSTALLATION_DIRS=	sbin

# XXX This package should have an option for python to install gpsfake
# and gpsctl.

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
