# $NetBSD: options.mk,v 1.4 2020/11/09 12:02:25 micha Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.flnews
PKG_SUPPORTED_OPTIONS=	inet6 nls xdbe xdg-utils
PKG_SUGGESTED_OPTIONS=	inet6 nls xdbe xdg-utils

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

# POSIX.1c-1996 Threads (THR) extension is required
PTHREAD_OPTS+=	require

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
PLIST_VARS+=			nls
.if !empty(PKG_OPTIONS:Mnls)
PLIST.nls=			yes
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

# xdg: Optional support for XDG (Cross-Desktop Group, now freedesktop.org)
# - Install desktop file
# - Install icon-theme
# - xdg-utils (Portland project) dependency
#   Used for WWW browser and e-mail redirection
PLIST_VARS+=			xdg
.if !empty(PKG_OPTIONS:Mxdg-utils)
PLIST.xdg=			yes
FLNEWS_OPT_DISABLE_XDG=		0
DEPENDS+=	xdg-utils>=1.1:../../misc/xdg-utils
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.else
FLNEWS_OPT_DISABLE_XDG=		1
.endif
