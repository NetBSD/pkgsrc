# $NetBSD: options.mk,v 1.4 2026/10/27 07:59:32 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.keepassxc
PKG_SUPPORTED_OPTIONS=		keepassxc-browser keepassxc-fdosecrets
PKG_SUPPORTED_OPTIONS+=		keepassxc-networking keepassxc-sshagent
PKG_SUGGESTED_OPTIONS=		keepassxc-browser

.include "../../mk/bsd.options.mk"

# Enable/Disable KeePassXC-Browser extension support
.if !empty(PKG_OPTIONS:Mkeepassxc-browser)
CMAKE_CONFIGURE_ARGS+=	-DKPXC_FEATURE_BROWSER=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DKPXC_FEATURE_BROWSER=OFF
.endif

# Enable/Disable Freedesktop.org Secrets Service support
.if !empty(PKG_OPTIONS:Mkeepassxc-fdosecrets)
CMAKE_CONFIGURE_ARGS+=	-DKPXC_FEATURE_FDOSECRETS=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DKPXC_FEATURE_FDOSECRETS=OFF
.endif

# Enable/Disable Networking support
.if !empty(PKG_OPTIONS:Mkeepassxc-networking)
CMAKE_CONFIGURE_ARGS+=	-DKPXC_FEATURE_NETWORK=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DKPXC_FEATURE_NETWORK=OFF
.endif

# Enable/Disable SSHAgent support
.if !empty(PKG_OPTIONS:Mkeepassxc-sshagent)
CMAKE_CONFIGURE_ARGS+=	-DKPXC_FEATURE_SSHAGENT=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DKPXC_FEATURE_SSHAGENT=OFF
.endif
