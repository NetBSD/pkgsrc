# $NetBSD: Makefile,v 1.13 2012/10/23 17:18:26 asau Exp $
#

DISTNAME=	gupnp-av-0.10.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gupnp-av/0.10/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gupnp.org/
COMMENT=	Helpers for audio/video applications using GUPnP
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	gupnp-av-1.0.pc.in

.include "../../net/gupnp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
