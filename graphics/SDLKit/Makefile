# $NetBSD: Makefile,v 1.7 2003/11/30 22:58:41 jschauma Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/SDLKit/}
PKGREVISION=	4
WRKSRC=		${WRKDIR}/${DISTNAME}/SDLKit

COMMENT=	3DKit SDL backend

DISTINFO_FILE=	${.CURDIR}/distinfo

.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/RenderKit/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
