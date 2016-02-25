# $NetBSD: Makefile,v 1.57 2016/02/25 15:49:43 jperkin Exp $
#

DISTNAME=		gstreamer-0.10.36
PKGNAME=		${DISTNAME:S/gstreamer/gstreamer0.10/}
PKGREVISION=		8
CATEGORIES=		multimedia gnome
MASTER_SITES=		http://gstreamer.freedesktop.org/src/gstreamer/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gstreamer.net/
COMMENT=		Open source multimedia framework

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		bison flex gmake perl pkg-config

# queue2 moved from gst-plugins-base to here
CONFLICTS+=		gst-plugins0.10-base<0.10.26

CONFIGURE_ARGS+=	--disable-examples
CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ENV+=		ac_cv_path_PYTHON=${TRUE:Q}
CONFIGURE_ENV+=		ac_cv_path_XSLTPROC=${TRUE:Q}

FLEX_REQD=		2.5.31

PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-base-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-base.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-check-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-check.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-controller-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-controller.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-dataprotocol-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-dataprotocol.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-net-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-net.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer.pc.in

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ENV.FreeBSD+=	ac_cv_func_register_printf_function="no"

.if ${OPSYS} == "NetBSD"
# We must have a glib2 compiled with the RTLD_GLOBAL fix; if not, plugins
# won't work at all.
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.4.0nb1
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.gstreamer
PKG_SUPPORTED_OPTIONS=	gstcheck
.include "../../mk/bsd.options.mk"

PLIST_VARS+=	gstcheck
.if !empty(PKG_OPTIONS:Mgstcheck)
.include "../../devel/check/buildlink3.mk"
PLIST.gstcheck=	yes
# don't worry if the "GstABI" check fails -- GstPlugin contains
# off_t and time_t which are system dependent
TEST_TARGET=	check-torture
.else
CONFIGURE_ARGS+= --disable-check
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
