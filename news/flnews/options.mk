# $NetBSD: options.mk,v 1.1 2018/08/20 12:57:34 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.flnews
PKG_SUPPORTED_OPTIONS=	inet6 nls xdbe xdg-utils
PKG_SUGGESTED_OPTIONS=	xdbe xdg-utils

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

# inet6: Optional support for Internet Protocol Version 6 (IPv6)
# Requires an OS with POSIX.1-2001 API and IP6 option
.if !empty(PKG_OPTIONS:Minet6)
FLNEWS_OPT_DISABLE_IP6=		0
.else
FLNEWS_OPT_DISABLE_IP6=		1
.endif

# nls: Optional support for National Language Support (NLS)
# Requires an OS with X/Open XSI extension API (SUSv2) and the gencat utility
# Note: Only locales with UTF-8, ISO-8859-1 or US-ASCII codeset are supported!
PLIST_VARS+=	nls
.if !empty(PKG_OPTIONS:Mnls)
PLIST.nls=	yes
FLNEWS_OPT_DISABLE_NLS=		0
.else
FLNEWS_OPT_DISABLE_NLS=		1
.endif

# xdbe: Optional support for X11 Double Buffer Extension (XDBE)
# This option should be disabled for slow machines
.if !empty(PKG_OPTIONS:Mxdbe)
FLNEWS_OPT_DISABLE_XDBE=	0
.else
FLNEWS_OPT_DISABLE_XDBE=	1
.endif

# xdg-utils: Create dependency for xdg-utils (Portland project)
# xdg-utils are used for WWW-Browser and eMail redirection
.if !empty(PKG_OPTIONS:Mxdg-utils)
DEPENDS+=	xdg-utils>=1.1:../../misc/xdg-utils
.endif
