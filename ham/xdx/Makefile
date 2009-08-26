# $NetBSD: Makefile,v 1.21 2009/08/26 19:57:53 sno Exp $
#

DISTNAME=	xdx-2.4.2
PKGREVISION=	2
CATEGORIES=	ham
MASTER_SITES=	http://www.qsl.net/pg4i/download/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.qsl.net/pg4i/linux/xdx.html
COMMENT=	Amateur Radio tcp/ip DX-cluster client
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR=yes

BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
