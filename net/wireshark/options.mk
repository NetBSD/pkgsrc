# $NetBSD: options.mk,v 1.8 2015/05/07 21:40:43 roy Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wireshark
PKG_SUPPORTED_OPTIONS=	gtk2 lua
PKG_SUGGESTED_OPTIONS=	gtk2 lua

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gtk2
PLIST_VARS+=		icons

.if !empty(PKG_OPTIONS:Mgtk2)
CONFIGURE_ARGS+=	--enable-wireshark
PLIST.gtk2=		yes
POST_INSTALL_TARGETS+=	install-gtk-desktop
.include "../../x11/gtk2/buildlink3.mk"

install-gtk-desktop:
	${INSTALL_DATA} ${WRKSRC}/wireshark.desktop \
		${DESTDIR}${PREFIX}/share/applications

.else
CONFIGURE_ARGS+=	--disable-wireshark
.endif

# We might install the qt front end one day as well,
# so have a generic icon target
.if !empty(PKG_OPTIONS:Mgtk2)
PLIST.icons=		yes
POST_INSTALL_TARGETS+=	install-icons
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/scalable/apps
ICON_COLORS=		hi lo
ICON_SIZES=		16 32 48
MIMEICON_SIZES=		16 24 32 48 64 128 256

.for c in ${ICON_COLORS}
.for d in ${ICON_SIZES}
INSTALLATION_DIRS+=	share/icons/${c}color/${d}x${d}/apps
.endfor
.endfor

.for d in ${MIMEICON_SIZES}
INSTALLATION_DIRS+=	share/icons/hicolor/${d}x${d}/mimetypes
.endfor

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"

install-icons:
	${INSTALL_DATA} ${WRKSRC}/image/wsicon.svg \
		${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps/wireshark.svg
.for c in ${ICON_COLORS}
.for d in ${ICON_SIZES}
	${INSTALL_DATA} ${WRKSRC}/image/${c}${d}-app-wireshark.png \
		${DESTDIR}${PREFIX}/share/icons/${c}color/${d}x${d}/apps/wireshark.png
.endfor
.endfor

.for d in ${MIMEICON_SIZES}
	${INSTALL_DATA} ${WRKSRC}/image/WiresharkDoc-${d}.png \
		${DESTDIR}${PREFIX}/share/icons/hicolor/${d}x${d}/mimetypes/application-vnd.tcpdump.pcap.png
.endfor
.endif

PLIST_VARS+=		lua

.if empty(PKG_OPTIONS:Mlua)
CONFIGURE_ARGS+=	--with-lua=no
.else
.include "../../lang/lua/buildlink3.mk"

CONFIGURE_ARGS+=	--with-lua=${BUILDLINK_PREFIX.lua}
PLIST.lua=		yes
.endif
