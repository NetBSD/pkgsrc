# $NetBSD: options.mk,v 1.2 2005/02/20 21:50:57 cube Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.netbsd-tap
PKG_SUPPORTED_OPTIONS=	bpf
PKG_DEFAULT_OPTIONS?=	bpf

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbpf)
BUILD_ENV+=	USE_BPF=YES
.endif

TAP_KERNEL_ENV?=	# empty
BUILD_DEFS+=	TAP_KERNEL_ENV
MAKE_ENV+=	TAP_KERNEL_ENV=${TAP_KERNEL_ENV:Q}
