# $NetBSD: Makefile,v 1.2 2005/04/11 21:46:39 tv Exp $

DISTNAME=	qbrew-0.3.4
CATEGORIES=	misc
MASTER_SITES=	http://www.usermode.org/code/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.usermode.org/code.html
COMMENT= 	Homebrewer's recipe calculator

USE_GNU_TOOLS+= make
GNU_CONFIGURE=  yes
USE_LIBTOOL=    yes

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
