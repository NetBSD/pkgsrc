# $NetBSD: Makefile,v 1.3 2003/05/02 11:55:09 wiz Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/SDLKit/}
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${DISTNAME}/SDLKit

COMMENT=	3DKit SDL backend

DISTINFO_FILE=	${.CURDIR}/distinfo

.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/RenderKit/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
