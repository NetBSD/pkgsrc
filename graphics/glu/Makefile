# $NetBSD: Makefile,v 1.14 2002/11/18 07:49:25 jlam Exp $

PKGNAME=		${DISTNAME:C/MesaLib/glu/}
WRKSRC=			${WRKDIR}/${DISTNAME:C/Lib//}
MAINTAINER=		rh@netbsd.org
COMMENT=		GLU polygon tesselation facility for Mesa

CONFLICTS+=		Mesa-glx-[0-9]*
CONFLICTS+=		Mesa<3.2.1

.include "../Mesa/Makefile.common"

USE_BUILDLINK2=		yes
USE_X11BASE=		yes
BUILD_DIRS=		${WRKSRC}/src-glu

.include "../../mk/bsd.prefs.mk"

# Check if we got libGLU distributed with XFree86 4.x.
.if exists(${X11BASE}/include/GL/glu.h) && \
    exists(${X11BASE}/lib/X11/config/X11.tmpl)
_IS_BUILTIN_GLU!=	${EGREP} -c BuildGLULibrary ${X11BASE}/lib/X11/config/X11.tmpl || ${TRUE}
.else
_IS_BUILTIN_GLU=	0
.endif

.if (${X11PREFIX} == ${X11BASE}) && (${_IS_BUILTIN_GLU} != "0")
IGNORE=		"GLU has already been installed as part of XFree86-4.x"
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/GL
	cd ${WRKSRC}/include/GL; for hdr in				\
		glu.h glu_mangle.h;					\
	do								\
		${INSTALL_DATA} $${hdr} ${PREFIX}/include/GL;		\
	done

.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
