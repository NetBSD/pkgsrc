# $NetBSD: Makefile,v 1.19 2003/09/18 16:25:11 jmmv Exp $

PKGNAME=		${DISTNAME:C/MesaLib/glu/}
WRKSRC=			${WRKDIR}/${DISTNAME:C/Lib//}
MAINTAINER=		rh@NetBSD.org
COMMENT=		GLU polygon tesselation facility for Mesa

CONFLICTS+=		Mesa-glx-[0-9]*
CONFLICTS+=		Mesa<3.2.1

.include "../../graphics/Mesa/Makefile.common"

USE_BUILDLINK2=		yes
USE_X11BASE=		yes
BUILD_DIRS=		${WRKSRC}/src-glu

.include "../../mk/bsd.prefs.mk"

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
