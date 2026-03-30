# $NetBSD: options.mk,v 1.3 2026/03/30 15:11:36 ktnb Exp $

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
.include "../../sysutils/dbus/buildlink3.mk"
INFO_FILES=	yes
USE_TOOLS+=	makeinfo
PLIST_SRC+=	PLIST.emacs
EMACS_VERSIONS_ACCEPTED=	emacs30 emacs30nox emacs29 emacs29nox
EMACS_VERSIONS_ACCEPTED+=	emacs28 emacs28nox
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
MESON_ARGS+=	-Dscm=enabled
.else
MESON_ARGS+=	-Dscm=disabled
.endif
