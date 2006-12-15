# $NetBSD: Makefile,v 1.47 2006/12/15 18:41:16 joerg Exp $

PKGNAME=	glut-${MESA_VERSION}
COMMENT=	GLUT Graphics library similar to SGI's OpenGL

CONFLICTS+=	Mesa-glx-[0-9]*
CONFLICTS+=	Mesa<3.2.1

.include "../../graphics/Mesa/Makefile.lib"

BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=${MESA_VERSION}
BUILDLINK_API_DEPENDS.glu+=	glu>=${MESA_VERSION}

INSTLIBS=	${WRKSRC}/src/glut/glx/libglut.la

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"

pre-build:
	cd ${WRKSRC} && ${RM} -fr src/mesa src/glu src/glw progs

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/GL
	cd ${WRKSRC}/include/GL; for hdr in				\
		glut.h glutf90.h;					\
	do								\
		${INSTALL_DATA} $${hdr} ${DESTDIR}${PREFIX}/include/GL;	\
	done

.include "../../mk/bsd.pkg.mk"
