# $NetBSD: Makefile,v 1.8 2005/05/22 20:08:08 jlam Exp $
#

DISTNAME=	xdx-1.2
CATEGORIES=	ham
MASTER_SITES=	http://www.qsl.net/pg4i/download/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.qsl.net/pg4i/linux/xdx.html
COMMENT=	Amateur Radio tcp/ip DX-cluster client

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR=yes

BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
