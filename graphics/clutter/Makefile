# $NetBSD: Makefile,v 1.32.2.1 2012/10/03 12:07:56 spz Exp $
#

DISTNAME=	clutter-1.2.14
PKGREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	http://source.clutter-project.org/sources/clutter/1.2/
#		${MASTER_SITE_GNOME:=sources/clutter/1.2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://clutter-project.org/
COMMENT=	Open GL based interactive canvas library
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ARGS+=	--with-json=system

PKGCONFIG_OVERRIDE+=	clutter/cogl/cogl/cogl.pc.in
PKGCONFIG_OVERRIDE+=	clutter/x11/clutter-x11.pc.in
PKGCONFIG_OVERRIDE+=	clutter/win32/clutter-win32.pc.in
PKGCONFIG_OVERRIDE+=	clutter.pc.in

.include "options.mk"

TEST_TARGET=	check

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.pango+=	pango>=1.20.0
.include "../../devel/pango/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.6.0
.include "../../graphics/cairo/buildlink3.mk"
BUILDLINK_API_DEPENDS.json-glib+=	json-glib>=0.8.0
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
