# $NetBSD: Makefile,v 1.1.1.1 2004/02/23 23:01:55 wulf Exp $
#

DISTNAME=	xdx-1.1
CATEGORIES=	ham
MASTER_SITES=	http://www.qsl.net/pg4i/download/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.qsl.net/pg4i/linux/xdx.html
COMMENT=	Amateur Radio tcp/ip DX-cluster client

USE_BUILDLINK2=	yes
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR=yes

.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
