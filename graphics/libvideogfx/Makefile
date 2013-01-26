# $NetBSD: Makefile,v 1.24 2013/01/26 21:36:30 adam Exp $
#

DISTNAME=	libvideogfx-1.0.3
PKGREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	http://rachmaninoff.informatik.uni-mannheim.de/libvideogfx/data/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rachmaninoff.informatik.uni-mannheim.de/libvideogfx/index.html
COMMENT=	C++ library for low-level video processing
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
