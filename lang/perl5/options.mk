# $NetBSD: options.mk,v 1.3 2013/06/05 22:00:35 jperkin Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.perl
PKG_OPTIONS_REQUIRED_GROUPS=	perlbits
PKG_OPTIONS_GROUP.perlbits=	64bitauto 64bitint 64bitmore 64bitall 64bitnone
PKG_SUPPORTED_OPTIONS=		debug dtrace threads mstats

CHECK_BUILTIN.pthread:=	yes
.include "../../mk/pthread.builtin.mk"
CHECK_BUILTIN.pthread:=	no

# By default, build with threads only if the threads are native.
.if !empty(USE_BUILTIN.pthread:M[yY][eE][sS])
PERL5_BUILD_THREADS_SUPPORT=	yes
.else
PERL5_BUILD_THREADS_SUPPORT=	${DLOPEN_REQUIRE_PTHREADS}
.endif

# Needs to be include here for the broken-vax-pthreads hack
.include "hacks.mk"

.if !empty(PERL5_BUILD_THREADS_SUPPORT:M[yY][eE][sS])
PKG_SUGGESTED_OPTIONS=		threads
.endif

.if ${OPSYS} == "IRIX"
.  if defined(ABI) && ${ABI} == "64"
PKG_SUGGESTED_OPTIONS+=		64bitint
.  endif
.elif ${OPSYS} == "AIX"
.  if defined(ABI) && ${ABI} == "64"
PKG_SUGGESTED_OPTIONS+=		64bitall
.  else
PKG_SUGGESTED_OPTIONS+=		64bitnone
.  endif
.else
PKG_SUGGESTED_OPTIONS+=		64bitauto
.endif

.if ${OPSYS} == "Darwin" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "SunOS" 
PKG_SUGGESTED_OPTIONS+=		dtrace
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mthreads)
.  include "../../mk/pthread.buildlink3.mk"
CONFIGURE_ARGS+=	-Duseithreads
CFLAGS+=		${PTHREAD_CFLAGS}
LDFLAGS+=		${PTHREAD_LDFLAGS}
LIBSWANTED+=		${PTHREAD_LIBS:M-l*:S/^-l//}
.  if ${OBJECT_FMT} == "XCOFF"
PERL5_RPATH_THREAD=-thread
.  endif
.else
CONFIGURE_ARGS+=	-Uuseithreads
.  if ${OBJECT_FMT} == "XCOFF"
PERL5_RPATH_THREAD=
.  endif
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CFLAGS+=		-DDEBUGGING
.endif

.if !empty(PKG_OPTIONS:Mdtrace)
CONFIGURE_ARGS+=	-Dusedtrace
# perldtrace.h has incorrect dependencies, needs to be built first.
BUILD_TARGET=		perldtrace.h all
.endif

.if !empty(PKG_OPTIONS:Mmstats)
CFLAGS+=		-DPERL_DEBUGGING_MSTATS
CONFIGURE_ARGS+=	-Dusemymalloc
.else
CONFIGURE_ARGS+=	-Uusemymalloc
.endif

.if !empty(PKG_OPTIONS:M64bitint)
CONFIGURE_ARGS+=	-Duse64bitint
.elif !empty(PKG_OPTIONS:M64bitmore)
CONFIGURE_ARGS+=	-Dusemorebits
.elif !empty(PKG_OPTIONS:M64bitall)
CONFIGURE_ARGS+=	-Duse64bitall
.elif !empty(PKG_OPTIONS:M64bitnone)
CONFIGURE_ARGS+=	-Uuse64bitall -Uusemorebits -Uuse64bitint
.else
.  if ${OBJECT_FMT} == "XCOFF"
BROKEN=		XCOFF targets need the path specified where libperl.a resides.\
Please choose on of 64bitint 64bitmore 64bitall or 64bitnone to allow this.
.  endif
.endif
