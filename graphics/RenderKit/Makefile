# $NetBSD: Makefile,v 1.6 2004/01/20 12:18:15 agc Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/RenderKit/}
PKGREVISION=	3

COMMENT=	Objective-C API for core scene rendering

DISTINFO_FILE=	${.CURDIR}/distinfo

WRKSRC=		${WRKDIR}/${DISTNAME}/3DKit/RenderKit

.include "../../graphics/GeometryKit/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
