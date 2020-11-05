# $NetBSD: Makefile,v 1.44 2020/11/05 09:07:03 ryoon Exp $

DISTNAME=	gupnp-av-0.12.7
PKGREVISION=	18
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gupnp-av/0.12/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gupnp.org/
COMMENT=	Helpers for audio/video applications using GUPnP
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	gupnp-av-1.0.pc.in

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../net/gupnp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
