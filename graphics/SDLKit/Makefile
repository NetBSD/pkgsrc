# $NetBSD: Makefile,v 1.11 2004/03/26 02:27:40 wiz Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/SDLKit/}
PKGREVISION=	7

COMMENT=	3DKit SDL backend

DISTINFO_FILE=	${.CURDIR}/distinfo

WRKSRC=		${WRKDIR}/${DISTNAME}/SDLKit

.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/RenderKit/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
