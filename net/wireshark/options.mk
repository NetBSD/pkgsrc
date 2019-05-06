# $NetBSD: options.mk,v 1.23 2019/05/06 09:36:47 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wireshark
PKG_SUPPORTED_OPTIONS=	http2 lua qt5
PKG_SUGGESTED_OPTIONS=	qt5 lua

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		icons lua qt

.if !empty(PKG_OPTIONS:Mhttp2)
.  include "../../www/nghttp2/buildlink3.mk"
.else
CMAKE_ARGS+=		-DENABLE_NGHTTP2=OFF
.endif

.if !empty(PKG_OPTIONS:Mlua)
LUA_VERSIONS_INCOMPATIBLE=	53
.  include "../../lang/lua/buildlink3.mk"
PLIST.lua=		yes
.else
CMAKE_ARGS+=		-DENABLE_LUA=OFF
.endif

.if !empty(PKG_OPTIONS:Mqt5)
.  include "../../x11/qt5-qtsvg/buildlink3.mk"
.  include "../../x11/qt5-qttools/buildlink3.mk"
PLIST.qt=		yes
.  if ${OPSYS} == "Darwin"
.    include "../../x11/qt5-qtmacextras/buildlink3.mk"
.  else
PLIST.icons=		yes
.    include "../../x11/qt5-qtx11extras/buildlink3.mk"
POST_INSTALL_TARGETS+=	install-icons
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/scalable/apps
ICON_SIZES=		16 32 48
MIMEICON_SIZES=		16 24 32 48 64 128 256

.    for d in ${ICON_SIZES}
INSTALLATION_DIRS+=	share/icons/hicolor/${d}x${d}/apps
.    endfor

.    for d in ${MIMEICON_SIZES}
INSTALLATION_DIRS+=	share/icons/hicolor/${d}x${d}/mimetypes
.    endfor

.    include "../../sysutils/desktop-file-utils/desktopdb.mk"
.    include "../../graphics/hicolor-icon-theme/buildlink3.mk"

.PHONY: install-icons
install-icons:
	${INSTALL_DATA} ${WRKSRC}/image/wsicon.svg \
		${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps/wireshark.svg
.    for d in ${MIMEICON_SIZES}
	${INSTALL_DATA} ${WRKSRC}/image/WiresharkDoc-${d}.png \
		${DESTDIR}${PREFIX}/share/icons/hicolor/${d}x${d}/mimetypes/application-vnd.tcpdump.pcap.png
.    endfor
.  endif
.else
CMAKE_ARGS+=		-DBUILD_wireshark=OFF
.endif
