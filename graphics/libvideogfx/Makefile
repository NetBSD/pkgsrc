# $NetBSD: Makefile,v 1.5 2004/04/25 01:04:36 snj Exp $
#

DISTNAME=	libvideogfx-1.0.3
CATEGORIES=	graphics
MASTER_SITES= \
  http://rachmaninoff.informatik.uni-mannheim.de/libvideogfx/data/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE= \
  http://rachmaninoff.informatik.uni-mannheim.de/libvideogfx/index.html
COMMENT=	C++ library for low-level video processing

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_X11=	yes

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
