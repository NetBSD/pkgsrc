# $NetBSD: Makefile,v 1.2 2003/04/01 09:46:08 rh Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/GLXKit/}
WRKSRC=		${WRKDIR}/${DISTNAME}/GLXKit

COMMENT=	3DKit GLX backend

DISTINFO_FILE=	${.CURDIR}/distinfo

.include "../../graphics/RenderKit/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
