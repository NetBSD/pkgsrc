# $NetBSD: Makefile,v 1.4 2003/07/13 13:51:57 wiz Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/SDLKit/}
PKGREVISION=	2
WRKSRC=		${WRKDIR}/${DISTNAME}/SDLKit

COMMENT=	3DKit SDL backend

DISTINFO_FILE=	${.CURDIR}/distinfo

.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/RenderKit/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
