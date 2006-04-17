# $NetBSD: Makefile,v 1.14 2006/04/17 13:46:03 wiz Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/GLXKit/}
PKGREVISION=	10

COMMENT=	3DKit GLX backend

DISTINFO_FILE=	${.CURDIR}/distinfo
WRKSRC=		${WRKDIR}/${DISTNAME}/GLXKit

.include "../../graphics/RenderKit/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
