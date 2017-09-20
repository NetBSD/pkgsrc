# $NetBSD: options.mk,v 1.15 2017/09/20 19:49:38 adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.wireshark
PKG_SUPPORTED_OPTIONS=		gtk3 lua
PKG_OPTIONS_OPTIONAL_GROUPS=	qt
PKG_OPTIONS_GROUP.qt=		qt4 qt5
PKG_SUGGESTED_OPTIONS=		gtk3 lua
.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gtk3 icons lua mans qt

.if empty(PKG_OPTIONS:Mqt4) && empty(PKG_OPTIONS:Mqt5)
CONFIGURE_ARGS+=	--without-qt
.else
.  if !empty(PKG_OPTIONS:Mqt4)
CONFIGURE_ARGS+=	--with-qt=4
.    include "../../x11/qt4-tools/buildlink3.mk"
.  elif !empty(PKG_OPTIONS:Mqt5)
CONFIGURE_ARGS+=	--with-qt=5
.    include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.    include "../../x11/qt5-qttools/buildlink3.mk"
.    if ${OPSYS} == "Darwin"
.      include "../../x11/qt5-qtmacextras/buildlink3.mk"
.    else
.      include "../../x11/qt5-qtx11extras/buildlink3.mk"
.    endif
.  endif
CONFIGURE_ENV+=		LRELEASE=${QTDIR}/bin/lrelease
CONFIGURE_ENV+=		MOC=${QTDIR}/bin/moc
CONFIGURE_ENV+=		RCC=${QTDIR}/bin/rcc
CONFIGURE_ENV+=		UIC=${QTDIR}/bin/uic
PLIST.qt=		yes
.endif

.if empty(PKG_OPTIONS:Mgtk3)
CONFIGURE_ARGS+=	--without-gtk3
.else
CONFIGURE_ARGS+=	--with-gtk3
PLIST.gtk3=		yes
POST_INSTALL_TARGETS+=	install-gtk-desktop
.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/adwaita-icon-theme/buildlink3.mk"

.PHONY: install-gtk-desktop
install-gtk-desktop:
	${INSTALL_DATA} ${WRKSRC}/wireshark.desktop \
		${DESTDIR}${PREFIX}/share/applications/

.endif

# We might install the qt front end one day as well,
# so have a generic icon target
.if empty(PKG_OPTIONS:Mgtk3) && empty(PKG_OPTIONS:Mqt4) && empty(PKG_OPTIONS:Mqt5)
CONFIGURE_ARGS+=	--disable-wireshark
.else
CONFIGURE_ARGS+=	--enable-wireshark
PLIST.mans=		yes
INSTALLATION_DIRS+=	share/applications
.  if ${OPSYS} != "Darwin"
PLIST.icons=		yes
POST_INSTALL_TARGETS+=	install-icons
INSTALLATION_DIRS+=	share/icons/hicolor/scalable/apps
ICON_COLORS=		hi lo
ICON_SIZES=		16 32 48
MIMEICON_SIZES=		16 24 32 48 64 128 256

.    for c in ${ICON_COLORS}
.      for d in ${ICON_SIZES}
INSTALLATION_DIRS+=	share/icons/${c}color/${d}x${d}/apps
.      endfor
.    endfor

.    for d in ${MIMEICON_SIZES}
INSTALLATION_DIRS+=	share/icons/hicolor/${d}x${d}/mimetypes
.    endfor

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"

.PHONY: install-icons
install-icons:
	${INSTALL_DATA} ${WRKSRC}/image/wsicon.svg \
		${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps/wireshark.svg
.    for c in ${ICON_COLORS}
.      for d in ${ICON_SIZES}
	${INSTALL_DATA} ${WRKSRC}/image/${c}${d}-app-wireshark.png \
		${DESTDIR}${PREFIX}/share/icons/${c}color/${d}x${d}/apps/wireshark.png
.      endfor
.    endfor

.    for d in ${MIMEICON_SIZES}
	${INSTALL_DATA} ${WRKSRC}/image/WiresharkDoc-${d}.png \
		${DESTDIR}${PREFIX}/share/icons/hicolor/${d}x${d}/mimetypes/application-vnd.tcpdump.pcap.png
.    endfor
.  endif
.endif

.if empty(PKG_OPTIONS:Mlua)
CONFIGURE_ARGS+=	--with-lua=no
.else
LUA_VERSIONS_INCOMPATIBLE=	53
.include "../../lang/lua/buildlink3.mk"

CONFIGURE_ARGS+=	--with-lua=yes
PLIST.lua=		yes
.endif
