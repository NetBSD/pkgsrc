# $NetBSD: Makefile,v 1.7 2004/10/03 00:14:55 tv Exp $
#

DISTNAME=	libvideogfx-1.0.3
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES= \
  http://rachmaninoff.informatik.uni-mannheim.de/libvideogfx/data/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE= \
  http://rachmaninoff.informatik.uni-mannheim.de/libvideogfx/index.html
COMMENT=	C++ library for low-level video processing

USE_BUILDLINK3=	YES
USE_LANGUAGES=	c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_X11=	yes

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
