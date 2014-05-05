# $NetBSD: Makefile,v 1.8 2014/05/05 00:47:55 ryoon Exp $
#

DISTNAME=	cogl-1.16.2
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/cogl/1.16/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cogl3d.org/
COMMENT=	Modern 3D graphics API
LICENSE=	gnu-lgpl-v2.1

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

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.32.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.pango+=	pango>=1.20.0
.include "../../devel/pango/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.10.0
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
