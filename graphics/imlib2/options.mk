# $NetBSD: options.mk,v 1.3 2005/06/10 18:21:45 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.imlib2
PKG_SUPPORTED_OPTIONS=	mmx

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.prefs.mk"

.if !empty(PKG_OPTIONS:Mmmx)
.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-mmx
.endif
.endif
