# $NetBSD: Makefile,v 1.16 2008/01/18 05:06:37 tnn Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/GLXKit/}
PKGREVISION=	12

COMMENT=	3DKit GLX backend

DISTINFO_FILE=	${.CURDIR}/distinfo
WRKSRC=		${WRKDIR}/${DISTNAME}/GLXKit

.include "../../graphics/RenderKit/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
