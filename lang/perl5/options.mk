# $NetBSD: options.mk,v 1.19 2023/07/06 09:22:14 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.perl
PKG_OPTIONS_REQUIRED_GROUPS=	perlbits
PKG_OPTIONS_GROUP.perlbits=	perl-64bitauto perl-64bitint perl-64bitmore perl-64bitall perl-64bitnone
PKG_SUPPORTED_OPTIONS=		debug dtrace threads mstats

CHECK_BUILTIN.pthread:=	yes
.include "../../mk/pthread.builtin.mk"
CHECK_BUILTIN.pthread:=	no

# By default, build with threads only if the threads are native.
.if ${USE_BUILTIN.pthread:tl} == yes
PERL5_BUILD_THREADS_SUPPORT=	yes
.else
PERL5_BUILD_THREADS_SUPPORT=	${DLOPEN_REQUIRE_PTHREADS}
.endif

### from KNOWN PROBLEMS in README.haiku
### Perl cannot be compiled with threading support ATM.
###
.if ${MACHINE_PLATFORM:MHaiku-*-*}
PERL5_BUILD_THREADS_SUPPORT=	no
.endif

# miniperl fails with locking errors during build on QNX.
.if ${OPSYS} == "QNX"
PERL5_BUILD_THREADS_SUPPORT=	no
.endif

.if !empty(PERL5_BUILD_THREADS_SUPPORT:M[yY][eE][sS])
PKG_SUGGESTED_OPTIONS=		threads
.endif

.if ${OPSYS} == "IRIX"
.  if defined(ABI) && ${ABI} == "64"
PKG_SUGGESTED_OPTIONS+=		perl-64bitint
.  endif
.elif ${OPSYS} == "AIX"
.  if defined(ABI) && ${ABI} == "64"
PKG_SUGGESTED_OPTIONS+=		perl-64bitall
.  else
PKG_SUGGESTED_OPTIONS+=		perl-64bitnone
.  endif
.else
PKG_SUGGESTED_OPTIONS+=		perl-64bitauto
.endif

.if (${OPSYS} == "SunOS" && ${OPSYS_VERSION} >= 051100) || \
    (${OPSYS} == "Darwin" && ${OPSYS_VERSION} >= 100500)
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
.endif

.if !empty(PKG_OPTIONS:Mmstats)
CFLAGS+=		-DPERL_DEBUGGING_MSTATS
CONFIGURE_ARGS+=	-Dusemymalloc
.else
CONFIGURE_ARGS+=	-Uusemymalloc
.endif

.if !empty(PKG_OPTIONS:Mperl-64bitint)
CONFIGURE_ARGS+=	-Duse64bitint
.elif !empty(PKG_OPTIONS:Mperl-64bitmore)
CONFIGURE_ARGS+=	-Dusemorebits
.elif !empty(PKG_OPTIONS:Mperl-64bitall)
CONFIGURE_ARGS+=	-Duse64bitall
.elif !empty(PKG_OPTIONS:Mperl-64bitnone)
CONFIGURE_ARGS+=	-Uuse64bitall -Uusemorebits -Uuse64bitint
.else
.  if ${OBJECT_FMT} == "XCOFF"
BROKEN=			"XCOFF targets need the path specified where libperl.a resides."
BROKEN+=		"Please choose on of perl-64bitint perl-64bitmore perl-64bitall or perl-64bitnone to allow this."
.  endif
.endif
