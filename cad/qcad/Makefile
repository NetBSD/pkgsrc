# $NetBSD: Makefile,v 1.79 2019/11/13 00:26:49 gdt Exp $
#

DISTNAME=		qcad-3.23.0.0
PKGREVISION=		4
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_GITHUB:=qcad/}
EXTRACT_USING=		bsdtar
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.qcad.org/
COMMENT=		2D CAD system
LICENSE=		gnu-gpl-v3

DEPENDS+=		bash-[0-9]*:../../shells/bash

USE_TOOLS+=		chmod find make pax
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Attending to hard-coded paths.
SUBST_FILES.paths+=	shared.pri src/core/RS.cpp src/core/RSettings.cpp
SUBST_FILES.paths+=	scripts/Help/ShowReadme/ShowReadme.js
SUBST_FILES.paths+=	scripts/Widgets/LibraryBrowser/LibraryBrowser.js
SUBST_VARS.paths=	PREFIX

# Don't build intermediate libraries with the same name in debug mode
# as in release mode. (Resolves regular libraries ending up in debug
# mode, which breaks plugin loading.)
# Reported on QCad Community Edition forum:
#   https://qcad.org/rsforum/viewtopic.php?f=76&t=6708
#
SUBST_CLASSES+=         dbgmode
SUBST_STAGE.dbgmode=    post-configure
SUBST_MESSAGE.dbgmode=  Debug mode: lib*.so -> lib*_debug.so
SUBST_FILES.dbgmode=    src/3rdparty/dxflib/Makefile.Debug
SUBST_FILES.dbgmode+=   src/core/Makefile.Debug
SUBST_FILES.dbgmode+=   src/entity/Makefile.Debug
SUBST_FILES.dbgmode+=   src/operations/Makefile.Debug
SUBST_SED.dbgmode=      -e 's,\(lib[dq]..*\)\(\.so\),\1_debug\2,g'

.include "../../mk/bsd.prefs.mk"
PLIST_VARS+=	glx egl
.if ${OPSYS} != "Darwin"
PLIST.glx=	yes
.  include "../../graphics/MesaLib/buildlink3.mk"
.  if ${MESALIB_SUPPORTS_EGL} == "yes"
PLIST.egl=	yes
.  endif
.endif

AUTO_MKDIRS=	yes

#
# The QCad build system normally links direct to a release dir but this
# causes a lot of problems with libtool dependencies. We patch it so that
# the libs are linked from the source dirs and add an install target to
# allow pkgsrc to use DESTDIR
#
do-configure:
	cd ${WRKSRC} && ${MKDIR} release
	cd ${WRKSRC} && ${QTDIR}/bin/qmake -r -after DESTDIR=

do-install:
	cd ${WRKSRC} && make INSTALL_ROOT=${DESTDIR} install
	${INSTALL_DATA} ${WRKSRC}/qcad.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/support/logo/logo_512.svg \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps/qcad_icon.svg
	${INSTALL_DATA} ${WRKSRC}/support/logo/logo_512.svg \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/512x512/apps/qcad_icon.svg
	${INSTALL_DATA} ${WRKSRC}/support/logo/logo_512.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/512x512/apps/qcad_icon.png
	${INSTALL_DATA} ${WRKSRC}/scripts/qcad_icon.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/256x256/apps/qcad_icon.png
	${INSTALL_DATA} ${WRKSRC}/support/doc/api/qcad_icon.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/64x64/apps/qcad_icon.png
	${INSTALL_LIB} ${WRKSRC}/src/3rdparty/qt-labs-qtscriptgenerator-*/qtbindings/qtscript_*/libqtscript_*.so* \
	    ${DESTDIR}${PREFIX}/lib/qcad/plugins/script
	${INSTALL_MAN} ${WRKSRC}/qcad.1 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${FIND} ${WRKSRC}/scripts -name \*.orig -delete
	${FIND} ${WRKSRC} -name \*.gitignore -delete
	cd ${WRKSRC} && ${PAX} -rwpm \
	    fonts linetypes patterns plugins platforminputcontexts platforms \
	    xcbglintegrations scripts themes ts \
	    ${DESTDIR}${PREFIX}/lib/${PKGBASE}
	cd ${WRKSRC} && ${PAX} -rwpm \
	    readme.txt examples libraries \
	    ${DESTDIR}${PREFIX}/share/${PKGBASE}

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
