# $NetBSD: Makefile,v 1.41 2013/10/10 14:42:17 ryoon Exp $
#

DISTNAME=	xdx-2.4.2
PKGREVISION=	20
CATEGORIES=	ham
MASTER_SITES=	http://www.qsl.net/pg4i/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.qsl.net/pg4i/linux/xdx.html
COMMENT=	Amateur Radio tcp/ip DX-cluster client
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR=yes

BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
