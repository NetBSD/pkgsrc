# $NetBSD: Makefile,v 1.41 2005/12/05 20:50:20 rillig Exp $

PKGNAME=	${DISTNAME:C/MesaLib/glu/}
PKGREVISION=	1
COMMENT=	GLU polygon tessellation facility for Mesa

CONFLICTS+=	Mesa-glx-[0-9]*
CONFLICTS+=	Mesa<3.2.1

.include "../../graphics/Mesa/Makefile.common"

USE_LANGUAGES=	c c++

INSTLIBS=	${WRKSRC}/src/glu/sgi/libGLU.la

BUILDLINK_DEPENDS.MesaLib+=	MesaLib>=${MESA_VERSION}
.include "../../graphics/MesaLib/buildlink3.mk"

pre-build:
	cd ${WRKSRC} && ${RM} -fr src/mesa src/glut src/glw progs

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/GL
	cd ${WRKSRC}/include/GL; for hdr in				\
		glu.h glu_mangle.h;					\
	do								\
		${INSTALL_DATA} $${hdr} ${PREFIX}/include/GL;		\
	done

.include "../../mk/bsd.pkg.mk"
