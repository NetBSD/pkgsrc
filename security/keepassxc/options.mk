# $NetBSD: options.mk,v 1.3 2025/02/10 20:03:36 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.keepassxc
PKG_SUPPORTED_OPTIONS=		keepassxc-browser keepassxc-browser-passkey \
				keepassxc-fdosecrets keepassxc-keeshare \
				keepassxc-networking keepassxc-sshagent \
				keepassxc-yubikey
PKG_SUGGESTED_OPTIONS=		keepassxc-browser

.include "../../mk/bsd.options.mk"

# Enable/Disable KeePassXC-Browser extension support
.if !empty(PKG_OPTIONS:Mkeepassxc-browser)
CMAKE_CONFIGURE_ARGS+=	-DWITH_XC_BROWSER=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_XC_BROWSER=OFF
.endif

# Enable/Disable Passkeys support for browser integration
.if !empty(PKG_OPTIONS:Mkeepassxc-browser-passkey)
CMAKE_CONFIGURE_ARGS+=	-DWITH_XC_BROWSER_PASSKEYS=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_XC_BROWSER_PASSKEYS=OFF
.endif

# Enable/Disable Freedesktop.org Secrets Service support
.if !empty(PKG_OPTIONS:Mkeepassxc-fdosecrets)
CMAKE_CONFIGURE_ARGS+=	-DWITH_XC_FDOSECRETS=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_XC_FDOSECRETS=OFF
.endif

# Enable/Disable KeeShare group synchronization extension
.if !empty(PKG_OPTIONS:Mkeepassxc-keeshare)
CMAKE_CONFIGURE_ARGS+=	-DWITH_XC_KEESHARE==ON
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_XC_KEESHARE==OFF
.endif

# Enable/Disable Networking support
.if !empty(PKG_OPTIONS:Mkeepassxc-networking)
CMAKE_CONFIGURE_ARGS+=	-DWITH_XC_NETWORKING=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_XC_NETWORKING=OFF
.endif

# Enable/Disable SSHAgent support
.if !empty(PKG_OPTIONS:Mkeepassxc-sshagent)
CMAKE_CONFIGURE_ARGS+=	-DWITH_XC_SSHAGENT=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_XC_SSHAGENT=OFF
.endif

# Enable/Disable YubiKey HMAC-SHA1 authentication support
.if !empty(PKG_OPTIONS:Mkeepassxc-yubikey)
CMAKE_CONFIGURE_ARGS+=	-DWITH_XC_YUBIKEY=ON
.include "../../devel/libusb1/buildlink3.mk"
.include "../../security/pcsc-lite/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_XC_YUBIKEY=OFF
.endif
