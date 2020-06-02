# $NetBSD: Makefile,v 1.38 2020/06/02 08:22:50 adam Exp $
#

.include "Makefile.common"
PKGREVISION=		14

#CONFIGURE_ARGS+=	--disable-silent-rules

COMMENT+=		Base plugins

# some plugins were moved from bad to base
CONFLICTS+=		gst-plugins0.10-bad<0.10.10

USE_TOOLS+=		perl:run
MAKE_JOBS_SAFE=		no
PKGCONFIG_OVERRIDE+=	pkgconfig/*.pc.in
REPLACE_PERL+=		tools/gst-visualise-m.m

PKG_OPTIONS_VAR=	PKG_OPTIONS.gst-plugins0.10-base
PKG_SUPPORTED_OPTIONS=	introspection
PKG_SUGGESTED_OPTIONS=	introspection
.include "../../mk/bsd.options.mk"

PLIST_VARS+=	introspection

# only useful if gstreamer was built with the "gstcheck" option
TEST_TARGET=		check-torture

# soft dependency only, .pc file not needed
#.include "../../textproc/iso-codes/buildlink3.mk"

.if !empty(PKG_OPTIONS:Mintrospection)
PLIST.introspection=	yes
.include "../../devel/gobject-introspection/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-introspection
.endif

.include "../../mk/bsd.pkg.mk"
