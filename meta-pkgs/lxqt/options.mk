# $NetBSD: options.mk,v 1.5 2021/11/19 11:49:53 pin Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.lxqt
PKG_OPTIONS_OPTIONAL_GROUPS=	wm
PKG_OPTIONS_GROUP.wm=		openbox xfce4-wm
PKG_SUGGESTED_OPTIONS=		openbox
# wip/kwin and wm/xfce4-wm are known to work alternate options.
# See https://github.com/lxqt/lxqt/wiki/ConfigWindowManagers

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenbox)
DEPENDS+=	openbox>=3.6.1:../../wm/openbox
.endif

.if !empty(PKG_OPTIONS:Mxfce4-wm)
DEPENDS+=	xfce4-wm>=4.14.6:../../wm/xfce4-wm
.endif
