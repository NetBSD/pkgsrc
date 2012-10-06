# $NetBSD: Makefile,v 1.8 2012/10/06 14:10:42 asau Exp $
#

PKGNAME=		cal3d-${CAL3D_VERSION}
PKGREVISION=	2

.include "../../graphics/cal3d/Makefile.common"

COMMENT=	Skeletal based 3d character animation library in C++

USE_TOOLS+=		automake

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../graphics/Mesa/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
