# $NetBSD: options.mk,v 1.3 2011/05/29 11:52:12 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cppcheck
PKG_SUPPORTED_OPTIONS=	qt

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt)
INSTALLATION_DIRS+=	lib share/cppcheck

PLIST_SRC+=		PLIST PLIST.qt

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cli/cppcheck ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/gui/cppcheck-gui \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/man/cppcheck.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools?= full
.include "../../x11/qt4-tools/buildlink3.mk"
.else
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cli/cppcheck ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/man/cppcheck.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endif
