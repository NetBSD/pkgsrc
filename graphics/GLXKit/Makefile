# $NetBSD: Makefile,v 1.9 2004/05/05 03:36:22 snj Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/GLXKit/}
PKGREVISION=	5

COMMENT=	3DKit GLX backend

DISTINFO_FILE=	${.CURDIR}/distinfo
WRKSRC=		${WRKDIR}/${DISTNAME}/GLXKit

.include "../../graphics/RenderKit/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
