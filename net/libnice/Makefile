# $NetBSD: Makefile,v 1.23 2013/07/06 16:27:35 ryoon Exp $
#
# Also update net/gst-plugins1-libnice when you update this!

DISTNAME=	libnice-0.1.4
PKGREVISION=	1
CATEGORIES=	net devel
MASTER_SITES=	http://nice.freedesktop.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nice.freedesktop.org/wiki/
COMMENT=	IETF's draft Interactice Connectivity Establishment standard implementation
LICENSE=	gnu-lgpl-v2.1 OR mpl-1.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
CONFIGURE_ARGS+= --without-gstreamer

PKGCONFIG_OVERRIDE+=	nice/nice.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/gupnp-igd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
