# $NetBSD: Makefile,v 1.1.1.1 2008/12/14 11:06:42 obache Exp $
#

DISTNAME=	clutter-gtk-0.8.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.clutter-project.org/sources/clutter-gtk/0.8/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.clutter-project.org/
COMMENT=	GTK+ Integration library for Clutter

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	clutter-gtk.pc.in

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/clutter/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.clutter:Mx11)
CONFIGURE_ARGS+=	--with-flavour=x11
.else
PKG_FAIL_REASON+=	Require Clutter with X11 backend
.endif
.include "../../mk/bsd.pkg.mk"
