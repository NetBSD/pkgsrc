# $NetBSD: Makefile,v 1.43 2014/05/05 00:48:01 ryoon Exp $
#

DISTNAME=	xdx-2.4.2
PKGREVISION=	21
CATEGORIES=	ham
MASTER_SITES=	http://www.qsl.net/pg4i/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.qsl.net/pg4i/linux/xdx.html
COMMENT=	Amateur Radio tcp/ip DX-cluster client
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR=yes

LDFLAGS.SunOS+=	-lsocket -lnsl -lresolv

BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
