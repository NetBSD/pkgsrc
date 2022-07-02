# $NetBSD: Makefile,v 1.15 2022/07/02 16:53:14 ryoon Exp $

DISTNAME=	qt-creator-opensource-src-5.0.3
PKGNAME=	${DISTNAME:S/qt-/qt/:S/-opensource-src//}
PKGREVISION=	6
CATEGORIES=	editors
MASTER_SITES=	http://download.qt.io/official_releases/${PKGBASE}/${PKGVERSION_NOREV:R}/${PKGVERSION_NOREV}/
MASTER_SITES+=	http://download.qt.io/archive/${PKGBASE}/${PKGVERSION_NOREV:R}/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.qt.io/
COMMENT=	Cross-platform IDE for Qt and C++
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	bash perl

REPLACE_BASH+=	src/app/winicons/createicons.sh
REPLACE_BASH+=	src/libs/qmljs/parser/gen-parser.sh
REPLACE_BASH+=	src/shared/qbs/tests/auto/blackbox/testdata/badInterpreter/script-ok
REPLACE_BASH+=	tests/manual/distribution/elflint
REPLACE_BASH+=	scripts/deployqtHelper_mac.sh

REPLACE_PYTHON+=	src/libs/qmljs/parser/changeLicense.py
REPLACE_PYTHON+=	src/tools/icons/export.py
REPLACE_PYTHON+=	tests/system/tools/findUnusedObjects.py
REPLACE_PYTHON+=	tests/system/tools/objectsToTable.py
REPLACE_PYTHON+=	scripts/checkInstalledFiles.py
REPLACE_PYTHON+=	scripts/dependencyinfo.py
REPLACE_PYTHON+=	scripts/deployqt.py
REPLACE_PYTHON+=	scripts/packagePlugins.py
REPLACE_PYTHON+=	scripts/uichanges.py

REPLACE_PERL+=	doc/fixnavi.pl
REPLACE_PERL+=	share/qtcreator/translations/check-ts.pl
REPLACE_PERL+=	src/shared/qbs/doc/fixnavi.pl
REPLACE_PERL+=	scripts/gcc2tasks.pl
REPLACE_PERL+=	scripts/hasCopyright.pl
REPLACE_PERL+=	scripts/krazy2tasks.pl
REPLACE_PERL+=	scripts/msvc2tasks.pl
REPLACE_PERL+=	scripts/mytasks.pl
REPLACE_PERL+=	scripts/purify2tasks.pl
REPLACE_PERL+=	scripts/qdoc2tasks.pl
REPLACE_PERL+=	scripts/test2tasks.pl
REPLACE_PERL+=	scripts/updateCopyright.pl

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}/${PREFIX}
BUILD_TARGET=		all qch_docs
INSTALL_TARGET=		install install_inst_qch_docs

# Has a header called context.h (also in python 3.x) and it includes
# python headers before its own headers.
PYTHON_VERSIONS_ACCEPTED=	27

# XXX doesn't seem to get built on netbsd. probably results in
# PLIST differences when it does.
CMAKE_ARGS.NetBSD+=	-DBUILD_WITH_PCH=OFF

#LDFLAGS+=	${COMPILER_RPATH_FLAG}${QTDIR}/lib
#LDFLAGS+=	${COMPILER_RPATH_FLAG}${X11BASE}/lib

do-configure:
	${RUN} cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QTDIR}/bin/qmake \
		QMAKE_RPATHDIR+=${QTDIR}/lib \
		QMAKE_RPATHDIR+=${X11BASE}/lib \
		QMAKE_RPATHDIR+=${LOCALBASE}/lib/qtcreator \
		QMAKE_RPATHDIR+=${LOCALBASE}/lib/qtcreator/plugins \
		-o Makefile

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtserialport/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
# XXX libSqlite.so fails to link but silently resumes without this.
# XXX Unclear why the conditional doesn't work for NetBSD.
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
