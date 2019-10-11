# $NetBSD: Makefile,v 1.80 2019/10/11 16:32:13 kamil Exp $

DISTNAME=	gssdp-1.0.3
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gssdp/1.0/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gupnp.org/
COMMENT=	Simple Service Discovery Protocol library and device sniffer (1.0 branch)
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --without-gtk
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	gssdp-1.0.pc.in

.include "../../archivers/brotli/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
