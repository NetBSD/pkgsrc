# $NetBSD: Makefile,v 1.3 2003/07/13 13:51:56 wiz Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/GeometryKit/}
PKGREVISION=	2
WRKSRC=		${WRKDIR}/${DISTNAME}/3DKit/GeometryKit

COMMENT=	Objective-C class library for calculating 3D geometry

.include "../../x11/gnustep-back/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
