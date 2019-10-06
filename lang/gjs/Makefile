# $NetBSD: Makefile,v 1.1 2019/10/06 15:50:31 fox Exp $

DISTNAME=	gjs-1.53.4
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gjs/1.53/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/Gjs
COMMENT=	Javascript binding for GNOME based on Spidermonkey
LICENSE=	mit

BUILD_DEPENDS+=	autoconf-archive-[0-9]*:../../devel/autoconf-archive

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf autoreconf automake
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	gjs-1.0.pc.in

CONFIGURE_ARGS+=	--disable-profiler
CONFIGURE_ARGS+=	--prefix=${PREFIX}

LDFLAGS.NetBSD+=	${X11_LDFLAGS}

# Needed by the Javascript JIT used in gjs
NOT_PAX_MPROTECT_SAFE+=	bin/gjs-console
NOT_PAX_MPROTECT_SAFE+=	bin/gjs

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} autoreconf -vfi

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/spidermonkey52/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
