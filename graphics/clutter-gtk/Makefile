# $NetBSD: Makefile,v 1.53 2022/08/11 05:08:39 gutteridge Exp $

DISTNAME=	clutter-gtk-1.8.4
PKGREVISION=	5
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/clutter-gtk/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Clutter
COMMENT=	GTK+ Integration library for Clutter
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_TOOLS+=	pkg-config gmake
USE_TOOLS+=	msgfmt msgmerge xgettext

CONFIGURE_ARGS+=	--enable-introspection=yes

USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	clutter-gtk.pc.in

BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=0.9.12
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.6.0
.include "../../x11/gtk3/buildlink3.mk"
BUILDLINK_API_DEPENDS.clutter+=	clutter>=1.18.0
.include "../../graphics/clutter/buildlink3.mk"
.if !${PKG_BUILD_OPTIONS.clutter:Mx11}
PKG_FAIL_REASON+=	"Requires Clutter with X11 backend"
.endif
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
