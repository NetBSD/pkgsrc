# $NetBSD: options.mk,v 1.3 2018/07/27 07:39:12 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.highlight
PKG_SUPPORTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		x11
.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/qt5-qtbase/buildlink3.mk"
BUILD_TARGET+=		gui
INSTALL_TARGET+=	install-gui
PLIST.x11=		yes
pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${TOOLS_DIR}/bin
.endif
