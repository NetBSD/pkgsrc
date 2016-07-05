# $NetBSD: options.mk,v 1.10 2016/07/05 01:26:59 dholland Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ecl
PKG_SUPPORTED_OPTIONS+=		debug threads unicode ffi clx
PKG_SUGGESTED_OPTIONS+=		unicode ffi clx
# Unicode support proved to break Axioms.
# Threads are off, since threaded ECL requires threads support
# in Boehm GC (off by default).

.include "../../mk/bsd.options.mk"

PLIST_SRC=	PLIST	# default value

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Mthreads)
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ENV+=		THREAD_CFLAGS=${PTHREAD_CFLAGS:Q}
CONFIGURE_ENV+=		THREAD_LDFLAGS=${BUILDLINK_LDFLAGS.pthread:Q}
CONFIGURE_ENV+=		THREAD_LIBS=${BUILDLINK_LIBS.pthread:Q}
# XXX Although NetBSD-6+ supports TLS, ECL oddly crashes on startup
# on NetBSD-6 when it's used here.  Untested yet with NetBSD-7.
.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "Linux" || ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--with-__thread=yes
.else
CONFIGURE_ARGS+=	--with-__thread=no
.endif
.include "../../mk/pthread.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-threads
.endif

.if !empty(PKG_OPTIONS:Municode)
CONFIGURE_ARGS+=	--enable-unicode
.else
CONFIGURE_ARGS+=	--disable-unicode
.endif

.if !empty(PKG_OPTIONS:Mffi)
.include "../../devel/libffi/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-dffi=no
.endif

.if !empty(PKG_OPTIONS:Mclx)
CONFIGURE_ARGS+=	--with-clx
.endif

PLIST_VARS+=		clx unicode

.for option in clx unicode
.  if !empty(PKG_OPTIONS:M${option})
PLIST.${option}=	yes
.  endif
.endfor

# Help generating PLIST:
.if !empty(PKG_OPTIONS:Mclx)
PRINT_PLIST_AWK+=	{if ($$0 ~ /lib\/.*\/libclx.a$$/) {$$0 = "$${PLIST.clx}" $$0;}}
PRINT_PLIST_AWK+=	{if ($$0 ~ /lib\/.*\/clx.(asd|fas)$$/) {$$0 = "$${PLIST.clx}" $$0;}}
.endif

.if !empty(PKG_OPTIONS:Municode)
PRINT_PLIST_AWK+=	{if ($$0 ~ /lib\/.*\/encodings\//) {$$0 = "$${PLIST.unicode}" $$0;}}
.endif
