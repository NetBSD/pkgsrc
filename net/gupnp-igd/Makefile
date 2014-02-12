# $NetBSD: Makefile,v 1.27 2014/02/12 17:53:02 drochner Exp $

DISTNAME=	gupnp-igd-0.2.3
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gupnp-igd/0.2/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gupnp.org/
COMMENT=	Library to handle UPnP IGD port mapping
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	gupnp-igd-1.0.pc.in

TEST_TARGET=	check

.include "../../net/gupnp/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.14.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
