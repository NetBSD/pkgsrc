# $NetBSD: Makefile,v 1.22 2010/01/01 17:47:05 joerg Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/GeometryKit/}
PKGREVISION=	14

MAKE_JOBS_SAFE=	no

COMMENT=	Objective-C class library for calculating 3D geometry

DISTINFO_FILE=	${.CURDIR}/distinfo

USE_LANGUAGES=	objc

WRKSRC=		${WRKDIR}/${DISTNAME}/3DKit/GeometryKit

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
