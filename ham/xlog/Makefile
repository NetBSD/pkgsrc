# $NetBSD: Makefile,v 1.12 2005/01/23 09:02:54 wulf Exp $
#

DISTNAME=	xlog-1.0
CATEGORIES=	ham
MASTER_SITES=	http://www.qsl.net/pg4i/download/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.qsl.net/pg4i/linux/xlog.html
COMMENT=	Amateur Radio logging program

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_PKGLOCALEDIR=yes
USE_GNU_TOOLS+=	make

CONFIGURE_ARGS=	--enable-hamlib

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../ham/hamlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
