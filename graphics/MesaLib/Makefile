# $NetBSD: Makefile,v 1.39 2005/06/05 15:39:06 minskim Exp $

PKGNAME=	MesaLib-${MESA_VERSION}
PKGREVISION=	1
COMMENT=	Graphics library similar to SGI's OpenGL

.include "../Mesa/Makefile.common"

INSTLIBS=	${WRKSRC}/src/mesa/libGL.la \
		${WRKSRC}/src/glw/libGLw.la \
		${WRKSRC}/src/mesa/libOSMesa.la

# The sparc asm included with Mesa does not build on sparc64
.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "sparc64"
CONFIGURE_ARGS+=	--disable-sparc
.endif

.if !empty(CC_VERSION:Mgcc-3*)
BUILDLINK_TRANSFORM+=   rm:-O[23]
.endif

pre-build:
	cd ${WRKSRC} && ${RM} -fr src/glu src/glut progs

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/GL
	cd ${WRKSRC}/include/GL; for hdr in				\
		gl.h gl_mangle.h glext.h glx.h glxext.h glx_mangle.h	\
		osmesa.h xmesa.h xmesa_x.h xmesa_xf86.h;		\
	do								\
		${INSTALL_DATA} $${hdr} ${PREFIX}/include/GL;		\
	done

.include "../../mk/bsd.pkg.mk"
