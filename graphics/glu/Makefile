# $NetBSD: Makefile,v 1.16 2003/03/09 19:04:54 jschauma Exp $

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

# XXX should be >= 3.4.2
.if empty(MESA_REQD:M5.[0-9]*)

# Check if we got libGLU distributed with XFree86 4.x.
.if exists(${X11BASE}/include/GL/glu.h) && \
    exists(${X11BASE}/lib/X11/config/X11.tmpl)
_IS_BUILTIN_GLU!=	${EGREP} -c BuildGLULibrary ${X11BASE}/lib/X11/config/X11.tmpl || ${TRUE}
.else
_IS_BUILTIN_GLU=	0
.endif

.if (${X11PREFIX} == ${X11BASE}) && (${_IS_BUILTIN_GLU} != "0")
PKG_SKIP_REASON= "${PKGNAME} is part of your X11 distribution"
.endif

.endif  # MESA_REQD

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/GL
	cd ${WRKSRC}/include/GL; for hdr in				\
		glu.h glu_mangle.h;					\
	do								\
		${INSTALL_DATA} $${hdr} ${PREFIX}/include/GL;		\
	done

.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

# must be below bsd.pkg.mk to overwrite values
PREFIX=		${LOCALBASE}
X11PREFIX=	${LOCALBASE}
