# $NetBSD: options.mk,v 1.2 2024/05/01 19:00:19 cheusov Exp $

## Our threading check here is the same as the one used in devel/perl5.
#
CHECK_BUILTIN.pthread:=yes
.include "../../mk/pthread.builtin.mk"
CHECK_BUILTIN.pthread:=no

PLIST_VARS+=		nls

## XXX I'm following the USE_FEATURES semantics used in security/openssl.
#
.if !empty(USE_BUILTIN.pthread:tl:Myes)
USE_FEATURES.dar=	threads
.else
USE_FEATURES.dar=	# empty
.endif

PKG_OPTIONS_VAR=		PKG_OPTIONS.dar
PKG_OPTIONS_OPTIONAL_GROUPS=	int
PKG_OPTIONS_GROUP.int=		dar-int32 dar-int64
PKG_SUGGESTED_OPTIONS=		dar-int64 ${USE_FEATURES.dar}
PKG_SUPPORTED_OPTIONS=		threads nls

.include "../../mk/bsd.options.mk"

## Dar is built by default with an arbitrary-size-integer library for
## managing all file length/timestamp details.  If 32-bit or 64-bit
## integers (with overflow protection) are sufficient for requirements,
## the following options can significantly reduce the run-time memory
## and CPU overheads of Dar.
#
DARBITS=		${PKG_OPTIONS:C/[^[:digit:]]*//:M[36][24]}
PLIST_SUBST+=		DARBITS=${DARBITS}

.if !empty(DARBITS)
CONFIGURE_ARGS+=	--enable-mode=${DARBITS:Q}
.endif

## We want the threading library to be specified by pkgsrc, and only
## when desired, viz. in the case below.  Using PTHREAD_AUTO_VARS
## with the accompanying BUILDLINK_TRANSFORM directive is easier
## then patching configure.
#
.if !empty(PKG_OPTIONS:Mthreads)
USE_FEATURES.openssl+=	threads
PTHREAD_AUTO_VARS=	yes
BUILDLINK_TRANSFORM+=	rm:-lpthread
.include "../../devel/libthreadar/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-thread-safe
.endif

# readline/editline
.if !empty(PKG_OPTIONS:Mnls)
CONFIGURE_ARGS+= --enable-nls
PLIST.nls=	yes
.else
CONFIGURE_ARGS+= --disable-nls
.endif
