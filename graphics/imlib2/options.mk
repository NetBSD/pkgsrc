# $NetBSD: options.mk,v 1.6 2007/06/13 14:01:11 obache Exp $

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.imlib2
PKG_SUPPORTED_OPTIONS=	#empty
.if ${MACHINE_ARCH} == "i386"
PKG_SUPPORTED_OPTIONS+=	mmx
.elif ${MACHINE_ARCH} == "x86_64"
PKG_SUPPORTED_OPTIONS+=	imlib2-amd64
PKG_SUGGESTED_OPTIONS+=	imlib2-amd64
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmmx)
CONFIGURE_ARGS+=	--enable-mmx
.endif

.if !empty(PKG_OPTIONS:Mimlib2-amd64)
CONFIGURE_ARGS+=	--enable-amd64
.endif
