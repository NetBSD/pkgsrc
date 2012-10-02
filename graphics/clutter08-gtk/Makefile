# $NetBSD: Makefile,v 1.12 2012/10/02 17:11:08 tron Exp $
#

DISTNAME=	clutter-gtk-0.8.3
PKGNAME=	${DISTNAME:S/clutter/clutter08/}
PKGREVISION=	11
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

# Workaround for Upstream Bug#562310.
# for more detail, see also PR#41475.
TOOLS_NOOP+=		gtkdoc-rebase

MAKE_ENV+=	DOC_MODULE_VERSION=0.8

PKGCONFIG_OVERRIDE+=	clutter-gtk.pc.in

.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.clutter08+=	clutter08>=0.8.7
.include "../../graphics/clutter08/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.clutter08:Mx11)
CONFIGURE_ARGS+=	--with-flavour=x11
.else
PKG_FAIL_REASON+=	Require Clutter with X11 backend
.endif
.include "../../mk/bsd.pkg.mk"
