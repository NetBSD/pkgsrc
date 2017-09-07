# $NetBSD: options.mk,v 1.2 2017/09/07 14:50:44 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pcre2
PKG_SUPPORTED_OPTIONS=	pcre2-jit

.if (${MACHINE_ARCH} == "i386" || \
    ${MACHINE_ARCH} == "x86_64" || \
    ${MACHINE_ARCH} == "mips" || \
    ${MACHINE_ARCH} == "powerpc" || \
    ${MACHINE_ARCH} == "sparc" || \
    (!empty(MACHINE_ARCH:M*arm*) && empty(MACHINE_ARCH:M*armv4*)))
PKG_SUGGESTED_OPTIONS=	pcre2-jit
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpcre2-jit)
CONFIGURE_ARGS+=	--enable-jit
.endif
