# $NetBSD: Makefile,v 1.7 2008/05/26 02:13:19 joerg Exp $
#

DISTNAME=	BillardGL-1.75
PKGNAME=	${DISTNAME:S/BillardGL/billardgl/}
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://wesley.informatik.uni-freiburg.de/~nopper/BillardGL/download/

MAINTAINER=	wojtek@3miasto.net
HOMEPAGE=	http://www.tobias-nopper.de/BillardGL/
COMMENT=	3D Billard using OpenGL hardware acceleration

BUILD_DIRS=	src
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake imake pax
MAKE_ENV+=	PAX=${PAX:Q}
LDFLAGS+=	${X11_LDFLAGS}

SUBST_CLASSES+=			billardgl
SUBST_STAGE.billardgl=		do-configure
SUBST_MESSAGE.billardgl=	Fixing hard-coded paths
SUBST_FILES.billardgl=		src/Namen.h
SUBST_SED.billardgl=		-e 's,"/usr/share/,"${PREFIX}/share/,'

SUBST_CLASSES+=		d2u
SUBST_STAGE.d2u=	post-extract
SUBST_MESSAGE.d2u=	Removing CR end-of-line markers.
SUBST_FILES.d2u=	src/*.h src/*.cpp
SUBST_FILTER_CMD.d2u=	${TR} -d '\r'

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
