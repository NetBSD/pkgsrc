# $NetBSD: Makefile,v 1.54 2003/11/30 22:58:41 jschauma Exp $
#

PKGNAME=	Mesa-${MESA_VERSION}
PKGREVISION=	1
MASTER_SITES= 	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Graphics library meta package, similar to SGI's OpenGL

CONFLICTS=	Mesa-glx-[0-9]*

pre-patch:	# empty

USE_BUILDLINK2=	yes

USE_X11BASE=	yes
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
EXTRACT_ONLY=	# empty

post-patch:	# empty
do-install:	# empty

.include "Makefile.common"

.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../graphics/glut/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
