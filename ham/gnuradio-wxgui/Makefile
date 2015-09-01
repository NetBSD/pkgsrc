# $NetBSD: Makefile,v 1.56 2015/09/01 04:14:55 mef Exp $

PKGNAME=	gnuradio-wxgui-${VERSION}
COMMENT=	WxGTK Toolkit module of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

#CONF_FILES+=	${EGDIR}/gr-wxgui.conf	${PKG_SYSCONFDIR}/gr-wxgui.conf

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_WXGUI=True
CMAKE_ARGS+=	-DENABLE_PYTHON=True

.include	"../../x11/wxGTK28/buildlink3.mk"
.include	"../../x11/py-wxWidgets/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"
