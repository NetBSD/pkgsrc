# $NetBSD: Makefile,v 1.3 2006/03/02 20:05:57 drochner Exp $

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
.include "../../mk/bsd.pkg.mk"
