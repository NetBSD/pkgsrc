# $NetBSD: options.mk,v 1.2 2010/02/03 09:52:32 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cppcheck
PKG_SUPPORTED_OPTIONS=	qt

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt)
SUBST_CLASSES+=		lrelease
SUBST_FILES.lrelease=	gui/gui.pro
SUBST_STAGE.lrelease=	post-extract
SUBST_SED.lrelease=	-e "s,lrelease gui.pro,${PREFIX}/qt4/bin/lrelease gui.pro,g"
SUBST_MESSAGE.lrelease=	Fixing path to lrelease.

INSTALLATION_DIRS+=	lib share/cppcheck

PLIST_SRC+=		PLIST PLIST.qt

do-configure:
	cd ${WRKSRC} && ${PREFIX}/qt4/bin/qmake

.PHONY: link-build
post-build: link-build
link-build:
	${ECHO} '#!/bin/sh' > ${WRKSRC}/cppcheck-gui
	${ECHO} 'cd ${PREFIX}/share/cppcheck && ${PREFIX}/lib/cppcheck-gui "$$@"' >> ${WRKSRC}/cppcheck-gui

.PHONY: qt-install
post-install: qt-install
qt-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cli/cppcheck ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/cppcheck-gui ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/gui/gui \
		${DESTDIR}${PREFIX}/lib/cppcheck-gui
	${INSTALL_DATA} ${WRKSRC}/man/cppcheck.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/gui/*.qm ${DESTDIR}${PREFIX}/share/cppcheck

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.else
.PHONY: main-install
post-install: main-install
main-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cppcheck ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/man/cppcheck.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endif
