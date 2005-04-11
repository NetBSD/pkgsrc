# $NetBSD: Makefile,v 1.3 2005/04/11 21:46:00 tv Exp $
#

PKGNAME=		cal3d-${CAL3D_VERSION}
PKGREVISION=	1

.include "../../graphics/cal3d/Makefile.common"

COMMENT=	        Skeletal based 3d character animation library in C++


pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../graphics/Mesa/buildlink3.mk"

.include "../../mk/automake.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
