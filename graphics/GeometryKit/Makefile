# $NetBSD: Makefile,v 1.1.1.1 2002/09/29 06:14:11 rh Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/GeometryKit/}
WRKSRC=		${WRKDIR}/${DISTNAME}/3DKit/GeometryKit

COMMENT=	Objective-C class library for calculating 3D geometry

.include "../../x11/gnustep-back/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
