# $NetBSD: Makefile,v 1.11 2012/09/15 10:06:01 obache Exp $
#

DISTNAME=	gupnp-av-0.5.4
PKGREVISION=	8
CATEGORIES=	net
MASTER_SITES=	http://www.gupnp.org/sources/gupnp-av/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gupnp.org/
COMMENT=	Helpers for audio/video applications using GUPnP
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
PKG_DESTDIR_SUPPORT= user-destdir

PKGCONFIG_OVERRIDE+=	gupnp-av-1.0.pc.in

.include "../../net/gupnp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
