# $NetBSD: Makefile,v 1.3 2003/05/02 11:55:07 wiz Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/GLXKit/}
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${DISTNAME}/GLXKit

COMMENT=	3DKit GLX backend

DISTINFO_FILE=	${.CURDIR}/distinfo

.include "../../graphics/RenderKit/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
