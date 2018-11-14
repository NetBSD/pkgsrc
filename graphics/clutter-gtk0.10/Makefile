# $NetBSD: Makefile,v 1.12 2018/11/14 22:21:36 kleink Exp $
#

DISTNAME=	clutter-gtk-0.10.8
PKGNAME=	${DISTNAME:S/gtk-/gtk0.10-/}
PKGREVISION=	10
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

PKGCONFIG_OVERRIDE+=	clutter-gtk.pc.in

.include "options.mk"

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.19.5
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.clutter+=	clutter>=1.2.0
.include "../../graphics/clutter/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.clutter:Mx11)
CONFIGURE_ARGS+=	--with-flavour=x11
.else
PKG_FAIL_REASON+=	Require Clutter with X11 backend
.endif
.include "../../mk/bsd.pkg.mk"
