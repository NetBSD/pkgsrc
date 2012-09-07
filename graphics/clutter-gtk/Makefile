# $NetBSD: Makefile,v 1.19 2012/09/07 19:16:42 adam Exp $
#

DISTNAME=	clutter-gtk-0.10.8
PKGREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://source.clutter-project.org/sources/clutter-gtk/0.10/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.clutter-project.org/
COMMENT=	GTK+ Integration library for Clutter
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	clutter-gtk.pc.in

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
