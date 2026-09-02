# $NetBSD: Makefile,v 1.45 2026/09/02 19:02:38 wiz Exp $

DISTNAME=	goocanvas-2.0.4
PKGNAME=	${DISTNAME:S/-/2-/}
PKGREVISION=	23
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/goocanvas/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://live.gnome.org/GooCanvas
COMMENT=	Cairo-based canvas widget for GTK+3.0
LICENSE=	gnu-lgpl-v2

TOOL_DEPENDS+=		glib2-introspection-[0-9]*:../../devel/glib2-introspection

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config msgfmt gmake
TOOLS_BROKEN+=		perl
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	goocanvas-2.0.pc.in

CFLAGS+=		-Wno-incompatible-pointer-types

TOOLS_NOOP+=		python
CONFIGURE_ARGS+=	--enable-python=no

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.28.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.10.0
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
