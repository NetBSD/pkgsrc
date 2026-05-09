# $NetBSD: options.mk,v 1.1 2026/05/09 13:20:56 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome-online-accounts
PKG_SUPPORTED_OPTIONS=	doc gssapi
PKG_SUGGESTED_OPTIONS=	# empty

PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

#
# Build documentation
#
.if !empty(PKG_OPTIONS:Mdoc)
USE_TOOLS+=	gdbus-codegen
MESON_ARGS+=	-Ddocumentation=true
.  include "../../devel/py-gi-docgen/buildlink3.mk"
PLIST.doc=	yes
.else
MESON_ARGS+=	-Ddocumentation=false
.endif

#
# KRB5 support
#
.if !empty(PKG_OPTIONS:Mgssapi)
.  include "../../mk/krb5.buildlink3.mk"
KRB5_ACCEPTED=	mit-krb5
MESON_ARGS+=	-Dkerberos=true
.else
MESON_ARGS+=	-Dkerberos=false
.endif
