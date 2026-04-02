# $NetBSD: options.mk,v 1.39 2026/04/02 20:29:33 gutteridge Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.wireshark
PKG_SUPPORTED_OPTIONS=		doc http2 http3 ilbc lua spandsp
PKG_OPTIONS_OPTIONAL_GROUPS=	gui
PKG_OPTIONS_GROUP.gui=		qt5 qt6
PKG_SUGGESTED_OPTIONS=		http2 http3 lua qt6

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	doc icons ilbc qt spandsp

.if !empty(PKG_OPTIONS:Mdoc)
.  include "../../lang/ruby/rubyversion.mk"
# XXX: Undo inopportune RUBY_DLEXT PLIST var replacement
PRINT_PLIST_AWK+=	/\$${RUBY_DLEXT}$$/ { gsub(/\$${RUBY_DLEXT}$$/, "${RUBY_DLEXT}") }
PLIST.doc=              yes
PRINT_PLIST_AWK+=	/^man\// { $$0 = "$${PLIST.doc}" $$0 }
PRINT_PLIST_AWK+=	/^share\/doc\/.*\.html$$/ { $$0 = "$${PLIST.doc}" $$0 }
TOOL_DEPENDS+=          libxslt-[0-9]*:../../textproc/libxslt
TOOL_DEPENDS+=          ${RUBY_PKGPREFIX}-asciidoctor>=1.5:../../textproc/ruby-asciidoctor
CMAKE_CONFIGURE_ARGS+=	-DASCIIDOCTOR_EXECUTABLE=${PREFIX}/bin/asciidoctor${RUBY_SUFFIX}
.else
CMAKE_CONFIGURE_ARGS+=  -DCMAKE_DISABLE_FIND_PACKAGE_Asciidoctor=TRUE
.endif

.if !empty(PKG_OPTIONS:Mhttp2)
.  include "../../www/nghttp2/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DENABLE_NGHTTP2=OFF
.endif

.if !empty(PKG_OPTIONS:Mhttp3)
.  include "../../www/nghttp3/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DENABLE_NGHTTP3=OFF
.endif

.if !empty(PKG_OPTIONS:Milbc)
.  include "../../audio/libilbc/buildlink3.mk"
PLIST.ilbc=		yes
PRINT_PLIST_AWK+=	/codecs\/ilbc/ { $$0 = "$${PLIST.ilbc}" $$0 }
.else
CMAKE_CONFIGURE_ARGS+=	-DENABLE_ILBC=OFF
.endif

.if !empty(PKG_OPTIONS:Mlua)
LUA_VERSIONS_ACCEPTED=	54 53
.  include "../../lang/lua/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DENABLE_LUA=OFF
.endif

.if !empty(PKG_OPTIONS:Mqt5) || !empty(PKG_OPTIONS:Mqt6)
.  if !empty(PKG_OPTIONS:Mqt5)
CMAKE_CONFIGURE_ARGS+=	-DUSE_qt6=OFF
.    include "../../x11/qt5-qtsvg/buildlink3.mk"
.    include "../../x11/qt5-qttools/buildlink3.mk"
.    if ${OPSYS} == "Darwin"
.      include "../../x11/qt5-qtmacextras/buildlink3.mk"
.    else
.      include "../../x11/qt5-qtx11extras/buildlink3.mk"
.    endif
.  elif !empty(PKG_OPTIONS:Mqt6)
CMAKE_CONFIGURE_ARGS+=	-DUSE_qt6=ON
.    include "../../graphics/qt6-qtsvg/buildlink3.mk"
.    include "../../multimedia/qt6-qtmultimedia/buildlink3.mk"
.    include "../../devel/qt6-qttools/buildlink3.mk"
.    include "../../devel/qt6-qt5compat/buildlink3.mk"
.  endif
PLIST.qt=		yes
PRINT_PLIST_AWK+=	/^bin\/wireshark/ { $$0 = "$${PLIST.qt}" $$0 }
.  if ${OPSYS} != "Darwin"
PLIST.icons=		yes
PRINT_PLIST_AWK+=	/^share\/applications\// { $$0 = "$${PLIST.icons}" $$0 }
PRINT_PLIST_AWK+=	/^share\/icons\// { $$0 = "$${PLIST.icons}" $$0 }
PRINT_PLIST_AWK+=	/^share\/metainfo\// { $$0 = "$${PLIST.icons}" $$0 }
PRINT_PLIST_AWK+=	/^share\/mime\// { $$0 = "$${PLIST.icons}" $$0 }
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
	${INSTALL_DATA} ${WRKSRC}/resources/historic/wsicon.svg \
		${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps/wireshark.svg
.    for d in ${MIMEICON_SIZES}
	${INSTALL_DATA} ${WRKSRC}/resources/icons/WiresharkDoc-${d}.png \
		${DESTDIR}${PREFIX}/share/icons/hicolor/${d}x${d}/mimetypes/application-vnd.tcpdump.pcap.png
.    endfor
.  endif
.else
CMAKE_CONFIGURE_ARGS+=	-DBUILD_wireshark=OFF
.endif

.if !empty(PKG_OPTIONS:Mspandsp)
.include "../../comms/spandsp/buildlink3.mk"
PLIST.spandsp=		yes
PRINT_PLIST_AWK+=	/codecs\/g72/ { $$0 = "$${PLIST.spandsp}" $$0 }
CMAKE_CONFIGURE_ARGS+=	-DENABLE_SPANDSP=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DENABLE_SPANDSP=OFF
.endif
