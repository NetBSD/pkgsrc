# $NetBSD: Makefile,v 1.18 2022/06/28 10:37:32 nia Exp $
#

DISTNAME=	clutter-gtk-0.10.8
PKGNAME=	${DISTNAME:S/gtk-/gtk0.10-/}
PKGREVISION=	15
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/clutter-gtk/0.10/}
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Clutter
COMMENT=	GTK+ Integration library for Clutter (0.10)
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	clutter-gtk<0.12

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--enable-introspection=yes

PKGCONFIG_OVERRIDE+=	clutter-gtk.pc.in

BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=0.9.3
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.19.5
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.clutter+=	clutter>=1.2.0
.include "../../graphics/clutter/buildlink3.mk"
.if !${PKG_BUILD_OPTIONS.clutter:Mx11}
CONFIGURE_ARGS+=	--with-flavour=x11
.else
PKG_FAIL_REASON+=	"Requires Clutter with X11 backend"
.endif
.include "../../mk/bsd.pkg.mk"
