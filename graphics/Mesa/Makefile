# $NetBSD: Makefile,v 1.56 2004/01/22 12:58:07 adam Exp $
#

PKGNAME=	Mesa-${MESA_VERSION}
MASTER_SITES= 	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Graphics library meta package, similar to SGI's OpenGL

CONFLICTS=	Mesa-glx-[0-9]*

USE_BUILDLINK2=		yes
USE_X11=		yes
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes
NO_PATCH=		yes
EXTRACT_ONLY=		# empty

do-patch:	# empty
do-buildlink:	# empty
do-install:	# empty

.include "Makefile.common"

.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../graphics/glut/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
