# $NetBSD: Makefile,v 1.50 2017/09/06 09:03:02 wiz Exp $
#

DISTNAME=	xdx-2.5.0
PKGREVISION=	3
CATEGORIES=	ham
MASTER_SITES=	https://sourceforge.net/projects/xdxclusterclient/files/latest/download

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/xdxclusterclient/
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
