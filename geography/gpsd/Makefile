# $NetBSD: Makefile,v 1.8 2008/01/12 23:54:46 joerg Exp $

DISTNAME=	gpsd-2.33
PKGREVISION=	1
CATEGORIES=	geography
MASTER_SITES=	http://download.berlios.de/gpsd/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://gpsd.berlios.de/
COMMENT=	GPS information daemon

GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	sbin

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
