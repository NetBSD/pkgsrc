# $NetBSD: Makefile,v 1.25 2025/09/14 10:29:34 adam Exp $

DISTNAME=	fs-uae-launcher-3.2.20
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=FrodeSolheim/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://fs-uae.net/
COMMENT=	Graphical launcher for FS-UAE, the Amiga Emulator
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	fs-uae>=3.2.35:../../emulators/fs-uae
DEPENDS+=	${PYPKGPREFIX}-OpenGL-[0-9]*:../../graphics/py-OpenGL
DEPENDS+=	${PYPKGPREFIX}-lhafile-[0-9]*:../../archivers/py-lhafile
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-qt6>=6.9.1:../../x11/py-qt6
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=3:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Quartz>=3:../../devel/py-pyobjc-framework-Quartz
.endif

INSTALL_TARGET=		install-data
USE_TOOLS+=		gmake msgfmt

PYSETUPINSTALLARGS=	--install-lib=${PREFIX:Q}/share/fs-uae-launcher
PYSETUPINSTALLARGS+=	--install-scripts=${PREFIX:Q}/share/fs-uae-launcher

REPLACE_PYTHON+=	fs-uae-launcher

INSTALLATION_DIRS+=	bin

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing installation prefix.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	Makefile
SUBST_FILES.prefix+=	launcher/ui/launcherwindow.py
SUBST_SED.prefix=	-e 's,/usr/local,${PREFIX},'

post-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${INSTALL_MAKE_FLAGS} \
		-f ${MAKE_FILE} ${INSTALL_TARGET}

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
