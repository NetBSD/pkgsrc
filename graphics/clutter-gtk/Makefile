# $NetBSD: Makefile,v 1.6 2009/10/26 08:51:01 obache Exp $
#

DISTNAME=	clutter-gtk-0.10.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.clutter-project.org/sources/clutter-gtk/0.10/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.clutter-project.org/
COMMENT=	GTK+ Integration library for Clutter
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

# Workaround for Upstream Bug#562310.
# for more detail, see also PR#41475.
TOOLS_NOOP+=		gtkdoc-rebase

PKGCONFIG_OVERRIDE+=	clutter-gtk.pc.in

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.12.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/clutter/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.clutter:Mx11)
CONFIGURE_ARGS+=	--with-flavour=x11
.else
PKG_FAIL_REASON+=	Require Clutter with X11 backend
.endif
.include "../../mk/bsd.pkg.mk"
