# $NetBSD: Makefile,v 1.1.1.1 2004/12/27 09:11:05 wulf Exp $

DISTNAME=	qbrew-0.3.4
CATEGORIES=	misc
MASTER_SITES=	http://www.usermode.org/code/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.usermode.org/code.html
COMMENT= 	Homebrewer's recipe calculator

USE_BUILDLINK3= yes
USE_GNU_TOOLS+= make
GNU_CONFIGURE=  yes
USE_LIBTOOL=    yes

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
