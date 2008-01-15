# $NetBSD: Makefile,v 1.9 2008/01/15 00:58:17 gdt Exp $

DISTNAME=	gpsd-2.36
CATEGORIES=	geography
MASTER_SITES=	http://download.berlios.de/gpsd/

MAINTAINER=	tsarna@NetBSD.org
# also gdt@NetBSD.org
HOMEPAGE=	http://gpsd.berlios.de/
COMMENT=	GPS information daemon

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
