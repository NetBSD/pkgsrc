# $NetBSD: Makefile,v 1.36 2015/04/06 08:17:16 adam Exp $
#
# Also update net/gst-plugins1-libnice when you update this!

DISTNAME=	libnice-0.1.10
PKGREVISION=	1
CATEGORIES=	net devel
MASTER_SITES=	http://nice.freedesktop.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nice.freedesktop.org/wiki/
COMMENT=	IETF's draft Interactice Connectivity Establishment standard implementation
LICENSE=	gnu-lgpl-v2.1 OR mpl-1.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
CONFIGURE_ARGS+= --without-gstreamer

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
USE_LANGUAGES+=	c99
.endif

PKGCONFIG_OVERRIDE+=	nice/nice.pc.in

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
_WRAP_EXTRA_ARGS.CC+=	-Wunused-but-set-variable
CWRAPPERS_APPEND.cc+=	-Wunused-but-set-variable
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/gupnp-igd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
