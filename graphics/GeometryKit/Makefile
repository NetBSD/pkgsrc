# $NetBSD: Makefile,v 1.8 2004/05/05 03:36:23 snj Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/GeometryKit/}
PKGREVISION=	5

COMMENT=	Objective-C class library for calculating 3D geometry

WRKSRC=		${WRKDIR}/${DISTNAME}/3DKit/GeometryKit

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
