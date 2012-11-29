# $NetBSD: options.mk,v 1.4 2012/11/29 13:52:51 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cppcheck
PKG_SUPPORTED_OPTIONS=	qt

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt)
PLIST_SRC+=		PLIST PLIST.qt

.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools?= full
.include "../../x11/qt4-tools/buildlink3.mk"

post-build:
	cd ${WRKSRC}/gui && \
		${CONFIGURE_ENV} QTDIR=${QTDIR} HAVE_RULES=yes ${QTDIR}/bin/qmake gui.pro && \
		${MAKE_ENV} QTDIR=${QTDIR} make
.endif
