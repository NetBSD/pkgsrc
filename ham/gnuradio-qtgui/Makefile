# $NetBSD: Makefile,v 1.89 2025/02/27 13:49:54 adam Exp $

PKGNAME=	gnuradio-qtgui-${VERSION}
COMMENT=	Qt GUI module of GNU Radio

DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5

.include "../../ham/gnuradio-core/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_QTGUI=ON

REPLACE_PYTHON+=	gr-qtgui/apps/*.py
REPLACE_PYTHON+=	gr-qtgui/examples/*.py
REPLACE_PYTHON+=	gr-qtgui/grc/qtgui_time_sink_x.block.yml.py 
REPLACE_PYTHON+=	gr-qtgui/python/qtgui/*.py

pre-configure: Qt5Qwt6.pc
.PHONY: Qt5Qwt6.pc
Qt5Qwt6.pc:
	ln -sf ${QWT_DIR}/lib/pkgconfig/Qt5Qwt6.pc ${BUILDLINK_DIR}/lib/pkgconfig/Qt5Qwt6.pc

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qwt6-qt5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
