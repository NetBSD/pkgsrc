# $NetBSD: Makefile,v 1.2 2003/05/02 11:55:08 wiz Exp $
#

.include "../../graphics/3DKit/Makefile.common"

PKGNAME=	${DISTNAME:S/3DKit/GeometryKit/}
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${DISTNAME}/3DKit/GeometryKit

COMMENT=	Objective-C class library for calculating 3D geometry

.include "../../x11/gnustep-back/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
