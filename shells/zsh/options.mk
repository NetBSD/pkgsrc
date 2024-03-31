# $NetBSD: options.mk,v 1.7 2024/03/31 22:08:42 js Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.zsh
PKG_SUPPORTED_OPTIONS=		debug static

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-zsh-debug
CONFIGURE_ARGS+=	--enable-zsh-hash-debug
CONFIGURE_ARGS+=	--enable-zsh-heap-debug
CONFIGURE_ARGS+=	--enable-zsh-mem-debug
CONFIGURE_ARGS+=	--enable-zsh-mem-warning
CONFIGURE_ARGS+=	--enable-zsh-secure-free
CONFIGURE_ARGS+=	--enable-zsh-mem
.endif

PLIST_VARS+=		dynamic
.if !empty(PKG_OPTIONS:Mstatic) || ${OPSYS} == "QNX"
CONFIGURE_ARGS+=	--disable-dynamic
.  if ${OPSYS} != "Darwin" && ${OPSYS} != "SunOS"
LDFLAGS+=		-static
.  endif
.else
PLIST.dynamic=		yes
.endif
PRINT_PLIST_AWK+=	{if ($$0 ~ /\.so$$/) {$$0 = "$${PLIST.dynamic}" $$0;}}
PRINT_PLIST_AWK+=	{if ($$0 ~ /functions\/tcp/) {$$0 = "$${PLIST.dynamic}" $$0;}}
PRINT_PLIST_AWK+=	{if ($$0 ~ /functions\/zf/) {$$0 = "$${PLIST.dynamic}" $$0;}}
PRINT_PLIST_AWK+=	{if ($$0 ~ /functions\/zsh-newuser/) {$$0 = "$${PLIST.dynamic}" $$0;}}
PRINT_PLIST_AWK+=	{if ($$0 ~ /scripts\/newuser/) {$$0 = "$${PLIST.dynamic}" $$0;}}
