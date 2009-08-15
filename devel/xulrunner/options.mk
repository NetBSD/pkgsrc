# $NetBSD: options.mk,v 1.3 2009/08/15 05:03:30 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xulrunner
PKG_SUPPORTED_OPTIONS=	debug mozilla-jemalloc

PLIST_VARS+=	jit

.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
PKG_SUGGESTED_OPTIONS+=	mozilla-jemalloc
.endif

.if !empty(MACHINE_ARCH:Mi386) || !empty(MACHINE_ARCH:Msparc) || \
	!empty(MACHINE_ARCH:Marm)
PKG_SUPPORTED_OPTIONS+=	mozilla-jit
PKG_SUGGESTED_OPTIONS+=	mozilla-jit
NANOJIT_ARCH.i386=	i386
NANOJIT_ARCH.arm=	ARM
NANOJIT_ARCH.sparc=	Sparc
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmozilla-jemalloc)
CONFIGURE_ARGS+=	--enable-jemalloc
.else
CONFIGURE_ARGS+=	--disable-jemalloc
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

.if !empty(PKG_OPTIONS:Mmozilla-jit)
PLIST.jit=		yes
PLIST_SUBST+=		NANOJIT_ARCH=${NANOJIT_ARCH.${MACHINE_ARCH}}
CONFIGURE_ARGS+=	--enable-jit
.else
CONFIGURE_ARGS+=	--disable-jit
.endif
