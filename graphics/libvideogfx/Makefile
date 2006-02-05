# $NetBSD: Makefile,v 1.10 2006/02/05 23:09:35 joerg Exp $
#

DISTNAME=	libvideogfx-1.0.3
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES= \
  http://rachmaninoff.informatik.uni-mannheim.de/libvideogfx/data/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE= \
  http://rachmaninoff.informatik.uni-mannheim.de/libvideogfx/index.html
COMMENT=	C++ library for low-level video processing

USE_LANGUAGES=	c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
