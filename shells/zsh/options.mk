# $NetBSD: options.mk,v 1.2 2017/10/13 09:35:19 jperkin Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.zsh
PKG_SUPPORTED_OPTIONS=		static

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		dynamic
.if !empty(PKG_OPTIONS:Mstatic)
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
