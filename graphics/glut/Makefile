# $NetBSD: Makefile,v 1.26 2004/01/20 12:18:16 agc Exp $

PKGNAME=		${DISTNAME:S/MesaLib/glut/}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		${DISTNAME:S/MesaLib/MesaDemos/}${EXTRACT_SUFX}
MAINTAINER=		rh@NetBSD.org
COMMENT=		GLUT Graphics library similar to SGI's OpenGL

CONFLICTS+=		Mesa-glx-[0-9]*
CONFLICTS+=		Mesa<3.2.1

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../graphics/Mesa/Makefile.common"

WRKSRC=			${WRKDIR}/${DISTNAME:S/Lib//}
USE_BUILDLINK3=		yes
USE_X11=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
INSTLIBS=		libglut.so.3.7

pre-build:
	${RM} -fr ${WRKSRC}/src/mesa ${WRKSRC}/src/glw 			\
		${WRKSRC}/src/glu ${WRKSRC}/progs

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/GL
	cd ${WRKSRC}/include/GL; for hdr in				\
		glut.h glutf90.h;					\
	do								\
		${INSTALL_DATA} $${hdr} ${PREFIX}/include/GL;		\
	done

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
