# $NetBSD: Makefile,v 1.48 2003/03/28 21:14:21 wiz Exp $
#

PKGNAME=	Mesa-${MESA_VERSION}
MASTER_SITES= 	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
COMMENT=	Graphics library meta package, similar to SGI's OpenGL

CONFLICTS=	Mesa-glx-[0-9]*

.include "Makefile.common"

USE_BUILDLINK2=	yes

USE_X11BASE=	yes
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
EXTRACT_ONLY=	# empty

MAKEFLAGS+=	MESA_REQD=${MESA_REQD}

do-install:	# empty

.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../graphics/glut/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
