# $NetBSD: Makefile,v 1.18 2024/05/29 16:33:17 adam Exp $

DISTNAME=	qtdeclarative-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtdeclarative-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt6 module for the QML language
CATEGORIES=	lang x11

LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6LabsAnimation.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6LabsFolderListModel.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6LabsQmlModels.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6LabsSettings.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6LabsSharedImage.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6LabsWavefrontMesh.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Qml.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QmlCore.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QmlLocalStorage.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QmlModels.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QmlWorkerScript.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QmlXmlListModel.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Quick.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QuickControls2.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QuickControls2Impl.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QuickDialogs2.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QuickDialogs2QuickImpl.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QuickDialogs2Utils.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QuickLayouts.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QuickTemplates2.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QuickTest.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QuickWidgets.pc

PLIST_VARS+=	jit

# jit-enabled platforms per src/qml/configure.cmake.
# NetBSD-*-aarch64 could be added, but I/D cache flushing in ARM64Assembler.h is missing.
.if	\
	  !empty(MACHINE_PLATFORM:M*-*-i386) ||			\
	  !empty(MACHINE_PLATFORM:M*-*-x86_64) ||		\
	  !empty(MACHINE_PLATFORM:MLinux-*-*arm*) ||		\
	  !empty(MACHINE_PLATFORM:MLinux-*-aarch64*)
PLIST.jit=	yes
.endif

# installs .cpp.o file that should not be there
post-install:
	${RM} -r ${DESTDIR}${QTPREFIX}/qml/Qt/test/controls/objects-Release

.include "../../graphics/qt6-qtimageformats/buildlink3.mk"
.include "../../graphics/qt6-qtshadertools/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/qt6-qtlanguageserver/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
