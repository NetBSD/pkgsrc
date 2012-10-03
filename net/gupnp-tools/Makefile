# $NetBSD: Makefile,v 1.18.2.1 2012/10/03 12:09:06 spz Exp $
#

DISTNAME=	gupnp-tools-0.8
PKGREVISION=	14
CATEGORIES=	net
MASTER_SITES=	http://www.gupnp.org/sources/gupnp-tools/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gupnp.org/
COMMENT=	Framework for UPnP devices
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
PKG_DESTDIR_SUPPORT= user-destdir

.include "../../net/gupnp/buildlink3.mk"
.include "../../net/gupnp-av/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
