# $NetBSD: Makefile,v 1.8 2004/03/26 02:27:40 wiz Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/RenderKit/}
PKGREVISION=	5

COMMENT=	Objective-C API for core scene rendering

DISTINFO_FILE=	${.CURDIR}/distinfo

WRKSRC=		${WRKDIR}/${DISTNAME}/3DKit/RenderKit

.include "../../graphics/GeometryKit/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
