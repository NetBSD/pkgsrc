# $NetBSD: Makefile,v 1.3 2003/05/02 11:55:08 wiz Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/GlutKit/}
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${DISTNAME}/GlutKit

COMMENT=	3DKit GLUT backend

DISTINFO_FILE=	${.CURDIR}/distinfo

.include "../../graphics/RenderKit/buildlink2.mk"
.include "../../graphics/glut/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
