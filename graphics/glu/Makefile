# $NetBSD: Makefile,v 1.25 2004/01/20 12:18:16 agc Exp $

PKGNAME=		${DISTNAME:C/MesaLib/glu/}
MAINTAINER=		rh@NetBSD.org
COMMENT=		GLU polygon tesselation facility for Mesa

CONFLICTS+=		Mesa-glx-[0-9]*
CONFLICTS+=		Mesa<3.2.1

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../graphics/Mesa/Makefile.common"

WRKSRC=			${WRKDIR}/${DISTNAME:C/Lib//}
USE_BUILDLINK3=		yes
USE_X11=		yes
INSTLIBS=		libGLU.so.1.3

.include "../../mk/bsd.prefs.mk"

pre-build:
	${RM} -fr ${WRKSRC}/src/mesa ${WRKSRC}/src/glw

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/GL
	cd ${WRKSRC}/include/GL; for hdr in				\
		glu.h glu_mangle.h;					\
	do								\
		${INSTALL_DATA} $${hdr} ${PREFIX}/include/GL;		\
	done

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
