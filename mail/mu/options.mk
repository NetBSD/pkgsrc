# $NetBSD: options.mk,v 1.1 2024/05/02 13:35:48 ktnb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mu
PKG_SUPPORTED_OPTIONS=	mu-emacs guile
PKG_SUGGESTED_OPTIONS=	mu-emacs

.include "../../mk/bsd.options.mk"

PLIST_SRC=	PLIST

###
###  Include the Emacs mu frontend, mu4e
###
.if !empty(PKG_OPTIONS:Mmu-emacs)
.include "../../editors/emacs/modules.mk"
INFO_FILES=	yes
USE_TOOLS+=	makeinfo
PLIST_SRC+=	PLIST.emacs
.else
MESON_ARGS+=	-Demacs=disabled
.endif

###
###  Support guile
###
.if !empty(PKG_OPTIONS:Mguile)
.include "../../lang/guile30/buildlink3.mk"
PLIST_SRC+=	PLIST.guile
# TODO: update for meson
# CONFIGURE_ENV+= ac_cv_path_GUILE=guile
USE_TOOLS+= makeinfo
MESON_ARGS+=	-Dguile=enabled
.else
MESON_ARGS+=	-Dguile=disabled
.endif
