# $NetBSD: Makefile,v 1.1.1.1 2003/02/13 18:55:41 drochner Exp $
#

DISTNAME=	libvideogfx-1.0.3
CATEGORIES=	graphics
MASTER_SITES= \
  http://rachmaninoff.informatik.uni-mannheim.de/libvideogfx/data/

MAINTAINER=	packages@netbsd.org
HOMEPAGE= \
  http://rachmaninoff.informatik.uni-mannheim.de/libvideogfx/index.html
COMMENT=	C++ library for low-level video processing

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=	YES
USE_X11=	yes

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
