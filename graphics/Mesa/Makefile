# $NetBSD: Makefile,v 1.45 2002/11/18 07:49:24 jlam Exp $
#

PKGNAME=	Mesa-${MESA_VERSION}
PKGREVISION=	1
MASTER_SITES= 	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
COMMENT=	Graphics library meta package, similar to SGI's OpenGL

CONFLICTS=	Mesa-glx-[0-9]*

.include "Makefile.common"

MESA_REQD=	${MESA_VERSION}

USE_BUILDLINK2=	yes

USE_X11BASE=	yes
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
EXTRACT_ONLY=	# empty

do-install:	# empty

.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../graphics/glut/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
