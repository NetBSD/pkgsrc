# $NetBSD: Makefile,v 1.12 2017/08/01 17:40:11 wiz Exp $
#

DISTNAME=	BillardGL-1.75
PKGNAME=	${DISTNAME:S/BillardGL/billardgl/}
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=billardgl/}

MAINTAINER=	wojtek@3miasto.net
#HOMEPAGE=	http://www.tobias-nopper.de/BillardGL/
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

INSTALLATION_DIRS=	bin

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
