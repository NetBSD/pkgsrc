# $NetBSD: Makefile,v 1.55 2004/01/20 02:48:33 jschauma Exp $
#

PKGNAME=	Mesa-${MESA_VERSION}
MASTER_SITES= 	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Graphics library meta package, similar to SGI's OpenGL

CONFLICTS=	Mesa-glx-[0-9]*

USE_BUILDLINK2=	yes

USE_X11=	yes
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_PATCH=	yes
EXTRACT_ONLY=	# empty

do-patch:	# empty
do-buildlink:	# empty
do-install:	# empty

.include "Makefile.common"

.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../graphics/glut/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
