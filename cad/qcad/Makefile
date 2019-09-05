# $NetBSD: Makefile,v 1.75 2019/09/05 13:39:10 nia Exp $
#

DISTNAME=		qcad-3.23.0.0
PKGREVISION=		1
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_GITHUB:=qcad/}
EXTRACT_USING=		bsdtar

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.qcad.org/
COMMENT=		2D CAD system
LICENSE=		gnu-gpl-v3

GITHUB_TAG=		v${PKGVERSION_NOREV}

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

AUTO_MKDIRS=	yes

#
# The QCad build system normally links direct to a release dir but this
# causes a lot of problems with libtool dependencies. We patch it so that
# the libs are linked from the source dirs and add an install target to
# allow pkgsrc to use DESTDIR
#
# The Qt script bindings are built in Qt version specific subdirectory
# which we can't patch directly, so we create a fake qtscript.pro file
# and use it to overwrite Makefiles. Makefile.qtscript is ignored
#
do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake -r -after DESTDIR=
	cd ${WRKSRC}/src/3rdparty && ${QTDIR}/bin/qmake -r -after DESTDIR= \
	    INSTALLS+=target target.path=${PREFIX}/lib/${PKGBASE}/plugins/script \
	    qtscript.pro -o Makefile.qtscript

do-install:
	cd ${WRKSRC} && make INSTALL_ROOT=${DESTDIR} install
	${INSTALL_DATA} ${WRKSRC}/qcad.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_MAN} ${WRKSRC}/qcad.1 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${FIND} ${WRKSRC}/scripts -name \*.orig -delete
	cd ${WRKSRC} && ${PAX} -rwpm fonts linetypes patterns \
	    plugins scripts themes ts ${DESTDIR}${PREFIX}/lib/${PKGBASE}
	cd ${WRKSRC} && ${PAX} -rwpm readme.txt examples libraries \
	    ${DESTDIR}${PREFIX}/share/${PKGBASE}

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
