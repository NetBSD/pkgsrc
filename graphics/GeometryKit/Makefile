# $NetBSD: Makefile,v 1.16 2006/07/21 06:31:26 rillig Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/GeometryKit/}
PKGREVISION=	10

COMMENT=	Objective-C class library for calculating 3D geometry

DISTINFO_FILE=	${.CURDIR}/distinfo

USE_LANGUAGES=	c objc

WRKSRC=		${WRKDIR}/${DISTNAME}/3DKit/GeometryKit

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
