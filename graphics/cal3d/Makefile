# $NetBSD: Makefile,v 1.1.1.1 2004/02/10 09:14:34 garbled Exp $
#

PKGNAME=		cal3d-${CAL3D_VERSION}

.include "../../graphics/cal3d/Makefile.common"

COMMENT=	        Skeletal based 3d character animation library in C++

USE_BUILDLINK3=		yes

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../graphics/Mesa/buildlink3.mk"

.include "../../mk/automake.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
