# $NetBSD: Makefile,v 1.1.1.1 2008/10/20 09:28:51 wiz Exp $
#

DISTNAME=		audacious-1.5.0
CATEGORIES=		audio
MASTER_SITES=		http://distfiles.atheme.org/
EXTRACT_SUFX=		.tbz2

MAINTAINER=		jfranz@bsdprojects.net
HOMEPAGE=		http://audacious-media-player.org/
COMMENT=		Media player based on BMP and XMMS

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool pkg-config
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_DIRS+=		xdg-1.4

CONFIGURE_ARGS+=	--enable-chardet --enable-nls

PKGCONFIG_OVERRIDE+=	audacious.pc.in

PKG_OPTIONS_VAR=	PKG_OPTIONS.audacious
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libmcs/buildlink3.mk"
.include "../../devel/mowgli/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
