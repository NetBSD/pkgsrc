# $NetBSD: Makefile,v 1.19 2010/02/01 02:40:26 joerg Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/RenderKit/}
PKGREVISION=	14

COMMENT=	Objective-C API for core scene rendering

DISTINFO_FILE=	${.CURDIR}/distinfo

WRKSRC=		${WRKDIR}/${DISTNAME}/3DKit/RenderKit

.include "../../graphics/GeometryKit/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
