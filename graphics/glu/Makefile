# $NetBSD: Makefile,v 1.12 2002/09/01 11:49:42 tron Exp $

PKGNAME=		${DISTNAME:C/MesaLib/glu/}
WRKSRC=			${WRKDIR}/${DISTNAME:C/Lib//}
MAINTAINER=		rh@netbsd.org
COMMENT=		GLU polygon tesselation facility for Mesa

CONFLICTS+=		Mesa-glx-[0-9]*
CONFLICTS+=		Mesa<3.2.1

.include "../Mesa/Makefile.common"

USE_BUILDLINK2=		yes
USE_X11BASE=		yes

.include "../../mk/bsd.prefs.mk"

# Check if we got libGLU distributed with XFree86 4.x.
.if (${OPSYS} != SunOS) && exists(${X11BASE}/include/GL/glu.h)
_IS_BUILTIN_GLU!=	${EGREP} -c BuildGLULibrary ${X11BASE}/lib/X11/config/X11.tmpl || ${TRUE}
.else
_IS_BUILTIN_GLU=	0
.endif

.if ${_IS_BUILTIN_GLU} != "0"
IGNORE=		"GLU has already been installed as part of XFree86-4.x"
.endif

do-build:
	cd ${WRKSRC}/src-glu && ${SETENV} ${MAKE_ENV} \
	${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}

do-install:
	cd ${WRKSRC}/src-glu && ${SETENV} ${MAKE_ENV} \
	${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/GL
	cd ${WRKSRC}/include/GL; for hdr in				\
		glu.h glu_mangle.h;					\
	do								\
		${INSTALL_DATA} $${hdr} ${PREFIX}/include/GL;		\
	done

.include "../../mk/bsd.pkg.mk"
