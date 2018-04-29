# $NetBSD: Makefile,v 1.70 2018/04/29 21:31:48 adam Exp $

PKGNAME=	gnuradio-wxgui-${VERSION}
PKGREVISION=	6
COMMENT=	WxGTK Toolkit module of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

CONF_FILES+=	${EGDIR}/gr-wxgui.conf	${PKG_SYSCONFDIR}/gr-wxgui.conf

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_WXGUI=True
CMAKE_ARGS+=	-DENABLE_PYTHON=True

.include	"../../x11/wxGTK28/buildlink3.mk"
.include	"../../x11/py-wxWidgets/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"
