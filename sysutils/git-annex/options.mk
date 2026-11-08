# $NetBSD: options.mk,v 1.4 2026/11/08 18:10:53 pho Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.git-annex
PKG_SUPPORTED_OPTIONS=	dbus debug
PKG_SUGGESTED_OPTIONS=	dbus

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} != "SunOS"
PKG_SUPPORTED_OPTIONS+=	git-annex-assistant
PKG_SUGGESTED_OPTIONS+=	git-annex-assistant
.endif

.include "../../mk/bsd.options.mk"

###
### Enable D-Bus and desktop notification support
###
.if ${PKG_OPTIONS:Mdbus}
CONFIGURE_ARGS+=	-f +Dbus
.  include "../../sysutils/hs-dbus/buildlink3.mk"
.  include "../../sysutils/hs-fdo-notify/buildlink3.mk"
.else
CONFIGURE_ARGS+=	-f -Dbus
.endif

###
### Enable debugging
###
.if ${PKG_OPTIONS:Mdebug}
CONFIGURE_ARGS+=	-f +DebugLocks
.else
CONFIGURE_ARGS+=	-f -DebugLocks
.endif

###
### Enable git-annex assistant, webapp, and watch command
###
.if ${PKG_OPTIONS:Mgit-annex-assistant}
CONFIGURE_ARGS+=	-f +assistant
.  include "../../sysutils/hs-mountpoints/buildlink3.mk"
.  include "../../www/hs-path-pieces/buildlink3.mk"
.  include "../../www/hs-wai/buildlink3.mk"
.  include "../../www/hs-wai-extra/buildlink3.mk"
.  include "../../devel/hs-blaze-builder/buildlink3.mk"
.  include "../../www/hs-clientsession/buildlink3.mk"
.  include "../../textproc/hs-shakespeare/buildlink3.mk"
.  include "../../www/hs-yesod/buildlink3.mk"
.  include "../../www/hs-yesod-static/buildlink3.mk"
.  include "../../www/hs-yesod-form/buildlink3.mk"
.  include "../../www/hs-yesod-core/buildlink3.mk"
.else
CONFIGURE_ARGS+=	-f -assistant
.endif
