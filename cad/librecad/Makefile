# $NetBSD: Makefile,v 1.44 2018/08/16 18:54:36 adam Exp $
#

DISTNAME=	LibreCAD-2.1.3
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	7
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=LibreCAD/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://librecad.org/
COMMENT=	Free Open Source personal CAD application
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	bsdtar

USE_LANGUAGES=	c c++11
USE_TOOLS+=	pax pkg-config
USE_LIBTOOL=	yes

GCC_REQD+=	4.7

SUBST_CLASSES+=		qtdir
SUBST_STAGE.qtdir=	pre-configure
SUBST_MESSAGE.qtdir=	Set qt4/bin
SUBST_FILES.qtdir+=	scripts/postprocess-unix.sh
SUBST_VARS.qtdir+=	QTDIR

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fix hardcoded path
SUBST_FILES.prefix+=	librecad/src/lib/engine/rs_system.cpp
SUBST_VARS.prefix+=	PREFIX

AUTO_MKDIRS=	yes

#
# We disable long double math functions, because otherwise one of
# the boost headers brings in a log1pl() function which was not
# present (in NetBSD 7) causing compilation failure
#
# We configure the plugins directory separately so that we can use
# make install below, which handles the libtooling of the shared
# plugins automatically
#
do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake \
	    QMAKE_CXXFLAGS=-DBOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
	cd ${WRKSRC}/plugins && ${QTDIR}/bin/qmake \
	    INSTALLS+=target target.path=${PREFIX}/lib/librecad/plugins

do-install:
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
	cd ${WRKSRC}/plugins && \
	    ${SETENV} ${MAKE_ENV} ${MAKE} INSTALL_ROOT=${DESTDIR} install
	cd ${WRKSRC}/unix/resources && ${PAX} -rwpm fonts \
	    ${DESTDIR}${PREFIX}/lib/librecad
	cd ${WRKSRC}/unix/resources && ${PAX} -rwpm library patterns qm \
	    ${DESTDIR}${PREFIX}/share/librecad

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../math/muparser/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
