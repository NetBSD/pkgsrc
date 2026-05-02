# $NetBSD: options.mk,v 1.9 2026/05/02 12:41:52 pin Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.lxqt
PKG_OPTIONS_OPTIONAL_GROUPS=	wm
PKG_OPTIONS_GROUP.wm=		openbox xfce4-wm #labwc
PKG_SUGGESTED_OPTIONS=		openbox #labwc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenbox)
DEPENDS+=	openbox>=3.6.1:../../wm/openbox
DEPENDS+=	obconf-qt>=0.16.6:../../wm/obconf-qt
.endif

.if !empty(PKG_OPTIONS:Mxfce4-wm)
DEPENDS+=	xfce4-wm>=4.14.6:../../wm/xfce4-wm
.endif

# This needs to be commented out for now as wayland only works on NetBSD >=11.
# If you want to use LXQt under wayland you may want to use labwc.
# This option will also need to be added to /mk/defaults/options.description.
#.if !empty(PKG_OPTIONS:Mlabwc)
#DEPENDS+=	labwc>=0.9.7:../../wayland/labwc
#DEPENDS+=	labwc-tweaks>=0.1.0:../../wayland/labwc-tweaks
#.endif
