# $NetBSD: Makefile,v 1.18 2003/07/17 21:40:59 grant Exp $

PKGNAME=		${DISTNAME:S/MesaLib/glut/}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		${DISTNAME:S/MesaLib/MesaDemos/}${EXTRACT_SUFX}
WRKSRC=			${WRKDIR}/${DISTNAME:S/Lib//}
MAINTAINER=		rh@NetBSD.org
COMMENT=		GLUT Graphics library similar to SGI's OpenGL

CONFLICTS+=		Mesa-glx-[0-9]*
CONFLICTS+=		Mesa<3.2.1

.include "../Mesa/Makefile.common"

USE_BUILDLINK2=		yes
USE_X11BASE=		yes
CONFIGURE_DIRS=		${WRKSRC}
BUILD_DIRS=		${WRKSRC}/src-glut

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/GL
	cd ${WRKSRC}/include/GL; for hdr in				\
		glut.h glutf90.h;					\
	do								\
		${INSTALL_DATA} $${hdr} ${PREFIX}/include/GL;		\
	done

.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

.if (${MESA_REQD} == 3.4.2)
SO_SUFFIX=3
SO_VERS=3.7
.elif (${MESA_REQD} == 5.0.1)
SO_SUFFIX=10
SO_VERS=10.1
.else
.error Library version not known!
.endif

PLIST_SUBST+=SO_SUFFIX=${SO_SUFFIX}
PLIST_SUBST+=SO_VERS=${SO_VERS}

# must be below bsd.pkg.mk to overwrite values
PREFIX=		${LOCALBASE}
X11PREFIX=	${LOCALBASE}
