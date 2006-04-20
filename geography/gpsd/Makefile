# $NetBSD: Makefile,v 1.4 2006/04/20 15:28:00 joerg Exp $

DISTNAME=	gpsd-2.31
CATEGORIES=	geography
MASTER_SITES=	http://download.berlios.de/gpsd/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.pygps.org/gpsd/
COMMENT=	GPS information daemon

GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes

INSTALLATION_DIRS=	sbin

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
