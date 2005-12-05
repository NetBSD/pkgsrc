# $NetBSD: Makefile,v 1.40 2005/12/05 20:50:20 rillig Exp $

PKGNAME=	${DISTNAME:S/MesaLib/glut/}
PKGREVISION=	3
COMMENT=	GLUT Graphics library similar to SGI's OpenGL

CONFLICTS+=	Mesa-glx-[0-9]*
CONFLICTS+=	Mesa<3.2.1

.include "../../graphics/Mesa/Makefile.common"

BUILDLINK_DEPENDS.MesaLib+=	MesaLib>=${MESA_VERSION}
BUILDLINK_DEPENDS.glu+=		glu>=${MESA_VERSION}

INSTLIBS=	${WRKSRC}/src/glut/glx/libglut.la

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"

pre-build:
	cd ${WRKSRC} && ${RM} -fr src/mesa src/glu src/glw progs

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/GL
	cd ${WRKSRC}/include/GL; for hdr in				\
		glut.h glutf90.h;					\
	do								\
		${INSTALL_DATA} $${hdr} ${PREFIX}/include/GL;		\
	done

.include "../../mk/bsd.pkg.mk"
