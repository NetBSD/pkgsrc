# $NetBSD: Makefile,v 1.8 2006/08/23 09:45:16 jmmv Exp $
#

DISTNAME=	dbus-glib-0.71
CATEGORIES=	sysutils
MASTER_SITES=	http://freedesktop.org/software/dbus/releases/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/Software/dbus
COMMENT=	GLib bindings for the D-BUS message bus system

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake msgfmt pkg-config
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	dbus-glib-1.pc.in

CONFIGURE_ARGS+=	--disable-ansi
CONFIGURE_ARGS+=	--disable-asserts
CONFIGURE_ARGS+=	--disable-doxygen-docs
CONFIGURE_ARGS+=	--disable-gcov
CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ARGS+=	--disable-verbose-mode
CONFIGURE_ARGS+=	--disable-xml-docs
CONFIGURE_ARGS+=	--enable-checks
CONFIGURE_ARGS+=	--with-xml=expat

PKG_OPTIONS_VAR=	PKG_OPTIONS.dbus-glib
PKG_SUPPORTED_OPTIONS+=	debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-asserts
CONFIGURE_ARGS+=	--enable-tests
CONFIGURE_ARGS+=	--enable-verbose-mode
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
