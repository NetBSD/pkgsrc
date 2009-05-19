# $NetBSD: Makefile,v 1.3 2009/05/19 08:59:16 wiz Exp $
#

DISTNAME=	clutter-gtk-0.8.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.clutter-project.org/sources/clutter-gtk/0.8/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.clutter-project.org/
COMMENT=	GTK+ Integration library for Clutter
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	clutter-gtk.pc.in

.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.clutter+=	clutter>=0.8.7
.include "../../graphics/clutter/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.clutter:Mx11)
CONFIGURE_ARGS+=	--with-flavour=x11
.else
PKG_FAIL_REASON+=	Require Clutter with X11 backend
.endif
.include "../../mk/bsd.pkg.mk"
