# $NetBSD: Makefile,v 1.13 2002/10/30 15:15:16 seb Exp $

PKGNAME=		${DISTNAME:S/MesaLib/glut/}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		${DISTNAME:S/MesaLib/MesaDemos/}${EXTRACT_SUFX}
WRKSRC=			${WRKDIR}/${DISTNAME:S/Lib//}
MAINTAINER=		rh@netbsd.org
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

.include "../../mk/bsd.pkg.mk"
