# $NetBSD: options.mk,v 1.1.1.1 2005/01/20 18:02:39 cube Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.netbsd-tap
PKG_SUPPORTED_OPTIONS=	bpf
PKG_DEFAULT_OPTIONS?=	bpf

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbpf)
BUILD_ENV+=	USE_BPF=YES
.endif
