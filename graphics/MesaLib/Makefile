# $NetBSD: Makefile,v 1.28 2004/01/20 02:48:33 jschauma Exp $

PKGNAME=		MesaLib-${MESA_VERSION}
WRKSRC=			${WRKDIR}/${DISTNAME:S/Lib//}
MAINTAINER=		rh@NetBSD.org
COMMENT=		Graphics library similar to SGI's OpenGL

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../graphics/Mesa/Makefile.common"

USE_BUILDLINK3=		yes
USE_X11=		yes
#USE_PKGINSTALL=		yes
#CONF_FILES=		${PREFIX}/share/examples/mesa/mesa.conf		\
#			${PKG_SYSCONFDIR}/mesa.conf

INSTLIBS=		libGL.so.1.5 libGLw.so.1.0 libOSMesa.so.6.0

.include "../../mk/bsd.prefs.mk"

# The sparc asm included with Mesa does not build on sparc64
.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "sparc64"
CONFIGURE_ARGS+=	--disable-sparc
.endif

pre-build:
	${RM} -fr ${WRKSRC}/src/glu

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/GL
	cd ${WRKSRC}/include/GL; for hdr in				\
		gl.h gl_mangle.h glext.h glx.h glxext.h glx_mangle.h	\
		osmesa.h xmesa.h xmesa_x.h xmesa_xf86.h;		\
	do								\
		${INSTALL_DATA} $${hdr} ${PREFIX}/include/GL;		\
	done

.include "../../mk/bsd.pkg.mk"
