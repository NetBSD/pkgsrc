# $NetBSD: Makefile,v 1.23 2012/07/03 18:20:51 joerg Exp $
#

DISTNAME=		audacious-1.5.1
PKGREVISION=		12
CATEGORIES=		audio
MASTER_SITES=		http://distfiles.atheme.org/
EXTRACT_SUFX=		.tbz2

MAINTAINER=		jfranz@bsdprojects.net
HOMEPAGE=		http://audacious-media-player.org/
COMMENT=		Media player based on BMP and XMMS

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--enable-chardet --enable-nls

PKGCONFIG_OVERRIDE+=	audacious.pc.in

PKG_OPTIONS_VAR=	PKG_OPTIONS.audacious
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

# for backtrace
.if ${OPSYS} == "NetBSD" && exists(/usr/include/execinfo.h)
LIBS+=  -lexecinfo
.endif

LIBS.SunOS+=		-lm -lX11
LDFLAGS.DragonFly=	-lm -lX11 -lgmodule-2.0

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libmcs/buildlink3.mk"
.include "../../devel/libmowgli/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
