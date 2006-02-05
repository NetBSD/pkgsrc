# $NetBSD: Makefile,v 1.18 2006/02/05 23:09:27 joerg Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/SDLKit/}
PKGREVISION=	13

COMMENT=	3DKit SDL backend

DISTINFO_FILE=	${.CURDIR}/distinfo

WRKSRC=		${WRKDIR}/${DISTNAME}/SDLKit

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/RenderKit/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
