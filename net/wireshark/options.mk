# $NetBSD: options.mk,v 1.20 2018/09/02 21:49:05 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.wireshark
PKG_SUPPORTED_OPTIONS=		gtk3 lua
PKG_OPTIONS_OPTIONAL_GROUPS=	qt
PKG_OPTIONS_GROUP.qt=		qt4 qt5
PKG_SUGGESTED_OPTIONS=		qt5 lua

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gtk3 icons lua mans qt

.if empty(PKG_OPTIONS:Mqt4) && empty(PKG_OPTIONS:Mqt5)
CONFIGURE_ARGS+=	--without-qt
.else
.  if !empty(PKG_OPTIONS:Mqt4)
CONFIGURE_ARGS+=	--with-qt=4
BUILDLINK_API_DEPENDS.qt4-tools+=	qt4-tools>=4.8
.    include "../../x11/qt4-tools/buildlink3.mk"
.  elif !empty(PKG_OPTIONS:Mqt5)
CONFIGURE_ARGS+=	--with-qt=5
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

.if !empty(PKG_OPTIONS:Mgtk3)
CONFIGURE_ARGS+=	--with-gtk=3
PLIST.gtk3=		yes
POST_INSTALL_TARGETS+=	install-gtk-desktop
.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/adwaita-icon-theme/buildlink3.mk"

.PHONY: install-gtk-desktop
install-gtk-desktop:
	${INSTALL_DATA} ${WRKSRC}/wireshark.desktop \
		${DESTDIR}${PREFIX}/share/applications/

.else
CONFIGURE_ARGS+=	--without-gtk
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
ICON_SIZES=		16 32 48
MIMEICON_SIZES=		16 24 32 48 64 128 256

.    for d in ${ICON_SIZES}
INSTALLATION_DIRS+=	share/icons/hicolor/${d}x${d}/apps
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
.    for d in ${MIMEICON_SIZES}
	${INSTALL_DATA} ${WRKSRC}/image/WiresharkDoc-${d}.png \
		${DESTDIR}${PREFIX}/share/icons/hicolor/${d}x${d}/mimetypes/application-vnd.tcpdump.pcap.png
.    endfor
.  endif
.endif

.if !empty(PKG_OPTIONS:Mlua)
LUA_VERSIONS_INCOMPATIBLE=	53
.include "../../lang/lua/buildlink3.mk"

CONFIGURE_ARGS+=	--with-lua=yes
PLIST.lua=		yes
.else
CONFIGURE_ARGS+=	--with-lua=no
.endif
