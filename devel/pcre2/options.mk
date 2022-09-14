# $NetBSD: options.mk,v 1.3 2022/09/14 09:35:01 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pcre2
PKG_SUPPORTED_OPTIONS=	pcre2-jit

.include "../../mk/bsd.options.mk"

.if (${MACHINE_ARCH} == "i386" || \
    ${MACHINE_ARCH} == "x86_64" || \
    ${MACHINE_ARCH} == "mips" || \
    ${MACHINE_ARCH} == "powerpc" || \
    ${MACHINE_ARCH} == "sparc" || \
    (!empty(MACHINE_ARCH:M*arm*) && empty(MACHINE_ARCH:M*armv4*)))
.if ${OPSYS} != "NetBSD"
# causes core dumps in rspamd
# https://mail-index.netbsd.org/pkgsrc-users/2022/09/11/msg036184.html
PKG_SUGGESTED_OPTIONS=	pcre2-jit
.endif
.endif

.if !empty(PKG_OPTIONS:Mpcre2-jit)
CONFIGURE_ARGS+=	--enable-jit
.endif
