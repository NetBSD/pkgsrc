# $NetBSD: Makefile,v 1.11 2002/09/01 11:49:43 tron Exp $

PKGNAME=		MesaLib-${MESA_VERSION}
WRKSRC=			${WRKDIR}/${DISTNAME:S/Lib//}
MAINTAINER=		rh@netbsd.org
COMMENT=		Graphics library similar to SGI's OpenGL

.include "../Mesa/Makefile.common"

USE_BUILDLINK2=		yes
USE_X11BASE=		yes
CONFIGURE_ARGS+=	--without-glut

.include "../../mk/bsd.prefs.mk"

# Check if we got Mesa distributed with XFree86 4.x.
.if (${OPSYS} != SunOS) && exists(${X11BASE}/include/GL/glx.h)
_IS_BUILTIN_MESA!=	${EGREP} -c BuildGLXLibrary ${X11BASE}/lib/X11/config/X11.tmpl || ${TRUE}
.else
_IS_BUILTIN_MESA=	0
.endif

.if ${_IS_BUILTIN_MESA} != "0"
IGNORE=		"MesaLib/GLX has already been installed as part of XFree-4.x"
.endif

do-build:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} \
	${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}

do-install:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} \
	${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/GL
	cd ${WRKSRC}/include/GL; for hdr in				\
		gl.h gl_mangle.h glext.h glx.h glx_mangle.h osmesa.h	\
		xmesa.h xmesa_x.h xmesa_xf86.h;				\
	do								\
		${INSTALL_DATA} $${hdr} ${PREFIX}/include/GL;		\
	done

.include "../../mk/bsd.pkg.mk"
