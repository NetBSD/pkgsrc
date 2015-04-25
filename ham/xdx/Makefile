# $NetBSD: Makefile,v 1.45 2015/04/25 14:23:21 tnn Exp $
#

DISTNAME=	xdx-2.4.3
PKGREVISION=	1
CATEGORIES=	ham
MASTER_SITES=	http://sourceforge.net/projects/xdxclusterclient/files/latest/download

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/xdxclusterclient/
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
