# $NetBSD: Makefile,v 1.32 2022/06/28 10:40:39 nia Exp $

DISTNAME=	cogl-1.22.0
PKGREVISION=	12
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/cogl/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cogl3d.org/
COMMENT=	Modern 3D graphics API
LICENSE=	mit AND sgi-free-software-b-v2.0 AND modified-bsd
# if --standalone
# LICENSE += AND gnu-lgpl-v2.1

CONFLICTS+=	clutter<1.8

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake gsed pkg-config msgfmt
USE_PKGLOCALEDIR=	yes

# Disable -Werror.
# code is not clean enough for modern compilers
CONFIGURE_ARGS+=	--enable-maintainer-flags=no
CONFIGURE_ARGS+=	--enable-introspection=yes

PKGCONFIG_OVERRIDE+=	cogl-gles2/cogl-gles2-experimental.pc.in
PKGCONFIG_OVERRIDE+=	cogl-pango/cogl-pango-1.0.pc.in
PKGCONFIG_OVERRIDE+=	cogl-pango/cogl-pango-2.0-experimental.pc.in
PKGCONFIG_OVERRIDE+=	cogl-pango/cogl-pango.pc.in
PKGCONFIG_OVERRIDE+=	cogl/cogl-1.0.pc.in
PKGCONFIG_OVERRIDE+=	cogl/cogl-2.0-experimental.pc.in

PKGCONFIG_OVERRIDE+=	cogl-pango/cogl-pango2.pc.in
PKGCONFIG_OVERRIDE+=	cogl-pango/cogl-pango.pc.in
PKGCONFIG_OVERRIDE+=	cogl/cogl2.pc.in
PKGCONFIG_OVERRIDE+=	cogl-gles2/cogl-gles2-experimental.pc.in
PKGCONFIG_OVERRIDE+=	cogl-gst/cogl-gst.pc.in
PKGCONFIG_OVERRIDE+=	cogl-path/cogl-path.pc.in

.include "options.mk"
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=0.9.5
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.32.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.pango+=	pango>=1.20.0
.include "../../devel/pango/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.10.0
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
