# $NetBSD: Makefile,v 1.10 2018/01/03 00:35:24 rillig Exp $
#

PKGNAME=		cal3d-${CAL3D_VERSION}
PKGREVISION=	3

.include "../../graphics/cal3d/Makefile.common"

COMMENT=	Skeletal based 3d character animation library in C++
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=		automake

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../graphics/Mesa/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
