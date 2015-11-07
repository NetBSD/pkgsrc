# $NetBSD: Makefile,v 1.2 2015/11/07 13:32:09 adam Exp $

DISTNAME=	fs-uae-launcher-2.6.2
CATEGORIES=	emulators
MASTER_SITES=	http://fs-uae.net/fs-uae/stable/${PKGVERSION_NOREV}/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://fs-uae.net/
COMMENT=	Graphical launcher for FS-UAE, the Amiga Emulator
LICENSE=	gnu-gpl-v2

DEPENDS+=	fs-use>=${PKGVERSION_NOREV}:../../emulators/fs-uae
DEPENDS+=	${PYPKGPREFIX}-lhafile>=0.2.1:../../archivers/py-lhafile
DEPENDS+=	${PYPKGPREFIX}-sqlite3>=1:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-qt5>=5.4:../../x11/py-qt5
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=3:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Quartz>=3:../../devel/py-pyobjc-framework-Quartz
.endif

INSTALL_TARGET=		install-data
USE_TOOLS+=		gmake msgfmt

# Imports urllib.parse which is 3+.
PYTHON_VERSIONS_ACCEPTED=	34 33
PYTHON_VERSIONS_INCOMPATIBLE=	26 27
PYDISTUTILSPKG=		yes
PYSETUPINSTALLARGS=	--install-lib=${PREFIX:Q}/share/fs-uae-launcher
PYSETUPINSTALLARGS+=	--install-scripts=${PREFIX:Q}/share/fs-uae-launcher

REPLACE_PYTHON+=	fs-uae-launcher
REPLACE_PYTHON+=	OpenGL/arrays/_buffers.py
REPLACE_PYTHON+=	OpenGL/arrays/buffers.py

INSTALLATION_DIRS+=	bin

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing installation prefix.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	Makefile
SUBST_FILES.prefix+=	fs_uae_launcher/FSUAELauncher.py
SUBST_FILES.prefix+=	game_center/gamecenterutil.py
SUBST_SED.prefix=	-e 's,/usr/local,${PREFIX},'

post-install:
	cd ${WRKSRC} && env ${MAKE_ENV} ${MAKE_PROGRAM} ${INSTALL_MAKE_FLAGS} \
		-f ${MAKE_FILE} ${INSTALL_TARGET}
	cd ${DESTDIR}${PREFIX}/bin && rm -f fs-uae-launcher && \
		ln -s ../share/fs-uae-launcher/fs-uae-launcher \
			${DESTDIR}${PREFIX}/bin/fs-uae-launcher

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
