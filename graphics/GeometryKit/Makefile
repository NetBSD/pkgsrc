# $NetBSD: Makefile,v 1.17 2006/07/22 05:10:54 rillig Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/GeometryKit/}
PKGREVISION=	10

COMMENT=	Objective-C class library for calculating 3D geometry

DISTINFO_FILE=	${.CURDIR}/distinfo

USE_LANGUAGES=	objc

WRKSRC=		${WRKDIR}/${DISTNAME}/3DKit/GeometryKit

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
