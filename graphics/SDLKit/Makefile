# $NetBSD: Makefile,v 1.8 2004/01/03 18:49:41 reed Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/SDLKit/}
PKGREVISION=	5
WRKSRC=		${WRKDIR}/${DISTNAME}/SDLKit

COMMENT=	3DKit SDL backend

DISTINFO_FILE=	${.CURDIR}/distinfo

.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/RenderKit/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
