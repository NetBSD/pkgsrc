# $NetBSD: options.mk,v 1.12 2026/07/07 07:33:45 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mkvtoolnix
PKG_SUPPORTED_OPTIONS=	doc gui
PKG_SUGGESTED_OPTIONS=	doc

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	doc gui

.if !empty(PKG_OPTIONS:Mgui)
PLIST.gui=		yes
CONFIGURE_ARGS+=	--enable-gui
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.  if ${OPSYS} == "Darwin"
PLIST_SUBST+=	SOUND_EXT=caf
.  else
PLIST_SUBST+=	SOUND_EXT=webm
.  endif
.else
CONFIGURE_ARGS+=	--disable-gui
.endif

.if !empty(PKG_OPTIONS:Mdoc)
PLIST.doc=		yes
CONFIGURE_ARGS+=	--with-po4a=${PREFIX}/bin/po4a
TOOL_DEPENDS+=		po4a-[0-9]*:../../textproc/po4a
.else
CONFIGURE_ARGS+=	--without-po4a
.endif
