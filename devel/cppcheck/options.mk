# $NetBSD: options.mk,v 1.6 2016/09/19 11:05:53 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cppcheck
PKG_SUPPORTED_OPTIONS=	qt5

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	qt5

.if !empty(PKG_OPTIONS:Mqt5)
PLIST.qt5=	yes
USE_LIBTOOL=	yes

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"

post-build:
	cd ${WRKSRC}/gui && \
		${CONFIGURE_ENV} QTDIR=${QTDIR} HAVE_RULES=yes ${QTDIR}/bin/qmake gui.pro && \
		${MAKE_ENV} QTDIR=${QTDIR} make

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gui/cppcheck-gui ${DESTDIR}${PREFIX}/bin

.endif
