# $NetBSD: Makefile,v 1.21 2010/02/01 02:32:34 joerg Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/GlutKit/}
PKGREVISION=	15

COMMENT=	3DKit GLUT backend

DISTINFO_FILE=	${.CURDIR}/distinfo

WRKSRC=		${WRKDIR}/${DISTNAME}/GlutKit

MAKE_FLAGS+=	ADDITIONAL_INCLUDE_DIRS=-I${BUILDLINK_PREFIX.RenderKit}/System/Library/Headers


.include "../../graphics/RenderKit/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
