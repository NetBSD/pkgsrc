# $NetBSD: Makefile,v 1.38 2005/02/23 13:04:47 grant Exp $

PKGNAME=	${DISTNAME:C/MesaLib/glu/}
COMMENT=	GLU polygon tessellation facility for Mesa

CONFLICTS+=	Mesa-glx-[0-9]*
CONFLICTS+=	Mesa<3.2.1

.include "../Mesa/Makefile.common"

USE_LANGUAGES=	c c++
MESA_REQD+=	${MESA_VERSION}

INSTLIBS=	${WRKSRC}/src/glu/sgi/libGLU.la

pre-build:
	cd ${WRKSRC} && ${RM} -fr src/mesa src/glut src/glw progs

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/GL
	cd ${WRKSRC}/include/GL; for hdr in				\
		glu.h glu_mangle.h;					\
	do								\
		${INSTALL_DATA} $${hdr} ${PREFIX}/include/GL;		\
	done

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
