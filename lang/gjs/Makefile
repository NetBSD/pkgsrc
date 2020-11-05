# $NetBSD: Makefile,v 1.6 2020/11/05 17:12:00 nia Exp $

DISTNAME=	gjs-1.64.3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gjs/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://live.gnome.org/Gjs
COMMENT=	Javascript binding for GNOME based on Spidermonkey
LICENSE=	mit

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/gjs@sha:${WRKSRC}/output/gjs-jsapi@sta:${WRKSRC}/output/gjs-console@exe
MESON_ARGS+=	-Dinstalled_tests=false

PKGCONFIG_OVERRIDE+=		output/meson-private/gjs-1.0.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.mozjs68+=	mozjs68>=68.6.0nb6
.include "../../lang/mozjs68/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
