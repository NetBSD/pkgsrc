# $NetBSD: Makefile,v 1.18 2003/04/17 22:15:44 jmmv Exp $

PKGNAME=		MesaLib-${MESA_VERSION}
PKGREVISION=		2
WRKSRC=			${WRKDIR}/${DISTNAME:S/Lib//}
MAINTAINER=		rh@netbsd.org
COMMENT=		Graphics library similar to SGI's OpenGL

.include "../Mesa/Makefile.common"

USE_BUILDLINK2=		yes
USE_X11BASE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--without-glut
BUILD_DIRS=		${WRKSRC}/src

.include "../../mk/bsd.prefs.mk"

# XXX should be >= 3.4.2
.if empty(MESA_REQD:M5.[0-9]*)

# Check if we got Mesa distributed with XFree86 4.x.
.if exists(${X11BASE}/include/GL/glx.h) && \
    exists(${X11BASE}/lib/X11/config/X11.tmpl)
_IS_BUILTIN_MESA!=	${EGREP} -c BuildGLXLibrary ${X11BASE}/lib/X11/config/X11.tmpl || ${TRUE}
.else
_IS_BUILTIN_MESA=	0
.endif

.if (${X11PREFIX} == ${X11BASE}) && (${_IS_BUILTIN_MESA} != "0")
PKG_SKIP_REASON= "${PKGNAME} is part of your X11 distribution"
.endif

.endif  # MESA_REQD

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
