# $NetBSD: Makefile,v 1.9 2005/07/21 16:29:52 wiz Exp $
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

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
