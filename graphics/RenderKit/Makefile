# $NetBSD: Makefile,v 1.7 2004/01/23 21:50:45 jmmv Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/RenderKit/}
PKGREVISION=	4

COMMENT=	Objective-C API for core scene rendering

DISTINFO_FILE=	${.CURDIR}/distinfo

WRKSRC=		${WRKDIR}/${DISTNAME}/3DKit/RenderKit

.include "../../graphics/GeometryKit/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
