# $NetBSD: options.mk,v 1.3 2021/11/15 19:39:27 kim Exp $

.if !empty(PKGNAME:Mstandalone-tcsh-[0-9]*)
PKG_OPTIONS_VAR=	PKG_OPTIONS.standalone-tcsh
.elif !empty(PKGNAME:Mstatic-tcsh-[0-9]*)
PKG_OPTIONS_VAR=	PKG_OPTIONS.static-tcsh
.else
PKG_OPTIONS_VAR=	PKG_OPTIONS.tcsh
.endif

PKG_SUPPORTED_OPTIONS=	nls
PKG_SUGGESTED_OPTIONS=	nls
.if empty(PKGNAME:Mstatic-tcsh-[0-9]*)
PKG_SUPPORTED_OPTIONS+=	static
.  if !empty(PKGNAME:Mstandalone-tcsh-[0-9]*) && ${OPSYS} != "SunOS"
PKG_SUGGESTED_OPTIONS+=	static
.  endif
.endif

PLIST_VARS+=		nls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnls)
PLIST.nls=		yes
.else
CONFIGURE_ARGS+=	--disable-nls-catalogs
.endif

.if !empty(PKG_OPTIONS:Mstatic) || !empty(PKGNAME:Mstatic-tcsh-[0-9]*)
LDFLAGS+=		-static

# SunOS 5.10 stopped shipping static libraries.
NOT_FOR_PLATFORM+=	SunOS-5.1[0-9]-*
.endif

PRINT_PLIST_AWK+=	{if ($$0 ~ /\.cat$$/) {$$0 = "$${PLIST.nls}" $$0;}}
