# $NetBSD: Makefile,v 1.6 2009/10/26 08:45:51 obache Exp $
#

DISTNAME=	clutter-1.0.8
CATEGORIES=	graphics
MASTER_SITES=	http://www.clutter-project.org/sources/clutter/1.0/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://clutter-project.org/
COMMENT=	Open GL based interactive canvas library
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ARGS+=	--with-json=check

PKGCONFIG_OVERRIDE+=	clutter/x11/clutter-x11.pc.in
PKGCONFIG_OVERRIDE+=	clutter/win32/clutter-win32.pc.in
PKGCONFIG_OVERRIDE+=	clutter.pc.in

# Workaround for Upstream Bug#562310.
# for more detail, see also PR#41475.
TOOLS_NOOP+=	gtkdoc-rebase

.include "options.mk"

TEST_TARGET=	check

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.pango+=	pango>=1.20.0
.include "../../devel/pango/buildlink3.mk"
BUILDLINK_API_DEPENDS.json-glib+=	json-glib>=0.7.4
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
