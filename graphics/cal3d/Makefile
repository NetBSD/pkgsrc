# $NetBSD: Makefile,v 1.12 2019/11/02 22:37:54 rillig Exp $
#

PKGNAME=	cal3d-${CAL3D_VERSION}
PKGREVISION=	3

.include "../../graphics/cal3d/Makefile.common"

COMMENT=	Skeletal based 3d character animation library in C++
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=		automake

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../mk/bsd.pkg.mk"
