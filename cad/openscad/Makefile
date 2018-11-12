# $NetBSD: Makefile,v 1.52 2018/11/12 03:51:46 ryoon Exp $
#

DISTNAME=	openscad-2015.03-3.src
PKGNAME=	openscad-2015.03p3
PKGREVISION=	11
CATEGORIES=	cad
MASTER_SITES=	http://files.openscad.org/

MAINTAINER=	reinoud@NetBSD.org
HOMEPAGE=	http://www.openscad.org/
COMMENT=	OpenSCAD - The Programmers Solid 3D CAD Modeller
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	bison gettext pkg-config
USE_LIBTOOL=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:R}

MAKE_JOBS_SAFE=	no

CHECK_PORTABILITY_SKIP+=tests/compare-bitmaps.sh

REPLACE_PYTHON=	libraries/MCAD/get_submodules.py
.include "../../lang/python/application.mk"

MAKE_ENV+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake \
	    PREFIX=${PREFIX} -after QMAKE_YACC=bison QMAKE_LEX=flex \
	    QMAKE_CXXFLAGS+=-std=c++0x

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
# DragonFly requires FlexLexer.h from pkgsrc - base doesn't cut it.
.include "../../devel/flex/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/opencsg/buildlink3.mk"
.include "../../math/cgal/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qscintilla/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
