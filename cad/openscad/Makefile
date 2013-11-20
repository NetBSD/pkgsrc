# $NetBSD: Makefile,v 1.26 2013/11/20 13:23:42 obache Exp $
#

PKGNAME=	openscad-2011.12
DISTNAME=	openscad-2011.12.src
PKGREVISION=	17
CATEGORIES=	cad
MASTER_SITES=	http://cloud.github.com/downloads/openscad/openscad/

MAINTAINER=	reinoud@NetBSD.org
HOMEPAGE=	http://www.openscad.org/
COMMENT=	OpenSCAD - The Programmers Solid 3D CAD Modeller
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/openscad-2011.12
USE_LANGUAGES=	c c++

USE_TOOLS+=	cmake bison pkg-config
USE_LIBTOOL=	yes

SUBST_CLASSES+=prefix
SUBST_SED.prefix=-e 's,@PREFIX@,${PREFIX},g'
SUBST_FILES.prefix=${WRKSRC}/eigen2.pri ${WRKSRC}/openscad.pro
SUBST_STAGE.prefix=post-patch

SUBST_CLASSES+=destdir
SUBST_SED.destdir=-e 's,@DESTDIR@,${DESTDIR},g'
SUBST_FILES.destdir=${WRKSRC}/openscad.pro
SUBST_STAGE.destdir=post-patch

UNLIMIT_RESOURCES=	stacksize
CHECK_PORTABILITY_SKIP+=tests/compare-bitmaps.sh
CHECK_INTERPRETER_SKIP+=share/openscad/libraries/MCAD/get_submodules.py

pre-build:
	(cd ${WRKSRC} && ${QTDIR}/bin/qmake)

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
_WRAP_EXTRA_ARGS.CXX+=	-std=c++11 -Wno-c++11-narrowing
.endif

# DragonFly requires FlexLexer.h from pkgsrc - base doesn't cut it.
.include "../../devel/flex/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../math/cgal/buildlink3.mk"
.include "../../graphics/opencsg/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../math/eigen2/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
