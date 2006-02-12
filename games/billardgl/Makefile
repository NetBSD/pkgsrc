# $NetBSD: Makefile,v 1.4 2006/02/12 07:19:31 rillig Exp $
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
USE_TOOLS+=	gmake imake
MAKE_ENV+=	PAX=${PAX:Q}
LDFLAGS+=	${X11_LDFLAGS}

SUBST_CLASSES+=			billardgl
SUBST_STAGE.billardgl=		do-configure
SUBST_MESSAGE.billardgl=	Fixing hard-coded paths
SUBST_FILES.billardgl=		src/Namen.h
SUBST_SED.billardgl=		-e 's,"/usr/share/,"${PREFIX}/share/,'

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
