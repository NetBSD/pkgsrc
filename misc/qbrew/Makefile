# $NetBSD: Makefile,v 1.7 2006/02/05 23:10:13 joerg Exp $

DISTNAME=	qbrew-0.3.5
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://www.usermode.org/code/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.usermode.org/code.html
COMMENT= 	Homebrewer's recipe calculator

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
