# $NetBSD: Makefile,v 1.4 2005/06/01 20:08:00 jlam Exp $
#

PKGNAME=		cal3d-${CAL3D_VERSION}
PKGREVISION=	1

.include "../../graphics/cal3d/Makefile.common"

COMMENT=	        Skeletal based 3d character animation library in C++

USE_TOOLS+=		automake

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../graphics/Mesa/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
