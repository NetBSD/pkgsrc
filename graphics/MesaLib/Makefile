# $NetBSD: Makefile,v 1.30 2004/01/22 12:58:19 adam Exp $
#

PKGNAME=	MesaLib-${MESA_VERSION}
COMMENT=	Graphics library similar to SGI's OpenGL

.include "../../graphics/Mesa/Makefile.common"

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
#CONF_FILES=		${PREFIX}/share/examples/mesa/mesa.conf		\
#			${PKG_SYSCONFDIR}/mesa.conf

INSTLIBS=	${WRKSRC}/src/mesa/libGL.la \
		${WRKSRC}/src/glw/libGLw.la \
		${WRKSRC}/src/mesa/libOSMesa.la

.include "../../mk/bsd.prefs.mk"

# The sparc asm included with Mesa does not build on sparc64
.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "sparc64"
CONFIGURE_ARGS+=	--disable-sparc
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
