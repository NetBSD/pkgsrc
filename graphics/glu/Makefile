# $NetBSD: Makefile,v 1.23 2004/01/05 11:47:33 jlam Exp $

PKGNAME=		${DISTNAME:C/MesaLib/glu/}
PKGREVISION=		3
WRKSRC=			${WRKDIR}/${DISTNAME:C/Lib//}
MAINTAINER=		rh@NetBSD.org
COMMENT=		GLU polygon tesselation facility for Mesa

CONFLICTS+=		Mesa-glx-[0-9]*
CONFLICTS+=		Mesa<3.2.1

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../graphics/Mesa/Makefile.common"

USE_BUILDLINK3=		yes
USE_X11=		yes
BUILD_DIRS=		${WRKSRC}/si-glu

.include "../../mk/bsd.prefs.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/GL
	cd ${WRKSRC}/include/GL; for hdr in				\
		glu.h glu_mangle.h;					\
	do								\
		${INSTALL_DATA} $${hdr} ${PREFIX}/include/GL;		\
	done

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
