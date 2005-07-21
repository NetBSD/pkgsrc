# $NetBSD: Makefile,v 1.15 2005/07/21 16:29:52 wiz Exp $
#

DISTNAME=	xlog-1.0
CATEGORIES=	ham
MASTER_SITES=	http://www.qsl.net/pg4i/download/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.qsl.net/pg4i/linux/xlog.html
COMMENT=	Amateur Radio logging program

GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR=yes
USE_TOOLS+=	gmake

CONFIGURE_ARGS=	--enable-hamlib

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../ham/hamlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
