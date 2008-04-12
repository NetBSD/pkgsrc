# $NetBSD: options.mk,v 1.5 2008/04/12 22:43:00 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.semi
PKG_SUPPORTED_OPTIONS=	semi-bbdb
PKG_OPTIONS_OPTIONAL_GROUPS=	semi-browser
PKG_OPTIONS_GROUP.semi-browser=	w3 w3m
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	bbdb w3

.if !empty(PKG_OPTIONS:Msemi-bbdb)
.include "../../misc/bbdb/buildlink3.mk"
PLIST.bbdb=	yes
.endif

.if !empty(PKG_OPTIONS:Mw3)
.include "../../www/w3/buildlink3.mk"
PLIST.w3=	yes
.endif

# XXX inter-dependency!?!?!?
#.if !empty(PKG_OPTIONS:Mw3m)
#.include "../../www/emacs-w3m/buildlink3.mk"
#.endif
