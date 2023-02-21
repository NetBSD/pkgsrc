# $NetBSD: options.mk,v 1.31 2023/02/21 09:10:03 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.wireshark
PKG_SUPPORTED_OPTIONS=		http2 lua spandsp
PKG_OPTIONS_OPTIONAL_GROUPS=	gui
PKG_OPTIONS_GROUP.gui=		qt5 qt6
PKG_SUGGESTED_OPTIONS=		http2 lua

.if ${OPSYS} == "Darwin"
# problems building qt6 on Darwin as of 2023/01/30
PKG_SUGGESTED_OPTIONS+=	qt5
.else
PKG_SUGGESTED_OPTIONS+=	qt6
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		icons lua qt spandsp

.if !empty(PKG_OPTIONS:Mhttp2)
.  include "../../www/nghttp2/buildlink3.mk"
.else
CMAKE_ARGS+=		-DENABLE_NGHTTP2=OFF
.endif

.if !empty(PKG_OPTIONS:Mlua)
LUA_VERSIONS_ACCEPTED=	52 51
.  include "../../lang/lua/buildlink3.mk"
PLIST.lua=		yes
.else
CMAKE_ARGS+=		-DENABLE_LUA=OFF
.endif

.if !empty(PKG_OPTIONS:Mqt5) || !empty(PKG_OPTIONS:Mqt6)
.  if !empty(PKG_OPTIONS:Mqt5)
.    include "../../x11/qt5-qtsvg/buildlink3.mk"
.    include "../../x11/qt5-qttools/buildlink3.mk"
.    if ${OPSYS} == "Darwin"
.      include "../../x11/qt5-qtmacextras/buildlink3.mk"
.    else
.      include "../../x11/qt5-qtx11extras/buildlink3.mk"
.    endif
.  elif !empty(PKG_OPTIONS:Mqt6)
GCC_REQD+=		8 # std::filesystem
CMAKE_ARGS+=		-DUSE_qt6=ON
.    include "../../graphics/qt6-qtsvg/buildlink3.mk"
.    include "../../multimedia/qt6-qtmultimedia/buildlink3.mk"
.    include "../../devel/qt6-qttools/buildlink3.mk"
.    include "../../devel/qt6-qt5compat/buildlink3.mk"
.  endif
PLIST.qt=		yes
.  if ${OPSYS} != "Darwin"
PLIST.icons=		yes
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
	${INSTALL_DATA} ${WRKSRC}/resources/icons/wsicon.svg \
		${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps/wireshark.svg
.    for d in ${MIMEICON_SIZES}
	${INSTALL_DATA} ${WRKSRC}/resources/icons/WiresharkDoc-${d}.png \
		${DESTDIR}${PREFIX}/share/icons/hicolor/${d}x${d}/mimetypes/application-vnd.tcpdump.pcap.png
.    endfor
.  endif
.else
CMAKE_ARGS+=		-DBUILD_wireshark=OFF
.endif

.if !empty(PKG_OPTIONS:Mspandsp)
.include "../../comms/spandsp/buildlink3.mk"
PLIST.spandsp=		yes
CMAKE_ARGS+=		-DENABLE_SPANDSP=ON
.else
CMAKE_ARGS+=		-DENABLE_SPANDSP=OFF
.endif
