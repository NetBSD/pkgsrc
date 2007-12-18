# $NetBSD: options.mk,v 1.2 2007/12/18 14:25:21 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libast
PKG_SUPPORTED_OPTIONS=	# empty

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
PKG_SUPPORTED_OPTIONS+=	mmx
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmmx)
CONFIGURE_ARGS+=	--enable-mmx
.endif
