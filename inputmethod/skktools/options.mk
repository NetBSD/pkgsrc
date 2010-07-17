# $NetBSD: options.mk,v 1.1.1.1 2010/07/17 08:36:41 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.skktools
PKG_SUPPORTED_OPTIONS=	skkdic-expr2
PKG_SUGGESTED_OPTIONS=	skkdic-expr2

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	expr2

#
# Enable skkdic-expr2, faster tool.
#
.if !empty(PKG_OPTIONS:Mskkdic-expr2)
CONFIGURE_ARGS+=	--with-skkdic-expr2
.include "../../devel/glib2/buildlink3.mk"
USE_TOOLS+=	pkg-config
PLIST.expr2=	yes
.else
CONFIGURE_ARGS+=	--without-skkdic-expr2
.endif
