# $NetBSD: Makefile,v 1.6 2005/01/23 09:24:18 wulf Exp $
#

DISTNAME=	xdx-1.2
CATEGORIES=	ham
MASTER_SITES=	http://www.qsl.net/pg4i/download/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.qsl.net/pg4i/linux/xdx.html
COMMENT=	Amateur Radio tcp/ip DX-cluster client

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR=yes

BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
