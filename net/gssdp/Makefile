# $NetBSD: Makefile,v 1.56 2016/04/11 19:01:36 ryoon Exp $

DISTNAME=	gssdp-0.14.11
PKGREVISION=	6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gssdp/0.14/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gupnp.org/
COMMENT=	Simple Service Discovery Protocol library and device sniffer
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --without-gtk
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	gssdp-1.0.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
