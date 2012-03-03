# $NetBSD: Makefile,v 1.4 2012/03/03 00:12:47 wiz Exp $
#

PKGNAME=	openscad-2011.12
DISTNAME=	openscad-2011.12.src
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	https://github.com/downloads/openscad/openscad/

MAINTAINER=	reinoud@NetBSD.org
HOMEPAGE=	http://www.openscad.org/
COMMENT=	OpenSCAD - The Programmers Solid 3D CAD Modeller
LICENSE=	gnu-gpl-v2

FETCH_USING=	curl

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/openscad-2011.12
USE_LANGUAGES=	c c++

USE_TOOLS+=	cmake flex bison pkg-config
USE_LIBTOOL=	yes

SUBST_CLASSES+=prefix
SUBST_SED.prefix=-e 's,@PREFIX@,${PREFIX},g'
SUBST_FILES.prefix=${WRKSRC}/eigen2.pri ${WRKSRC}/openscad.pro
SUBST_STAGE.prefix=post-patch

SUBST_CLASSES+=destdir
SUBST_SED.destdir=-e 's,@DESTDIR@,${DESTDIR},g'
SUBST_FILES.destdir=${WRKSRC}/openscad.pro
SUBST_STAGE.destdir=post-patch

pre-build:
	(cd ${WRKSRC} && ${QTDIR$}/bin/qmake)

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
