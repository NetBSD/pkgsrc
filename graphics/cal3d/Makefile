# $NetBSD: Makefile,v 1.7 2008/06/12 02:14:31 joerg Exp $
#

PKGNAME=		cal3d-${CAL3D_VERSION}
PKGREVISION=	2

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../graphics/cal3d/Makefile.common"

COMMENT=	Skeletal based 3d character animation library in C++

USE_TOOLS+=		automake

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../graphics/Mesa/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
