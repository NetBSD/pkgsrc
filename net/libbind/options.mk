# $NetBSD: options.mk,v 1.1.1.1 2010/04/15 12:57:49 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.libbind
PKG_SUPPORTED_OPTIONS=	threads inet6

.include "../../mk/bsd.prefs.mk"

CHECK_BUILTIN.pthread:=	yes
.include "../../mk/pthread.builtin.mk"
CHECK_BUILTIN.pthread:=	no

.if !empty(IS_BUILTIN.pthread:M[yY][eE][sS])
PKG_SUGGESTED_OPTIONS+=	threads
.endif

.if empty(MISSING_FEATURES:Minet6)
PKG_SUGGESTED_OPTIONS+=	inet6
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mthreads)
CONFIGURE_ARGS+=	--enable-threads
.include "../../mk/pthread.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-threads
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
