# $NetBSD: Makefile,v 1.9 2015/01/17 14:28:51 prlw1 Exp $

DISTNAME=	cogl-1.18.2
PKGREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/cogl/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cogl3d.org/
COMMENT=	Modern 3D graphics API
LICENSE=	mit AND sgi-free-software-b-v2.0 AND modified-bsd
# if --standalone
# LICENSE += AND gnu-lgpl-v2.1

CONFLICTS+=	clutter<1.8

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config msgfmt
USE_PKGLOCALEDIR=	yes

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

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.32.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.pango+=	pango>=1.20.0
.include "../../devel/pango/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.10.0
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
