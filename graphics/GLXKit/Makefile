# $NetBSD: Makefile,v 1.4 2003/07/13 13:51:55 wiz Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/GLXKit/}
PKGREVISION=	2
WRKSRC=		${WRKDIR}/${DISTNAME}/GLXKit

COMMENT=	3DKit GLX backend

DISTINFO_FILE=	${.CURDIR}/distinfo

.include "../../graphics/RenderKit/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
