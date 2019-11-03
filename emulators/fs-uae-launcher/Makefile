# $NetBSD: Makefile,v 1.13 2019/11/03 19:24:32 rillig Exp $

DISTNAME=	fs-uae-launcher-3.0.0
CATEGORIES=	emulators
MASTER_SITES=	https://fs-uae.net/stable/${PKGVERSION_NOREV}/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://fs-uae.net/
COMMENT=	Graphical launcher for FS-UAE, the Amiga Emulator
LICENSE=	gnu-gpl-v2

DEPENDS+=	fs-uae>=${PKGVERSION_NOREV}:../../emulators/fs-uae
DEPENDS+=	${PYPKGPREFIX}-lhafile-[0-9]*:../../archivers/py-lhafile
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-qt5>=5.4:../../x11/py-qt5
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=3:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Quartz>=3:../../devel/py-pyobjc-framework-Quartz
.endif

INSTALL_TARGET=		install-data
USE_TOOLS+=		gmake msgfmt

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYSETUPINSTALLARGS=		--install-lib=${PREFIX:Q}/share/fs-uae-launcher
PYSETUPINSTALLARGS+=		--install-scripts=${PREFIX:Q}/share/fs-uae-launcher

REPLACE_PYTHON+=	fs-uae-launcher

INSTALLATION_DIRS+=	bin

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing installation prefix.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	Makefile
SUBST_FILES.prefix+=	fs_uae_launcher/FSUAELauncher.py
SUBST_FILES.prefix+=	game_center/gamecenterutil.py
SUBST_SED.prefix=	-e 's,/usr/local,${PREFIX},'

post-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${INSTALL_MAKE_FLAGS} \
		-f ${MAKE_FILE} ${INSTALL_TARGET}
	cd ${DESTDIR}${PREFIX}/bin && ${RM} -f fs-uae-launcher && \
		${LN} -s ../share/fs-uae-launcher/fs-uae-launcher fs-uae-launcher

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
