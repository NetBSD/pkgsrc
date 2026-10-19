# $NetBSD: options.mk,v 1.1 2026/10/19 08:39:42 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.chipass
PKG_SUPPORTED_OPTIONS=		chipass-browser chipass-browser-passkey \
				chipass-fdosecrets chipass-keeshare \
				chipass-networking chipass-sshagent \
				chipass-yubikey
PKG_SUGGESTED_OPTIONS=		chipass-browser

.include "../../mk/bsd.options.mk"

# Enable/Disable KeepassXC-Browser extension support
.if !empty(PKG_OPTIONS:Mchipass-browser)
CMAKE_CONFIGURE_ARGS+=	-DCHIPASS_WITH_BROWSER=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DCHIPASS_WITH_BROWSER=OFF
.endif

# Enable/Disable Passkeys support for browser integration
.if !empty(PKG_OPTIONS:Mchipass-browser-passkey)
CMAKE_CONFIGURE_ARGS+=	-DCHIPASS_WITH_BROWSER_PASSKEYS=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DCHIPASS_WITH_BROWSER_PASSKEYS=OFF
.endif

# Enable/Disable Freedesktop.org Secrets Service support
.if !empty(PKG_OPTIONS:Mchipass-fdosecrets)
CMAKE_CONFIGURE_ARGS+=	-DCHIPASS_WITH_FDOSECRETS=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DCHIPASS_WITH_FDOSECRETS=OFF
.endif

# Enable/Disable KeeShare group synchronization extension
.if !empty(PKG_OPTIONS:Mchipass-keeshare)
CMAKE_CONFIGURE_ARGS+=	-DCHIPASS_WITH_KEESHARE==ON
.else
CMAKE_CONFIGURE_ARGS+=	-DCHIPASS_WITH_KEESHARE==OFF
.endif

# Enable/Disable Networking support
.if !empty(PKG_OPTIONS:Mchipass-networking)
CMAKE_CONFIGURE_ARGS+=	-DCHIPASS_WITH_NETWORKING=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DCHIPASS_WITH_NETWORKING=OFF
.endif

# Enable/Disable SSHAgent support
.if !empty(PKG_OPTIONS:Mchipass-sshagent)
CMAKE_CONFIGURE_ARGS+=	-DCHIPASS_ENABLE_SSHAGENT=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DCHIPASS_ENABLE_SSHAGENT=OFF
.endif

# Enable/Disable YubiKey HMAC-SHA1 authentication support
.if !empty(PKG_OPTIONS:Mchipass-yubikey)
CMAKE_CONFIGURE_ARGS+=	-DCHIPASS_ENABLE_YUBIKEY=ON
.include "../../security/pcsc-lite/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DCHIPASS_ENABLE_YUBIKEY=OFF
.endif
