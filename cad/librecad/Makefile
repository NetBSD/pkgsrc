# $NetBSD: Makefile,v 1.92 2025/01/20 23:29:25 gdt Exp $

DISTNAME=	LibreCAD-2.2.0
PKGNAME=	${DISTNAME:tl}
#PKGNAME=	${DISTNAME:tl:S/-rc2/.rc2/g}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=LibreCAD/}
GITHUB_PROJECT=	LibreCAD
GITHUB_TAG=	${DISTNAME:S/LibreCAD-//g}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://librecad.org/
COMMENT=	Free Open Source personal CAD application
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

EXTRACT_USING=	bsdtar

USE_LANGUAGES=	c c++
# Upstream declares a requirement of C++11 and uses --std=c++11
# (top-level Makefile) and -std=gnu++11 (several subdirectories).
# However it uses boost.math, which as of boost>=1.82 requires C++14:
#
# https://web.archive.org/web/20241120103157/https://www.boost.org/doc/libs/1_82_0/?view=category_math#lib-math
#
# So we explicitly delete the -std=c++11 and -std=gnu++11 arguments
# and replace then by -std=gnu++14, via FORCE_CXX_STD.  (We assume
# that the implication of gnu++11 and c++14 is gnu++14, without
# proof.)
USE_CXX_FEATURES+=	gnu++14
BUILDLINK_TRANSFORM+=	rm:-std=c++11
BUILDLINK_TRANSFORM+=	rm:-std=gnu++11
FORCE_CXX_STD=		gnu++14

USE_TOOLS+=	pax pkg-config
USE_LIBTOOL=	yes

SUBST_CLASSES+=		qtdir
SUBST_STAGE.qtdir=	pre-configure
SUBST_MESSAGE.qtdir=	Set qt5/bin
SUBST_FILES.qtdir+=	scripts/postprocess-unix.sh
SUBST_VARS.qtdir+=	QTDIR

.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mclang*)
BUILDLINK_TRANSFORM+=   rm:-fext-numeric-literals
.endif

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/${PKGBASE}
INSTALLATION_DIRS+=	lib/${PKGBASE}

QMAKE_OPTIONS+=	CONFIG+=release
QMAKE_OPTIONS+=	BOOST_DIR=${BUILDLINK_DIR}
QMAKE_OPTIONS+=	BOOST_LIBDIR=${BUILDLINK_DIR}/lib
QMAKE_OPTIONS+=	MUPARSER_DIR=${BUILDLINK_DIR}
QMAKE_OPTIONS+=	QMAKE_LFLAGS_RELEASE=
QMAKE_OPTIONS+=	DISABLE_POSTSCRIPT=true

do-configure:
	${RUN} cd ${WRKSRC} && ${QTDIR}/bin/qmake ${QMAKE_OPTIONS}
	${RUN} cd ${WRKSRC}/plugins && ${QTDIR}/bin/qmake \
		INSTALLS+=target target.path=${PREFIX}/lib/librecad/plugins

do-install:
	${RUN} cd ${WRKSRC} && ./scripts/postprocess-unix.sh
	${INSTALL_PROGRAM} ${WRKSRC}/unix/librecad \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/unix/ttf2lff \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/desktop/librecad.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_MAN} ${WRKSRC}/desktop/librecad.1 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/tools/ttf2lff/ttf2lff.1 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${RUN} cd ${WRKSRC}/plugins && \
	    ${SETENV} ${MAKE_ENV} ${MAKE} INSTALL_ROOT=${DESTDIR} install
	${RUN} cd ${WRKSRC}/unix/resources && ${PAX} -rwpm fonts \
	    ${DESTDIR}${PREFIX}/lib/librecad
	${RUN} cd ${WRKSRC}/unix/resources && ${PAX} -rwpm library patterns qm \
	    ${DESTDIR}${PREFIX}/share/librecad

.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../math/muparser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
