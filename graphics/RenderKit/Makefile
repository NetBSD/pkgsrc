# $NetBSD: Makefile,v 1.2 2003/04/01 09:24:54 rh Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/RenderKit/}
WRKSRC=		${WRKDIR}/${DISTNAME}/3DKit/RenderKit

COMMENT=	Objective-C API for core scene rendering

DISTINFO_FILE=	${.CURDIR}/distinfo

.include "../../graphics/GeometryKit/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
