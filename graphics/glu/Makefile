# $NetBSD: Makefile,v 1.32 2004/10/07 16:36:47 tv Exp $
#

PKGNAME=	${DISTNAME:C/MesaLib/glu/}
PKGREVISION=	2
COMMENT=	GLU polygon tessellation facility for Mesa

CONFLICTS+=	Mesa-glx-[0-9]*
CONFLICTS+=	Mesa<3.2.1

.include "../../graphics/Mesa/Makefile.common"

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++
MESA_REQD+=		${MESA_VERSION}

INSTLIBS=	${WRKSRC}/src/glu/sgi/libGLU.la

.include "../../mk/bsd.prefs.mk"

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
