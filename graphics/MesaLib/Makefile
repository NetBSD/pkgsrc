# $NetBSD: Makefile,v 1.23 2003/09/18 16:25:08 jmmv Exp $

PKGNAME=		MesaLib-${MESA_VERSION}
WRKSRC=			${WRKDIR}/${DISTNAME:S/Lib//}
MAINTAINER=		rh@NetBSD.org
COMMENT=		Graphics library similar to SGI's OpenGL

.include "../../graphics/Mesa/Makefile.common"

USE_BUILDLINK2=		yes
USE_X11BASE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--without-glut
BUILD_DIRS=		${WRKSRC}/src

.include "../../mk/bsd.prefs.mk"

# The sparc asm included with Mesa does not build on sparc64
.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "sparc64"
CONFIGURE_ARGS+=	--disable-sparc
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/GL
	cd ${WRKSRC}/include/GL; for hdr in				\
		gl.h gl_mangle.h glext.h glx.h glxext.h glx_mangle.h	\
		osmesa.h xmesa.h xmesa_x.h xmesa_xf86.h;		\
	do								\
		${INSTALL_DATA} $${hdr} ${PREFIX}/include/GL;		\
	done

.include "../../mk/bsd.pkg.mk"

# must be below bsd.pkg.mk to overwrite values
PREFIX=		${LOCALBASE}
X11PREFIX=	${LOCALBASE}
