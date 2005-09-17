# $NetBSD: Makefile,v 1.11 2005/09/17 14:51:02 minskim Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/GeometryKit/}
PKGREVISION=	7

COMMENT=	Objective-C class library for calculating 3D geometry

DISTINFO_FILE=	${.CURDIR}/distinfo

WRKSRC=		${WRKDIR}/${DISTNAME}/3DKit/GeometryKit

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
