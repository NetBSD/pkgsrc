# $NetBSD: Makefile,v 1.9 2015/04/25 14:23:07 tnn Exp $
#

PKGNAME=		cal3d-${CAL3D_VERSION}
PKGREVISION=	3

.include "../../graphics/cal3d/Makefile.common"

COMMENT=	Skeletal based 3d character animation library in C++

USE_TOOLS+=		automake

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../graphics/Mesa/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
