# $NetBSD: Makefile,v 1.24 2004/01/05 11:47:33 jlam Exp $

PKGNAME=		${DISTNAME:S/MesaLib/glut/}
PKGREVISION=		3
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		${DISTNAME:S/MesaLib/MesaDemos/}${EXTRACT_SUFX}
WRKSRC=			${WRKDIR}/${DISTNAME:S/Lib//}
MAINTAINER=		rh@NetBSD.org
COMMENT=		GLUT Graphics library similar to SGI's OpenGL

CONFLICTS+=		Mesa-glx-[0-9]*
CONFLICTS+=		Mesa<3.2.1

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../graphics/Mesa/Makefile.common"

USE_BUILDLINK3=		yes
USE_X11=		yes
CONFIGURE_DIRS=		${WRKSRC}
BUILD_DIRS=		${WRKSRC}/src-glut
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/GL
	cd ${WRKSRC}/include/GL; for hdr in				\
		glut.h glutf90.h;					\
	do								\
		${INSTALL_DATA} $${hdr} ${PREFIX}/include/GL;		\
	done

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
