# $NetBSD: Makefile,v 1.42 2005/12/05 20:50:19 rillig Exp $

PKGNAME=	MesaLib-${MESA_VERSION}
PKGREVISION=	3
COMMENT=	Graphics library similar to SGI's OpenGL

.include "../../graphics/Mesa/Makefile.common"

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

.include "../../mk/pthread.buildlink3.mk"

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
