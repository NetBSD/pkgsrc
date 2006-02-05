# $NetBSD: Makefile,v 1.5 2006/02/05 23:09:28 joerg Exp $
#

PKGNAME=		cal3d-${CAL3D_VERSION}
PKGREVISION=	2

.include "../../graphics/cal3d/Makefile.common"

COMMENT=	        Skeletal based 3d character animation library in C++

USE_TOOLS+=		automake

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../graphics/Mesa/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
