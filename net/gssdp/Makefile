# $NetBSD: Makefile,v 1.60 2016/12/04 21:56:30 marino Exp $

DISTNAME=	gssdp-1.0.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gssdp/1.0/}
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
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
