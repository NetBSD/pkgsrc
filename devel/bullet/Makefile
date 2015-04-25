# $NetBSD: Makefile,v 1.4 2015/04/25 14:20:32 tnn Exp $
#

DISTNAME=	bullet-2.76
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://bullet.googlecode.com/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bullet.googlecode.com/
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

# clean up after install rules
post-install:
	${RMDIR} ${DESTDIR}${PREFIX}/include/LinearMath/ibmsdk
	${RMDIR} ${DESTDIR}${PREFIX}/include/LinearMath/CMakeFiles/LinearMath.dir
	${RMDIR} ${DESTDIR}${PREFIX}/include/BulletSoftBody/CMakeFiles/BulletSoftBody.dir
	${RMDIR} ${DESTDIR}${PREFIX}/include/BulletDynamics/ibmsdk
	${RMDIR} ${DESTDIR}${PREFIX}/include/BulletDynamics/CMakeFiles/BulletDynamics.dir/Vehicle
	${RMDIR} ${DESTDIR}${PREFIX}/include/BulletDynamics/CMakeFiles/BulletDynamics.dir/Dynamics
	${RMDIR} ${DESTDIR}${PREFIX}/include/BulletDynamics/CMakeFiles/BulletDynamics.dir/ConstraintSolver
	${RMDIR} ${DESTDIR}${PREFIX}/include/BulletDynamics/CMakeFiles/BulletDynamics.dir/Character
	${RMDIR} ${DESTDIR}${PREFIX}/include/BulletCollision/ibmsdk
	${RMDIR} ${DESTDIR}${PREFIX}/include/BulletCollision/CMakeFiles/BulletCollision.dir/NarrowPhaseCollision
	${RMDIR} ${DESTDIR}${PREFIX}/include/BulletCollision/CMakeFiles/BulletCollision.dir/Gimpact
	${RMDIR} ${DESTDIR}${PREFIX}/include/BulletCollision/CMakeFiles/BulletCollision.dir/CollisionShapes
	${RMDIR} ${DESTDIR}${PREFIX}/include/BulletCollision/CMakeFiles/BulletCollision.dir/CollisionDispatch
	${RMDIR} ${DESTDIR}${PREFIX}/include/BulletCollision/CMakeFiles/BulletCollision.dir/BroadphaseCollision

.include "../../graphics/glut/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
