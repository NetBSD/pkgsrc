# $NetBSD: Makefile,v 1.24 2023/10/23 06:37:45 wiz Exp $

DISTNAME=	fs-uae-launcher-3.1.68
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	https://fs-uae.net/files/FS-UAE-Launcher/Stable/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://fs-uae.net/
COMMENT=	Graphical launcher for FS-UAE, the Amiga Emulator
LICENSE=	gnu-gpl-v2

DEPENDS+=	fs-uae>=3.1.66:../../emulators/fs-uae
DEPENDS+=	${PYPKGPREFIX}-lhafile-[0-9]*:../../archivers/py-lhafile
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-qt5>=5.4:../../x11/py-qt5
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=3:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Quartz>=3:../../devel/py-pyobjc-framework-Quartz
.endif

INSTALL_TARGET=		install-data
USE_TOOLS+=		gmake msgfmt

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

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
	cd ${DESTDIR}${PREFIX}/bin && ${RM} -f fs-uae-launcher && \
		${LN} -s ../share/fs-uae-launcher/fs-uae-launcher fs-uae-launcher

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
