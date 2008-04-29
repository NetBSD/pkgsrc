# $NetBSD: options.mk,v 1.1 2008/04/29 11:40:50 wiz Exp $

# Loadable filter currently don't work on NetBSD, see
# https://sourceforge.net/tracker/?func=detail&atid=100245&aid=1336865&group_id=245
# Disable dynamic loading of filters until it is fixed.
PKG_OPTIONS_VAR=	PKG_OPTIONS.aspell
PKG_SUPPORTED_OPTIONS=	# none
#PKG_SUPPORTED_OPTIONS=	aspell-loadable-filters

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		filters
.if !empty(PKG_OPTIONS:Maspell-loadable-filters)
CONFIGURE_ARGS+=	--disable-compile-in-filters
PLIST.filters=		yes
.else
CONFIGURE_ARGS+=	--enable-compile-in-filters
.endif
