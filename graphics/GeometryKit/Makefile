# $NetBSD: Makefile,v 1.4 2004/01/03 18:49:41 reed Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/GeometryKit/}
PKGREVISION=	3
WRKSRC=		${WRKDIR}/${DISTNAME}/3DKit/GeometryKit

COMMENT=	Objective-C class library for calculating 3D geometry

.include "../../x11/gnustep-back/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
