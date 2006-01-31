# $NetBSD: Makefile,v 1.1.1.1 2006/01/31 02:47:25 rillig Exp $
#

DISTNAME=	BillardGL-1.75
PKGNAME=	${DISTNAME:S/BillardGL/billardgl/}
CATEGORIES=	games
MASTER_SITES=	http://wesley.informatik.uni-freiburg.de/~nopper/BillardGL/download/

MAINTAINER=	wojtek@3miasto.net
HOMEPAGE=	http://www.tobias-nopper.de/BillardGL/
COMMENT=	3D Billard using OpenGL hardware acceleration

BUILD_DIRS=	src
USE_TOOLS+=	gmake imake
MAKE_ENV+=	PAX=${PAX:Q}

SUBST_CLASSES+=			billardgl
SUBST_STAGE.billardgl=		do-configure
SUBST_MESSAGE.billardgl=	Fixing hard-coded paths
SUBST_FILES.billardgl=		src/Namen.h
SUBST_SED.billardgl=		-e 's,"/usr/share/,"${PREFIX}/share/,'

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../pkgtools/x11-links/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
