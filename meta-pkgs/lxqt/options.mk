# $NetBSD: options.mk,v 1.1 2020/04/26 03:13:14 gutteridge Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.lxqt
PKG_OPTIONS_OPTIONAL_GROUPS=	wm
PKG_OPTIONS_GROUP.wm=		openbox xfce4-wm
PKG_SUGGESTED_OPTIONS=		openbox
# wip/kwin and wm/xfce4-wm are known to work alternate options.
# See https://github.com/lxqt/lxqt/wiki/ConfigWindowManagers

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenbox)
DEPENDS+=	openbox>=3.6.1:../../wm/openbox
DEPENDS+=	obconf-qt>=0.14.1:../../wm/obconf-qt
.endif

.if !empty(PKG_OPTIONS:Mxfce4-wm)
DEPENDS+=	xfce4-wm>=4.14.0:../../wm/xfce4-wm
.endif
