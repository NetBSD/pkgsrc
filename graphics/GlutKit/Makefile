# $NetBSD: Makefile,v 1.1.1.1 2002/09/29 06:16:06 rh Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/GlutKit/}
WRKSRC=		${WRKDIR}/${DISTNAME}/GlutKit

COMMENT=	3DKit GLUT backend

.include "../../graphics/RenderKit/buildlink2.mk"
.include "../../graphics/glut/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
