# $NetBSD: options.mk,v 1.4 2007/10/29 13:01:37 uebayasi Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.semi
PKG_SUPPORTED_OPTIONS=	semi-bbdb
PKG_OPTIONS_OPTIONAL_GROUPS=	semi-browser
PKG_OPTIONS_GROUP.semi-browser=	w3 w3m
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msemi-bbdb)
.include "../../misc/bbdb/buildlink3.mk"
PLIST_SUBST+=	FOR_bbdb=
.else
PLIST_SUBST+=	FOR_bbdb="@comment "
.endif

.if !empty(PKG_OPTIONS:Mw3)
.include "../../www/w3/buildlink3.mk"
PLIST_SUBST+=	FOR_w3=
.else
PLIST_SUBST+=	FOR_w3="@comment "
.endif

# XXX inter-dependency!?!?!?
#.if !empty(PKG_OPTIONS:Mw3m)
#.include "../../www/emacs-w3m/buildlink3.mk"
#.endif
