# $NetBSD: Makefile,v 1.1.1.1 2002/09/29 06:15:34 rh Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/GLXKit/}
WRKSRC=		${WRKDIR}/${DISTNAME}/GLXKit

COMMENT=	3DKit GLX backend

.include "../../graphics/RenderKit/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
