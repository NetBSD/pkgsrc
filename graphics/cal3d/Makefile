# $NetBSD: Makefile,v 1.2 2004/10/03 00:14:49 tv Exp $
#

PKGNAME=		cal3d-${CAL3D_VERSION}
PKGREVISION=	1

.include "../../graphics/cal3d/Makefile.common"

COMMENT=	        Skeletal based 3d character animation library in C++

USE_BUILDLINK3=		yes

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../graphics/Mesa/buildlink3.mk"

.include "../../mk/automake.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
