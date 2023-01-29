# $NetBSD: Makefile,v 1.62 2023/01/29 21:16:51 ryoon Exp $
#

DISTNAME=	xdx-2.5.0
PKGREVISION=	14
CATEGORIES=	ham
MASTER_SITES=	https://sourceforge.net/projects/xdxclusterclient/files/latest/download

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/xdxclusterclient/
COMMENT=	Amateur Radio tcp/ip DX-cluster client
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

LDFLAGS.SunOS+=	-lsocket -lnsl -lresolv

BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
