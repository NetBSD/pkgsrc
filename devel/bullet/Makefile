# $NetBSD: Makefile,v 1.10 2019/08/08 10:33:27 nia Exp $

PKGNAME=	${DISTNAME:S/-r2704//}
DISTNAME=	bullet-2.82-r2704
CATEGORIES=	devel
#MASTER_SITES=	http://bullet.googlecode.com/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bulletphysics.org/wordpress/
COMMENT=	Collision detection, soft body and rigid body dynamics library
LICENSE=	mit

USE_TOOLS+=	pkg-config
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	bullet.pc.in
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE:STRING=Release
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=on
# doesn't install anything without this
CMAKE_ARGS+=	-DINSTALL_LIBS:BOOL=on

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Linux" && ${OPSYS} != "SunOS"
SUBST_CLASSES+=	lcompat
SUBST_STAGE.lcompat=	pre-configure
SUBST_FILES.lcompat=	Demos/AllBulletDemos/CMakeLists.txt
SUBST_SED.lcompat=	-e "s|{OPENGL_glu_LIBRARY}|{OPENGL_glu_LIBRARY} -lcompat|g"
SUBST_MESSAGE.lcompat=	Adding -lcompat for demos
.endif

.include "../../graphics/glut/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
