# $NetBSD: Makefile,v 1.2 2003/04/01 10:00:20 rh Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/SDLKit/}
WRKSRC=		${WRKDIR}/${DISTNAME}/SDLKit

COMMENT=	3DKit SDL backend

DISTINFO_FILE=	${.CURDIR}/distinfo

.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/RenderKit/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
