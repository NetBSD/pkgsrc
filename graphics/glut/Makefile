# $NetBSD: Makefile,v 1.51 2009/06/11 07:23:24 wiz Exp $

PKGNAME=	glut-${MESA_PKGVERSION}
PKGREVISION=	1
COMMENT=	GLUT Graphics library similar to SGI's OpenGL

CONFLICTS+=	Mesa-glx-[0-9]*
CONFLICTS+=	Mesa<3.2.1

MESA_HEADERS=	glut.h glutf90.h

PKGCONFIG_OVERRIDE+=    src/glut/glx/glut.pc.in
# no configure stage
PKGCONFIG_OVERRIDE_STAGE=       pre-build

.include "../../graphics/Mesa/Makefile.lib"

BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=${MESA_PKGVERSION}
BUILDLINK_API_DEPENDS.glu+=	glu>=${MESA_PKGVERSION}

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"

pre-build:
	cd ${WRKSRC} && ${RM} -fr src/mesa src/glu src/glx src/glw progs
###	XXX why is this needed?
	mkdir -p ${WRKSRC}/src/glut/lib

# no configure phase
.include "../../mk/configure/pkg-config-override.mk"
.include "../../mk/bsd.pkg.mk"
