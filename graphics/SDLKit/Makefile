# $NetBSD: Makefile,v 1.24 2009/07/07 05:50:21 joerg Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/SDLKit/}
PKGREVISION=	18

COMMENT=	3DKit SDL backend

DISTINFO_FILE=	${.CURDIR}/distinfo

WRKSRC=		${WRKDIR}/${DISTNAME}/SDLKit

MAKE_FLAGS+=	ADDITIONAL_INCLUDE_DIRS=-I${BUILDLINK_PREFIX.RenderKit}/System/Library/Headers

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/RenderKit/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
