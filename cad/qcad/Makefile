# $NetBSD: Makefile,v 1.67 2017/04/09 00:23:26 mef Exp $
#

DISTNAME=		qcad-3.16.7.0
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_GITHUB:=qcad/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.qcad.org/
COMMENT=		2D CAD system
LICENSE=		gnu-gpl-v3

GITHUB_TAG=		v${PKGVERSION_NOREV}

DEPENDS+=		bash-[0-9]*:../../shells/bash
DEPENDS+=		qt4-tiff-[0-9]*:../../x11/qt4-tiff
DEPENDS+=		qt4-sqlite3-[0-9]*:../../x11/qt4-sqlite3

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		chmod find make pax
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_MESSAGE.paths=	Attending to hard-coded paths.
SUBST_FILES.paths+=	shared.pri src/core/RS.cpp src/core/RSettings.cpp
SUBST_FILES.paths+=	scripts/Help/ShowReadme/ShowReadme.js
SUBST_FILES.paths+=	scripts/Widgets/LibraryBrowser/LibraryBrowser.js
SUBST_SED.paths=	-e 's,@PREFIX@,${PREFIX},g'

AUTO_MKDIRS=	yes

#
# Fix permissions from zip file
#
post-extract:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} u=rw,go=r "{}" "+"

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
.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt4-libs+=	qt4-libs>=4.7
.include "../../x11/qt4-tools/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt4-tools+=	qt4-tools>=4.7
BUILDLINK_DEPMETHOD.qt4-tools=		full
.include "../../mk/bsd.pkg.mk"
