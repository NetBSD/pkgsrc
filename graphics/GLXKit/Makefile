# $NetBSD: Makefile,v 1.7 2004/01/23 21:50:45 jmmv Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/GLXKit/}
PKGREVISION=	4

COMMENT=	3DKit GLX backend

DISTINFO_FILE=	${.CURDIR}/distinfo
WRKSRC=		${WRKDIR}/${DISTNAME}/GLXKit

.include "../../graphics/RenderKit/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
