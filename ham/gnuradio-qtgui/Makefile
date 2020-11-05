# $NetBSD: Makefile,v 1.32 2020/11/05 09:08:29 ryoon Exp $

PKGNAME=	gnuradio-qtgui-${VERSION}
PKGREVISION=	1
COMMENT=	Qt GUI module of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

#CONF_FILES+=	${EGDIR}/gr-qtgui.conf	${PKG_SYSCONFDIR}/gr-qtgui.conf

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_QTGUI=ON
CMAKE_ARGS+=	-DENABLE_GRC=ON

PLIST_MINUS+=	companion

pre-configure: Qt5Qwt6.pc
.PHONY: Qt5Qwt6.pc
Qt5Qwt6.pc:
	ln -sf ${QWT_DIR}/lib/pkgconfig/Qt5Qwt6.pc ${BUILDLINK_DIR}/lib/pkgconfig/Qt5Qwt6.pc

.include	"../../x11/py-qt5/buildlink3.mk"
.include	"../../x11/qwt6-qt5/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
